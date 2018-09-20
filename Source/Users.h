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


#ifndef USERS_H
#define USERS_H

#include <QObject>
#include "GlobalFunctions.h"
#include "Common.h"

#define USER_NAMELENGTHMAX 200
#define GROUP_NAMELENGTHMAX 200
#define RANK_NAMELENGTHMAX 200


enum class EUserGroupList {
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

struct FUserGroupStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Description
	QString desc;
	// Users list
	QList<QString> userList;

	FUserGroupStruct( QString _NameID = "", QString _Name = "", QString _Desc = "", QList<QString> _UserList = {} )
	: nameID( _NameID )
	, name( _Name )
	, desc( _Desc )
	, userList( _UserList ){}
};

// Cost modifier of commands cost execution
struct FUserGroupCostStruct {
public:
    FUserGroupStruct* group;
    int cost;
    FUserGroupCostStruct(FUserGroupStruct* _Group, int _Cost = 0) {
        group = _Group;
        cost = _Cost;
    }
};

struct FUserRankStruct {
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
	bool autoJoin;

	FUserRankStruct( QString _NameID = "", QString _Name = "", QString _Desc = "",
	bool _UsePoints = false, int _Points = 0, bool _UseCurrency = false, int _Currency = 0,
	bool _UseTickets = false, int _Tickets = 0, bool _UseTime = false, FTimeStruct _Time = 0.0, bool _AutoJoin = false )
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
	, autoJoin( _AutoJoin ) {}
};

// Cost modifier of commands cost execution
struct FUserRankCostStruct {
public:
    FUserRankStruct* rank;
    int cost;
    FUserRankCostStruct(FUserRankStruct* _Rank, int _Cost = 0) {
        rank = _Rank;
        cost = _Cost;
    }
};


enum class EUserTypeList {
	eDefault,
	eBot
};

enum class EUserStatusList {
	eDefault,
	eKicked, // AKA Timeout
	eBanned // Banned
};

struct FUserStruct {
public:

	// Name
	QString nameID;
	// Name
	QString name;
	// Twitch Username
	QString tUsername;
	// Twitch current subscribed
	bool tSub;
	// Twitch total subscriptions number
	int tSubNum;
	// Twitch total subscriptions number in Row
	bool tSubInRow;
	// Twitch total subscriptions number in Row
	int tSubInRowNum;
	// Twitch total donated bits
	int tBitsNum;
	// Discord Username
	QString dUsername;
	// Total points given
	int pointsNum;
	// Total points spend
	int pointsSpentNum;
	// Total currency given
	int currencyNum;
	// Total currency spend
	int currencySpentNum;
	// Total tickets given
	int ticketsNum;
	// Total tickets spend
	int ticketsSpentNum;
	// Total keys given
	int keysNum;
	// Total points spend
	int keysSpentNum;
	// Total hours and decimal minutes
	FTimeStruct timeNum;
	// Rank in stream
	FUserRankStruct* rank;
	// Group, fixed or custom ?
	QList<EUserGroupList*> group;
	// If custom name
	QList<FUserGroupStruct*> groupCustomName;
	// Status
	EUserStatusList status;
	// User Type is a bot ?
	EUserTypeList userType;
	// Is the first message ?
	bool firstMessage;
	bool commandCooldown;


	FUserStruct( QString _NameID = "", QString _Name = "", QString _TUsername = "",
	bool _TSub = false, int _TSubNum = 0, bool _TSubInRow = false, int _TSubInRowNum = 0, int _TBitsNum = 0,
	int _PointsNum = 0, int _PointsSpentNum = 0, int _CurrencyNum = 0, int _CurrencySpentNum = 0,
	QString _DUsername = "", int _TicketsNum = 0, int _TicketsSpentNum = 0, FTimeStruct _TimeNum = {}, FUserRankStruct* _Rank = {},
	QList<EUserGroupList*> _Group = {}, QList<FUserGroupStruct*> _GroupCustomName = {},
	EUserStatusList _Status = EUserStatusList::eDefault, EUserTypeList _UserType = EUserTypeList::eDefault, bool _FirstMessage = true )
	: nameID( _NameID )
	, name( _Name )
	, tUsername( _TUsername )
	, tSub( _TSub )
	, tSubNum( _TSubNum )
	, tSubInRow( _TSubInRow )
	, tSubInRowNum( _TSubInRowNum )
	, tBitsNum( _TBitsNum )
	, dUsername( _DUsername )
	, pointsNum( _PointsNum )
	, pointsSpentNum( _PointsSpentNum )
	, currencyNum( _CurrencyNum )
	, currencySpentNum( _CurrencySpentNum )
	, ticketsNum( _TicketsNum )
	, ticketsSpentNum( _TicketsSpentNum )
	, timeNum( _TimeNum )
	, rank( _Rank )
	, group( _Group  )
	, groupCustomName( _GroupCustomName )
	, status( _Status )
	, userType( _UserType )
	, firstMessage( _FirstMessage ){}

};

class Users : public QObject
{
    Q_OBJECT
public:
    explicit Users(QObject *parent = nullptr);

    static bool init();

    bool LoadPlayerProfile();


    static QList<FUserGroupStruct*> UserGroupsList;
    static QList<FUserRankStruct*> UserRanksList;

    static QList<FUserStruct*> UsersList;
    static QList<FUserStruct*> UsersConnectedList;

    static bool LoadUsersScripts();
    static bool LoadScriptGroups( QJsonObject _File );
    static bool LoadScriptRanks( QJsonObject _File );

    static bool LoadStoredLocalUsers();


    // Is playing
    bool bPlaying;

    // Social Public Management

    // Social

    QString TwitchName;
    QString DiscordName;
    QString SteamName;

    QString NickName;

    static bool ClearUser( FUserStruct* _User );
    static bool ClearUsersArray( QList<FUserStruct*>& _UsersArray );

    static bool ClearGroup( FUserGroupStruct* _Group );
    static bool ClearGroupsArray( QList<FUserGroupStruct*>& _GroupsArray );

    static bool ClearRank( FUserRankStruct* _Rank );
    static bool ClearRanksArray( QList<FUserRankStruct*>& _RanksArray );

    static void LoadUserList( bool& _Result );

    static void SaveUserList( bool& _Result );

    static void AddUser( QString _User, FUserStruct _UserStruct, bool& _Result );

    static void EditUser( QString _User, bool& _Result );

    static void RemoveUser( QString _User, bool& _Result );

    static void LoadUser( QString _User, bool& _Result );

    static void SaveUser( QString _User, bool& _Result );

private:

signals:

public slots:

};

#endif // USERS_H

