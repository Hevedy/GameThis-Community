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


#ifndef GCOMMAND_H
#define GCOMMAND_H

#include <QObject>
#include "GameFunctions.h"

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

struct FCommandDiceStruct {
public:

	// Name ID
	QString NameID;
	// Name
	QString Name;
	// Command
	QList<QString> Commands;
	// Input Needed ?
	bool bInputNeeded;
	// Input by Default
	QString InputDefault;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> GroupsLocked;
	// List of Dices by group name
	QList<QString> DiceCall;


	FCommandDiceStruct( QString nameID = "", QString name = "", QList<QString> commands = {},
	bool binputNeeded = false, QString inputDefault = "", QList<QString> groupsLocked = {}, QList<QString> diceCall = {} )
	: NameID( nameID )
	, Name( name )
	, Commands( commands )
	, bInputNeeded( binputNeeded )
	, InputDefault( inputDefault )
	, GroupsLocked( groupsLocked )
	, DiceCall( diceCall ) {}
};

struct FCommandSkillStruct {
public:

	// Name ID
	QString NameID;
	// Name
	QString Name;
	// Command
	QList<QString> Commands;
	// Input Needed ?
	bool bInputNeeded;
	// Input by Default
	QString InputDefault;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> GroupsLocked;
	// List of Skill by name
	QList<QString> SkillCall;


	FCommandSkillStruct( QString nameID = "", QString name = "", QList<QString> commands = {},
	bool binputNeeded = false, QString inputDefault = "", QList<QString> groupsLocked = {}, QList<QString> skillCall = {} )
	: NameID( nameID )
	, Name( name )
	, Commands( commands )
	, bInputNeeded( binputNeeded )
	, InputDefault( inputDefault )
	, GroupsLocked( groupsLocked )
	, SkillCall( skillCall ) {}
};

struct FCommandStruct {
public:

	// Name ID
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Command
	QList<QString> Commands;
	// Input Needed ?
	bool bInputNeeded;
	// Input by Default
	QString InputDefault;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> GroupsLocked;
	// Reply Sentence
	QList<QString> Text;


	FCommandStruct( QString nameID = "", QString name = "", QString desc = "", QList<QString> commands = {},
	bool binputNeeded = false, QString inputDefault = "", QList<QString> groupsLocked = {}, QList<QString> text = {} )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, Commands( commands )
	, bInputNeeded( binputNeeded )
	, InputDefault( inputDefault )
	, GroupsLocked( groupsLocked )
	, Text( text ) {}
};


class GCommand : public QObject
{
    Q_OBJECT
	
public:
	explicit GCommand(QObject *parent = nullptr);

	void Init();
	
	FCommandStruct CommandStruct;

	static QList<FCommandDiceStruct> DiceCommands;

	static QList<FCommandSkillStruct> SkillCommands;

	static QList<FCommandStruct> GeneralCommands;

	static void ReadCommands( bool& bResult );

	static void ReadDiceCommands( QList<FCommandDiceStruct>& Commands, bool& bResult );

	static void ReadSkillCommands( QList<FCommandSkillStruct>& Commands, bool& bResult );

	static void ReadGeneralCommands( QList<FCommandStruct>& Commands, bool& bResult );


	static void CallDiceCommand( FCommandDiceStruct Command );

	static void CallSkillCommand( FCommandSkillStruct Command );

	static void CallGeneralCommand( FCommandStruct Command );

private:
	
signals:

public slots:
};

#endif // GCOMMAND_H
