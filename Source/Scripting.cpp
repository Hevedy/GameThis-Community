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


#include "Scripting.h"
#include "MiniGames.h"
//#include "ScriptingVM.h"

bool Scripting::ProcessingCommand = false;

QList<FScrGlobalVarStruct*> Scripting::GlobalVarsList;
QList<FScrTokenStruct*> Scripting::TokensList;
QList<FScrTokenStaticStruct> Scripting::TokensStaticList;
QList<FScrFunctionStruct*> Scripting::FunctionsList;

QString Scripting::GVarPrefix = "@";
QString Scripting::GVarSuffix = "";
QString Scripting::TokenPrefix = "$";
QString Scripting::TokenSuffix = "";
QString Scripting::FuncPrefix = ".";
QString Scripting::FuncSuffix = "(";

FUserStruct* Scripting::CUser;
FUserStruct* Scripting::CUserTarget;
FCommandStruct* Scripting::CCommand;


bool Scripting::ClearGlobalVar( FScrGlobalVarStruct* _Var ) {
	delete _Var;
	_Var = nullptr;
	return true;
}

bool Scripting::ClearGlobalVarsArray( QList<FScrGlobalVarStruct*>& _VarsArray ) {
	qDeleteAll(_VarsArray);
	_VarsArray.clear();
	return true;
}

Scripting::Scripting(QObject *parent) : QObject(parent)
{

}

bool Scripting::init() {
	AddCoreFunctions();
	if( !LoadScriptingScripts() ) { return false; }
	return true;

}

