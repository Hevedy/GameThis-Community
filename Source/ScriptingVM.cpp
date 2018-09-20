/*
===========================================================================

Game This - Community Edition by Hevedy
<https://github.com/Hevedy/GameThis-Community>

Game This - Community Edition GPL Source Code
Copyright (C) 2018 Hevedy <https://github.com/Hevedy>.

This file is part of the Game This - Community Edition GPL Source Code.


Game This - Community Edition GPL Source Code is free software:
you can redistribute it and/or modify it under the terms of the
GNU General Public License as published bythe Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

Game This - Community Edition GPL Source Code is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Game This - Community Edition GPL Source Code.
If not, see <http://www.gnu.org/licenses/>.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#include "ScriptingVM.h"
#include "ScriptingVMSys.h"
#include "Scripting.h"
#include "gmCall.h"

ScriptingVM::ScriptingVM() {

}

ScriptingVM::~ScriptingVM() {

}

bool ScriptingVM::init() {
	//AddCoreFunctions();
	//if( !LoadScriptingScripts() ) { return false; }
	RegisterScriptBindings();
	return true;

}

///
/// SCRIPT REFERENCES
///
// The functions that return values aren't static
int GM_CDECL ScriptingVM::SScrFuncPing( gmThread* a_thread ) {
	QString returnVal = "";
	if( Scripting::ScrFuncPing( returnVal ) ) {
		a_thread->PushNewString( returnVal.toStdString().c_str(), returnVal.size() );
		return GM_OK;
	} else {
		return GM_EXCEPTION;
	}
}

int GM_CDECL ScriptingVM::SScrFuncSoundPlay( gmThread* a_thread ) {
	GM_CHECK_NUM_PARAMS(1);
	GM_CHECK_STRING_PARAM(_File, 0);
	bool returnVal = false;
	if( Scripting::ScrFuncSoundPlay( returnVal, QString::fromUtf8(_File) ) ) {
		a_thread->PushInt( 1 );
		return GM_OK;
	} else {
		a_thread->PushInt( 0 );
		return GM_EXCEPTION;
	}
}

int GM_CDECL ScriptingVM::SScrFuncNL( gmThread* a_thread ) {
	return GM_OK;
}


int GM_CDECL ScriptingVM::SScrFuncMBoolRand( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumRand( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumRandRange( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumAdd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumSub( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumMul( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumDiv( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMNumMod( gmThread* a_thread ) {
	return GM_OK;
}


int GM_CDECL ScriptingVM::SScrFuncIOReadFileLine( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncIOReadRandLine( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncIOSaveFileLine( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncIOSaveFileLastLine( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncIOSaveFileOverwrite( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncIOReadWeb( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncIOReadWebLine( gmThread* a_thread ) {
	return GM_OK;
}


int GM_CDECL ScriptingVM::SScrFuncUserGroupGet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserGroupAdd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserGroupRem( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserRankGet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserRankSet( gmThread* a_thread ) {
	return GM_OK;
}


int GM_CDECL ScriptingVM::SScrFuncEventStart( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventEnd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventOpen( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventClose( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventUserJoin( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventUserLeave( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventUserSet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncEventUserRem( gmThread* a_thread ) {
	return GM_OK;
}


int GM_CDECL ScriptingVM::SScrFuncUserPointsGet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserPointsAdd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserPointsSub( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserPointsSet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserPointsGive( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserCurrencyGet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserCurrencyAdd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserCurrencySub( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserCurrencySet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserCurrencyGive( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserTicketsGet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserTicketsAdd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserTicketsSub( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserTicketsSet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserTicketsGive( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserKeysGet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserKeysAdd( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserKeysSub( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserKeysSet( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncUserKeysGive( gmThread* a_thread ) {
	return GM_OK;
}


int GM_CDECL ScriptingVM::SScrFuncMGChest( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMGChestSpawn( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMGDiceRoll( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMGQAQuestion( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMGQAAnswer( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncMGPianoPlay( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncRPGJoin( gmThread* a_thread ) {
	return GM_OK;
}

int GM_CDECL ScriptingVM::SScrFuncRPGLeave( gmThread* a_thread ) {
	return GM_OK;
}

void ScriptingVM::RegisterScriptBindings()
{

    gmFunctionEntry scr_FunctionLib[] =
    {
        { "Ping", SScrFuncPing },
        { "SoundPlay", SScrFuncSoundPlay },
        { "NL", SScrFuncNL },
        // Math
        { "BoolRand", SScrFuncMBoolRand },
        { "NumRand", SScrFuncMNumRand },
        { "NumRandRange", SScrFuncMNumRandRange },
        { "NumAdd", SScrFuncMNumAdd },
        { "NumSub", SScrFuncMNumSub },
        { "NumMul", SScrFuncMNumMul },
        { "NumDiv", SScrFuncMNumDiv },
        { "NumMod", SScrFuncMNumMod },
        // IO
        { "ReadFileLine", SScrFuncIOReadFileLine },
        { "ReadRandLine", SScrFuncIOReadRandLine },
        { "SaveFileLine", SScrFuncIOSaveFileLine },
        { "SaveFileLastLine", SScrFuncIOSaveFileLastLine },
        { "SaveFileOverwrite", SScrFuncIOSaveFileOverwrite },
        { "ReadWeb", SScrFuncIOReadWeb },
        { "ReadWebLine", SScrFuncIOReadWebLine },
        // Users manager
        { "UserGroupGet", SScrFuncUserGroupGet },
        { "UserGroupAdd", SScrFuncUserGroupAdd },
        { "cUserGroupRem", SScrFuncUserGroupRem },
        { "UserRankGet", SScrFuncUserRankGet },
        { "UserRankSet", SScrFuncUserRankSet },
        // Events
        { "EventStart", SScrFuncEventStart },
        { "EventEnd", SScrFuncEventEnd },
        { "EventOpen", SScrFuncEventOpen },
        { "EventClose", SScrFuncEventClose },
        { "EventUserJoin", SScrFuncEventUserJoin },
        { "EventUserLeave", SScrFuncEventUserLeave },
        { "EventUserSet", SScrFuncEventUserSet },
        { "EventUserRem", SScrFuncEventUserRem },
        // Users currency
        { "UserPointsGet", SScrFuncUserPointsGet },
        { "UserPointsAdd", SScrFuncUserPointsAdd },
        { "UserPointsSub", SScrFuncUserPointsSub },
        { "UserPointsSet", SScrFuncUserPointsSet },
        { "UserPointsGive", SScrFuncUserPointsGive },
        { "UserCurrencyGet", SScrFuncUserCurrencyGet },
        { "UserCurrencyAdd", SScrFuncUserCurrencyAdd },
        { "UserCurrencySub", SScrFuncUserCurrencySub },
        { "UserCurrencySet", SScrFuncUserCurrencySet },
        { "UserCurrencyGive", SScrFuncUserCurrencyGive },
        { "UserTicketsGet", SScrFuncUserTicketsGet },
        { "UserTicketsAdd", SScrFuncUserTicketsAdd },
        { "UserTicketsSub", SScrFuncUserTicketsSub },
        { "UserTicketsSet", SScrFuncUserTicketsSet },
        { "UserTicketsGive", SScrFuncUserTicketsGive },
        { "UserKeysGet", SScrFuncUserKeysGet },
        { "UserKeysAdd", SScrFuncUserKeysAdd },
        { "UserKeysSub", SScrFuncUserKeysSub },
        { "UserKeysSet", SScrFuncUserKeysSet },
        { "UserKeysGive", SScrFuncUserKeysGive },
        // Minigames
        { "MGChest", SScrFuncMGChest },
        { "MGChestSpawn", SScrFuncMGChestSpawn },
        { "MGDiceRoll", SScrFuncMGDiceRoll },
        { "MGQAQuestion", SScrFuncMGQAQuestion },
        { "MGQAAnswer", SScrFuncMGQAAnswer },
        { "MGPianoPlay", SScrFuncMGPianoPlay },
        // RPG Game
        { "RPGJoin", SScrFuncRPGJoin },
        { "RPGLeave", SScrFuncRPGLeave },
    };

  gmMachine* machine = ScriptingVMSys::Get()->GetMachine();

  machine->RegisterLibrary(scr_FunctionLib, sizeof(scr_FunctionLib) / sizeof(scr_FunctionLib[0]), "FunctionLib");

}

