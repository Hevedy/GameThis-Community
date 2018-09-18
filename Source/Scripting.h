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


#ifndef SCRIPTING_H
#define SCRIPTING_H

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


struct FScrGlobalVarStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Type
	EVariableTypeList type;
	// value
	QString value;
	float valueLogic;

	FScrGlobalVarStruct( QString _NameID = "", QString _Name = "", EVariableTypeList _Type = EVariableTypeList::eString, QString _Value = "" )
	: nameID( _NameID )
	, name( _Name )
	, type( _Type )
	, value( _Value ) {}
};

enum class EScrVarTypeList {
	eNone,
	// Names
	eBool,
	eFloat,
	eInt,
	eString,
	eUser,
	eGroup,
	eRank,
	eModule,
	eEvent
};

// Used to preload vars into a container for faster access
struct FScrVarContainerStruct {
public:

	EVariableTypeList varType;
	bool varBool;
	float varFloat;
	int varInt;
	QString varString;
	FUserStruct varUser;
	FUserGroupStruct varGroup;
	FUserRankStruct varRank;

};

// Function call procesed before to be stored on command
struct FScrFunctionContainerStruct {
public:

	// Name
	QString functionName;

	QList<QString> inputs;
	// Need Master
	bool master;
	// Force safe lock to the admins and master groups or channel or bots
	// Can be a danger if a user uses it
	bool safeLock;
	// Inputs
	QList<EVariableTypeList> inputClasses;
	// Return true or false functions
	bool trueFalse;


	FScrFunctionContainerStruct( QString _FunctionName = "", bool* _FunctionRef(int) = nullptr, bool _Master = false, bool _SafeLock = true,
							QList<EVariableTypeList> _InputClasses = {}, bool _TrueFalse = false )
	: functionName( _FunctionName )
	, functionRef( _FunctionRef )
	, master( _Master )
	, safeLock( _SafeLock )
	, inputClasses( _InputClasses )
	, trueFalse( _TrueFalse ) {}
};

// Token list for reference
enum class EScrTokenList {
	eNone,
	// Names
	eChannelN,
	ePointsN,
	eCurrencyN,
	eTicketsN,
	eKeysN,
	eUserTarget,
	eUserN,
	// Number
	ePoints,
	eCurrency,
	eTickets,
	eKeys

};

// Function list for reference
enum class EScrFunctionList {
	eNone,
	// Tools
	ePing,
	eSoundPlay,
	eNL,
	// Math
	eMBoolRand,
	eMNumRand,
	eMNumRandRange,
	eMNumAdd,
	eMNumSub,
	eMNumMul,
	eMNumDiv,
	eMNumMod,
	// IO
	eIOReadFileLine,
	eIOReadRandLine,
	eIOSaveFileLine,
	eIOSaveFileLastLine,
	eIOSaveFileOverwrite,
	eIOReadWeb,
	eIOReadWebLine,
	// Users manager
	eUserGroupGet,
	eUserGroupAdd,
	eUserGroupRem,
	eUserRankGet,
	eUserRankSet,
	// Events
	eEventStart,
	eEventEnd,
	eEventOpen,
	eEventClose,
	eEventUserJoin,
	eEventUserLeave,
	eEventUserSet,
	eEventUserRem,
	// Users currency
	eUserPointsGet,
	eUserPointsAdd,
	eUserPointsSub,
	eUserPointsSet,
	eUserPointsGive,
	eUserCurrencyGet,
	eUserCurrencyAdd,
	eUserCurrencySub,
	eUserCurrencySet,
	eUserCurrencyGive,
	eUserTicketsGet,
	eUserTicketsAdd,
	eUserTicketsSub,
	eUserTicketsSet,
	eUserTicketsGive,
	eUserKeysGet,
	eUserKeysAdd,
	eUserKeysSub,
	eUserKeysSet,
	eUserKeysGive,
	// Minigames
	eMGChest,
	eMGChestSpawn,
	eMGDiceRoll,
	eMGQAQuestion,
	eMGQAAnswer,
	eMGPianoPlay,
	// RPG Game
	eRPGJoin,
	eRPGLeave
};

// Direct reference to function, removed as are dynamic
//bool (*functionRef)(int);
//bool (*_FunctionRef)(int) = nullptr

// Registered functions for list
struct FScrFunctionStruct {
public:

	// Name
	QString functionName;
	// Function ID
	EScrFunctionList functionRef;
	// Need Master
	bool master;
	// Force safe lock to the admins and master groups or channel or bots
	// Can be a danger if a user uses it
	bool safeLock;
	// Inputs
	QList<EVariableTypeList> inputClasses;
	// Return true or false functions
	bool trueFalse;


	FScrFunctionStruct( QString _FunctionName = "", EScrFunctionList _FunctionRef = EScrFunctionList::eNone, bool _Master = false, bool _SafeLock = true,
							QList<EVariableTypeList> _InputClasses = {}, bool _TrueFalse = false )
	: functionName( _FunctionName )
	, functionRef( _FunctionRef )
	, master( _Master )
	, safeLock( _SafeLock )
	, inputClasses( _InputClasses )
	, trueFalse( _TrueFalse ) {}
};


