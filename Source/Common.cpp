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


#include "Common.h"

QList<FCommonModuleStruct*> Common::Modules;
QList<FCommonEventStruct*> Common::Events;

bool Common::ClearModule( FCommonModuleStruct* _Module ) {
	delete _Module;
	_Module = nullptr;
	return true;
}

bool Common::ClearModulesArray( QList<FCommonModuleStruct*>& _ModulesArray ) {
	qDeleteAll(_ModulesArray);
	_ModulesArray.clear();
	return true;
}

bool Common::ClearEvent( FCommonEventStruct* _Event ) {
	delete _Event;
	_Event = nullptr;
	return true;
}

bool Common::ClearEventsArray( QList<FCommonEventStruct*>& _EventsArray ) {
	qDeleteAll(_EventsArray);
	_EventsArray.clear();
	return true;
}

Common::Common(QObject* _Parent) : QObject(_Parent)
{

}

void Common::init() {

}

bool Common::LoadCommonScripts() {
	QJsonObject fileJSON;
	if ( GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eCommon ) ) { return false; }
	if ( !LoadScriptModules( fileJSON ) ) { return false; }
	if ( !LoadScriptEvents( fileJSON ) ) { return false; }
	return true;
}

bool Common::LoadScriptModules( QJsonObject _File ) {
	qDebug() << "Read & Load Modules";
	QList<FCommonModuleStruct*> modules;
	QJsonArray modulesArray = _File["Common"].toObject()["Modules"].toArray();
	if ( !modulesArray.isEmpty() ) {
		for (int i = 0; i < modulesArray.size(); i++) {
			FCommonModuleStruct* module = new FCommonModuleStruct;
			module->name = modulesArray[i].toObject()["Name"].toString();
			module->nameID = module->name;
			module->enabled = modulesArray[i].toObject()["Enabled"].toBool();
			modules << module;
		}
	}
	ClearModulesArray(Modules);
	//qDeleteAll(Modules);
	//Modules.clear();
	Modules = modules;
	// Because the errors already has been pulled
	return true;
}

bool Common::LoadScriptEvents( QJsonObject _File ) {
	qDebug() << "Read & Load Events";
	QList<FCommonEventStruct*> events;
	QJsonArray eventsArray = _File["Common"].toObject()["Events"].toArray();
	if ( !eventsArray.isEmpty() ) {
		for (int i = 0; i < eventsArray.size(); i++) {
			FCommonEventStruct* event = new FCommonEventStruct;
			event->name = eventsArray[i].toObject()["Name"].toString();
			event->nameID = event->name;
			//event->enabled = eventsArray[i].toObject()["Enabled"].toBool();
			events << event;
		}
	}
	ClearEventsArray(Events);
	//qDeleteAll(Modules);
	//Modules.clear();
	Events = events;
	// Because the errors already has been pulled
	return true;
}