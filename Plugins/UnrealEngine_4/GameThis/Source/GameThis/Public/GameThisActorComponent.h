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
GameThisActorComponent.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "GameThisStructs.h"
#include "GameThisCore.h"
#include "GameThisActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNexusConnectionChanged, bool, _IsConnected );

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNexusConnectionStatusChanged, bool, _IsReady );

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FNexusChatMessageReceived, FGameThisChatMessageData, _Data );

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMETHIS_API UGameThisActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameThisActorComponent();

	UPROPERTY(BlueprintReadOnly, Category = "Game This")
		bool bIsConnected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game This")
		bool bUseFile;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	GameThisCore NexusCore;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void OnComponentDestroyed(const bool bDestroyingHierarchy) override;

	UPROPERTY( BlueprintAssignable, Category = "GameThis|Integrator" )
		FNexusConnectionChanged OnConnectionChanged;

	UPROPERTY( BlueprintAssignable, Category = "GameThis|Integrator" )
		FNexusConnectionStatusChanged OnConnectionStatusChanged;

	UPROPERTY( BlueprintAssignable, Category = "GameThis|Integrator" )
		FNexusChatMessageReceived OnChatMessageReceived;

	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		bool SetNexusData( const TArray<FString>& _Admins, const TArray<FString>& _Moderators, const TArray<FString>& _VIPs, const TArray<FString>& _Bots );

	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		bool SetDiscordData( const FString& _ServerName, const FString& _ChannelName, const FString& _AdminName, const FString& _BotName, const FString& _Password );

	// Create the nexus and launch it
	UFUNCTION( BlueprintCallable, Category = "GameThis|Core" )
		bool CreateNexus( const EGameThisProcessType _Type );

	UFUNCTION(BlueprintCallable, Category = "Game This")
		void ConnectToNexus();

	UFUNCTION(BlueprintCallable, Category = "Game This")
		void DisconnectFromNexus();


private:

};