void Scripting::AddCoreFunctions() {

	// Implicits = $username, $inp1
	// functions return true, false and the text split by /
	// Read functions from last to first to make sure longer names are checked before

	QList<FScrTokenStruct*> tokens;
	tokens << new FScrTokenStruct( "ChannelName", EScrTokenList::eChannelN );
	tokens << new FScrTokenStruct( "MasterName", EScrTokenList::eMasterN );
	tokens << new FScrTokenStruct( "OwnerName", EScrTokenList::eOwnerN );
	tokens << new FScrTokenStruct( "BotName", EScrTokenList::eBotN );
	tokens << new FScrTokenStruct( "PointsName", EScrTokenList::ePointsN );
	tokens << new FScrTokenStruct( "CurrencyName", EScrTokenList::eCurrencyN );
	tokens << new FScrTokenStruct( "TicketsName", EScrTokenList::eTicketsN );
	tokens << new FScrTokenStruct( "KeysName", EScrTokenList::eKeysN );
	tokens << new FScrTokenStruct( "UserName", EScrTokenList::eUserN );
	tokens << new FScrTokenStruct( "TargetName", EScrTokenList::eUserTargetN );
	tokens << new FScrTokenStruct( "UPoints", EScrTokenList::ePoints );
	tokens << new FScrTokenStruct( "UCurrency", EScrTokenList::eCurrency );
	tokens << new FScrTokenStruct( "UTickets", EScrTokenList::eTickets );
	tokens << new FScrTokenStruct( "UKeys", EScrTokenList::eKeys );

	qDeleteAll(TokensList);
	TokensList.clear();
	TokensList = tokens;

	QList<FScrTokenStaticStruct> tokensS;
	tokensS << FScrTokenStaticStruct( " True ", "1" );
	tokensS << FScrTokenStaticStruct( " False ", "0" );
	tokensS << FScrTokenStaticStruct( ",True", "1" );
	tokensS << FScrTokenStaticStruct( ",False", "0" );
	tokensS << FScrTokenStaticStruct( ", True", "1" );
	tokensS << FScrTokenStaticStruct( ", False", "0" );
	tokensS << FScrTokenStaticStruct( "True,", "1" );
	tokensS << FScrTokenStaticStruct( "False,", "0" );
	tokensS << FScrTokenStaticStruct( "True ,", "1" );
	tokensS << FScrTokenStaticStruct( "False ,", "0" );
	tokensS << FScrTokenStaticStruct( "/", "\\\\" );
	tokensS << FScrTokenStaticStruct( "\\", "\\\\" );
	tokensS << FScrTokenStaticStruct( "[", "\"" );
	tokensS << FScrTokenStaticStruct( "]", "\"" );
	TokensStaticList.clear();
	TokensStaticList = tokensS;


	QList<FScrFunctionStruct*> functions;
	functions << new FScrFunctionStruct( "Ping", EScrFunctionList::ePing, false, false,
	{ }, EVariableTypeList::eString );
	functions << new FScrFunctionStruct( "SoundPlay", EScrFunctionList::eSoundPlay, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "NL", EScrFunctionList::eNL, false, false,
	{ }, EVariableTypeList::eString );

	functions << new FScrFunctionStruct( "BoolRand", EScrFunctionList::eMBoolRand, false, false,
	{ }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "NumRand", EScrFunctionList::eMNumRand, false, false,
	{ }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "NumRandR", EScrFunctionList::eMNumRandRange, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "NumAdd", EScrFunctionList::eMNumAdd, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "NumSub", EScrFunctionList::eMNumSub, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "NumMul", EScrFunctionList::eMNumMul, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "NumDiv", EScrFunctionList::eMNumDiv, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "NumMod", EScrFunctionList::eMNumMod, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, EVariableTypeList::eInt );

	functions << new FScrFunctionStruct( "ReadFileLine", EScrFunctionList::eIOReadFileLine, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eString );
	functions << new FScrFunctionStruct( "ReadRandLine", EScrFunctionList::eIOReadRandLine, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eString );
	functions << new FScrFunctionStruct( "SaveFileLine", EScrFunctionList::eIOSaveFileLine, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "SaveFileLastLine", EScrFunctionList::eIOSaveFileLastLine, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "SaveFileOverwrite", EScrFunctionList::eIOSaveFileOverwrite, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "ReadWeb", EScrFunctionList::eIOReadWeb, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eString );
	functions << new FScrFunctionStruct( "ReadWebLine", EScrFunctionList::eIOReadWebLine, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eString );

	functions << new FScrFunctionStruct( "UserGroupGet", EScrFunctionList::eUserGroupGet, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eString );
	functions << new FScrFunctionStruct( "UserGroupAdd", EScrFunctionList::eUserGroupAdd, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserGroupRem", EScrFunctionList::eUserGroupRem, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserRankGet", EScrFunctionList::eUserRankGet, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eString );
	functions << new FScrFunctionStruct( "UserRankSet", EScrFunctionList::eUserRankSet, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );

	functions << new FScrFunctionStruct( "EventStart", EScrFunctionList::eEventStart, false, true,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "EventEnd", EScrFunctionList::eEventEnd, false, true,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "EventOpen", EScrFunctionList::eEventOpen, false, true,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "EventClose", EScrFunctionList::eEventClose, false, true,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "EventUserJoin", EScrFunctionList::eEventUserJoin, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "EventUserLeave", EScrFunctionList::eEventUserLeave, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "EventUserSet", EScrFunctionList::eEventUserSet, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "EventUserRem", EScrFunctionList::eEventUserRem, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );

	functions << new FScrFunctionStruct( "UserPointsGet", EScrFunctionList::eUserPointsGet, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eBool }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "UserPointsAdd", EScrFunctionList::eUserPointsAdd, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserPointsSub", EScrFunctionList::eUserPointsSub, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserPointsSet", EScrFunctionList::eUserPointsSet, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserPointsGive", EScrFunctionList::eUserPointsGive, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "UserCurrencyGet", EScrFunctionList::eUserCurrencyGet, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eBool }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "UserCurrencyAdd", EScrFunctionList::eUserCurrencyAdd, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserCurrencySub", EScrFunctionList::eUserCurrencySub, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserCurrencySet", EScrFunctionList::eUserCurrencySet, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserCurrencyGive", EScrFunctionList::eUserCurrencyGive, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "UserTicketsGet", EScrFunctionList::eUserTicketsGet, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eBool }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "UserTicketsAdd", EScrFunctionList::eUserTicketsAdd, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserTicketsSub", EScrFunctionList::eUserTicketsSub, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserTicketsSet", EScrFunctionList::eUserTicketsSet, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserTicketsGive", EScrFunctionList::eUserTicketsGive, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "UserKeysGet", EScrFunctionList::eUserKeysGet, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eBool }, EVariableTypeList::eInt );
	functions << new FScrFunctionStruct( "UserKeysAdd", EScrFunctionList::eUserKeysAdd, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserKeysSub", EScrFunctionList::eUserKeysSub, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserKeysSet", EScrFunctionList::eUserKeysSet, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "UserKeysGive", EScrFunctionList::eUserKeysGive, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eBool );

	functions << new FScrFunctionStruct( "MGChest", EScrFunctionList::eMGChest, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "MGChestSpawn", EScrFunctionList::eMGChestSpawn, false, true,
	{ EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "MGDiceRoll", EScrFunctionList::eMGDiceRoll, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "MGQAQuestion", EScrFunctionList::eMGQAQuestion, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "MGQAAnswer", EScrFunctionList::eMGQAAnswer, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );
	functions << new FScrFunctionStruct( "MGPianoPlay", EScrFunctionList::eMGPianoPlay, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, EVariableTypeList::eVoid );

	functions << new FScrFunctionStruct( "RPGJoin", EScrFunctionList::eRPGJoin, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eBool );
	functions << new FScrFunctionStruct( "RPGLeave", EScrFunctionList::eRPGLeave, false, false,
	{ EVariableTypeList::eString }, EVariableTypeList::eBool );

	qDeleteAll(FunctionsList);
	FunctionsList.clear();
	FunctionsList = functions;

	//gmMachine machine;

	// Table of functions to register
	//regFuncList

	//machine.RegisterLibrary(regFuncList, sizeof(regFuncList) / sizeof(regFuncList[0]));

	int funcSize = FunctionsList.size();
	for( int i = 0; i < funcSize; i++ ) {
		//{ FunctionsList[i]->functionName, ScrFuncPingT }
	}
}

