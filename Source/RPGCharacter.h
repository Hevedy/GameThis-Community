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


#ifndef GCHARACTER_H
#define GCHARACTER_H

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
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Is Positive
	bool IsPositive;
	QString Text;

	FRPGSkillResultStruct( QString nameID = "", QString name = "", QString desc = "",
						bool isPositive = false, QString text = "" )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, IsPositive( isPositive )
	, Text( text ) {}
};

// Skill the action
// Skill means the hability the character have to do something, can level up and change the number
struct FRPGSkillStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Level
	quint32 Level;
	quint32 LevelMax;
	int Amount;
	int AmountMax;

	FRPGSkillStruct( QString nameID = "", QString name = "", QString desc = "", quint32 level = 0 )
	: Name( name )
	, Desc( desc )
	, Level( level ) {}
};

// Attribute the points for actions
// Character attibutes means the points it have to do something, defined by the class character
// Usually don't level up and just affect the performance at do actions
struct FRPGAttributeStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Level
	QList<QString> Inputs;
	QList<EVariableTypeList> InputTypes;
	int Amount;
	int AmountDefault;
	int AmountMax;
	// Have limit and should use the number ?
	bool AmountMaxLimit;

	FRPGAttributeStruct( QString nameID = "", QString name = "", QString desc = "",
					  QList<QString> inputs = {}, QList<EVariableTypeList> inputTypes = {},
					  int amount = 0, int amountDefault = 0, int amountMax = 0, bool amountMaxLimit = true )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, Inputs( inputs )
	, InputTypes( inputTypes )
	, Amount( amount )
	, AmountDefault( amountDefault )
	, AmountMax( amountMax )
	, AmountMaxLimit( amountMaxLimit ){}
};

// Stats to keep info about character
// Counter for some stat, health, money, etc
struct FRPGStatStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Level
	QList<QString> Inputs;
	QList<EVariableTypeList> InputTypes;
	int Amount;
	int AmountDefault;
	int AmountMin;
	bool AmountMinLimit;
	int AmountMax;
	bool AmountMaxLimit;

	FRPGStatStruct( QString nameID = "", QString name = "", QString desc = "",
				QList<QString> inputs = {}, QList<EVariableTypeList> inputTypes = {},
				int amount = 0, int amountDefault = 0, int amountMin = 0, bool amountMinLimit = true,
				int amountMax = 0, bool amountMaxLimit = true )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, Inputs( inputs )
	, InputTypes( inputTypes )
	, Amount( amount )
	, AmountDefault( amountDefault )
	, AmountMin( amountMin )
	, AmountMinLimit( amountMinLimit )
	, AmountMax( amountMax )
	, AmountMaxLimit( amountMaxLimit ) {}
};

struct FRPGTraitStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Is Positive
	bool IsPositive;
	QString Text;

	FRPGTraitStruct( QString nameID = "", QString name = "", QString desc = "", bool isPositive = false )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, IsPositive( isPositive ) {}
};

// Character Class, where defines a class with stats and skills and default intentory, characters may change
struct FRPGClassStruct {
public:

	// Name
	QString Name;
	// Description
	QString Desc;
	// Positive Actions
	QList<QString> Positive;
	// Negative Actions
	QList<QString> Negative;
	// Attacks
	QList<QString> Attacks;
	// Attacks Description
	QList<QString> AttacksDesc;
	// Skills
	QList<QString> Skills;
	// Skills Description
	QList<QString> SkillsDesc;
	// Special Actions
	QList<QString> SpecialActions;
	// Health Points
	int HealthPoints;
	// Action Points
	int ActionPoints;
	// Stamina Points
	int StaminaPoints;
	// Food Points
	int FoodPoints;
	// Water Points
	int WaterPoints;
	// Space on Inventory
	int InventorySpace;
	// Slots on character
	QList<FItemSlotStruct> Slots;

	FRPGClassStruct( QString name = "", QString desc = "",
	QList<QString> positive = {}, QList<QString> negative = {}, QList<QString> attacks = {}, QList<QString> attacksDesc = {},
	QList<QString> skills = {}, QList<QString> skillsDesc = {}, QList<QString> specialActions = {},
	int healthPoints = 0, int actionPoints = 0 )
	: Name( name )
	, Desc( desc )
	, Positive( positive )
	, Negative( negative )
	, Attacks( attacks )
	, AttacksDesc( attacksDesc )
	, Skills( skills )
	, SkillsDesc( skillsDesc )
	, SpecialActions( specialActions )
	, HealthPoints( healthPoints )
	, ActionPoints( actionPoints ) {}
};

// Difficualty calculated for enemies
struct FRPGRankStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Level
	quint32 Level;
	// Level
	quint32 LevelMax;
	// Level
	quint32 Skill;

	FRPGRankStruct( QString nameID = "", QString name = "", QString desc = "", quint32 level = 0 )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, Level( level ) {}
};

// Actual character struct
struct FRPGCharacterStruct {
public:

	// Name
	QString Name;
	// Description
	QString Desc;
	// Positive Actions
	QList<QString> Positive;
	// Negative Actions
	QList<QString> Negative;
	// Attacks
	QList<QString> Attacks;
	// Attacks Description
	QList<QString> AttacksDesc;
	// Skills
	QList<QString> Skills;
	// Skills Description
	QList<QString> SkillsDesc;
	// Special Actions
	QList<QString> SpecialActions;
	// Health Points
	int HealthPoints;
	// Action Points
	int ActionPoints;
	// Stamina Points
	int StaminaPoints;
	// Food Points
	int FoodPoints;
	// Water Points
	int WaterPoints;
	// Space on Inventory
	int InventorySpace;
	// Slots on character
	QList<FItemSlotStruct> Slots;

	FRPGCharacterStruct( QString name = "", QString desc = "",
	QList<QString> positive = {}, QList<QString> negative = {}, QList<QString> attacks = {}, QList<QString> attacksDesc = {},
	QList<QString> skills = {}, QList<QString> skillsDesc = {}, QList<QString> specialActions = {},
	int healthPoints = 0, int actionPoints = 0 )
	: Name( name )
	, Desc( desc )
	, Positive( positive )
	, Negative( negative )
	, Attacks( attacks )
	, AttacksDesc( attacksDesc )
	, Skills( skills )
	, SkillsDesc( skillsDesc )
	, SpecialActions( specialActions )
	, HealthPoints( healthPoints )
	, ActionPoints( actionPoints ) {}
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

#endif // GCHARACTER_H