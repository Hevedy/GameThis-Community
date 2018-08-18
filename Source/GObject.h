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


#ifndef GOBJECT_H
#define GOBJECT_H

#include <QObject>
#include "GameFunctions.h"

#define ObjectSTR Objects

enum class EObjectTypeList {
	ENone,
	EWeapon,
	ETool,
	ESpell,
	EConsumable,
	EOther
};

enum class EObjectSlotList {
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

enum class EObjectUsesList {
	EInfinite,
	EOne,
	ENumber,
	ESpell,
	EConsumable,
	EOther
};

struct FObjectStruct {
public:

	// Name
	QString Name;
	// Description
	QString Desc;
	// Name
	QString Command;
	// Can be placed in the world
	bool bPlaceable;
	// Type
	EObjectTypeList Type;
	// Space on the inventory
	int Weight;
	// Slots where can be placed
	QList<EObjectSlotList> ValidSlots;
	// Status of the object
	int Status;
	
	FObjectStruct( QString name = "", QString desc = "", QString command = "", bool bplaceable = false, EObjectTypeList type = {},
				   int weight = 0, QList<EObjectSlotList> validSlots = {}, int status = 0 )
	: Name( name )
	, Desc( desc )
	, Command( command )
	, bPlaceable( bplaceable )
	, Type( type )
	, Weight( weight )
	, ValidSlots( validSlots )
	, Status( status ) {}
};


class GObject : public QObject
{
    Q_OBJECT
	
public:
    explicit GObject(QObject *parent = nullptr);

	void Init();
	
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
	bool bStartZero;

	// Last result used
	quint8 LastResult;

private:
	
signals:

public slots:
};

#endif // GOBJECT_H
