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


#include "GCommand.h"
#include "Game.h"

GCommand::GCommand(QObject *parent) : QObject(parent)
{

}

void GCommand::Init() {
	
	
}

void GCommand::ReadCommands( bool& bResult ) {
	bool bresult = false;
	ReadDiceCommands( DiceCommands, bresult );
	if ( !bresult ) { bResult = bresult; return; }
	ReadSkillCommands( SkillCommands, bresult );
	if ( !bresult ) { bResult = bresult; return; }
	ReadGeneralCommands( GeneralCommands, bresult );

	bResult = bresult;
}

void GCommand::ReadDiceCommands( QList<FCommandDiceStruct>& Commands, bool& bResult ) {
	QJsonObject fileJSON;
	bool bresult = GameFunctions::GetGameJSONObject( fileJSON , EGameFilesList::ECommands );
	if ( !bresult ) { return; }

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
}

void GCommand::ReadSkillCommands( QList<FCommandSkillStruct>& Commands, bool& bResult ) {

}

void GCommand::ReadGeneralCommands( QList<FCommandStruct>& Commands, bool& bResult ) {
	bool bresult = false;

}

void GCommand::CallDiceCommand( FCommandDiceStruct Command ) {

}

void GCommand::CallSkillCommand( FCommandSkillStruct Command ) {

}

void GCommand::CallGeneralCommand( FCommandStruct Command ) {

}
