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
GameThisIO.h
================================================
*/


#pragma once

#include "CoreMinimal.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/App.h"
#include "Misc/Paths.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameThisIO.generated.h"


UCLASS()
class GAMETHIS_API UGameThisIO : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UGameThisIO( const FObjectInitializer& ObjectInitializer );

public:

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static FString GameName() { return FString( FApp::GetProjectName() ); };

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static FString VariableGameRootDir();

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static FString GameRootDir() { return FPaths::ConvertRelativePathToFull( FPaths::RootDir() ); };

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static FString GameThisDir() { return GameRootDir() + "GameThis/"; };

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static FString GameThisNexusExe() { return GameThisDir() + "GameThis.exe"; };

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static bool GameThisNexusExeValid() { return FPaths::FileExists( GameThisNexusExe() ); };

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static FString GameThisTunnelFile() { return GameThisDir() + "/Tunnel/Nexus.tnl"; };

	UFUNCTION( BlueprintPure, Category = "GameThis|IO" )
		static TArray<FString> TunnelFileToArray();

};