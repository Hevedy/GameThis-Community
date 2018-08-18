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


#ifndef GACTION_H
#define GACTION_H

#include <QObject>
#include "GameFunctions.h"

#define ActionSTR Actions
#define ActionTypeSTR ActionResultTypes

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

struct FActionEffectTypeStruct {
public:

	// Name ID
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Is Positive Effect ?
	bool bIsPositive;

	FActionEffectTypeStruct( QString nameID = "", QString name = "", QString desc = "", bool bisPositive = false )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, bIsPositive( bisPositive ) {}
};


struct FActionEffectStruct {
public:

	// Name ID
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Type
	FActionEffectTypeStruct Type;
	// Dice Range Min
	quint8 DiceMin;
	// Dice Range Max
	quint8 DiceMax;
	// Reply Sentence
	QList<QString> Reply;

	FActionEffectStruct( QString nameID = "", QString name = "", QString desc = "", FActionEffectTypeStruct type = {},
						 quint8 diceMin = 0, quint8 diceMax = 0, QList<QString> reply = {} )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, Type( type )
	, DiceMin( diceMin )
	, DiceMax( diceMax )
	, Reply( reply ) {}
};

struct FActionStruct {
public:

	// Name
	QString Name;
	// Description
	QString Desc;
	// Command
	QString Command;
	// Input Needed ?
	bool bInputNeeded;
	// Input by Default
	QString InputDefault;
	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> GroupLocked;
	// Characters locked to (If equal null or "All" then all)
	QList<QString> CharacterLocked;
	// Reply Sentence
	QList<QString> Reply;
	// Effects
	FActionEffectStruct Effects;
	

	FActionStruct( QString name = "", QString desc = "", QString command = "", bool binputNeeded = false, QString inputDefault = "",
	QList<QString> groupLocked = {}, QList<QString> characterLocked = {}, QList<QString> reply = {}, FActionEffectStruct effects = {} )
	: Name( name )
	, Desc( desc )
	, Command( command )
	, bInputNeeded( binputNeeded )
	, InputDefault( inputDefault )
	, GroupLocked( groupLocked )
	, CharacterLocked( characterLocked )
	, Reply( reply )
	, Effects( effects ) {}
};


class GAction : public QObject
{
    Q_OBJECT
	
public:
    explicit GAction(QObject *parent = nullptr);

	void Init();
	
	// Name ID
	QString NameID;

	// Name
	QString Name;

	// Description
	QString Desc;

	// Command
	QString Command;

	// Input Needed ?
	bool bInputNeeded;

	// Input by Default
	QString InputDefault;

	// Groups of locked to (If equal null or "All" then all) Groups defined on Config
	QList<QString> GroupLocked;

	// Characters locked to (If equal null or "All" then all)
	QList<QString> CharacterLocked;

	// Reply Sentence
	QList<QString> Reply;

	// Effects
	FActionEffectStruct Effects;

private:
	
signals:

public slots:
};

#endif // GACTION_H
