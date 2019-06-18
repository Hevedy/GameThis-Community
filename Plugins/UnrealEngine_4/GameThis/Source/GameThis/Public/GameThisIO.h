/*
===========================================================================
This code is part of the "Source Code" content in
Game This - Community by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/GameThis-Community>

The MIT License (MIT)
Copyright (C) 2018-2019 David Palacios (Hevedy) <https://github.com/Hevedy>
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
GameThisIO.h
================================================
*/


#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/Engine.h"
#include "GameThisIO.generated.h"


UCLASS()
class GAMETHIS_API UGameThisIO : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UGameThisMisc( const FObjectInitializer& ObjectInitializer );
	
	FString GameURL;
	
	FString GameName;
	
	FString GameThisURL;
	
	FString GameThisUsername;
	
	FString InputText;
	
	FString OutputText;

protected:

public:

	/** Returns if Game This is connected */
	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool IsGameThisConnected();
		
	/** Returns if Game This is connected */
	UFUNCTION( BlueprintPure, Category = "GameThis|Status" )
		bool IsGameThisReady();
	
	/** Returns if the file ready to be read */
	bool ReplyReady();
	
	
	bool GetGameURL( FString URL );
	
	bool GetGameName( FString Name );
	
	/** Returns valid keys list */
	bool GetGameThisFileName();
	/** Returns complate url to file */
	bool GetGameThisFileURL( FString URL );
	/** Returns valid keys list */
	bool GetGameThisURL( FString URL );
	/** Returns Username for GameThis app */
	bool GetGameThisUsername( FString Username );

};