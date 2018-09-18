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


#include "Scripting.h"


QList<FScrFunctionStruct*> Scripting::Functions;

QList<FScrModuleStruct*> Scripting::Modules;
QList<FScrGlobalVarStruct*> Scripting::GlobalVars;


Scripting::Scripting(QObject *parent) : QObject(parent)
{

}

void Scripting::init() {
	AddCoreFunctions();
	LoadScriptingScripts();

}

void Scripting::AddCoreFunctions() {
	// Implicits = $username, $inp1
	// functions return true, false and the text split by /

	// Cuando leas los comandos leer desde el ultimo por si depende del anterior
	QList<FScrFunctionStruct*> functions;

	functions << new FScrFunctionStruct( ".Ping()", EScrFunctionList::ePing, false, false, { }, false );
	functions << new FScrFunctionStruct( ".Chest()", EScrFunctionList::ePing, false, false, { }, true );
	functions << new FScrFunctionStruct( ".JoinRPG()", EScrFunctionList::ePing, false, false, { }, true );
	functions << new FScrFunctionStruct( ".LeaveRPG()", EScrFunctionList::ePing, false, false, { }, true );
	functions << new FScrFunctionStruct( ".Dice()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eBool }, true );
	functions << new FScrFunctionStruct( ".RandBool()", EScrFunctionList::ePing, false, false, { }, false );
	functions << new FScrFunctionStruct( ".RandNum()", EScrFunctionList::ePing, false, false, { }, false );
	functions << new FScrFunctionStruct( ".RandNumRange()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eInt, EVariableTypeList::eInt }, true );
	functions << new FScrFunctionStruct( ".Piano()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt, EVariableTypeList::eInt }, true );
	functions << new FScrFunctionStruct( ".PlaySound()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString }, true );
	functions << new FScrFunctionStruct( ".QuestionA()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString }, true );
	functions << new FScrFunctionStruct( ".QAnswer()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eString }, true );
	// Line jump
	functions << new FScrFunctionStruct( ".NL()", EScrFunctionList::ePing, false, false, { }, false );
	// Get channel name
	functions << new FScrFunctionStruct( ".Channel()", EScrFunctionList::ePing, false, false, { }, false );
	// Get user name that used the command
	functions << new FScrFunctionStruct( ".UserName()", EScrFunctionList::ePing, false, false, { }, false );
	// Get currency name
	functions << new FScrFunctionStruct( ".PointsName()", EScrFunctionList::ePing, false, false, { }, false );
	// Get user currency from who used the command
	functions << new FScrFunctionStruct( ".Points()", EScrFunctionList::ePing, false, false, { }, false );
	// Give to x user x number currency
	functions << new FScrFunctionStruct( ".PointsGive()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	// Add points
	functions << new FScrFunctionStruct( ".PointsAdd()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	// Get currency name
	functions << new FScrFunctionStruct( ".CurrencyName()", EScrFunctionList::ePing, false, false, { }, false );
	// Get user currency from who used the command
	functions << new FScrFunctionStruct( ".Currency()", EScrFunctionList::ePing, false, false, { }, false );
	// Give to x user x number currency
	functions << new FScrFunctionStruct( ".CurrencyGive()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	functions << new FScrFunctionStruct( ".CurrencyAdd()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	functions << new FScrFunctionStruct( ".TicketsName()", EScrFunctionList::ePing, false, false, { }, false );
	functions << new FScrFunctionStruct( ".Tickets()", EScrFunctionList::ePing, false, false, { }, false );
	functions << new FScrFunctionStruct( ".TicketsGive()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	functions << new FScrFunctionStruct( ".TicketsAdd()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	// API will mean JSON, to be added in the future to read from web or files JSON
	// Read file x line
	functions << new FScrFunctionStruct( ".ReadFileLine()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	// Read file random line
	functions << new FScrFunctionStruct( ".ReadFileRandLine()", EScrFunctionList::ePing, false, false,
	{ EVariableTypeList::eString }, true );
	// Save to file x line if no x then last
	functions << new FScrFunctionStruct( ".SaveFileLine()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	// Save to file to the last line
	functions << new FScrFunctionStruct( ".SaveFileLastLine()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString }, true );
	// Save to file and replace
	functions << new FScrFunctionStruct( ".SaveFileOverwrite()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );
	// Read web text
	functions << new FScrFunctionStruct( ".ReadWeb()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString }, true );
	// Read web line
	functions << new FScrFunctionStruct( ".ReadWebLine()", EScrFunctionList::ePing, false, true,
	{ EVariableTypeList::eString, EVariableTypeList::eInt }, true );

	qDeleteAll(Functions); // Prevent leaks of pointers keep on nowhere
	Functions.clear();
	Functions = functions;
}

bool Scripting::LoadScriptingScripts() {
	QJsonObject fileJSON;
	if ( GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eCommon ) ) { return false; }
	if ( !LoadScriptGlobalVars( fileJSON ) ) { return false; }
	return true;
}

bool Scripting::LoadScriptGlobalVars( QJsonObject _File ) {
	qDebug() << "Read & Load Global Vars";
	QList<FScrGlobalVarStruct*> variables;
	QJsonArray variablesArray = _File["Common"].toObject()["Variables"].toArray();
	if ( !variablesArray.isEmpty() ) {
		for (int i = 0; i < variablesArray.size(); i++) {
			FScrGlobalVarStruct* variable;
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
	qDeleteAll(GlobalVars);
	GlobalVars.clear();
	GlobalVars = variables;
	// Because the errors already has been pulled
	return true;
}

// At call this command, before the inputs need to be verified by other function
bool Scripting::ValidateCommandScript( bool _Runtime, QString _Script, FCommandStruct* _Command, FUserStruct* _User ) {
	QString lString = _Script;


	//lString.replace()

	EScrTokenList tokenID;
	QString prefix = "$";
	// First replace the inputs in the script with given values
	// User info
	if ( lString.contains( prefix + "Username", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Username", _User->name, Qt::CaseInsensitive );
	}
	if ( lString.contains( prefix + "Points", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Points", QString::number(_User->pointsNum), Qt::CaseInsensitive );
	}
	if ( lString.contains( prefix + "Currency", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Currency", QString::number(_User->currencyNum), Qt::CaseInsensitive );
	}
	if ( lString.contains( prefix + "Tickets", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Tickets", QString::number(_User->ticketsNum), Qt::CaseInsensitive );
	}
	if ( lString.contains( prefix + "Tickets", Qt::CaseInsensitive ) ) {
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
	if ( lString.contains( prefix + "Target", Qt::CaseInsensitive ) ) {
		lString = lString.replace( prefix + "Target", _User->name, Qt::CaseInsensitive );
	}
	for ( int i = 0; i < 10; i++ ) {
		if ( lString.contains( prefix + "Inp" + QString::number(i), Qt::CaseInsensitive ) ) {
			lString = lString.replace( prefix + "Inp" + QString::number(i), userCommand->inputs[i].inputs[0], Qt::CaseInsensitive );
		}
	}

	// Replace global vars values
	for ( int i = 0; i < GlobalVars.size(); i++ ) {
		if ( lString.contains( prefix + GlobalVars[i]->name, Qt::CaseInsensitive ) ) {
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

	for ( int c = 0; c < lStringSize; c++  ) {

	}

	switch ( lChar ) {
		case "":
			break;
	}
}

bool Scripting::ScrFuncPing( QString& _Return ) {
	_Return = "Pong";
	return true;
}

bool Scripting::ScrFuncChest( QString& _Return, FUserStruct* _User ) {
	if ( Common::MGChestEnabled ) {
		if ( Common::MGChestToPick ) {
			Common::MGChestToPick = false;
			_User->pointsNum = _User->pointsNum + Common::MGChestPoints;
			_User->currencyNum = _User->currencyNum + Common::MGChestCurrency;
			_User->ticketsNum = _User->ticketsNum + Common::MGChestTickets;
		} else {

		}
	}
}

bool Scripting::ScrFuncJoinRPG( QString& _Return, FUserStruct* _User ) {
	if ( RPG::bPlayersCanJoin ) {

	}
}

bool Scripting::ScrFuncLeaveRPG( QString& _Return, FUserStruct* _User ) {

}

bool Scripting::ScrFuncDice( QString& _Return, QString _Sides ) {
	int sides = 0;
	bool result = false;
	sides = _Sides.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	_Return = QString::number(SharedLib::RandIntInRange(0, sides));
	return result;
}

bool Scripting::ScrFuncRandBool( QString& _Return ) {
	_Return = (QString::number(SharedLib::RandIntInRange(0, 1)) == 1 ? "True" : "False");
	return true;
}

bool Scripting::ScrFuncRandNum( QString& _Return ) {
	_Return = QString::number(SharedLib::RandIntInRange(0, 9999));
	return true;
}

bool Scripting::ValidateScrVarInput( FScrVarContainerStruct& _VarContainer, const QString _Input, const EVariableTypeList _Type ) {
	if ( _Input == "" || _Input == " " || _Input.isNull() || _Input.isEmpty() ) {
		return false;
	}
	bool vconv = false;
	FScrVarContainerStruct var;
	switch ( _Type ) {
		case EVariableTypeList::eBool:
		{
			bool val = false;
			if ( _Input.contains( "True", Qt::CaseInsensitive ) || _Input.contains( "1", Qt::CaseInsensitive ) ) {
				val = true;
				vconv = true;
			} else if ( _Input.contains( "False", Qt::CaseInsensitive ) || _Input.contains( "0", Qt::CaseInsensitive ) ) {
				val = false;
				vconv = true;
			} else {
				vconv = false;
			}
			if ( vconv ) {
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
			if ( vconv ) {
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
			if ( vconv ) {
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
			if ( vconv ) {
				var.varString = val;
				var.varType = EVariableTypeList::eString;
			} else {
				qDebug() << "Invalid value string";
				return false;
			}
		}
			break;
	}
	if ( vconv ) {
		_VarContainer = var;
		return true;
	} else {

		return false;
	}
}

bool Scripting::ValidateScrVarArrayInputs( QList<FScrVarContainerStruct>& _VarContainer, QList<QString> _Inputs, QList<EVariableTypeList> _Types ) {
	int iSize = _Inputs.size(), tSize = _Types.size();
	if ( iSize != tSize ) {
		// Invalid Size
		qDebug() << "Invalid Size on Function inputs";
		return false;
	}
	for ( int i = 0; i < iSize; i++ ) {
		FScrVarContainerStruct var;
		if ( ValidateScrVarInput( var, _Inputs[i], _Types[i] ) ) {
			_VarContainer << var;
		} else {
			return false;
		}
	}

}

bool Scripting::ScrFuncRandNumRange( QString& _Return, QString _NumA, QString _NumB ) {
	int numA = 0, numB = 0;
	bool result = false;
	numA = _NumA.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	numB = _NumB.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	_Return = QString::number(SharedLib::RandIntInRange(numA, numB));
	return result;
}

bool Scripting::ScrFuncAddNum( QString& _Return, QString _NumA, QString _NumB ) {
	int numA = 0, numB = 0;
	bool result = false;
	numA = _NumA.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	numB = _NumB.toInt(&result);
	if( !result ) { _Return = ""; return false; }

	_Return = QString::number(numA + numB);
	return result;
}

bool Scripting::ScrFuncSubNum( QString& _Return, QString _NumA, QString _NumB ) {
	int numA = 0, numB = 0;
	bool result = false;
	numA = _NumA.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	numB = _NumB.toInt(&result);
	if( !result ) { _Return = ""; return false; }

	_Return = QString::number(numA - numB);
	return result;
}

bool Scripting::ScrFuncMulNum( QString& _Return, QString _NumA, QString _NumB ) {
	int numA = 0, numB = 0;
	bool result = false;
	numA = _NumA.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	numB = _NumB.toInt(&result);
	if( !result ) { _Return = ""; return false; }

	_Return = QString::number(numA * numB);
	return result;
}

bool Scripting::ScrFuncDivNum( QString& _Return, QString _NumA, QString _NumB ) {
	int numA = 0, numB = 0;
	bool result = false;
	numA = _NumA.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	numB = _NumB.toInt(&result);
	if( !result ) { _Return = ""; return false; }

	_Return = QString::number(numA / numB);
	return result;
}

bool Scripting::ScrFuncModNum( QString& _Return, QString _NumA, QString _NumB ) {
	int numA = 0, numB = 0;
	bool result = false;
	numA = _NumA.toInt(&result);
	if( !result ) { _Return = ""; return false; }
	numB = _NumB.toInt(&result);
	if( !result ) { _Return = ""; return false; }

	_Return = QString::number(numA % numB);
	return result;
}


bool ScrResolveUserByName( const QString _Name, FUserStruct* _User ) {
	return false;
}

bool ScrResolveGroupByName( const QString _Name, FUserGroupStruct* _Group ) {
	return false;
}

bool ScrResolveRankByName( const QString _Name, FUserRankStruct* _Rank ) {
	return false;
}

bool ScrResolveModuleByName( const QString _Name, FCommonModuleStruct* _Event ) {
	return false;
}

bool ScrResolveEventByName( const QString _Name, FCommonEventStruct* _Event ) {
	return false;
}


//
// SCR TOKENS
//

// Token Helpers
QString ScrTkGetChannelName() {
	return false;
}

QString ScrTkGetPointsName() {
	return false;
}

QString ScrTkGetCurrencyName() {
	return false;
}

QString ScrTkGetTicketsName() {
	return false;
}

QString ScrTkGetKeysName() {
	return false;
}


bool ScrTkGetUserTarget( QString _Name, FUserStruct& _Target ) {
	return false;
}


QString ScrTkGetUserName( FUserStruct* _User ) {
	return false;
}

QString ScrTkGetUserPoints( FUserStruct* _User ) {
	return false;
}

QString ScrTkGetUserCurrency( FUserStruct* _User ) {
	return false;
}

QString ScrTkGetUserTickets( FUserStruct* _User ) {
	return false;
}

QString ScrTkGetUserKeys( FUserStruct* _User ) {
	return false;
}



bool ScrFuncPing( QString& _Return ) {
	return false;
}

bool ScrFuncSoundPlay( QString& _Return, const QString _File ) {
	return false;
}

bool ScrFuncNL( QString& _Return ) {
	return false;
}


bool ScrFuncMBoolRand( QString& _Return ) {
	return false;
}

bool ScrFuncMNumRand( QString& _Return ) {
	return false;
}

bool ScrFuncMNumRandRange( QString& _Return, const QString _Min, const QString _Max ) {
	return false;
}

bool ScrFuncMNumAdd( QString& _Return, const QString _NumA, const QString _NumB ) {
	return false;
}

bool ScrFuncMNumSub( QString& _Return, const QString _NumA, const QString _NumB ) {
	return false;
}

bool ScrFuncMNumMul( QString& _Return, const QString _NumA, const QString _NumB ) {
	return false;
}

bool ScrFuncMNumDiv( QString& _Return, const QString _NumA, const QString _NumB ) {
	return false;
}

bool ScrFuncMNumMod( QString& _Return, const QString _NumA, const QString _NumB ) {
	return false;
}


bool ScrFuncIOReadFileLine( QString& _Return, const QString _File, const int _Line ) {
	return false;
}

bool ScrFuncIOReadRandLine( QString& _Return, const QString _File ) {
	return false;
}

bool ScrFuncIOSaveFileLine( const QString _Text, const QString _File, const int _Line ) {
	return false;
}

bool ScrFuncIOSaveFileLastLine( const QString _Text, const QString _File ) {
	return false;
}

bool ScrFuncIOSaveFileOverwrite( const QString _Text, const QString _File ) {
	return false;
}

bool ScrFuncIOReadWeb( QString& _Return, const QString _URL ) {
	return false;
}

bool ScrFuncIOReadWebLine( QString& _Return, const QString _URL, const int _Line ) {
	return false;
}



bool ScrFuncUserGroupGet( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncUserGroupAdd( QString& _Return, FUserStruct* _User, FUserGroupStruct* _Group ) {
	return false;
}

bool ScrFuncUserGroupRem( QString& _Return, FUserStruct* _User, FUserGroupStruct* _Group ) {
	return false;
}

bool ScrFuncUserRankGet( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncUserRankSet( QString& _Return, FUserStruct* _User, FUserRankStruct* _Rank ) {
	return false;
}



bool ScrFuncEventStart( QString& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventEnd( QString& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventOpen( QString& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventClose( QString& _Return, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventUserJoin( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventUserLeave( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventUserSet( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}

bool ScrFuncEventUserRem( QString& _Return, FUserStruct* _User, FCommonEventStruct* _Event ) {
	return false;
}



bool ScrFuncUserPointsGet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserPointsAdd( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserPointsSub( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserPointsSet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserPointsGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserCurrencyGet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserCurrencyAdd( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserCurrencySub( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserCurrencySet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserCurrencyGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserTicketsGet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserTicketsAdd( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserTicketsSub( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserTicketsSet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserTicketsGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserKeysGet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserKeysAdd( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserKeysSub( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserKeysSet( QString& _Return, FUserStruct* _User, const int _Amount ) {
	return false;
}

bool ScrFuncUserKeysGive( QString& _Return, FUserStruct* _UserSender, FUserStruct* _User, const int _Amount ) {
	return false;
}


bool ScrFuncMGChest( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncMGChestSpawn( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncMGDiceRoll( QString& _Return, FUserStruct* _User, const int _Sides ) {
	return false;
}

bool ScrFuncMGQAQuestion( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncMGQAAnswer( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncMGPianoPlay( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncRPGJoin( QString& _Return, FUserStruct* _User ) {
	return false;
}

bool ScrFuncRPGLeave( QString& _Return, FUserStruct* _User ) {
	return false;
}
