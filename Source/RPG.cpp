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


#include <QAudio>
#include <QSound>
#include "RPG.h"


//TODO TAKE TOKEN FROM TWITCH
// EVENTS AND TYPES FOR THE CALLS

RPG::RPG(EngineTick* _Tick, QObject* _Parent) : QObject(_Parent) {
    LocalTick = _Tick;


    InitCore();
}

RPG::~RPG() {

}

void RPG::init() {
    InitScripts();

}

void RPG::getAppClose() {
    RPG::~RPG();
}


////////////////////////////////////////
// GAME CORE
////////////////////////////////////////

void RPG::WaitForMS( const double Milliseconds ) { // 10 ticks equal 1 second
    // Will return error if the loop reach 0 on reset at 24h
    double tick = LocalTick->TickMSCount() + Milliseconds;
    while ( tick > LocalTick->TickMSCount() ) {
    }
}

void RPG::WaitForTicks( const quint32 Ticks ) { // 10 ticks equal 1 second
    // Will return error if the loop reach 0 on reset at 24h
    quint32 tick = LocalTick->TickCount() + Ticks;
    while ( tick > LocalTick->TickCount() ) {
    }
}

void RPG::WaitForTicksFixed( const quint32 Ticks ) { // 10 ticks equal 1 second
    // Will return error if the loop reach 0 on reset at 24h
    quint32 tick = LocalTick->TickFixedCount() + Ticks;
    while ( tick > LocalTick->TickFixedCount() ) {
    }
}


////////////////////////////////////////
// GAME LOGICS
////////////////////////////////////////


void RPG::GivePlayerRandomCharacter( RPGPlayer* _Player ) {

}


void RPG::GivePlayerCharacterByName( RPGPlayer* _Player, const QString _CharacterStr ) {

}

void RPG::getGameNew() {

}

void RPG::getGameConnect() {

}

void RPG::getGameScriptsReload() {

}

void RPG::getGamePause() {

}

void RPG::getGameEnd() {

}

void RPG::getGameSaveTable() {

}

void RPG::getGameSaveLog() {

}

void RPG::getGameAddPlayer( const QString _Username ) {

}

void RPG::getGameRemovePlayer( const QString _Username ) {

}

void RPG::getPlayerNewCharacter( RPGPlayer* _Character ) {

}

void RPG::getPlayerDamageCharacter( RPGPlayer* _Character ) {

}

void RPG::getPlayerKillCharacter( RPGPlayer* _Character ) {

}


////////////////////////////////////////
// GAME MANAGERS
////////////////////////////////////////

void RPG::InitCore() {

}

void RPG::InitScripts() {
    ReadDices();
    ReadCharacters();
    ReadActions();
}

void RPG::ReadConfig() {
    QString baseUrl = GI::ContentFolder, fileUrl = "", fileUrlExt = "";
}

void RPG::ReadGame() {

}

void RPG::ReadDices() {

}

void RPG::ReadCharacters() {

}

void RPG::ReadActions() {

}

void RPG::SetupPlayer( const QList<int> _CharactersIndex, const QList<int> _ObjectsIndex ) {

}

// Game Logics on movement etc
void RPG::SetupGame() {

}

void RPG::NextGameStep() {

}

void RPG::LogRegister( const QString _Text, const EGameLogTypeList _Panel ) {
    QString text = "Text: " + _Text + " - Class: "+ QString::number(int(_Panel)) + "\n";
    GameLog += text;
}


////////////////////////////////////////
// SOCIAL MEDIA
////////////////////////////////////////


