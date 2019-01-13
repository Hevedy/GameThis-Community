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


#include <QSound>
#include <QSoundEffect>
#include "PianoMiniGameForm.h"
#include "AppMainWindow.h"
#include "ui_PianoMiniGameForm.h"


PianoMiniGameForm::PianoMiniGameForm(EngineTick* _Tick, Core* _Core, QWidget* _Parent) :
    QWidget(_Parent), ui(new Ui::PianoMiniGameForm) {
    ui->setupUi(this);
    LocalTick = _Tick;
    LocalCore = _Core;

	connect( LocalTick, SIGNAL(sendTickFixed()), this, SLOT(getTickFixed()));
	connect( LocalTick, SIGNAL(sendTickFixedPerMinute()), this, SLOT(getTickFixedPerMinute()));
	connect( LocalTick, SIGNAL(sendTickFixedPerSecond()), this, SLOT(getTickFixedPerSecond()));

	//connect( parent, SIGNAL(sendUIPlayPiano( const QString, const int )), this, SLOT(getUIPlayPiano( const QString, const int )));

    bWaitingKeyDisable = false;
    WaitingDisableKeyCount = 0;
    WaitingDisableKeyCountCap = 1; // Default after 1 second

    bVisible = false;

    bEnabled = false;
    bEnabledAudio = false;

    bInProcess = false;
}

PianoMiniGameForm::~PianoMiniGameForm()
{
    delete ui;
}

void PianoMiniGameForm::init() {

}

void PianoMiniGameForm::getTickFixed() {
    if( bPlayingList ) {
        WaitingNextKeyCount++;
        if ( WaitingNextKeyCount >= WaitingNextKeyCountCap ) {
            if ( KeyList.size() > 0 ) {
                PlayPianoNote( KeyList[0].first, KeyList[0].second, true );
                WaitingNextKeyCount = 0;
                KeyPressedList << KeyList[0];
                LastKeyPressed = KeyList[0];
                KeyList.removeFirst();
                LastKeySpeed = PlayListSpeeds[0];
                PlayListSpeeds.removeFirst();
                if ( PlayListSpeeds.size() > 0 ) {
                    WaitingNextKeyCountCap = PlayListSpeeds[0];
                } else {
                    WaitingNextKeyCountCap = 10;
                }
                if ( KeyList.size() > 0 ) {
                    bPlayingList = true;
                } else {
                    bPlayingList = false;
                    WaitingNextKeyCountCap = 0;
                    KeyList.clear();
                    PlayListSpeeds.clear();
                    WaitingNextKeyCount = 0;
                    WaitingNextKeyCountCap = 0;
                }
                bWaitingKeyDisable = true;
            } else {
                bPlayingList = false;
                WaitingNextKeyCountCap = 0;
                KeyList.clear();
                PlayListSpeeds.clear();
                WaitingNextKeyCount = 0;
                WaitingNextKeyCountCap = 0;
            }
        }
    }
}

void PianoMiniGameForm::getTickFixedPerMinute() {

}

void PianoMiniGameForm::getTickFixedPerSecond() {
    if ( bWaitingKeyDisable ) {
        if ( KeyPressedList.size() > 0 ) {
            WaitingDisableKeyCount++;
            if ( WaitingDisableKeyCount >= WaitingDisableKeyCountCap ) {
                if ( KeyPressedList.size() > 0 ) {
                    PlayPianoNote( KeyPressedList[0].first , KeyPressedList[0].second, false );
                    WaitingDisableKeyCount = 0;
                    KeyPressedList.removeFirst();
                    if( KeyPressedList.size() > 0 ) {
                        bWaitingKeyDisable = true;
                    } else {
                        bWaitingKeyDisable = false;
                        KeyPressedList.clear();
                    }
                } else {
                    bWaitingKeyDisable = false;
                    KeyPressedList.clear();
                }
            }
        } else {
            bWaitingKeyDisable = false;
        }
    } else {

    }
}


void PianoMiniGameForm::closeEvent(QCloseEvent *event) {
    AppMainWindow* parent = qobject_cast<AppMainWindow*>(this->parent());
    event->ignore();
    this->hide();
    parent->SetPianoVisible( false );


    //event->ignore();

    //QWidget::closeEvent(event);
}

