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
GameThisStructs.h
================================================
*/

#pragma once

#include "CoreMinimal.h"
#include "GameThisStructs.generated.h"

UENUM(BlueprintType)
enum class EGameThisProcessType : uint8 {
	eGT_DEFAULT	UMETA( DisplayName = "Default" ),
	eGT_TUNNEL	UMETA( DisplayName = "Tunnel" ),
	eGT_PIPE	UMETA( DisplayName = "Pipes" ),
	eGT_SOCKET	UMETA( DisplayName = "Sockets" )
};

UENUM(BlueprintType)
enum class EGameThisAccountType : uint8 {

	eDefault	UMETA( DisplayName = "Default" ),
	eVIP		UMETA( DisplayName = "VIP" ),
	eBot		UMETA( DisplayName = "Bot" ),
	eMod		UMETA( DisplayName = "Mod" ),
	eAdmin		UMETA( DisplayName = "Admin" )
};


// Input Time/Channel/User/Message
USTRUCT(BlueprintType)
struct GAMETHIS_API FGameThisChatMessageData {
	GENERATED_BODY()

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Game This" )
		FString Username;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Game This" )
		FString Channel;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Game This" )
		FString Message;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Game This" )
		FString TimeStamp;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Game This" )
		EGameThisAccountType AccountType;
};