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


#include "EngineTick.h"

EngineTick::EngineTick(MainLoopTick* _MainLoop, QObject* _Parent) : QObject(_Parent) {

    TickCounterLimit = (((1000 * 60) * 60) * 24);
    TickFixedCounterLimit = (((20 * 60) * 60) * 24); //(((10 * 60) * 60) * 24);

    TickCounter = 0;
    TickCounterLast = 0;
    TickNumOverruns = 0;
    TickFixedCounter = 0;
    TickFixedCounterLast = 0;
    TickFixedNumOverruns = 0;

    TickFixedMinCounter = 0;
    TickFixedMinCounterLast = 0;
    TickFixedMinCounterLimit = 10 * 60; // based on a 100ms tick

    TickFixedSecCounter = 0;
    TickFixedSecCounterLast = 0;
    TickFixedSecCounterLimit = 10; // based on a 100ms tick

    MSCurrent = 0;
    MSCount = 0;
    MSCountLimit = TickCounterLimit;

    bTickExecuted = false;


    if ( _MainLoop == nullptr ) {
        ///MainLoop = new MainLoopTick();
    } else {
        ///MainLoop = mainLoop;
    }

}

void EngineTick::init() {

    //Fixed Timer
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(tickFixed()));
    Timer->start(100);
    //Timer->

    ///connect(MainLoop, SIGNAL(SendTick( const double )), this, SLOT(Tick( const double )));
    bTickExecuted = true;


    ///MainLoop->Launch();
    //Need a new thread cause will overlap fixed tick
    //Tick();
}

// Better for Twitch and other apps
void EngineTick::tick( const double _Time ) {
    //while ( bTickExecuted ) {
    MSCurrent = _Time;
    MSCount = MSCount + MSCurrent;
    if ( MSCount > MSCountLimit ) {
        MSCount = 0;
        MSNumOverruns++;
    }
    TickCounter++;
    if ( TickCounter > TickCounterLimit ) {
        TickCounter = 0;
        TickNumOverruns++;
    }
    TickCounterLast = TickCounter;
    MSLast = MSCurrent;
    emit sendTick( _Time );
    //qDebug() << "Tick: " << QString::number(MSCount);
    //}

}

// Better for game events
void EngineTick::tickFixed() {
    TickFixedCounter++;
    if ( TickFixedCounter > TickFixedCounterLimit ) {
        TickFixedCounter = 0;
        TickFixedNumOverruns++;
    }
    TickFixedCounterLast = TickFixedCounter;
    emit sendTickFixed();

    TickFixedSecCounter++;
    if ( TickFixedSecCounter >= TickFixedSecCounterLimit ) {
        TickFixedSecCounter = 0;
        emit sendTickFixedPerSecond();
    }
    TickFixedSecCounterLast = TickFixedSecCounter;

    TickFixedMinCounter++;
    if ( TickFixedMinCounter >= TickFixedMinCounterLimit ) {
        TickFixedMinCounter = 0;
        emit sendTickFixedPerMinute();
    }
    TickFixedMinCounterLast = TickFixedMinCounter;
    //qDebug() << "TickFixed: " << QString::number(TickFixedCounter);

}

quint32 EngineTick::TickCount() {
    return TickCounter;
}

double EngineTick::TickMS() {
    return MSCurrent;
}

double EngineTick::TickMSCount() {
    return MSCount;
}

quint32 EngineTick::TickFixedCount() {
    return TickFixedCounter;
}
