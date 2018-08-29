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


#ifndef RPGITEM_H
#define RPGITEM_H

#include <QObject>
#include "GlobalFunctions.h"

#define ItemSTR Items

enum class EItemTypeList {
	eNone,
	eWeapon,
	eTool,
	eSpell,
	eConsumable,
	eOther
};

/*
enum class EItemSlotList {
	EDefault,
	EInventory,
	EHands,
	ERightHand,
	ELeftHand,
	ESpecial,
	EHead,
	EChest,
	EArms,
	ELegs,
	EFoots,
	EWorld
};
*/

enum class EItemUsesList {
	eInfinite,
	eOne,
	eNumber,
	eSpell,
	eConsumable,
	eOther
};

struct FItemSlotStruct {
public:


	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Is a character slot ?
	bool isCharacterSlot;

	FItemSlotStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", bool _IsCharacterSlot = true )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, isCharacterSlot( _IsCharacterSlot ) {}
};

struct FItemStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Name
	QString command;
	// Can be placed in the world
	bool placeable;
	// Type
	EItemTypeList type;
	// Space on the inventory
	int weight;
	// Slots where can be placed
	QList<FItemSlotStruct> validSlots;
	// Status of the object
	int status;
	
	FItemStruct( QString _Name = "", QString _Desc = "", QString _Command = "", bool _Placeable = false, EItemTypeList _Type = {},
				   int _Weight = 0, QList<FItemSlotStruct> _ValidSlots = {}, int _Status = 0 )
	: name( _Name )
	, desc( _Desc )
	, command( _Command )
	, placeable( _Placeable )
	, type( _Type )
	, weight( _Weight )
	, validSlots( _ValidSlots )
	, status( _Status ) {}
};


class RPGItem : public QObject
{
    Q_OBJECT
	
public:
	explicit RPGItem(QObject *parent = nullptr);

	void init();
	
	// Dice Generate Name Reference
	QString NameID;

	// Dice Name
	QString Name;

	// Dice Description
	QString Desc;

	// Dice Name
	QString Command;

	// Total Number of Sides
	quint8 SidesNum; // Min 0, Max 128

	// Count from 0 rather than 1
	bool StartZero;

	// Last result used
	quint8 LastResult;

private:
	
signals:

public slots:
};

#endif // RPGITEM_H
