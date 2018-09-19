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


#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include "GlobalFunctions.h"
//#include "Commands.h"

// Global vars struct
struct FScrGlobalVarStruct {
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

// Used to preload vars into a container for faster access
struct FScrVarContainerStruct {
	EVariableTypeList varType;
	bool varBool;
	float varFloat;
	int varInt;
	QString varString;

	FScrVarContainerStruct( EVariableTypeList _VarType = EVariableTypeList::eBool, bool _VarBool = false,
	float _VarFloat = 0.0, int _VarInt = 0, QString _VarString = "" )
	: varType( _VarType )
	, varBool( _VarBool )
	, varFloat( _VarFloat )
	, varInt( _VarInt )
	, varString( _VarString ) {}
};

// Function call procesed before to be stored on command
struct FScrFunctionContainerStruct {
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


	FScrFunctionContainerStruct( QString _FunctionName = "", bool _Master = false, bool _SafeLock = true,
							QList<EVariableTypeList> _InputClasses = {}, bool _TrueFalse = false )
	: functionName( _FunctionName )
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
	eMasterN,
	eOwnerN,
	eBotN,
	ePointsN,
	eCurrencyN,
	eTicketsN,
	eKeysN,
	eUserN,
	eUserTargetN,
	// Number
	ePoints,
	eCurrency,
	eTickets,
	eKeys
};

struct FScrTokenStruct {
	// Name
	QString name;
	// Type
	EScrTokenList type;

	FScrTokenStruct( QString _Name = "", EScrTokenList _Type = EScrTokenList::eNone )
	: name( _Name )
	, type( _Type ) {}
};

struct FScrTokenStaticStruct {
	// Name
	QString name;
	// Type
	QString replace;

	FScrTokenStaticStruct( QString _Name = "", QString _Replace = "" )
	: name( _Name )
	, replace( _Replace ) {}
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
	// Nos based in type if bool then can choose
	EVariableTypeList returnType;


	FScrFunctionStruct( QString _FunctionName = "", EScrFunctionList _FunctionRef = EScrFunctionList::eNone, bool _Master = false, bool _SafeLock = true,
							QList<EVariableTypeList> _InputClasses = {}, EVariableTypeList _ReturnType = EVariableTypeList::eVoid )
	: functionName( _FunctionName )
	, functionRef( _FunctionRef )
	, master( _Master )
	, safeLock( _SafeLock )
	, inputClasses( _InputClasses )
	, returnType( _ReturnType ) {}
};

///
/// COMMON
///

struct FCommonModuleStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Enabled
	bool enabled;

	FCommonModuleStruct( QString _NameID = "", QString _Name = "", bool _Enabled = false )
	: nameID( _NameID )
	, name( _Name )
	, enabled( _Enabled ) {}
};

struct FCommonEventStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Costs to enter
	int costPoints;
	int costCurrency;
	int costTickets;
	int costKeys;
	// Users list
	QList<QString> userList;

	FCommonEventStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
						int _CostPoints = 0, int _CostCurrency = 0, int _CostTickets = 0, int _CostKeys = 0,
						QList<QString> _UserList = {} )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, costPoints( _CostPoints )
	, costCurrency( _CostCurrency )
	, costTickets( _CostTickets )
	, costKeys( _CostKeys )
	, userList( _UserList ){}
};

// Cost modifier of commands cost execution
struct FCommonEventCostStruct {
public:
    FCommonEventStruct* event;
    int cost;
    FCommonEventCostStruct(FCommonEventStruct* _Event, int _Cost = 0) {
        event = _Event;
        cost = _Cost;
    }
};

class Common : public QObject
{
    Q_OBJECT
public:
    explicit Common(QObject* _Parent = nullptr);

    void init();

    // Social global
    static QString OwnerName;
    static QString BotName;

    // Twitch
    static QString TwitchChannelName;
    static bool TwitchUseMaster;
    static bool TwitchUseBot;
    static QString TwitchOwnerUsername;
    static QString TwitchBotUsername;
    static QString TwitchUsername;
    static QString TwitchOwnerToken;
    static QString TwitchBotToken;
    static QString TwitchToken;
    static QList<QString> TwitchBotHelpers;

    static bool TwitchEnabled;
    // Common
    static bool TwitchExecuted;
    static bool TwitchConnected;
    static bool TwitchOnline;
    // Master
    static bool TwitchMExecuted;
    static bool TwitchMConnected;
    static bool TwitchMOnline;

    // Dicord
    static QString DiscordChannelName;
    static bool DiscordUseMaster;
    static bool DiscordUseBot;
    static QString DiscordOwnerUsername;
    static QString DiscordBotUsername;
    static QString DiscordUsername;
    static QString DiscordOwnerToken;
    static QString DiscordBotToken;
    static QString DiscordToken;
    static QList<QString> DiscordBotHelpers;

    static bool DiscordEnabled;
    // Common
    static bool DiscordExecuted;
    static bool DiscordConnected;
    static bool DiscordOnline;
    // Master
    static bool DiscordMExecuted;
    static bool DiscordMConnected;
    static bool DiscordMOnline;

    // Steam
    static bool SteamEnabled;
    static bool SteamExecuted;
    static bool SteamConnected;
    static bool SteamOnline;

    // Global
    static QString PointsCustomName;
    static QString CurrencyCustomName;
    static QString TicketsCustomName;
    static QString KeysCustomName;


    static QList<FCommonModuleStruct*> ModulesList;
    static QList<FCommonEventStruct*> EventsList;

    static bool LoadCommonScripts();
    static bool LoadScriptModules( QJsonObject _File );
    static bool LoadScriptEvents( QJsonObject _File );

private:

	static bool ClearModule( FCommonModuleStruct* _Module );
	static bool ClearModulesArray( QList<FCommonModuleStruct*>& _ModulesArray );
	static bool ClearEvent( FCommonEventStruct* _Event );
	static bool ClearEventsArray( QList<FCommonEventStruct*>& _EventsArray );

signals:

public slots:

};

#endif // COMMON_H

