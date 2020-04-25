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
GameThisActorComponent.cpp
================================================
*/

#include "GameThisActorComponent.h"


// Sets default values for this component's properties
UGameThisActorComponent::UGameThisActorComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//GameThisCore = NewObject<UGameThisCore>();
	//NexusCore = GameThisCore();
	bIsConnected = false;
	// ...
}


// Called when the game starts
void UGameThisActorComponent::BeginPlay() {
	Super::BeginPlay();


}

bool UGameThisActorComponent::SetNexusData( const TArray<FString>& _Admins, const TArray<FString>& _Moderators, const TArray<FString>& _VIPs, const TArray<FString>& _Bots ) {
	return NexusCore.SetNexusData( _Admins, _Moderators, _VIPs, _Bots );
}

bool UGameThisActorComponent::SetDiscordData( const FString& _ServerName, const FString& _ChannelName, const FString& _AdminName, const FString& _BotName, const FString& _Password ) {
	return NexusCore.SetDiscordData( _ServerName, _ChannelName, _AdminName, _BotName, _Password );
}

bool UGameThisActorComponent::CreateNexus( const EGameThisProcessType _Type ) {
	return NexusCore.CreateNexus( _Type );
}


// Called every frame
void UGameThisActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if ( NexusCore.ConnectionChanged ) {
		OnConnectionChanged.Broadcast( NexusCore.NexusConnected );
		NexusCore.ConnectionChanged = false;
	}

	if ( NexusCore.ConnectionStateChanged ) {
		OnConnectionStatusChanged.Broadcast( NexusCore.NexusReady );
		NexusCore.ConnectionStateChanged = false;
	}

	if ( NexusCore.ChatMessageWaiting ) {
		OnChatMessageReceived.Broadcast( NexusCore.ChatMessage );
		NexusCore.ChatMessageWaiting = false;
	}
}

void UGameThisActorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	NexusCore.Shutdown();

	Super::EndPlay( EndPlayReason );

}

void UGameThisActorComponent::OnComponentDestroyed(const bool bDestroyingHierarchy) {
	if (bDestroyingHierarchy ) {
		NexusCore.Shutdown();
	}

	Super::OnComponentDestroyed( bDestroyingHierarchy );
}
void UGameThisActorComponent::ConnectToNexus() {

}

void UGameThisActorComponent::DisconnectFromNexus() {

}
