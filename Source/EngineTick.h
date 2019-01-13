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


#ifndef ENGINETICK_H
#define ENGINETICK_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QElapsedTimer>
#include "GlobalFunctions.h"
#include "MainLoopTick.h"

class EngineTick : public QObject
{
    Q_OBJECT
public:
    explicit EngineTick( MainLoopTick* _MainLoop = nullptr, QObject* _Parent = nullptr );

    quint32 TickCount();
    double TickMS();
    double TickMSCount();
    quint32 TickFixedCount();

signals:
    void sendTick( const double _Time );
    void sendTickFixed();

    void sendTickFixedPerMinute();
    void sendTickFixedPerSecond();

public slots:
    void tick( const double _Time );
    void tickFixed();

    void init();

private:

    QTimer* Timer;
    MainLoopTick* MainLoop;

    bool bTickExecuted;

    // Tick const app
    double MSCurrent;
    double MSLast;
    double MSCount;
    double MSCountLimit;
    quint32 MSNumOverruns;

    quint32 TickCounter;
    quint32 TickCounterLast;
    quint32 TickCounterLimit;
    quint32 TickNumOverruns;

    // Tick with fixed FPS 20 Default
    quint32 TickFixedCounter;
    quint32 TickFixedCounterLast;
    quint32 TickFixedCounterLimit;
    quint32 TickFixedNumOverruns;

    quint32 TickFixedMinCounter;
    quint32 TickFixedMinCounterLast;
    quint32 TickFixedMinCounterLimit;

    quint32 TickFixedSecCounter;
    quint32 TickFixedSecCounterLast;
    quint32 TickFixedSecCounterLimit;

};

#endif // ENGINETICK_H
