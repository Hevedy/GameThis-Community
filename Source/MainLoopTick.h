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


#ifndef MAINLOOPTICK_H
#define MAINLOOPTICK_H

#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <QString>
#include <QObject>
#include <QMetaObject>
#include <QThread>
#include "GlobalFunctions.h"
#include "Instance.h"

// TODO MOVE THIS FROM MAIN TO TICK FOR EXAMPLE, is taking Window draw

class MainLoopTick : public QObject
{

    Q_OBJECT
public:
    explicit MainLoopTick(QObject* _Parent = nullptr) : QObject(_Parent)
    {
        
    }

private:
    std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

signals:
    void SendTick( const double _Time );

public slots:

    void Launch()
    {
        TickNext();
    }

private slots:

    void Tick()
    {
        a = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> work_time = a - b;

        if (work_time.count() < 10.0) // 10ms = 99/100FPS
        {
            std::chrono::duration<double, std::milli> delta_ms(10.0 - work_time.count());
            auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
            //QMetaObject::msleep()
        }

        b = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> sleep_time = b - a;

        emit SendTick((work_time + sleep_time).count());
        //qDebug() << "Time: " + QString::number(double(work_time + sleep_time).cou));
        //printf("Time: %f \n", (work_time + sleep_time).count());

        // Continue ticking
        TickNext();
    }

private:

    void TickNext()
    {
        // Trigger the tick() invokation when the event loop runs next time
        QMetaObject::invokeMethod(this, "Tick", Qt::QueuedConnection);
    }

};

#endif // MAINLOOPTICK_H
