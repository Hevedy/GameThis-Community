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
#include "GameFunctions.h"
#include "GObject.h"

#define CharacterSTR PlayerCharacters
#define CharacterWorldSTR WorldCharacters
#define CharacterDifSTR DifficultyLevels

struct FCharacterStatStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Level
	quint32 Level;

	FCharacterStatStruct( QString name = "", QString desc = "", quint32 level = 0 )
	: Name( name )
	, Desc( desc )
	, Level( level ) {}
};

struct FCharacterDifficultyStruct {
public:

	// Name
	QString NameID;
	// Name
	QString Name;
	// Description
	QString Desc;
	// Level
	quint32 Level;

	FCharacterDifficultyStruct( QString nameID = "", QString name = "", QString desc = "", quint32 level = 0 )
	: NameID( nameID )
	, Name( name )
	, Desc( desc )
	, Level( level ) {}
};

struct FCharacterStruct {
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
	QList<EObjectSlotList> Slots;

	FCharacterStruct( QString name = "", QString desc = "",
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


class GCharacter : public QObject
{
    Q_OBJECT
public:
    explicit GCharacter(QObject *parent = nullptr);

    void Init();

	// Name ID
	QString NameID;
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
	QList<EObjectSlotList> Slots;

private:

signals:

public slots:
};

#endif // GCHARACTER_H
