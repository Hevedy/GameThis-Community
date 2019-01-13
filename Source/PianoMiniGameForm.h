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


#ifndef PIANOMINIGAMEFORM_H
#define PIANOMINIGAMEFORM_H

#include <QWidget>
#include <QCloseEvent>
#include "Core.h"
#include "EngineTick.h"

struct FPianoNoteStruct {
public:

	QString note;
	// Name
	int octave;
	// Speed
	int speed;

	FPianoNoteStruct( QString _Note = "", int _Octave = 3, int _Speed = 10 )
	: note( _Note )
	, octave( _Octave )
	, speed( _Speed ) {}
};

namespace Ui {
class PianoMiniGameForm;
}

class PianoMiniGameForm : public QWidget
{
    Q_OBJECT

public:
    explicit PianoMiniGameForm(EngineTick* _Tick = nullptr, Core* _Core = nullptr, QWidget* _Parent = nullptr);
    ~PianoMiniGameForm();

    EngineTick* LocalTick;

    Core* LocalCore;

    bool bEnabled;
    bool bEnabledAudio;
    bool bVisible;

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::PianoMiniGameForm *ui;

    void VisualSetup();

    void PlayPianoNote( const QString _Note, const int _Octave, const bool _Enabled );

    // Is playing a key list ?
    bool bPlayingList;
    // The actual key list
    QList<QPair<QString,int>> KeyList;
    // The key list speeds
    QList<int> PlayListSpeeds;

    // Count to disable key
    int WaitingNextKeyCount;
    // Count to disable key cap
    int WaitingNextKeyCountCap;

    // Some key waiting to disable ?
    bool bWaitingKeyDisable;
    // Last pressed key
    QPair<QString,int> LastKeyPressed;
    // Last key pressed speed
    int LastKeySpeed;
    // List of already pressed keys
    QList<QPair<QString,int>> KeyPressedList;

    // Count to disable key
    int WaitingDisableKeyCount;
    // Count to disable key cap
    int WaitingDisableKeyCountCap;

    // Is calculating
    bool bInProcess;


signals:

private slots:

public slots:
    void init();

    void getTickFixed();

    void getTickFixedPerMinute();

    void getTickFixedPerSecond();

    void getUIPlayPiano( const QList<QString> _Note, const QList<int> _Octave, const QList<int> _Speed );

};

#endif // PIANOMINIGAMEFORM_H
