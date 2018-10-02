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
#include "GameThisPrivatePCH.h"

#include "GameThisIO.h"

#include "BufferArchive.h"
#include "MemoryReader.h"
#include "PlatformFilemanager.h"

#include "Runtime/Core/Public/GenericPlatform/GenericPlatformDriver.h"
#include "Runtime/Core/Public/Misc/SecureHash.h"
#include "GenericTeamAgentInterface.h"
#include "MessageLog.h"

#if WITH_EDITOR
#include "Runtime/Core/Public/Internationalization/Regex.h"
#endif


UGameThisCore::UGameThisCore( const class FObjectInitializer& ObjectInitializer ) {

}

bool UGameThisCore::SetupApp( const FString _AppName, const EGTAppList _AppType, const EGTAppModeList _AppMode ) {
	return false;
}

bool UGameThisCore::SetupUser( const FString _GTUsername, const FString _GTURL ) {
	return false;
}

bool UGameThisCore::IsGameThisConnected() {
	return false;
}

bool UGameThisCore::IsGameThisReady() {
	return false;
}

bool UGameThisCore::ReplyReady() {
	return false;
}
	
bool UGameThisCore::SendData() {
	return false;
}
	
bool UGameThisCore::GetData() {
	return false;
}