bool Scripting::LoadScriptingScripts() {
	QJsonObject fileJSON;
	if ( !GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eCommon ) ) { return false; }
	if ( !LoadScriptGlobalVars( fileJSON ) ) { return false; }
	return true;
}

bool Scripting::LoadScriptGlobalVars( QJsonObject _File ) {
	qDebug() << "Read & Load Global Vars";
	QList<FScrGlobalVarStruct*> variables;
	QJsonArray variablesArray = _File["Common"].toObject()["Variables"].toArray();
	if ( !variablesArray.isEmpty() ) {
		for (int i = 0; i < variablesArray.size(); i++) {
			FScrGlobalVarStruct* variable = new FScrGlobalVarStruct;
			variable->name = variablesArray[i].toObject()["Name"].toString();
			variable->nameID = variable->name;
			QString type = variablesArray[i].toObject()["Type"].toString();
			if ( type.contains( "Int", Qt::CaseInsensitive ) ) {
				variable->type = EVariableTypeList::eInt;
				QString value = variablesArray[i].toObject()["Value"].toString();
				if ( value == "" || value == " " || value.isNull() || value.isEmpty() ) {

				} else {
					bool vconv = false;
					int val = value.toInt(&vconv);
					if ( vconv ) {
						variable->valueLogic = val;
						variable->value = value;
					} else {
						// Todo display warning
					}
				}
			} else if ( type.contains( "Float", Qt::CaseInsensitive ) ) {
				variable->type = EVariableTypeList::eFloat;
				QString value = variablesArray[i].toObject()["Value"].toString();
				if ( value == "" || value == " " || value.isNull() || value.isEmpty() ) {

				} else {
					bool vconv = false;
					float val = value.toFloat(&vconv);
					if ( vconv ) {
						variable->valueLogic = val;
						variable->value = value;
					} else {
						// Todo display warning
					}
				}
			} else if ( type.contains( "String", Qt::CaseInsensitive ) ) {
				variable->type = EVariableTypeList::eString;
				QString value = variablesArray[i].toObject()["Value"].toString();
				if ( value == "" || value == " " || value.isNull() || value.isEmpty() ) {

				} else {
					bool vconv = true;
					if ( vconv ) {
						variable->valueLogic = 0.0;
						variable->value = value;
					} else {
						// Todo display warning
					}
				}
			} else if ( type.contains( "Bool", Qt::CaseInsensitive ) ) {
				variable->type = EVariableTypeList::eBool;
				QString value = variablesArray[i].toObject()["Value"].toString();
				if ( value == "" || value == " " || value.isNull() || value.isEmpty() ) {

				} else {
					bool vconv = false;
					float val = 0.0;
					if ( value.contains( "True", Qt::CaseInsensitive ) || value.contains( "1", Qt::CaseInsensitive ) ) {
						val = 1.0;
						vconv = true;
					} else if ( value.contains( "False", Qt::CaseInsensitive ) || value.contains( "0", Qt::CaseInsensitive ) ) {
						val = 0.0;
						vconv = true;
					} else {
						vconv = false;
					}
					if ( vconv ) {
						variable->valueLogic = val;
						variable->value = value;
					} else {
						// Todo display warning
					}
				}
			} else {
				return false;
			}
			variables << variable;
		}
	}
	ClearGlobalVarsArray(GlobalVarsList);
	//qDeleteAll(GlobalVars);
	//GlobalVars.clear();
	GlobalVarsList = variables;
	// Because the errors already has been pulled
	return true;
}

