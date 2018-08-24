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


#ifndef GPLAYER_H
#define GPLAYER_H

#include <QObject>
#include "GameFunctions.h"
#include "GCharacter.h"
#include "GDice.h"
#include "GCommand.h"
#include "GItem.h"


enum class EPlayerTypeList {
	EAdmin,
	EMod,
	EPlayer
};

enum class EPlayerStatusList {
	EPlaying,
	EWaiting,
	ETurn
};

class GPlayer : public QObject
{
    Q_OBJECT
public:
    explicit GPlayer(QObject *parent = nullptr);

    void Init();

    bool LoadPlayerProfile();

    // Player Character
    GCharacter* Character;

    /// Player Dice
    GDice* Dice;

    // Player Action
    GCommand* Action;

    // Action Used
    bool bActionUsed;

    // Dice Used
    bool bDiceUsed;

    // Is playing
    bool bPlaying;

    // Current turn ?
    bool bOnTurn;

    // Social Public Management

    /// Player type in game
    EPlayerTypeList Type;

    /// Current status in game
    EPlayerStatusList Status;

    // Social

    QString TwitchName;
    QString DiscordName;
    QString SteamName;

    QString NickName;

private:

signals:

public slots:

};

#endif // GPLAYER_H

