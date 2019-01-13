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


#include <QtMath>
#include "Users.h"
#include "Commands.h"

QList<FUserGroupStruct*> Users::UserGroupsList;
QList<FUserRankStruct*> Users::UserRanksList;

QList<FUserStruct*> Users::UsersList;
QList<FUserStruct*> Users::UsersConnectedList;

bool Users::ClearUser( FUserStruct* _User ) {
	delete _User;
	_User = nullptr;
	return true;
}

bool Users::ClearUsersArray( QList<FUserStruct*>& _UsersArray ) {
	qDeleteAll(_UsersArray);
	_UsersArray.clear();
	return true;
}

bool Users::ClearGroup( FUserGroupStruct* _Group ) {
	delete _Group;
	_Group = nullptr;
	return true;
}

bool Users::ClearGroupsArray( QList<FUserGroupStruct*>& _GroupsArray ) {
	qDeleteAll(_GroupsArray);
	_GroupsArray.clear();
	return true;
}

bool Users::ClearRank( FUserRankStruct* _Rank ) {
	delete _Rank;
	_Rank = nullptr;
	return true;
}

bool Users::ClearRanksArray( QList<FUserRankStruct*>& _RanksArray ) {
	qDeleteAll(_RanksArray);
	_RanksArray.clear();
	return true;
}

Users::Users(QObject* _Parent) : QObject(_Parent)
{

}

bool Users::init() {
	if( !LoadUsersScripts() ) { return false; }
}

bool Users::LoadUsersScripts() {
	QJsonObject fileJSON;
	if ( !GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eCommon ) ) { return false; }
	if ( !LoadScriptGroups( fileJSON ) ) { return false; }
	if ( !LoadScriptRanks( fileJSON ) ) { return false; }
	if ( !LoadStoredLocalUsers() ) { return false; }
	return true;
}

bool Users::LoadScriptGroups( QJsonObject _File ) {
	qDebug() << "Read & Load Groups";
	QList<FUserGroupStruct*> groups;
	QJsonArray groupsArray = _File["Common"].toObject()["Groups"].toArray();
	if ( !groupsArray.isEmpty() ) {
		for ( int i = 0; i < groupsArray.size(); i++ ) {
			FUserGroupStruct* group = new FUserGroupStruct;
			group->name = groupsArray[i].toObject()["Name"].toString();
			group->nameID = group->name;
			group->desc = groupsArray[i].toObject()["Description"].toString();
			QJsonArray listArray = groupsArray[i].toObject()["List"].toArray();
			QString listItem;
			if ( listArray.size() <= 0 ) {

			} else {
				for ( int l = 0; l < listArray.size(); l++ ) {
					listItem = listArray[l].isString();
					if ( listItem == "" || listItem == " " || listItem.isNull() || listItem.isEmpty() ) {

					} else {
						if ( !group->userList.contains( listItem ) ) {
							group->userList << listItem;
						}
					}
				}
			}
			groups << group;
		}
	}
	ClearGroupsArray( UserGroupsList );
	//qDeleteAll(UserGroupsStruct);
	//UserGroupsStruct.clear();
	UserGroupsList = groups;
	// Because the errors already has been pulled
	return true;
}

bool Users::LoadScriptRanks( QJsonObject _File ) {
	qDebug() << "Read & Load Ranks";
	QList<FUserRankStruct*> ranks;
	QJsonArray ranksArray = _File["Common"].toObject()["Ranks"].toArray();
	if ( !ranksArray.isEmpty() ) {
		for ( int i = 0; i < ranksArray.size(); i++ ) {
			FUserRankStruct* rank = new FUserRankStruct;
			rank->name = ranksArray[i].toObject()["Name"].toString();
			rank->nameID = rank->name;
			rank->desc = ranksArray[i].toObject()["Description"].toString();

			rank->usePoints = ranksArray[i].toObject()["UsePoints"].toBool(false);
			rank->useCurrency = ranksArray[i].toObject()["UseCurrency"].toBool(false);
			rank->useTickets = ranksArray[i].toObject()["UseTickets"].toBool(false);
			rank->useTime = ranksArray[i].toObject()["UseTime"].toBool(false);
			rank->autoJoin = ranksArray[i].toObject()["AutoJoin"].toBool(false);

			rank->points = qBound( 0, ranksArray[i].toObject()["Points"].toInt(0), 99999 );
			rank->currency = qBound( 0, ranksArray[i].toObject()["Currency"].toInt(0), 99999 );
			rank->tickets = qBound( 0, ranksArray[i].toObject()["Tickets"].toInt(0), 99999 );

			float timevar = ranksArray[i].toObject()["Time"].toDouble(0.0);
			FTimeStruct time;
			time.hours = qBound( 0, qFloor(qFabs(timevar)), 99999 );
			float cal = (qFabs(timevar) - time.hours);
			cal = (cal) * (QString::number(cal).size() - 2) ;
			time.minutes = qBound( 0, qFloor(qFabs(cal)), 99999 );
			rank->time = time;
			ranks << rank;
		}
	}
	ClearRanksArray( UserRanksList );
	//qDeleteAll(UserRanksStruct);
	//UserRanksStruct.clear();
	UserRanksList = ranks;
	// Because the errors already has been pulled
	return true;
}

/// Last one to load all the data
bool Users::LoadStoredLocalUsers() {
	qDebug() << "Read & Load Users";
	QJsonObject fileJSON;
	if ( GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eSaveUsers ) ) { return false; }
	QList<FUserStruct*> users;
	QJsonArray usersArray = fileJSON["Users"].toArray();
	if ( !usersArray.isEmpty() ) {
		for ( int i = 0; i < usersArray.size(); i++ ) {
			FUserStruct* user = new FUserStruct;
			user->name = usersArray[i].toObject()["Name"].toString();
			user->nameID = user->name;
			//user->desc = usersArray[i].toObject()["Description"].toString();


			users << user;
		}
	}
	//qDeleteAll(UsersList);
	//UsersList.clear();
	ClearUsersArray( UsersList );
	UsersList = users;
	// Because the errors already has been pulled
	return true;
}

void Users::LoadUserList( bool& _Result ) {

}

void Users::SaveUserList( bool& _Result ) {

}

void Users::AddUser( QString _User, FUserStruct _UserStruct, bool& _Result ) {

}

void Users::EditUser( QString _User, bool& _Result ) {

}

void Users::RemoveUser( QString _User, bool& _Result ) {

}

void Users::LoadUser( QString _User, bool& _Result ) {

}

void Users::SaveUser( QString _User, bool& _Result ) {

}
