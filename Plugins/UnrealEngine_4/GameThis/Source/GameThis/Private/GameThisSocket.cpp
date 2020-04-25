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
GameThisSocket.cpp
================================================
*/


#include "GameThisSocket.h"
#include "GameThisIO.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformDriver.h"
#include "Runtime/Core/Public/Misc/SecureHash.h"
#include "Runtime/Core/Public/Logging/MessageLog.h"

#if WITH_EDITOR
#include "Runtime/Core/Public/Internationalization/Regex.h"
#endif


UGameThisSocket::UGameThisSocket( const class FObjectInitializer& ObjectInitializer ) {

}


void UGameThisSocket::Laaaaaauuuunch() {

}


bool UGameThisSocket::StartTCPReceiver( const FString& _YourChosenSocketName, const FString& _TheIP, const int32 _ThePort ){
	return false;
}

bool UGameThisSocket::FormatIP4ToNumber(const FString& TheIP, uint8 (&Out)[4])
{
	return false;
}

FSocket* UGameThisSocket::CreateTCPConnectionListener(const FString& _YourChosenSocketName,const FString& _TheIP, const int32 _ThePort,const int32 _ReceiveBufferSize ) {
	FSocket* ListenSocket;
	
	return ListenSocket;	
}

void UGameThisSocket::TCPConnectionListener() {
}

FString UGameThisSocket::StringFromBinaryArray(TArray<uint8>& _BinaryArray) {
	return "";
}

void UGameThisSocket::TCPSocketListener() {

}