/*
===========================================================================
This code is part of the "Source Code" content in
Game This - Community by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/GameThis-Community>

The MIT License (MIT)
Copyright (c) 2018-2020 David Palacios (Hevedy) <https://github.com/Hevedy>
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
GameThisCore.h
================================================
*/


#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameThisIO.h"
#include "GameThisStructs.h"
#include "GameThisCore.generated.h"


// Event triggered when receiveign a message from the Twitch API
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNexusChatMessageReceived, FGameThisChatMessageData, _Data );

// Event triggered when the connection to twitch chat changes
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNexusConnectionChanged, bool, _IsConnected );

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNexusConnectionStatusChanged, bool, _IsReady );


UCLASS()
class GAMETHIS_API UGameThisCore : public UObject {
	GENERATED_BODY()

	UGameThisCore( const FObjectInitializer& ObjectInitializer );


public:

	virtual void BeginDestroy() override;

	//
	// CORE
	//

	// Setup the nexus parameters
	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		bool SetNexusData( const TArray<FString>& _Admins, const TArray<FString>& _Moderators, const TArray<FString>& _VIPs, const TArray<FString>& _Bots );

	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		bool SetDiscordData( const FString& _ServerName, const FString& _ChannelName, const FString& _AdminName, const FString& _BotName, const FString& _Password );

	// Create the nexus and launch it
	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		bool CreateNexus( const EGameThisProcessType _Type );

	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool IsNexusRunning();

	// Returns if Game This is connected 
	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool IsGameThisConnected();
		
	// Returns if Game This is ready 
	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool IsGameThisReady();

	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		void Loop();

	UPROPERTY( BlueprintAssignable, Category = "GameThis|Integrator" )
		FNexusConnectionChanged OnConnectionChanged;

	UPROPERTY( BlueprintAssignable, Category = "GameThis|Integrator" )
		FNexusConnectionStatusChanged OnConnectionStatusChanged;

	UPROPERTY( BlueprintAssignable, Category = "GameThis|Integrator" )
		FNexusChatMessageReceived OnChatMessageReceived;

	//
	// TUNNEL
	//
	
	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool IsTunnelValid();

	UFUNCTION( BlueprintCallable, Category = "GameThis" )
		void GetTunnelMessages();

	//
	// PIPES
	//

	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool ArePipesValid();

	UFUNCTION( BlueprintCallable, Category = "GameThis" )
		void GetPipeMessages();

	//
	// SOCKETS
	//

	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool AreSocketsValid();

	UFUNCTION( BlueprintCallable, Category = "GameThis" )
		void GetSocketMessages();

private:
	uint32* NexusID;

	bool NexusConnected = false;
	bool NexusReady = false;
	bool NexusLastConnected = false;
	bool NexusLastReady = false;

	FString KeyID = "ABC";
	EGameThisProcessType ProcessType = EGameThisProcessType::eGT_DEFAULT;

	TArray<FGameThisChatMessageData> ChatMessages;
	int32 ChatMessagesLimit = 999;

	// Logics
	TArray<FString> Admins;
	TArray<FString> Moderators;
	TArray<FString> VIPs;
	TArray<FString> Bots;

	//Social
	bool DiscordValid = false;
	FString DiscordAdminName;
	FString DiscordBotName;
	FString DiscordServer;
	FString DiscordChannel;
	FString DiscordBotPassword;

	// TUNNEL
	TArray<FString> TunnelMessages;
	int32 TunnelMessagesLimit = 9999;


};