void PianoMiniGameForm::VisualSetup() {
/*
C major – C E G
C# major – C# E# G#
D major – D F# A
Eb major – Eb G Bb
E major – E G# B
F major – F A C
F# major – F# A# C#
G major – G B D
Ab major – Ab C Eb
A major – A C# E
Bb major – Bb D F
B major – B D# F#
 */
    QString blackStyle = "background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);";
    QString whiteStyle = "background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);";
    ui->label_K1->setStyleSheet(whiteStyle);
    ui->label_K2->setStyleSheet(whiteStyle);
    ui->label_K3->setStyleSheet(whiteStyle);
    ui->label_K4->setStyleSheet(whiteStyle);
    ui->label_K5->setStyleSheet(whiteStyle);
    ui->label_K6->setStyleSheet(whiteStyle);
    ui->label_K7->setStyleSheet(whiteStyle);
    ui->label_K8->setStyleSheet(whiteStyle);
    ui->label_K9->setStyleSheet(whiteStyle);
    ui->label_K10->setStyleSheet(whiteStyle);
    ui->label_K11->setStyleSheet(whiteStyle);
    ui->label_K12->setStyleSheet(whiteStyle);
    ui->label_K13->setStyleSheet(whiteStyle);
    ui->label_K14->setStyleSheet(whiteStyle);
    ui->label_K15->setStyleSheet(whiteStyle);
    ui->label_K16->setStyleSheet(whiteStyle);
    ui->label_K17->setStyleSheet(whiteStyle);
    ui->label_K18->setStyleSheet(whiteStyle);
    ui->label_K19->setStyleSheet(whiteStyle);
    ui->label_K20->setStyleSheet(whiteStyle);
    ui->label_K21->setStyleSheet(whiteStyle);
    ui->label_K22->setStyleSheet(whiteStyle);
    ui->label_K23->setStyleSheet(whiteStyle);
    ui->label_K24->setStyleSheet(whiteStyle);
    ui->label_K25->setStyleSheet(whiteStyle);
    ui->label_K26->setStyleSheet(whiteStyle);
    ui->label_K27->setStyleSheet(whiteStyle);
    ui->label_K28->setStyleSheet(whiteStyle);

    ui->label_KK1->setStyleSheet(blackStyle);
    ui->label_KK2->setStyleSheet(blackStyle);
    ui->label_KK3->setStyleSheet(blackStyle);
    ui->label_KK4->setStyleSheet(blackStyle);
    ui->label_KK5->setStyleSheet(blackStyle);
    ui->label_KK6->setStyleSheet(blackStyle);
    ui->label_KK7->setStyleSheet(blackStyle);
    ui->label_KK8->setStyleSheet(blackStyle);
    ui->label_KK9->setStyleSheet(blackStyle);
    ui->label_KK10->setStyleSheet(blackStyle);
    ui->label_KK11->setStyleSheet(blackStyle);
    ui->label_KK12->setStyleSheet(blackStyle);
    ui->label_KK13->setStyleSheet(blackStyle);
    ui->label_KK14->setStyleSheet(blackStyle);
    ui->label_KK15->setStyleSheet(blackStyle);
    ui->label_KK16->setStyleSheet(blackStyle);
    ui->label_KK17->setStyleSheet(blackStyle);
    ui->label_KK18->setStyleSheet(blackStyle);
    ui->label_KK19->setStyleSheet(blackStyle);
    ui->label_KK20->setStyleSheet(blackStyle);

}

