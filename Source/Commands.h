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


#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>
#include "GlobalFunctions.h"
#include "Common.h"
#include "Users.h"

#define COMMAND_NAMELENGTHMAX 200
#define COMMANDINPUT_LENGTHMAX 250

#define CommandSTR Commands
#define CommandTypeSTR CommandsResultTypes


/*
enum class ECommandUserGroupList {
	EAll,
	EWriter,
	EAdmins,
	EMods,
	EGroupA,
	EGroupB,
	EGroupC,
	EGroupD
};
*/

// Make input

// Input queue raw
struct FInputQueueStruct {
public:

	// Input user name
	QString username;
	// Text
	QString text;

	FInputQueueStruct( QString _Username = "", QString _Text = "" )
	: username( _Username )
	, text( _Text ) {}
};

// Outout queue raw
struct FOutputQueueStruct {
public:

	// Need master
	bool master;
	// Text
	QString text;

	FOutputQueueStruct( bool _Master = false, QString _Text = "" )
	: master( _Master )
	, text( _Text ) {}
};

/*
 *
 * List of functions calls , include name and index from
 * the actual setup and inputs
 *
 *
 *
 *
 *
 * */


// Registered functions for commands
struct FCommandFunctionStruct {
public:

	// Name
	QString function;
	// Need Master
	bool master;
	// Force safe lock to the admins and master groups or channel or bots
	// Can be a danger if a user uses it
	bool safeLock;
	// Inputs
	QList<EVariableTypeList> inputClasses;
	// Return true or false functions
	bool trueFalse;


	FCommandFunctionStruct( QString _Function = "", bool _Master = false, bool _SafeLock = true,
							QList<EVariableTypeList> _InputClasses = {}, bool _TrueFalse = false )
	: function( _Function )
	, master( _Master )
	, safeLock( _SafeLock )
	, inputClasses( _InputClasses )
	, trueFalse( _TrueFalse ) {}
};

struct FIndividualInputStruct {
public:

	QString inputRaw;

	QList<QString> inputs;

	FIndividualInputStruct( QString _InputRaw = "", QList<QString> _Inputs = {} )
	: inputRaw( _InputRaw )
	, inputs( _Inputs ) {}
};

// User input at write a command after detect the command is defined
struct FCommandInputStruct {
public:

	// Command
	QString command;
	// Command
	QString commandFixed;
	// Number inputs per command set by class
	QList<EVariableTypeList> inputClasses;
	// Number of commands accepted per command set by class
	int commandsLimit;
	// Inputs List
	QList<FIndividualInputStruct> inputs;
	// Inputs List
	QList<FIndividualInputStruct> inputsFixed;

	// Info of the linked command
	int commandIndex;
	QString returnValid;
	QString returnInvalid;


	FCommandInputStruct( QString _Command = "", QString _CommandFixed = "", QList<EVariableTypeList> _InputClasses = {},
	int _CommandsLimit = 0, QList<FIndividualInputStruct> _Inputs = {}, QList<FIndividualInputStruct> _InputsFixed = {} )
	: command( _Command )
	, commandFixed( _CommandFixed )
	, inputClasses( _InputClasses )
	, commandsLimit( _CommandsLimit )
	, inputs( _Inputs )
	, inputsFixed( _InputsFixed ) {}
};

// Command info for fast access from struct
//template <typename T>
struct FCommandLinkStruct {
public:

	// Name ID
	QString nameID;
	// Name
	QString name;
	// Command Name
	QString commandName;
	// Struct
	QString structName;
	//T* StructRef;
	// Name
	int structIndex;

	FCommandLinkStruct( QString _NameID = "", QString _Name = "", QString _CommandName = "", QString _StructName = "",
	int _StructIndex = 0 )
	: nameID( _NameID )
	, name( _Name )
	, commandName( _CommandName )
	, structName( _StructName )
	, structIndex( _StructIndex ) {}
};

/*
struct FCommandDiceStruct {
public:

	// Name ID
	QString nameID;
	// Name
	QString name;
	// Command
	QList<QString> commands;
	// Input Needed ?
	bool inputNeeded;
	// Input by Default
	QString inputDefault;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> groupsLocked;
	// List of Dices by group name
	QList<QString> diceCall;

	FCommandDiceStruct( QString _NameID = "", QString _Name = "", QList<QString> _Commands = {},
	bool _InputNeeded = false, QString _InputDefault = "", QList<QString> _GroupsLocked = {}, QList<QString> _DiceCall = {} )
	: nameID( _NameID )
	, name( _Name )
	, commands( _Commands )
	, inputNeeded( _InputNeeded )
	, inputDefault( _InputDefault )
	, groupsLocked( _GroupsLocked )
	, diceCall( _DiceCall ) {}
};

struct FCommandSkillStruct {
public:

	// Name ID
	QString nameID;
	// Name
	QString name;
	// Command
	QList<QString> commands;
	// Input Needed ?
	bool inputNeeded;
	// Input by Default
	QString inputDefault;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> groupsLocked;
	// List of Skill by name
	QList<QString> skillCall;

	FCommandSkillStruct( QString _NameID = "", QString _Name = "", QList<QString> _Commands = {},
	bool _InputNeeded = false, QString _InputDefault = "", QList<QString> _GroupsLocked = {}, QList<QString> _SkillCall = {} )
	: nameID( _NameID )
	, name( _Name )
	, commands( _Commands )
	, inputNeeded( _InputNeeded )
	, inputDefault( _InputDefault )
	, groupsLocked( _GroupsLocked )
	, skillCall( _SkillCall ) {}
};
*/

