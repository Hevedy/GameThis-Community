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


#ifndef SCRIPTING_H
#define SCRIPTING_H

//#define WIN32_LEAN_AND_MEAN

#include <QObject>
#include <QtMath>
#include "GlobalFunctions.h"
#include "Common.h"
#include "Commands.h"
#include "Users.h"

#define SCRIPT_LENGTHMAX 1000
#define SCRIPT_PERCHARLENGTHMAX 20
#define SCRIPT_NESTEDFUNCTIONSMAX 5
#define SCRIPT_VALUEINTMAX 9999
#define SCRIPT_LENGTHMAX 1000


class Scripting : public QObject
{
    Q_OBJECT
	
public:
	explicit Scripting(QObject *parent = nullptr);

	static bool init();
	
	static bool ProcessingCommand;

	static QList<FScrGlobalVarStruct*> GlobalVarsList;
	static QList<FScrTokenStruct*> TokensList;
	static QList<FScrTokenStaticStruct> TokensStaticList;
	static QList<FScrFunctionStruct*> FunctionsList;

	static QString GVarPrefix;
	static QString GVarSuffix;
	static QString TokenPrefix;
	static QString TokenSuffix;
	static QString FuncPrefix;
	static QString FuncSuffix;

	static FUserStruct* CUser;
	static FUserStruct* CUserTarget;
	static FCommandStruct* CCommand;

    static bool ClearGlobalVar( FScrGlobalVarStruct* _Var );
    static bool ClearGlobalVarsArray( QList<FScrGlobalVarStruct*>& _VarsArray );

	static void AddCoreFunctions();
	static bool LoadScriptingScripts();
	static bool LoadScriptGlobalVars( QJsonObject _File );

	static bool ScriptValidateCommandScript( bool _Runtime, QString _Script, FCommandStruct* _Command, FUserStruct* _User );
	static void ScriptFormatString();
	static bool ScriptTokenResolve( QString& _Script, FUserStruct* _UserSender, FUserStruct* _UserTarget );

	static bool ScriptValidateScrVarInput( FScrVarContainerStruct& _VarContainer, const QString _Input, const EVariableTypeList _Type );
	static bool ScriptValidateScrVarArrayInputs( QList<FScrVarContainerStruct>& _VarContainer, const QList<QString> _Inputs, const QList<EVariableTypeList> _Types );

	// Helpers
	static bool ScrResolveUserByName( const QString _Name, FUserStruct* _User );
	static bool ScrResolveGroupByName( const QString _Name, FUserGroupStruct* _Group );
	static bool ScrResolveRankByName( const QString _Name, FUserRankStruct* _Rank );
	static bool ScrResolveModuleByName( const QString _Name, FCommonModuleStruct* _Module );
	static bool ScrResolveEventByName( const QString _Name, FCommonEventStruct* _Event );

	//
	// SCR TOKENS
	//

	// Token Helpers
	static QString ScrTkGetChannelName();
	static QString ScrTkGetMasterName();
	static QString ScrTkGetOwnerName();
	static QString ScrTkGetBotName();
	static QString ScrTkGetPointsName();
	static QString ScrTkGetCurrencyName();
	static QString ScrTkGetTicketsName();
	static QString ScrTkGetKeysName();
	// Get target user from list using name
	static bool ScrTkGetUserTarget( QString _Name, FUserStruct* _Target );
	// General user info
	static QString ScrTkGetUserName( FUserStruct* _User );
	static QString ScrTkGetUserPoints( FUserStruct* _User );
	static QString ScrTkGetUserCurrency( FUserStruct* _User );
	static QString ScrTkGetUserTickets( FUserStruct* _User );
	static QString ScrTkGetUserKeys( FUserStruct* _User );

	//
	// SCR FUNCTIONS
	//

	// Logic tools
	//static bool GM_CDECL ScrFuncPingT(gmThread* a_thread);
	static bool ScrFuncPing( QString& _Return );
	static bool ScrFuncSoundPlay( bool& _Return, const QString _File );
	static bool ScrFuncNL( QString& _Return );
	// Math
	static bool ScrFuncMBoolRand( bool& _Return );
	static bool ScrFuncMNumRand( int& _Return );
	static bool ScrFuncMNumRandRange( int& _Return,  const int _Min, const int _Max );
	static bool ScrFuncMNumAdd( int& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumSub( int& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumMul( int& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumDiv( int& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumMod( int& _Return, const int _NumA, const int _NumB );
	// IO
	static bool ScrFuncIOReadFileLine( QString& _Return, const QString _File, const int _Line );
	static bool ScrFuncIOReadRandLine( QString& _Return, const QString _File );
	static bool ScrFuncIOSaveFileLine( bool& _Return, const QString _Text, const QString _File, const int _Line );
	static bool ScrFuncIOSaveFileLastLine( bool& _Return, const QString _Text, const QString _File );
	static bool ScrFuncIOSaveFileOverwrite( bool& _Return, const QString _Text, const QString _File );
	static bool ScrFuncIOReadWeb( QString& _Return, const QString _URL );
	static bool ScrFuncIOReadWebLine( QString& _Return, const QString _URL, const int _Line );
	// Users manager
	static bool ScrFuncUserGroupGet( QString& _Return, FUserStruct* _User );
	static bool ScrFuncUserGroupAdd( bool& _Return, FUserStruct* _User, FUserGroupStruct* _Group );
	static bool ScrFuncUserGroupRem( bool& _Return, FUserStruct* _User, FUserGroupStruct* _Group );
	static bool ScrFuncUserRankGet( QString& _Return, FUserStruct* _User );
	static bool ScrFuncUserRankSet( bool& _Return, FUserStruct* _User, FUserRankStruct* _Rank );
	// Events
	static bool ScrFuncEventStart( bool& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventEnd( bool& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventOpen(bool& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventClose( bool& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserJoin( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserLeave( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserSet( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserRem( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	// Users currency
	static bool ScrFuncUserPointsGet( int& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserPointsAdd( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserPointsSub( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserPointsSet( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserPointsGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencyGet( int& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserCurrencyAdd( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencySub( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencySet( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencyGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsGet( int& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserTicketsAdd( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsSub( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsSet( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysGet( int& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserKeysAdd( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysSub( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysSet( bool& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	// Minigames
	static bool ScrFuncMGChest( bool& _Return, FUserStruct* _User );
	static bool ScrFuncMGChestSpawn( bool& _Return, FUserStruct* _User );
	static bool ScrFuncMGDiceRoll( int& _Return, FUserStruct* _User, const int _Sides );
	static bool ScrFuncMGQAQuestion( bool& _Return, FUserStruct* _User, const QString _Question );
	static bool ScrFuncMGQAAnswer( bool& _Return, FUserStruct* _User, const QString _Answer );
	static bool ScrFuncMGPianoPlay( bool& _Return, FUserStruct* _User, const QString _Keys );
	// RPG Game
	static bool ScrFuncRPGJoin( bool& _Return, FUserStruct* _User );
	static bool ScrFuncRPGLeave( bool& _Return, FUserStruct* _User );

private:
	// Table of functions to register
	//QList<gmFunctionEntry> regFuncList;
	
signals:

public slots:
};

#endif // SCRIPTING_H
