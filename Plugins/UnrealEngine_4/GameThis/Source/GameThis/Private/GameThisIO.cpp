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
GameThisCore.cpp
================================================
*/


#include "GameThisIO.h"
#include "GameThisCore.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Misc/FileHelper.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformDriver.h"

UGameThisIO::UGameThisIO( const class FObjectInitializer& ObjectInitializer ) {

}

FString UGameThisIO::VariableGameRootDir() {
#if WITH_EDITOR
	return FPaths::ConvertRelativePathToFull( FPaths::ProjectSavedDir() );
#else
	return FPaths::ConvertRelativePathToFull( FPaths::RootDir() );
#endif
}


TArray<FString> UGameThisIO::TunnelFileToArray() {
	//FString dir = GameThisTunnelFile();
	//IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	TArray<FString> tunnelText;
	if ( FFileHelper::LoadFileToStringArray( tunnelText, *GameThisTunnelFile() ) ) {
		return tunnelText;
	} else {
		return {};
	}

}