// Command type that is called each x time
struct FCommandAutoStruct {
public:

	// Name ID
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Need master call
	bool needsMaster;
	// Reply Sentence
	QList<QString> text;

	FCommandAutoStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
	bool _NeedsMaster = false, QList<QString> _Text = {} )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, needsMaster( _NeedsMaster )
	, text( _Text ) {}
};

// Command type called at some msg input
struct FCommandTriggerStruct {
public:

	// Name ID
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Command
	QList<QString> commands;
	// Input Needed ?
	bool inputNeeded;
	// Input by Default
	QString inputDefault;
	// Need master call
	bool needsMaster;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> groupsLocked;
	// Ranks locked
	QList<QString> ranksLocked;
	// Reply Sentence
	QList<QString> text;

	FCommandTriggerStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", QList<QString> _Commands = {},
	bool _InputNeeded = false, QString _InputDefault = "", bool _NeedsMaster = false,
	QList<QString> _GroupsLocked = {}, QList<QString> _RanksLocked = {}, QList<QString> _Text = {} )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, commands( _Commands )
	, inputNeeded( _InputNeeded )
	, inputDefault( _InputDefault )
	, needsMaster( _NeedsMaster )
	, groupsLocked( _GroupsLocked )
	, ranksLocked( _RanksLocked )
	, text( _Text ) {}
};

// Default command
struct FCommandStruct {
public:

	// Name ID
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Modules
	QList<QString> modules;
	// Command
	QList<QString> commands;
	// Inputs classes
	QList<EVariableTypeList> inputsClasses;
	// Input by Default
	QList<QString> inputsDefault;
	// Allow multi input
	bool allowMultiCommand;
	// Need master call
	bool needsMaster;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<FUserGroupStruct*> groupsLocked;
	// Ranks locked
	QList<FUserRankStruct*> ranksLocked;
	// Points Cost
	QList<FUserGroupCostStruct> pointsCost;
	// Currency Cost
	QList<FUserGroupCostStruct> currencyCost;
	// Tickets Cost
	QList<FUserGroupCostStruct> ticketsCost;

	QList<EScrFunctionList> functions;
	QList<QString> functionArgs;

	// Reply Sentence
	QList<QString> returns;

	FCommandStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", QList<QString> _Modules = {},
	QList<QString> _Commands = {}, QList<EVariableTypeList> _InputsClasses = {}, QList<QString> _InputsDefault = {},
	bool _AllowMultiCommand = false, bool _NeedsMaster = false,
	QList<FUserGroupStruct*> _GroupsLocked = {}, QList<FUserRankStruct*> _RanksLocked = {},
	QList<FUserGroupCostStruct> _PointsCost = {}, QList<FUserGroupCostStruct> _CurrencyCost = {}, QList<FUserGroupCostStruct> _TicketsCost = {},
	QList<QString> _Returns = {} )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, modules( _Modules )
	, commands( _Commands )
	, inputsClasses( _InputsClasses )
	, inputsDefault( _InputsDefault )
	, allowMultiCommand( _AllowMultiCommand )
	, needsMaster( _NeedsMaster )
	, groupsLocked( _GroupsLocked )
	, ranksLocked( _RanksLocked )
	, pointsCost( _PointsCost )
	, currencyCost( _CurrencyCost )
	, ticketsCost( _TicketsCost )
	, returns( _Returns ) {}
};


class Commands : public QObject
{
    Q_OBJECT
	
public:
	explicit Commands(QObject *parent = nullptr);

	static bool init();
	
	FCommandStruct CommandStruct;

	static QList<FCommandFunctionStruct> FunctionsList;
	static QList<FCommandLinkStruct> CommandsList;


	//static QList<FCommandDiceStruct> DiceCommands;
	//static QList<FCommandSkillStruct> SkillCommands;
	static QList<FCommandStruct> GeneralCommandsList;
	static QList<FCommandAutoStruct> AutoCommandsList;
	static QList<FCommandTriggerStruct> TriggerCommandsList;

	static bool ReadCommands();

	//static bool ReadDiceCommands( QList<FCommandDiceStruct>& _Commands );

	//static bool ReadSkillCommands( QList<FCommandSkillStruct>& _Commands );

	static bool ReadGeneralCommands( QList<FCommandStruct>& _Commands );

	static bool ReadAutoCommands( QList<FCommandAutoStruct>& _Commands );

	static bool ReadTriggerCommands( QList<FCommandTriggerStruct>& _Commands );

private:
	
signals:

public slots:
};

#endif // COMMANDS_H
