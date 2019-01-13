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


#ifndef MINIGAMES_H
#define MINIGAMES_H

#include <QObject>
#include "GlobalFunctions.h"


struct FQAStruct {
public:

	// Questions
	QList<QString> questions;
	// Answers
	QList<QString> answers;



	FQAStruct( QList<QString> _Questions = {} , QList<QString> _Answers = {} )
	: questions( _Questions )
	, answers( _Answers ) {}
};

class MiniGames : public QObject
{
    Q_OBJECT
public:
    explicit MiniGames(QObject* _Parent = nullptr);

    static bool init();

    // Chest game
    // TODO Negative chests ?
    static bool ChestEnabled;
    static bool ChestToPick;
    static int ChestPoints;
    static int ChestPointsRand;
    static int ChestCurrency;
    static int ChestCurrencyRand;
    static int ChestTickets;
    static int ChestTicketsRand;
    static int ChestKeys;
    static int ChestKeysRand;
    static bool ChestAutoSpawn;
    static bool ChestReadyToSpawn;
    static int ChestSpawnMinutesRate;
    static int ChestSpawnMinutesCount;
    static int ChestSpawnMinimumUsers;

    // Question & Answer game
    static bool QAEnabled;
    static QList<FQAStruct*> QAList;
    static int QAPickedID;
    static bool QAToPick;
    static int QAPoints;
    static int QAPointsRand;
    static int QACurrency;
    static int QACurrencyRand;
    static int QATickets;
    static int QATicketsRand;
    static bool QAAutoSpawn;
    static int QASpawnMinutesRate;
    static int QASpawnMinimumUsers;

    // Piano game
    static bool PianoEnabled;
    static bool PianoReady;
    static bool PianoInUse;


    void ChestSpawn(  );
    void ChestPick(  );

    void QuestionA(  );
    void QAnswer(  );

    void PianoUse(  );

private:

signals:

public slots:

};

#endif // MINIGAMES_H

