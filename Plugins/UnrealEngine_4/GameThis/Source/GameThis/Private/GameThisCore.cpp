/*
===========================================================================
This code is part of the "Source Code" content in
Game This - Community by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/GameThis-Community>

The MIT License (MIT)
Copyright (c) 2018-2019 David Palacios (Hevedy) <https://github.com/Hevedy>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================
*/

/*
================================================
GameThisCore.cpp
================================================
*/


#include "GameThisCore.h"
#include "GameThisIO.h"

//#include "BufferArchive.h"
//#include "MemoryReader.h"
//#include "PlatformFilemanager.h"

#include "Runtime/Core/Public/GenericPlatform/GenericPlatformDriver.h"
#include "Runtime/Core/Public/Misc/SecureHash.h"
//#include "GenericTeamAgentInterface.h"
#include "Runtime/Core/Public/Logging/MessageLog.h"
#include "Containers/UnrealString.h"
#include "GenericPlatform/GenericPlatformProcess.h"

#if WITH_EDITOR
#include "Runtime/Core/Public/Internationalization/Regex.h"
#endif


static FProcHandle Nexus;

GameThisCore::GameThisCore() {
	//NexusID = 0;
}

GameThisCore::~GameThisCore() {
	Shutdown();
}

void GameThisCore::Shutdown() {
	if ( !Active ) { return; }
	Active = false;
	//NexusLastReady = false;
	if ( InputListeningThread != NULL && InputListeningThread->joinable() ) {
		InputListeningThread->join();
	}
	if ( Nexus.IsValid() ) {
		FGenericPlatformProcess::CloseProc( Nexus );
	}
}

bool GameThisCore::SetNexusData( const TArray<FString>& _Admins, const TArray<FString>& _Moderators, const TArray<FString>& _VIPs, const TArray<FString>& _Bots ) {
	if ( NexusConnected || NexusReady ) {
		return false;
	}
	
	Admins = _Admins;
	Moderators = _Moderators;
	VIPs = _VIPs;
	Bots = _Bots;

	return true;

}

bool GameThisCore::SetDiscordData( const FString& _ServerName, const FString& _ChannelName, const FString& _AdminName, const FString& _BotName, const FString& _Password ) {
	if ( NexusConnected || NexusReady ) {
		return false;
	}
	DiscordValid = true;
	DiscordAdminName = _AdminName;
	DiscordBotName =_BotName;
	DiscordServer = _ServerName;
	DiscordChannel = _ChannelName;
	DiscordBotPassword = _Password;
	if ( DiscordAdminName == "" || DiscordAdminName.Contains( " " ) ) { return false; }
	if ( DiscordBotName == "" || DiscordBotName.Contains( " " ) ) { return false; }
	if ( DiscordServer == "" || DiscordServer.Contains( " " ) ) { return false; }
	if ( DiscordChannel == "" || DiscordChannel.Contains( " " ) ) { return false; }
	if ( DiscordBotPassword == "" || DiscordBotPassword.Contains( " " ) ) { return false; }

	return true;
}

bool GameThisCore::CreateNexus( const EGameThisProcessType _Type ) {
	NexusID = 0;
	FString params = "-UE4 ";
	switch ( _Type ) {
		case EGameThisProcessType::eGT_DEFAULT:
			params += "-Default";
			break;
		case EGameThisProcessType::eGT_TUNNEL:
			params += "-Tunnel";
			break;
		case EGameThisProcessType::eGT_PIPE:
			params += "-Pipe";
			break;
		case EGameThisProcessType::eGT_SOCKET:
			params += "-Socket";
			break;
		default:
			break;
	}
	ProcessType = _Type;

	FString discordParam = " -Discord:";
	if ( DiscordValid ) {
		discordParam += DiscordServer + ":" + DiscordChannel + ":" + DiscordAdminName + ":" + DiscordBotName + ":" + DiscordBotPassword;
		params += discordParam;
	}

	if ( !UGameThisIO::GameThisNexusExeValid() ) {
		UE_LOG( LogTemp, Warning, TEXT( "Game This: Missing Nexus." ) );
		return false;
	}
	const FString exe = UGameThisIO::GameThisNexusExe();
	const FString param = params;
	Nexus = FPlatformProcess::CreateProc( *exe, *param, true, true, true, NexusID, 0, nullptr, nullptr );

	if ( Nexus.IsValid() ) {
		NexusConnected = false;
		NexusReady = false;
		UE_LOG( LogTemp, Warning, TEXT( "Game This: Process Failed at Launch." ) );
		return false;
	} else {
		NexusConnected = true;
		NexusReady = true;
		UE_LOG( LogTemp, Log, TEXT( "Game This: Process Launched." ) );
		Active = true;
		InputListeningThread = std::unique_ptr<std::thread>( new std::thread( &GameThisCore::Loop, this ) );
		InputListeningThread->detach();
		return true;
	}
}

