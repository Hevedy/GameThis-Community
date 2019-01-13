/*
===========================================================================

Game This - Community Edition by Hevedy
<https://github.com/Hevedy/GameThis-Community>

Game This - Community Edition GPL Source Code
Copyright (C) 2018-2019 Hevedy <https://github.com/Hevedy>.

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


#ifndef SCRIPTINGVM_H
#define SCRIPTINGVM_H


#include "gmThread.h"


class ScriptingVM
{
	
public:
	static ScriptingVM& Get() { return s_staticInstance; }
	virtual ~ScriptingVM();

private:
	ScriptingVM();
	static ScriptingVM s_staticInstance;
	bool init();

protected:
	void RegisterScriptBindings();
	

	static int GM_CDECL SScrFuncPing( gmThread* a_thread );
	static int GM_CDECL SScrFuncSoundPlay( gmThread* a_thread );

	static int GM_CDECL SScrFuncNL( gmThread* a_thread );
	static int GM_CDECL SScrFuncMBoolRand( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumRand( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumRandRange( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumAdd( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumSub( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumMul( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumDiv( gmThread* a_thread );
	static int GM_CDECL SScrFuncMNumMod( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOReadFileLine( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOReadRandLine( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOSaveFileLine( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOSaveFileLastLine( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOSaveFileOverwrite( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOReadWeb( gmThread* a_thread );
	static int GM_CDECL SScrFuncIOReadWebLine( gmThread* a_thread );

	static int GM_CDECL SScrFuncUserGroupGet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserGroupAdd( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserGroupRem( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserRankGet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserRankSet( gmThread* a_thread );

	static int GM_CDECL SScrFuncEventStart( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventEnd( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventOpen( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventClose( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventUserJoin( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventUserLeave( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventUserSet( gmThread* a_thread );
	static int GM_CDECL SScrFuncEventUserRem( gmThread* a_thread );

	static int GM_CDECL SScrFuncUserPointsGet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserPointsAdd( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserPointsSub( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserPointsSet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserPointsGive( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserCurrencyGet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserCurrencyAdd( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserCurrencySub( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserCurrencySet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserCurrencyGive( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserTicketsGet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserTicketsAdd( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserTicketsSub( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserTicketsSet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserTicketsGive( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserKeysGet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserKeysAdd( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserKeysSub( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserKeysSet( gmThread* a_thread );
	static int GM_CDECL SScrFuncUserKeysGive( gmThread* a_thread );

	static int GM_CDECL SScrFuncMGChest( gmThread* a_thread );
	static int GM_CDECL SScrFuncMGChestSpawn( gmThread* a_thread );
	static int GM_CDECL SScrFuncMGDiceRoll( gmThread* a_thread );
	static int GM_CDECL SScrFuncMGQAQuestion( gmThread* a_thread );
	static int GM_CDECL SScrFuncMGQAAnswer( gmThread* a_thread );
	static int GM_CDECL SScrFuncMGPianoPlay( gmThread* a_thread );

	static int GM_CDECL SScrFuncRPGJoin( gmThread* a_thread );
	static int GM_CDECL SScrFuncRPGLeave( gmThread* a_thread );
};

#endif // SCRIPTINGVM_H
