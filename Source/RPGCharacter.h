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


#ifndef RPGCHARACTER_H
#define RPGCHARACTER_H

#include <QObject>
#include "GlobalFunctions.h"
#include "RPGItem.h"

#define CharacterSTR PlayerCharacters
#define CharacterWorldSTR WorldCharacters
#define CharacterDifSTR DifficultyLevels

// TODO FIX

struct FRPGSkillResultStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Is Positive
	bool isPositive;
	QString text;

	FRPGSkillResultStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
						bool _IsPositive = false, QString _Text = "" )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, isPositive( _IsPositive )
	, text( _Text ) {}
};

// Skill the action
// Skill means the hability the character have to do something, can level up and change the number
struct FRPGSkillStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Level
	quint32 level;
	quint32 levelMax;
	int amount;
	int amountMax;

	FRPGSkillStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", quint32 _Level = 0 )
	: name( _Name )
	, desc( _Desc )
	, level( _Level ) {}
};

// Attribute the points for actions
// Character attibutes means the points it have to do something, defined by the class character
// Usually don't level up and just affect the performance at do actions
struct FRPGAttributeStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Level
	QList<QString> inputs;
	QList<EVariableTypeList> inputTypes;
	int amount;
	int amountDefault;
	int amountMax;
	// Have limit and should use the number ?
	bool amountMaxLimit;

	FRPGAttributeStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
					  QList<QString> _Inputs = {}, QList<EVariableTypeList> _InputTypes = {},
					  int _Amount = 0, int _AmountDefault = 0, int _AmountMax = 0, bool _AmountMaxLimit = true )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, inputs( _Inputs )
	, inputTypes( _InputTypes )
	, amount( _Amount )
	, amountDefault( _AmountDefault )
	, amountMax( _AmountMax )
	, amountMaxLimit( _AmountMaxLimit ){}
};

// Stats to keep info about character
// Counter for some stat, health, money, etc
struct FRPGStatStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Level
	QList<QString> inputs;
	QList<EVariableTypeList> inputTypes;
	int amount;
	int amountDefault;
	int amountMin;
	bool amountMinLimit;
	int amountMax;
	bool amountMaxLimit;

	FRPGStatStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
				QList<QString> _Inputs = {}, QList<EVariableTypeList> _InputTypes = {},
				int _Amount = 0, int _AmountDefault = 0, int _AmountMin = 0, bool _AmountMinLimit = true,
				int _AmountMax = 0, bool _AmountMaxLimit = true )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, inputs( _Inputs )
	, inputTypes( _InputTypes )
	, amount( _Amount )
	, amountDefault( _AmountDefault )
	, amountMin( _AmountMin )
	, amountMinLimit( _AmountMinLimit )
	, amountMax( _AmountMax )
	, amountMaxLimit( _AmountMaxLimit ) {}
};

struct FRPGTraitStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Is Positive
	bool isPositive;
	QString text;

	FRPGTraitStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", bool _IsPositive = false )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, isPositive( _IsPositive ) {}
};

// Character Class, where defines a class with stats and skills and default intentory, characters may change
struct FRPGClassStruct {
public:

	// Name
	QString name;
	// Description
	QString desc;
	// Positive Actions
	QList<QString> positive;
	// Negative Actions
	QList<QString> negative;
	// Attacks
	QList<QString> attacks;
	// Attacks Description
	QList<QString> attacksDesc;
	// Skills
	QList<QString> skills;
	// Skills Description
	QList<QString> skillsDesc;
	// Special Actions
	QList<QString> specialActions;
	// Health Points
	int healthPoints;
	// Action Points
	int actionPoints;
	// Stamina Points
	int staminaPoints;
	// Food Points
	int foodPoints;
	// Water Points
	int waterPoints;
	// Space on Inventory
	int inventorySpace;
	// Slots on character
	QList<FRPGItemSlotStruct> itemSlots;

	FRPGClassStruct( QString _Name = "", QString _Desc = "",
	QList<QString> _Positive = {}, QList<QString> _Negative = {}, QList<QString> _Attacks = {}, QList<QString> _AttacksDesc = {},
	QList<QString> _Skills = {}, QList<QString> _SkillsDesc = {}, QList<QString> _SpecialActions = {},
	int _HealthPoints = 0, int _ActionPoints = 0 )
	: name( _Name )
	, desc( _Desc )
	, positive( _Positive )
	, negative( _Negative )
	, attacks( _Attacks )
	, attacksDesc( _AttacksDesc )
	, skills( _Skills )
	, skillsDesc( _SkillsDesc )
	, specialActions( _SpecialActions )
	, healthPoints(  _HealthPoints )
	, actionPoints( _ActionPoints ) {}
};

// Difficualty calculated for enemies
struct FRPGRankStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Level
	quint32 level;
	// Level
	quint32 levelMax;
	// Level
	quint32 skill;

	FRPGRankStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", quint32 _Level = 0 )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, level( _Level ) {}
};

// Actual character struct
struct FRPGCharacterStruct {
public:

	// Name
	QString name;
	// Description
	QString desc;
	// Positive Actions
	QList<QString> positive;
	// Negative Actions
	QList<QString> negative;
	// Attacks
	QList<QString> attacks;
	// Attacks Description
	QList<QString> attacksDesc;
	// Skills
	QList<QString> skills;
	// Skills Description
	QList<QString> skillsDesc;
	// Special Actions
	QList<QString> specialActions;
	// Health Points
	int healthPoints;
	// Action Points
	int actionPoints;
	// Stamina Points
	int staminaPoints;
	// Food Points
	int foodPoints;
	// Water Points
	int waterPoints;
	// Space on Inventory
	int inventorySpace;
	// Slots on character
	QList<FRPGItemSlotStruct> itemSlots;

	FRPGCharacterStruct( QString _Name = "", QString _Desc = "",
	QList<QString> _Positive = {}, QList<QString> _Negative = {}, QList<QString> _Attacks = {}, QList<QString> _AttacksDesc = {},
	QList<QString> _Skills = {}, QList<QString> _SkillsDesc = {}, QList<QString> _SpecialActions = {},
	int _HealthPoints = 0, int _ActionPoints = 0 )
	: name( _Name )
	, desc( _Desc )
	, positive( _Positive )
	, negative( _Negative )
	, attacks( _Attacks )
	, attacksDesc( _AttacksDesc )
	, skills( _Skills )
	, skillsDesc( _SkillsDesc )
	, specialActions( _SpecialActions )
	, healthPoints( _HealthPoints )
	, actionPoints( _ActionPoints ) {}
};


class RPGCharacter : public QObject
{
    Q_OBJECT
public:
    explicit RPGCharacter(QObject *parent = nullptr);

    void init();

    static void ReadCharacterSkillResults( QList<FRPGSkillResultStruct>& _Characters, bool& _Result );

    static void ReadCharacterSkills( QList<FRPGSkillStruct>& _Characters, bool& _Result );

    static void ReadCharacterAttributes( QList<FRPGAttributeStruct>& _Characters, bool& _Result );

    static void ReadCharacterStats( QList<FRPGStatStruct>& _Characters, bool& _Result );


	static void ReadCharacterTraits( QList<FRPGTraitStruct>& _Characters, bool& _Result );

	static void ReadCharacterClass( QList<FRPGClassStruct>& _Characters, bool& _Result );

	static void ReadCharacterRanks( QList<FRPGRankStruct>& _Characters, bool& _Result );

	static void ReadCharacters( QList<FRPGCharacterStruct>& _Characters, bool& _Result );

private:

signals:

public slots:
};

#endif // RPGCHARACTER_H
