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


    static QList<FCommonModuleStruct*> Modules;
    static QList<FCommonEventStruct*> Events;

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

