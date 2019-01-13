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


#ifndef RPG_H
#define RPG_H

#include <QObject>
#include <QList>
#include <QTimer>
#include "../SharedLib.h"
#include "GlobalFunctions.h"
#include "Instance.h"
#include "RPGDice.h"
#include "RPGPlayer.h"
#include "RPGCharacter.h"
#include "EngineTick.h"
#include "ThirdParty/Twitch/TwitchChat.h"

class RPG : public QObject
{
    Q_OBJECT
public:
    explicit RPG(EngineTick* _Tick = nullptr, QObject* _Parent = nullptr);

    ~RPG();

    void SetupPlayer( const QList<int> _CharactersIndex, const QList<int> _ObjectsIndex );

    // Game Logics on movement etc
    void SetupGame();

    void NextGameStep();

    void ReadPlayerInput( const QString _TextInput );

    //ELanguagesList CurrentLanguage;

    // Turns & LOGIC

    void LogRegister( const QString _Text, const EGameLogTypeList _Panel );

private:

    ////////////////////////////////////////
    // GAME CORE
    ////////////////////////////////////////

    // Game Tick
    EngineTick* LocalTick;

    // Twitch Manager
    TwitchChat* Twitch;

    // Wait for x milliseconds
    void WaitForMS( const double _Milliseconds );

    // Wait for x ticks
    void WaitForTicks( const quint32 _Ticks );

    // Wait for x ticks on fixed tick
    void WaitForTicksFixed( const quint32 _Ticks );


    ////////////////////////////////////////
    // GAME LOGICS
    ////////////////////////////////////////

    // Plain Log
    QString GameLog;

	// Dices List
	QList<RPGDice*> DiceList;

	// Player Characters List
	QList<RPGCharacter*> PlayerCharacterList;

	// World Characters List
	QList<RPGCharacter*> WorldCharacterList;

	// Player List
	QList<RPGPlayer*> PlayerList;

	// Current Player
	RPGPlayer* PlayerCurrentTurn;

	// Game is waiting some action
	bool bGameWaiting;

	// Game is paused
	bool bGamePaused;

	// The game started ? if yes, lobby closed and can't join by player
	bool bGameStarted;

	// Can Join the game ? (On/Off when the people is allowed to enter)
	bool bPlayersCanJoin;

	// Players to enter into the game
	QList<QString> UsersWantPlay;

	// Pick Random Character from game
	void GivePlayerRandomCharacter( RPGPlayer* _Player );

	// Pick Random Character from game
	void GivePlayerCharacterByName( RPGPlayer* _Player, const QString _CharacterStr );


    ////////////////////////////////////////
    // GAME MANAGERS
    ////////////////////////////////////////

    // Read core scripts and data
    void InitCore();

    // Read and validate scripts and extern code
    void InitScripts();

    // Read config
    void ReadConfig();

    // Read game
    void ReadGame();

    // Read dices
    void ReadDices();

    // Read characters, player and world
    void ReadCharacters();

    // Read actions
    void ReadActions();

    ////////////////////////////////////////
    // SOCIAL MEDIA
    ////////////////////////////////////////


signals: // Outputs

    void SendWriteText(const QString Text, const EGameLogTypeList Panel, const int Difference);

    /// Save Log
    void sendGameSaveLog( const QString Text );

    /// Save Game
    void sendGameSaveTable( const QString Text );

public slots: // Inputs

    ////////////////////////////////////////
    // GAME CORE
    ////////////////////////////////////////

    // Class Initiate
    void init();

    void getAppClose();

    ////////////////////////////////////////
    // GAME LOGICS
    ////////////////////////////////////////

    /// Game New Game
    void getGameNew();

    /// Game Reload Scripts
    void getGameConnect();

    /// Game Reload Scripts
    void getGameScriptsReload();

    /// Game Pause
    void getGamePause();

    /// Game End
    void getGameEnd();

    /// Save Game
    void getGameSaveTable();

    /// Save Log
    void getGameSaveLog();

    /// Add player manually to the game
    void getGameAddPlayer( const QString _Username );

    /// Remove player manually from the game
    void getGameRemovePlayer( const QString _Username );

    /// Give new character to player
    void getPlayerNewCharacter( RPGPlayer* _Character );

    ///
    void getPlayerDamageCharacter( RPGPlayer* _Character );

    ///
    void getPlayerKillCharacter( RPGPlayer* _Character );


    ////////////////////////////////////////
    // SOCIAL MEDIA
    ////////////////////////////////////////


};

#endif // GAME_H
