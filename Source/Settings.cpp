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


#include "Settings.h"

Settings::Settings(QObject* _Parent) : QObject(_Parent)
{

}

bool Settings::init() {
	if ( !LoadScriptSettings() ) { return false; }
}

bool Settings::LoadScriptSettings() {
	QJsonObject fileJSON;
	if( !GlobalFunctions::GetGameJSONObject( fileJSON , EGameFilesList::eConfig ) ) { return false; }
	QList<QString> functionList;
	QList<QString> functionValueList;
	QList<bool> boolMixedList;
	QList<bool> intInfiniteList;
	QList<bool> floatInfiniteList;
	bool blocalResult = false;
	QJsonObject workObj = fileJSON["Config"].toObject();

	Common::TwitchChannelName = GlobalFunctions::STRToString( workObj["Channel"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::TwitchOwnerUsername = GlobalFunctions::STRToString( workObj["Owner"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::TwitchBotUsername = GlobalFunctions::STRToString( workObj["Bot"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::TwitchUseMaster = GlobalFunctions::STRToBool( workObj["UseMaster"].toString(), false,
			functionList, functionValueList, boolMixedList, blocalResult )[0];

	Common::TwitchUseBot = GlobalFunctions::STRToBool( workObj["UseBot"].toString(), false,
			functionList, functionValueList, boolMixedList, blocalResult )[0];

	Common::TwitchOwnerToken = GlobalFunctions::STRToString( workObj["OwnerToken"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::TwitchBotToken = GlobalFunctions::STRToString( workObj["BotToken"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::PointsCustomName = GlobalFunctions::STRToString( workObj["PointsName"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::CurrencyCustomName = GlobalFunctions::STRToString( workObj["CurrencyName"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::TicketsCustomName = GlobalFunctions::STRToString( workObj["TicketsName"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::KeysCustomName = GlobalFunctions::STRToString( workObj["KeysName"].toString(), false, false,
			functionList, functionValueList, blocalResult )[0];

	Common::TwitchUsername = ((Common::TwitchUseBot) ? Common::TwitchBotUsername : Common::TwitchOwnerUsername);
	Common::TwitchToken = ((Common::TwitchUseBot) ? Common::TwitchBotToken : Common::TwitchOwnerToken);
}
