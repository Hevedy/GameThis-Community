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


#include "Commands.h"

QList<FCommandFunctionStruct> Commands::FunctionsList;
QList<FCommandLinkStruct> Commands::CommandsList;

//QList<FCommandDiceStruct> Commands::DiceCommands;
//QList<FCommandSkillStruct> Commands::SkillCommands;
QList<FCommandStruct> Commands::GeneralCommandsList;
QList<FCommandAutoStruct> Commands::AutoCommandsList;
QList<FCommandTriggerStruct> Commands::TriggerCommandsList;


Commands::Commands(QObject *parent) : QObject(parent)
{

}

bool Commands::init() {
	if( !ReadCommands() ) { return false; }
	
}

bool Commands::ReadCommands() {
	qDebug() << "Read Commands";
	//ReadDiceCommands( DiceCommands, result );
	//if ( !result ) { _Result = result; return; }
	//ReadSkillCommands( SkillCommands, result );
	//if ( !result ) { _Result = result; return; }
	if( !ReadGeneralCommands( GeneralCommandsList ) ) { return false; }
	if( !ReadAutoCommands( AutoCommandsList ) ) { return false; }
	if( !ReadTriggerCommands( TriggerCommandsList ) ) { return false; }

	return true;
}

/*
void Commands::ReadDiceCommands( QList<FCommandDiceStruct>& _Commands, bool& _Result ) {
	QJsonObject fileJSON;
	bool result = GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eCommands );
	if ( !result ) { return; }


	for (int i = 0; i < fileJSON["DiceCommands"].toArray().size(); ++i) {
		QJsonObject workObj = fileJSON["DiceCommands"].toArray()[i].toObject();
		FCommandDiceStruct workCommand;
		QList<QString> functionList;
		QList<QString> functionValueList;
		QList<bool> boolMixedList;
		QList<bool> intInfiniteList;
		QList<bool> floatInfiniteList;
		bool blocalResult = false;
		workCommand.Name = workObj["Name"].toString();
	for (int ii = 0; ii < workObj["Command"].toArray().size(); ++ii) {
		workCommand.Commands << workObj["Command"].toArray()[i].toString();
	}
	workCommand.bInputNeeded = GameFunctions::STRToBool( workObj["InputNeeded"].toString(),
		 false, functionList, functionValueList, boolMixedList, blocalResult )[0];
	workCommand.Name = workObj["InputDefault"].toString();
	for (int ii = 0; ii < workObj["GroupsLocked"].toArray().size(); ++ii) {
		workObj["GroupsLocked"].toArray()[i].toString();
	}
	for (int ii = 0; ii < workObj["GroupsLocked"].toArray().size(); ++ii) {
		workObj["GroupsLocked"].toArray()[i].toString();
	}

	}

	_Result = true;
}

void Commands::ReadSkillCommands( QList<FCommandSkillStruct>& _Commands, bool& _Result ) {

}
*/
bool Commands::ReadGeneralCommands( QList<FCommandStruct>& _Commands ) {
	qDebug() << "Read Piano";
	QJsonObject fileJSON;
	if( !GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eCommands ) ) { return false; }
	QList<FCommandStruct> commands;
	for (int i = 0; i < fileJSON["PianoCommands"].toArray().size(); i++) {
		QJsonObject workObj = fileJSON["PianoCommands"].toArray()[i].toObject();
		FCommandStruct workCommand;
		QList<QString> functionList;
		QList<QString> functionValueList;
		QList<bool> boolMixedList;
		QList<bool> intInfiniteList;
		QList<bool> floatInfiniteList;
		bool blocalResult = false;
		workCommand.name = workObj["Name"].toString();

		if ( workObj["Command"].toArray().size() > 0 ) {
			for (int ii = 0; ii < workObj["Command"].toArray().size(); ii++) {
				workCommand.commands << workObj["Command"].toArray()[ii].toString();
			}
		}
		if ( workObj["GroupsLocked"].toArray().size() > 0 ) {

			for (int ii = 0; ii < workObj["GroupsLocked"].toArray().size(); ii++) {
				//workCommand.groupsLocked << workObj["GroupsLocked"].toArray()[ii].toString();
			}
		}
		if ( workObj["RanksLocked"].toArray().size() > 0 ) {

			for (int ii = 0; ii < workObj["RanksLocked"].toArray().size(); ii++) {
				//workCommand.ranksLocked << workObj["RanksLocked"].toArray()[ii].toString();
			}
		}
		if ( workObj["Text"].toArray().size() > 0 ) {

			for (int ii = 0; ii < workObj["Text"].toArray().size(); ii++) {
				workCommand.returns << workObj["Text"].toArray()[ii].toString();
			}
		}
		commands << workCommand;
	}
	_Commands = commands;
	return true;

}
bool Commands::ReadAutoCommands( QList<FCommandAutoStruct>& _Commands ) {
	return false;
}

bool Commands::ReadTriggerCommands( QList<FCommandTriggerStruct>& _Commands ) {
	return false;

}
