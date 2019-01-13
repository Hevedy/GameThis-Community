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


#include "MiniGames.h"


bool MiniGames::ChestEnabled;
bool MiniGames::ChestToPick;
int MiniGames::ChestPoints;
int MiniGames::ChestPointsRand;
int MiniGames::ChestCurrency;
int MiniGames::ChestCurrencyRand;
int MiniGames::ChestTickets;
int MiniGames::ChestTicketsRand;
int MiniGames::ChestKeys;
int MiniGames::ChestKeysRand;
bool MiniGames::ChestAutoSpawn;
bool MiniGames::ChestReadyToSpawn;
int MiniGames::ChestSpawnMinutesRate;
int MiniGames::ChestSpawnMinutesCount;
int MiniGames::ChestSpawnMinimumUsers;

bool MiniGames::QAEnabled;
QList<FQAStruct*> MiniGames::QAList;
int MiniGames::QAPickedID;
bool MiniGames::QAToPick;
int MiniGames::QAPoints;
int MiniGames::QAPointsRand;
int MiniGames::QACurrency;
int MiniGames::QACurrencyRand;
int MiniGames::QATickets;
int MiniGames::QATicketsRand;
bool MiniGames::QAAutoSpawn;
int MiniGames::QASpawnMinutesRate;
int MiniGames::QASpawnMinimumUsers;

bool MiniGames::PianoEnabled;
bool MiniGames::PianoReady;
bool MiniGames::PianoInUse;

MiniGames::MiniGames(QObject* _Parent) : QObject(_Parent)
{

}

bool MiniGames::init() {
    return true;
}

void MiniGames::ChestSpawn(  ) {

}

void MiniGames::ChestPick(  ) {

}

void MiniGames::QuestionA(  ) {

}

void MiniGames::QAnswer(  ) {

}

void MiniGames::PianoUse(  ) {

}