class Scripting : public QObject
{
    Q_OBJECT
	
public:
	explicit Scripting(QObject *parent = nullptr);

	static void init();
	

	static QList<FScrGlobalVarStruct*> GlobalVars;
	static QList<FScrFunctionStruct*> Functions;

    static bool ClearGlobalVar( FScrGlobalVarStruct* _Var );
    static bool ClearGlobalVarsArray( QList<FScrGlobalVarStruct*>& _VarsArray );
    static bool ClearFunction( FScrFunctionStruct* _Function );
    static bool ClearFunctionsArray( QList<FScrFunctionStruct*>& _FunctionsArray );


	static void AddCoreFunctions();
	static bool LoadScriptingScripts();
	static bool LoadScriptGlobalVars( QJsonObject _File );
	static bool ValidateCommandScript( bool _Runtime, QString _Script, FCommandStruct* _Command, FUserStruct* _User );
	static bool ScriptTokenResolve( QString& _Script, FUserStruct* _UserSender, FUserStruct* _UserTarget );

	static bool ValidateScrVarInput( FScrVarContainerStruct& _VarContainer, const QString _Input, const EVariableTypeList _Type );
	static bool ValidateScrVarArrayInputs( QList<FScrVarContainerStruct>& _VarContainer, const QList<QString> _Inputs, const QList<EVariableTypeList> _Types );

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
	static bool ScrFuncPing( QString& _Return );
	static bool ScrFuncSoundPlay( QString& _Return, const QString _File );
	static bool ScrFuncNL( QString& _Return );
	// Math
	static bool ScrFuncMBoolRand( QString& _Return );
	static bool ScrFuncMNumRand( QString& _Return );
	static bool ScrFuncMNumRandRange( QString& _Return,  const int _Min, const int _Max );
	static bool ScrFuncMNumAdd( QString& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumSub( QString& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumMul( QString& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumDiv( QString& _Return, const int _NumA, const int _NumB );
	static bool ScrFuncMNumMod( QString& _Return, const int _NumA, const int _NumB );
	// IO
	static bool ScrFuncIOReadFileLine( QString& _Return, const QString _File, const int _Line );
	static bool ScrFuncIOReadRandLine( QString& _Return, const QString _File );
	static bool ScrFuncIOSaveFileLine( const QString _Text, const QString _File, const int _Line );
	static bool ScrFuncIOSaveFileLastLine( const QString _Text, const QString _File );
	static bool ScrFuncIOSaveFileOverwrite( const QString _Text, const QString _File );
	static bool ScrFuncIOReadWeb( QString& _Return, const QString _URL );
	static bool ScrFuncIOReadWebLine( QString& _Return, const QString _URL, const int _Line );
	// Users manager
	static bool ScrFuncUserGroupGet( QString& _Return, FUserStruct* _User );
	static bool ScrFuncUserGroupAdd( QString& _Return, FUserStruct* _User, FUserGroupStruct* _Group );
	static bool ScrFuncUserGroupRem( QString& _Return, FUserStruct* _User, FUserGroupStruct* _Group );
	static bool ScrFuncUserRankGet( QString& _Return, FUserStruct* _User );
	static bool ScrFuncUserRankSet( QString& _Return, FUserStruct* _User, FUserRankStruct* _Rank );
	// Events
	static bool ScrFuncEventStart( QString& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventEnd( QString& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventOpen( QString& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventClose( QString& _Return, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserJoin( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserLeave( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserSet( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	static bool ScrFuncEventUserRem( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event );
	// Users currency
	static bool ScrFuncUserPointsGet( QString& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserPointsAdd( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserPointsSub( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserPointsSet( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserPointsGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencyGet( QString& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserCurrencyAdd( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencySub( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencySet( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserCurrencyGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsGet( QString& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserTicketsAdd( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsSub( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsSet( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserTicketsGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysGet( QString& _Return, FUserStruct* _User, const bool _Total );
	static bool ScrFuncUserKeysAdd( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysSub( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysSet( QString& _Return, FUserStruct* _User, const int _Amount );
	static bool ScrFuncUserKeysGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount );
	// Minigames
	static bool ScrFuncMGChest( QString& _Return, FUserStruct* _User );
	static bool ScrFuncMGChestSpawn( QString& _Return, FUserStruct* _User );
	static bool ScrFuncMGDiceRoll( QString& _Return, FUserStruct* _User, const int _Sides );
	static bool ScrFuncMGQAQuestion( QString& _Return, FUserStruct* _User );
	static bool ScrFuncMGQAAnswer( QString& _Return, FUserStruct* _User );
	static bool ScrFuncMGPianoPlay( QString& _Return, FUserStruct* _User );
	// RPG Game
	static bool ScrFuncRPGJoin( QString& _Return, FUserStruct* _User );
	static bool ScrFuncRPGLeave( QString& _Return, FUserStruct* _User );


private:
	
signals:

public slots:
};

#endif // SCRIPTING_H