// At call this command, before the inputs need to be verified by other function
/*
bool Scripting::ValidateCommandScript( bool _Runtime, QString _Script, FCommandStruct* _Command, FUserStruct* _User ) {
	QString lString = _Script;


	//lString.replace()

	EScrTokenList tokenID;
	QString prefix = "$";
	// First replace the inputs in the script with given values
	// User info
	if( lString.contains( prefix + "Username", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Username", _User->name, Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Points", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Points", QString::number(_User->pointsNum), Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Currency", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Currency", QString::number(_User->currencyNum), Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Tickets", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Tickets", QString::number(_User->ticketsNum), Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Tickets", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Tickets", QString::number(_User->ticketsNum), Qt::CaseInsensitive );
	}


	switch( tokenID ) {
		case EScrTokenList::eChannelN:
			break;
		case EScrTokenList::eUserN:
			break;
		case EScrTokenList::ePointsN:
			break;
		case EScrTokenList::eCurrencyN:
			break;
		case EScrTokenList::eTicketsN:
			break;
		case EScrTokenList::eKeysN:
			break;
		case EScrTokenList::ePoints:
			break;
		case EScrTokenList::eCurrency:
			break;
		case EScrTokenList::eTickets:
			break;
		case EScrTokenList::eKeys:
			break;
		case EScrTokenList::eNone:
		default:

			break;
	}

	// Inputs info and other info
	if( lString.contains( prefix + "Target", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Target", _User->name, Qt::CaseInsensitive );
	}
	for( int i = 0; i < 10; i++ ) {
		if ( lString.contains( prefix + "Inp" + QString::number(i), Qt::CaseInsensitive ) ) {
			lString = lString.replace( prefix + "Inp" + QString::number(i), userCommand->inputs[i].inputs[0], Qt::CaseInsensitive );
		}
	}

	// Replace global vars values
	for( int i = 0; i < GlobalVars.size(); i++ ) {
		if( lString.contains( prefix + GlobalVars[i]->name, Qt::CaseInsensitive ) ) {
			QString type;
			switch( GlobalVars[i]->type )   {
				case EVariableTypeList::eBool:
					type = (qFloor(GlobalVars[i]->valueLogic) == 1 ? "True" : "False");
					break;
				case EVariableTypeList::eFloat:
					type = QString::number(GlobalVars[i]->valueLogic);
					break;
				case EVariableTypeList::eInt:
					type = QString::number(qFloor(GlobalVars[i]->valueLogic));
					break;
				case EVariableTypeList::eString:
					type = GlobalVars[i]->value;
					break;
			}
			lString = lString.replace( prefix + GlobalVars[i]->name, GlobalVars[i]->value, Qt::CaseInsensitive );
		}
	}

	// After this check and divide each function to check individually and calculate individually

	QString lChar;
	int lStringSize = lString.size();

	for( int c = 0; c < lStringSize; c++  ) {

	}


}
*/
bool Scripting::ScriptValidateCommandScript( bool _Runtime, QString _Script, FCommandStruct* _Command, FUserStruct* _User ) {
	QString lString = _Script;


	//lString.replace()
	FUserStruct* user = _User;
	FUserStruct* userTarget = _User;
	FCommandStruct* command = _Command;
	EScrTokenList tokenID = EScrTokenList::eNone;
	QString prefix = "$";
	// First replace the inputs in the script with given values
	// User info
	if( lString.contains( prefix + "Username", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Username", _User->name, Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Points", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Points", QString::number(_User->pointsNum), Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Currency", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Currency", QString::number(_User->currencyNum), Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Tickets", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Tickets", QString::number(_User->ticketsNum), Qt::CaseInsensitive );
	}
	if( lString.contains( prefix + "Tickets", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Tickets", QString::number(_User->ticketsNum), Qt::CaseInsensitive );
	}


	QString value = "Error";
	switch( tokenID ) {
		case EScrTokenList::eChannelN:
			value = ScrTkGetChannelName();
			break;
		case EScrTokenList::eMasterN:
			value = ScrTkGetMasterName();
			break;
		case EScrTokenList::eOwnerN:
			value = ScrTkGetOwnerName();
			break;
		case EScrTokenList::eBotN:
			value = ScrTkGetBotName();
			break;
		case EScrTokenList::ePointsN:
			value = ScrTkGetPointsName();
			break;
		case EScrTokenList::eCurrencyN:
			value = ScrTkGetCurrencyName();
			break;
		case EScrTokenList::eTicketsN:
			value = ScrTkGetTicketsName();
			break;
		case EScrTokenList::eKeysN:
			value = ScrTkGetKeysName();
			break;
		case EScrTokenList::eUserN:
			value = ScrTkGetUserName( user );
			break;
		case EScrTokenList::eUserTargetN:
			value = ScrTkGetUserName( userTarget );
			break;
		case EScrTokenList::ePoints:
			value = ScrTkGetUserPoints( user );
			break;
		case EScrTokenList::eCurrency:
			value = ScrTkGetUserCurrency( user );
			break;
		case EScrTokenList::eTickets:
			value = ScrTkGetUserTickets( user );
			break;
		case EScrTokenList::eKeys:
			value = ScrTkGetUserKeys( user );
			break;
		case EScrTokenList::eNone:
		default:
			value = "Error";
			break;
	}

	// Inputs info and other info
	if( lString.contains( prefix + "Target", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Target", _User->name, Qt::CaseInsensitive );
	}
	for( int i = 0; i < 10; i++ ) {
		if ( lString.contains( prefix + "Inp" + QString::number(i), Qt::CaseInsensitive ) ) {
			//lString = lString.replace( prefix + "Inp" + QString::number(i), userCommand->inputs[i].inputs[0], Qt::CaseInsensitive );
		}
	}

	// Replace global vars values
	for( int i = 0; i < GlobalVarsList.size(); i++ ) {
		if( lString.contains( prefix + GlobalVarsList[i]->name, Qt::CaseInsensitive ) ) {
			QString type;
			switch( GlobalVarsList[i]->type )   {
				case EVariableTypeList::eBool:
					type = (qFloor(GlobalVarsList[i]->valueLogic) == 1 ? "True" : "False");
					break;
				case EVariableTypeList::eFloat:
					type = QString::number(GlobalVarsList[i]->valueLogic);
					break;
				case EVariableTypeList::eInt:
					type = QString::number(qFloor(GlobalVarsList[i]->valueLogic));
					break;
				case EVariableTypeList::eString:
					type = GlobalVarsList[i]->value;
					break;
			}
			lString = lString.replace( prefix + GlobalVarsList[i]->name, GlobalVarsList[i]->value, Qt::CaseInsensitive );
		}
	}

	// After this check and divide each function to check individually and calculate individually

	QString lChar;
	int lStringSize = lString.size();

	for( int c = 0; c < lStringSize; c++  ) {

	}
	return false;
}

//Script Validation

bool Scripting::ScriptValidateScrVarInput( FScrVarContainerStruct& _VarContainer, const QString _Input, const EVariableTypeList _Type ) {
	if( _Input == "" || _Input == " " || _Input.isNull() || _Input.isEmpty() ) {
		return false;
	}
	bool vconv = false;
	FScrVarContainerStruct var;
	switch( _Type ) {
		case EVariableTypeList::eBool:
		{
			bool val = false;
			if( _Input.contains( "True", Qt::CaseInsensitive ) || _Input.contains( "1", Qt::CaseInsensitive ) ) {
				val = true;
				vconv = true;
			} else if( _Input.contains( "False", Qt::CaseInsensitive ) || _Input.contains( "0", Qt::CaseInsensitive ) ) {
				val = false;
				vconv = true;
			} else {
				vconv = false;
			}
			if( vconv ) {
				var.varBool = val;
				var.varType = EVariableTypeList::eBool;
			} else {
				qDebug() << "Invalid value bool";
				return false;
			}
		}
			break;
		case EVariableTypeList::eFloat:
		{
			float val = _Input.toFloat(&vconv);
			if( vconv ) {
				var.varFloat = val;
				var.varType = EVariableTypeList::eFloat;
			} else {
				qDebug() << "Invalid value float";
				return false;
			}
		}
			break;
		case EVariableTypeList::eInt:
		{
			int val = _Input.toInt(&vconv);
			if( vconv ) {
				var.varInt = val;
				var.varType = EVariableTypeList::eInt;
			} else {
				qDebug() << "Invalid value int";
				return false;
			}
		}
			break;
		case EVariableTypeList::eString:
		{
			vconv = true;
			QString val = _Input;
			if( vconv ) {
				var.varString = val;
				var.varType = EVariableTypeList::eString;
			} else {
				qDebug() << "Invalid value string";
				return false;
			}
		}
			break;
	}
	if( vconv ) {
		_VarContainer = var;
		return true;
	} else {

		return false;
	}
}

bool Scripting::ScriptValidateScrVarArrayInputs( QList<FScrVarContainerStruct>& _VarContainer, QList<QString> _Inputs, QList<EVariableTypeList> _Types ) {
	int iSize = _Inputs.size(), tSize = _Types.size();
	if( iSize != tSize ) {
		// Invalid Size
		qDebug() << "Invalid Size on Function inputs";
		return false;
	}
	for( int i = 0; i < iSize; i++ ) {
		FScrVarContainerStruct var;
		if( ScriptValidateScrVarInput( var, _Inputs[i], _Types[i] ) ) {
			_VarContainer << var;
		} else {
			return false;
		}
	}
}

bool Scripting::ScrResolveUserByName( const QString _Name, FUserStruct* _User ) {
	FScrVarContainerStruct var;
	if( ScriptValidateScrVarInput( var, _Name, EVariableTypeList::eString ) ) {
		int listSize = Users::UsersList.size();
		for( int i = 0; i < listSize; i++ ) {
			if ( var.varString == Users::UsersList[i]->name ) {
				_User = Users::UsersList[i];
				return true;
			}
		}
		qDebug() << "Missing user";
		return false;
	} else {
		qDebug() << "Invalid name";
		return false;
	}
}

bool Scripting::ScrResolveGroupByName( const QString _Name, FUserGroupStruct* _Group ) {
	FScrVarContainerStruct var;
	if( ScriptValidateScrVarInput( var, _Name, EVariableTypeList::eString ) ) {
		int listSize = Users::UserGroupsList.size();
		for( int i = 0; i < listSize; i++ ) {
			if ( var.varString == Users::UserGroupsList[i]->name ) {
				_Group = Users::UserGroupsList[i];
				return true;
			}
		}
		qDebug() << "Missing user";
		return false;
	} else {
		qDebug() << "Invalid name";
		return false;
	}
}

bool Scripting::ScrResolveRankByName( const QString _Name, FUserRankStruct* _Rank ) {
	FScrVarContainerStruct var;
	if( ScriptValidateScrVarInput( var, _Name, EVariableTypeList::eString ) ) {
		int listSize = Users::UserRanksList.size();
		for( int i = 0; i < listSize; i++ ) {
			if ( var.varString == Users::UserRanksList[i]->name ) {
				_Rank = Users::UserRanksList[i];
				return true;
			}
		}
		qDebug() << "Missing user";
		return false;
	} else {
		qDebug() << "Invalid name";
		return false;
	}
}

bool Scripting::ScrResolveModuleByName( const QString _Name, FCommonModuleStruct* _Module ) {
	FScrVarContainerStruct var;
	if( ScriptValidateScrVarInput( var, _Name, EVariableTypeList::eString ) ) {
		int listSize = Common::ModulesList.size();
		for( int i = 0; i < listSize; i++ ) {
			if ( var.varString == Common::ModulesList[i]->name ) {
				_Module = Common::ModulesList[i];
				return true;
			}
		}
		qDebug() << "Missing user";
		return false;
	} else {
		qDebug() << "Invalid name";
		return false;
	}
}

bool Scripting::ScrResolveEventByName( const QString _Name, FCommonEventStruct* _Event ) {
	FScrVarContainerStruct var;
	if( ScriptValidateScrVarInput( var, _Name, EVariableTypeList::eString ) ) {
		int listSize = Common::EventsList.size();
		for( int i = 0; i < listSize; i++ ) {
			if ( var.varString == Common::EventsList[i]->name ) {
				_Event = Common::EventsList[i];
				return true;
			}
		}
		qDebug() << "Missing user";
		return false;
	} else {
		qDebug() << "Invalid name";
		return false;
	}
}


// Token Helpers
QString Scripting::ScrTkGetChannelName() {
	return Common::TwitchChannelName;
}

QString Scripting::ScrTkGetMasterName() {
	return Common::TwitchOwnerUsername;
}

QString Scripting::ScrTkGetOwnerName() {
	return Common::TwitchOwnerUsername;
}

QString Scripting::ScrTkGetBotName() {
	return Common::TwitchBotUsername;
}

QString Scripting::ScrTkGetPointsName() {
	return Common::PointsCustomName;
}

QString Scripting::ScrTkGetCurrencyName() {
	return Common::CurrencyCustomName;
}

QString Scripting::ScrTkGetTicketsName() {
	return Common::TicketsCustomName;
}

QString Scripting::ScrTkGetKeysName() {
	return Common::KeysCustomName;
}


bool Scripting::ScrTkGetUserTarget( QString _Name, FUserStruct* _Target ) {
	return ScrResolveUserByName( _Name, _Target );
}


QString Scripting::ScrTkGetUserName( FUserStruct* _User ) {
	return _User->name;
}

QString Scripting::ScrTkGetUserPoints( FUserStruct* _User ) {
	return QString::number(_User->pointsNum);
}

QString Scripting::ScrTkGetUserCurrency( FUserStruct* _User ) {
	return QString::number(_User->currencyNum);
}

QString Scripting::ScrTkGetUserTickets( FUserStruct* _User ) {
	return QString::number(_User->ticketsNum);
}

QString Scripting::ScrTkGetUserKeys( FUserStruct* _User ) {
	return QString::number(_User->keysNum);
}


bool Scripting::ScrFuncPing( QString& _Return ) {
	_Return = "Pong";
	return true;
}

bool Scripting::ScrFuncSoundPlay( bool& _Return, const QString _File ) {
	return false;
}

bool Scripting::ScrFuncNL( QString& _Return ) {
	_Return = "/n";
	return true;
}


bool Scripting::ScrFuncMBoolRand( bool& _Return ) {
	_Return = (SharedLib::RandIntInRange(0, 1) == 1 ? true : false);
	return true;
}

bool Scripting::ScrFuncMNumRand( int& _Return ) {
	_Return = SharedLib::RandIntInRange(0, 9999);
	return true;
}

bool Scripting::ScrFuncMNumRandRange( int& _Return, const int _Min, const int _Max ) {
	if ( _Min > _Max ) {
		_Return = SharedLib::RandIntInRange(_Max, _Min);
	} else {
		_Return = SharedLib::RandIntInRange(_Min, _Max);
	}
	return true;
}

bool Scripting::ScrFuncMNumAdd( int& _Return, const int _NumA, const int _NumB ) {
	_Return = _NumA + _NumB;
	return true;
}

bool Scripting::ScrFuncMNumSub( int& _Return, const int _NumA, const int _NumB ) {
	_Return = _NumA - _NumB;
	return true;
}

bool Scripting::ScrFuncMNumMul( int& _Return, const int _NumA, const int _NumB ) {
	_Return = _NumA * _NumB;
	return true;
}

bool Scripting::ScrFuncMNumDiv( int& _Return, const int _NumA, const int _NumB ) {
	_Return = _NumA / _NumB;
	return true;
}

bool Scripting::ScrFuncMNumMod( int& _Return, const int _NumA, const int _NumB ) {
	_Return = _NumA % _NumB;
	return true;
}


bool Scripting::ScrFuncIOReadFileLine( QString& _Return, const QString _File, const int _Line ) {
	return false;
}

bool Scripting::ScrFuncIOReadRandLine( QString& _Return, const QString _File ) {
	return false;
}

bool Scripting::ScrFuncIOSaveFileLine( bool& _Return, const QString _Text, const QString _File, const int _Line ) {
	return false;
}

bool Scripting::ScrFuncIOSaveFileLastLine( bool& _Return, const QString _Text, const QString _File ) {
	return false;
}

bool Scripting::ScrFuncIOSaveFileOverwrite( bool& _Return, const QString _Text, const QString _File ) {
	return false;
}

bool Scripting::ScrFuncIOReadWeb( QString& _Return, const QString _URL ) {
	return false;
}

bool Scripting::ScrFuncIOReadWebLine( QString& _Return, const QString _URL, const int _Line ) {
	return false;
}



bool Scripting::ScrFuncUserGroupGet( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool Scripting::ScrFuncUserGroupAdd( bool& _Return, FUserStruct* _User, FUserGroupStruct* _Group ) {
	return false;
}

bool Scripting::ScrFuncUserGroupRem( bool& _Return, FUserStruct* _User, FUserGroupStruct* _Group ) {
	return false;
}

bool Scripting::ScrFuncUserRankGet( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool Scripting::ScrFuncUserRankSet( bool& _Return, FUserStruct* _User, FUserRankStruct* _Rank ) {
	return false;
}



bool Scripting::ScrFuncEventStart( bool& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventEnd( bool& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventOpen( bool& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventClose( bool& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventUserJoin( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventUserLeave( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventUserSet( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}

bool Scripting::ScrFuncEventUserRem( bool& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}


bool Scripting::ScrFuncUserPointsGet( int& _Return, FUserStruct* _User, const bool _Total ) {
	if( _Total ) {
		_Return = _User->pointsNum + _User->pointsSpentNum;
	} else {
		_Return = _User->pointsNum;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserPointsAdd( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->pointsNum = qBound( 0, _User->pointsNum + amount, 999999 );
	_Return = true;
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserPointsSub( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->pointsNum = qBound( 0, _User->pointsNum - amount, 999999 );
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserPointsSet( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->pointsNum = amount;
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserPointsGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	if ( _UserSender->pointsNum >= amount ) {
		_UserSender->pointsNum = qBound( 0, _UserSender->pointsNum - amount, 999999 );
		_User->pointsNum = qBound( 0, _User->pointsNum - amount, 999999 );
	} else {
		_Return = false;
		return false;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserCurrencyGet( int& _Return, FUserStruct* _User, const bool _Total ) {
	if( _Total ) {
		_Return = _User->currencyNum + _User->currencySpentNum;
	} else {
		_Return = _User->currencyNum;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserCurrencyAdd( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->currencyNum = qBound( 0, _User->currencyNum + amount, 999999 );
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserCurrencySub( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->currencyNum = qBound( 0, _User->currencyNum - amount, 999999 );
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserCurrencySet( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->currencyNum = amount;
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserCurrencyGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	if ( _UserSender->currencyNum >= amount ) {
		_UserSender->currencyNum = qBound( 0, _UserSender->currencyNum - amount, 999999 );
		_User->currencyNum = qBound( 0, _User->currencyNum - amount, 999999 );
	} else {
		_Return = false;
		return false;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserTicketsGet( int& _Return, FUserStruct* _User, const bool _Total ) {
	if( _Total ) {
		_Return = _User->ticketsNum + _User->ticketsSpentNum;
	} else {
		_Return = _User->ticketsNum;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserTicketsAdd( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->ticketsNum = qBound(0, _User->ticketsNum + amount, 999999);
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserTicketsSub( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->ticketsNum = qBound(0, _User->ticketsNum - amount, 999999);
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserTicketsSet( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->ticketsNum = amount;
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserTicketsGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	if ( _UserSender->ticketsNum >= amount ) {
		_UserSender->ticketsNum = qBound( 0, _UserSender->ticketsNum - amount, 999999 );
		_User->ticketsNum = qBound( 0, _User->ticketsNum - amount, 999999 );
	} else {
		_Return = false;
		return false;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserKeysGet( int& _Return, FUserStruct* _User, const bool _Total ) {
	if( _Total ) {
		_Return = _User->keysNum + _User->keysSpentNum;
	} else {
		_Return = _User->keysNum;
	}
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserKeysAdd( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->keysNum = qBound(0, _User->keysNum + amount, 999999);
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserKeysSub( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->keysNum = qBound(0, _User->keysNum - amount, 999999);
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserKeysSet( bool& _Return, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	_User->keysNum = amount;
	_Return = true;
	return true;
}

bool Scripting::ScrFuncUserKeysGive( bool& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	int amount = qBound( 0, _Amount, 999999 );
	if ( _UserSender->keysNum >= amount ) {
		_UserSender->keysNum = qBound( 0, _UserSender->keysNum - amount, 999999 );
		_User->keysNum = qBound( 0, _User->keysNum - amount, 999999 );
	} else {
		_Return = false;
		return false;
	}
	_Return = true;
	return true;
}


bool Scripting::ScrFuncMGChest( bool& _Return, FUserStruct* _User ) {
	return false;
}

bool Scripting::ScrFuncMGChestSpawn( bool& _Return, FUserStruct* _User ) {
	if( MiniGames::ChestEnabled ) {
		if( MiniGames::ChestToPick ) {
			MiniGames::ChestToPick = false;
			_User->pointsNum = _User->pointsNum + MiniGames::ChestPoints;
			_User->currencyNum = _User->currencyNum + MiniGames::ChestCurrency;
			_User->ticketsNum = _User->ticketsNum + MiniGames::ChestTickets;
			_User->keysNum = _User->keysNum + MiniGames::ChestKeys;
		} else {

		}
	}

	return false;
}

bool Scripting::ScrFuncMGDiceRoll( int& _Return, FUserStruct* _User, const int _Sides ) {
	_Return = SharedLib::RandIntInRange(0, _Sides);
	return true;
}

bool Scripting::ScrFuncMGQAQuestion( bool& _Return, FUserStruct* _User, const QString _Question ) {
	return false;
}

bool Scripting::ScrFuncMGQAAnswer( bool& _Return, FUserStruct* _User, const QString _Answer ) {
	return false;
}

bool Scripting::ScrFuncMGPianoPlay( bool& _Return, FUserStruct* _User, const QString _Keys ) {
	return false;
}

bool Scripting::ScrFuncRPGJoin( bool& _Return, FUserStruct* _User ) {
	return false;
}

bool Scripting::ScrFuncRPGLeave( bool& _Return, FUserStruct* _User ) {
	return false;
}

