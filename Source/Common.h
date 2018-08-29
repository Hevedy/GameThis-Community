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
#include "Commands.h"

enum class ECommonUserGroupList {
	eDefault,
	eOther,
	eStaff,
	eMod,
	eEditor,
	eAdmin,
	eBotR,
	eBotRW,
	eChannel,
	eOwner
};

struct FCommonModuleStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Type
	bool enabled;

	FCommonModuleStruct( QString _NameID = "", QString _Name = "", bool _Enabled = false )
	: nameID( _NameID )
	, name( _Name )
	, enabled( _Enabled ) {}
};

struct FCommonVariableStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Type
	EVariableTypeList type;

	FCommonVariableStruct( QString _NameID = "", QString _Name = "", EVariableTypeList _Type = EVariableTypeList::eString )
	: nameID( _NameID )
	, name( _Name )
	, type( _Type ) {}
};

struct FCommonUserGroupStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Users list
	QList<QString> userList;

	FCommonUserGroupStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", QList<QString> _UserList = {} )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, userList( _UserList ){}
};

struct FCommonUserRankStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Use points to unlock
	bool usePoints;
	int points;
	// Use currency to unlock
	bool useCurrency;
	int currency;
	// Use tickects to unlock
	bool useTickets;
	int tickets;
	// Use time to unlock
	bool useTime;
	FTimeStruct time;
	// Is open automatic at level up ?
	bool open;

	FCommonUserRankStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
	bool _UsePoints = false, int _Points = 0, bool _UseCurrency = false, int _Currency = 0,
	bool _UseTickets = false, int _Tickets = 0, bool _UseTime = false, FTimeStruct _Time = 0.0, bool _Open = false )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, usePoints( _UsePoints )
	, points( _Points )
	, useCurrency( _UseCurrency )
	, currency( _Currency )
	, useTickets( _UseTickets )
	, tickets( _Tickets )
	, useTime( _UseTime )
	, time( _Time )
	, open( _Open ) {}
};

class Common : public QObject
{
    Q_OBJECT
public:
    explicit Common(QObject* _Parent = nullptr);

    void init();


private:

signals:

public slots:

};

#endif // COMMON_H