bool GameThisCore::IsNexusRunning() {
	return FGenericPlatformProcess::IsProcRunning( Nexus );
}

bool GameThisCore::IsGameThisConnected() {
	return NexusConnected;
}

bool GameThisCore::IsGameThisReady() {
	return NexusReady;
}

void GameThisCore::Loop() {

	while ( Active ) {
		if ( IsNexusRunning() ) {
			NexusConnected = true;
		} else {
			NexusConnected = false;
			return;
		}
		switch ( ProcessType ) {
			case EGameThisProcessType::eGT_DEFAULT:
				GetTunnelMessages();
				break;
			case EGameThisProcessType::eGT_TUNNEL:
				GetTunnelMessages();
				break;
			case EGameThisProcessType::eGT_PIPE:
				GetPipeMessages();
				break;
			case EGameThisProcessType::eGT_SOCKET:
				GetSocketMessages();
				break;
			default:
				break;
		}

		if ( NexusConnected != NexusLastConnected ) {
			// Status Change
			//OnConnectionChanged.Broadcast( NexusConnected );
			ConnectionChanged = true;
		}
		if ( NexusReady != NexusLastReady ) {
			// Status Change
			//OnConnectionStatusChanged.Broadcast( (NexusReady &&  NexusConnected) );
			ConnectionStateChanged = true;
		}
		NexusLastConnected = NexusConnected;
		NexusLastReady = NexusReady;
	}
}

bool GameThisCore::IsTunnelValid() {
	return FPaths::FileExists( UGameThisIO::GameThisTunnelFile() );
}

void GameThisCore::GetTunnelMessages() {
	if ( !IsTunnelValid() ) {
		NexusReady = false;
		return;
	}

	// TimeStap
	TArray<FString> rawMessages = UGameThisIO::TunnelFileToArray();
	int32 inputCount = rawMessages.Num();
	int32 internalCount = TunnelMessages.Num();
	if ( inputCount > TunnelMessagesLimit  || inputCount == 0 || internalCount > inputCount ) {
		TunnelMessages.Empty();
		internalCount = 0;
	}
	int32 startIndex = 0;
	if ( internalCount == inputCount ) {
		return;
	} else {
		startIndex = FMath::Max( 0, internalCount - 1 );
		//startIndex = inputCount - (inputCount - internalCount);
	}
	if ( ChatMessages.Num() > ChatMessagesLimit ) {
		ChatMessages.Empty();
	}
	for ( int32 i = startIndex; i < inputCount; i++ ) {
		FString msgStr = rawMessages[i];
		TunnelMessages.Add( msgStr );
		TArray<FString> rawMsgSplit;
		msgStr.ParseIntoArray( rawMsgSplit, TEXT( ":" ), true );
		FGameThisChatMessageData msg = FGameThisChatMessageData{};
		if ( rawMsgSplit.Num() >= 4 ) {
			msg.Username = rawMsgSplit[2];
			msg.Channel = rawMsgSplit[1];
			msg.Message = rawMsgSplit[3];
			msg.TimeStamp = rawMsgSplit[0];
			if ( Bots.Contains( msg.Username ) ) {
				msg.AccountType = EGameThisAccountType::eBot;
			} else if ( Admins.Contains( msg.Username ) ) {
				msg.AccountType = EGameThisAccountType::eAdmin;
			} else if ( Moderators.Contains( msg.Username ) ) {
				msg.AccountType = EGameThisAccountType::eMod;
			} else if ( VIPs.Contains( msg.Username ) ) {
				msg.AccountType = EGameThisAccountType::eVIP;
			} else {
				msg.AccountType = EGameThisAccountType::eDefault;
			}
			ChatMessages.Add( msg );
			//OnChatMessageReceived.Broadcast( msg );
			ChatMessage = msg;
			ChatMessageWaiting = true;
		} else {
			continue;
		}
	}
}

bool GameThisCore::ArePipesValid() {
	// TODO IMPLEMENTS PIPES
	return false;
}

void GameThisCore::GetPipeMessages() {
	if ( !ArePipesValid() ) {
		NexusReady = false;
		return;
	}
}

bool GameThisCore::AreSocketsValid() {
	// TODO IMPLEMENT SOCKETS
	return false;
}

void GameThisCore::GetSocketMessages() {
	if ( !AreSocketsValid() ) {
		NexusReady = false;
		return;
	}
}