void PianoMiniGameForm::PlayPianoNote( const QString _Note, const int _Octave, const bool _Enabled ) {
    QString blackStyle = "background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);";
    QString whiteStyle = "background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);";
    QString whiteEnabledStyle = "background-color: rgb(0, 255, 0); color: rgb(0, 255, 0);";
    QString blackEnabledStyle = "background-color: rgb(0, 255, 0); color: rgb(0, 255, 0);";
#ifdef QT_DEBUG
    QString audioURL = "../GameThisGameCore/Data/Audio/PianoSounds/";
#else
    QString audioURL = "Data/Audio/PianoSounds/";
#endif
    QString whiteResultStyle = (_Enabled ? whiteEnabledStyle : whiteStyle );
    QString blackResultStyle = (_Enabled ? blackEnabledStyle : blackStyle );
    int minOctave = 3, maxOctave = 6;
    int octave = qBound<int>(minOctave, _Octave, maxOctave);
    bool bValid = false;
    qDebug() << "Note: " + _Note;
    if ( _Note == "C" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K1->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K8->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K15->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K22->setStyleSheet(whiteResultStyle);
                break;
        }
    } else if ( _Note == "C#" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_KK1->setStyleSheet(blackResultStyle);
                break;
            case 4:
                ui->label_KK6->setStyleSheet(blackResultStyle);
                break;
            case 5:
                ui->label_KK11->setStyleSheet(blackResultStyle);
                break;
            case 6:
                ui->label_KK16->setStyleSheet(blackResultStyle);
                break;
        }
    } else if ( _Note == "D" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K2->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K9->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K16->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K23->setStyleSheet(whiteResultStyle);
                break;
        }
    } else if ( _Note == "D#" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_KK2->setStyleSheet(blackResultStyle);
                break;
            case 4:
                ui->label_KK7->setStyleSheet(blackResultStyle);
                break;
            case 5:
                ui->label_KK12->setStyleSheet(blackResultStyle);
                break;
            case 6:
                ui->label_KK17->setStyleSheet(blackResultStyle);
                break;
        }
    } else if ( _Note == "E" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K3->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K10->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K17->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K24->setStyleSheet(whiteResultStyle);
                break;
        }
    } else if ( _Note == "F" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K4->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K11->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K18->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K25->setStyleSheet(whiteResultStyle);
                break;
        }
    } else if ( _Note == "F#" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_KK3->setStyleSheet(blackResultStyle);
                break;
            case 4:
                ui->label_KK8->setStyleSheet(blackResultStyle);
                break;
            case 5:
                ui->label_KK13->setStyleSheet(blackResultStyle);
                break;
            case 6:
                ui->label_KK18->setStyleSheet(blackResultStyle);
                break;
        }
    } else if ( _Note == "G" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K5->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K12->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K19->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K26->setStyleSheet(whiteResultStyle);
                break;
        }
    } else if ( _Note == "G#" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_KK4->setStyleSheet(blackResultStyle);
                break;
            case 4:
                ui->label_KK9->setStyleSheet(blackResultStyle);
                break;
            case 5:
                ui->label_KK14->setStyleSheet(blackResultStyle);
                break;
            case 6:
                ui->label_KK19->setStyleSheet(blackResultStyle);
                break;
        }
    } else if ( _Note == "A" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K6->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K13->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K20->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K27->setStyleSheet(whiteResultStyle);
                break;
        }
    } else if ( _Note == "A#" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_KK5->setStyleSheet(blackResultStyle);
                break;
            case 4:
                ui->label_KK10->setStyleSheet(blackResultStyle);
                break;
            case 5:
                ui->label_KK15->setStyleSheet(blackResultStyle);
                break;
            case 6:
                ui->label_KK20->setStyleSheet(blackResultStyle);
                break;
        }
    } else if ( _Note == "B" ) {
        bValid = true;
        audioURL = audioURL + _Note + "_" + QString::number( octave );
        switch (octave) {
            case 3:
                ui->label_K7->setStyleSheet(whiteResultStyle);
                break;
            case 4:
                ui->label_K14->setStyleSheet(whiteResultStyle);
                break;
            case 5:
                ui->label_K21->setStyleSheet(whiteResultStyle);
                break;
            case 6:
                ui->label_K28->setStyleSheet(whiteResultStyle);
                break;
        }
    } else {
        bValid = false;
        //audioURL = audioURL + "Default_0";

    }

    if ( bEnabled && bValid ) {
        if ( bEnabledAudio ) {
            QSoundEffect effect;
            effect.setSource(QUrl::fromLocalFile(audioURL + ".wav"));
            effect.setVolume(1.0);
            effect.play();
        }

    } else if ( !bEnabled && bValid ) {

    } else {
        qDebug() << "Audio File Not Found or Invalid Note";
    }
}


void PianoMiniGameForm::getUIPlayPiano( const QList<QString> _Note, const QList<int> _Octave, const QList<int> _Speed ) {
    if ( !bWaitingKeyDisable && !bPlayingList && !bInProcess ) {
        bInProcess = true;
        if ( bEnabled && bVisible ) {
            for( int i = 0; i < _Note.size(); i++ ) {
                if ( i > _Octave.size() ) {
                    KeyList.append(qMakePair(_Note[i], qBound<int>(3, 3, 6)));
                } else {
                    KeyList.append(qMakePair(_Note[i], qBound<int>(3, _Octave[i], 6)));
                }

                if ( i > _Speed.size() ) {
                    PlayListSpeeds << 10;
                } else {
                    PlayListSpeeds << _Speed[i];
                }
            }
            bPlayingList = true;
        }
    }
    bInProcess = false;

}
