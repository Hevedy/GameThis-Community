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


#ifndef INSTANCE_H
#define INSTANCE_H

#include <QObject>

namespace GI {

    extern bool InJob;
    extern bool Loading;

    extern QString SettingsFile;
    extern QString CoreFile;
    extern QString ContentFolder;
    extern QString RootFolder;
}

class Instance : public QObject
{
    Q_OBJECT
public:
    explicit Instance(QObject* _Parent = nullptr);

    static int VersionMajor;
    static int VersionMinor;
    static int VersionFix;
    static int VersionBuild;
    static QString Version;

    static int VersionUMajor;
    static int VersionUMinor;
    static int VersionUFix;
    static int VersionUBuild;
    static QString VersionU;

    static qint32 AudioMasterVolume;
    static qint32 AudioEffectsVolume;
    static qint32 AudioDialogVolume;
    static qint32 AudioUIVolume;
    static qint32 AudioMusicVolume;
    static qint32 AudioSpeecherVolume;

    static qint32 GameLanguage;
    static bool GameTextToSpeech;

    static qint32 GameHUDSize;
    static qint32 GameEffectIntensity;

    static qint32 ResolutionX;
    static qint32 ResolutionY;

    static qint32 CalResolutionX;
    static qint32 CalResolutionY;

    static qint32 MonitorID;
    static qint32 MonitorName;

    static QString KeyUp;
    static QString KeyDown;
    static QString KeyRight;
    static QString KeyLeft;

    static QString KeyEnter;
    static QString KeyNext;
    static QString KeyPrev;

    static QString KeyOption1;
    static QString KeyOption2;
    static QString KeyOption3;
    static QString KeyOption4;
    static QString KeyOption5;
    static QString KeyOption6;

signals:

public slots:
};

#endif // INSTANCE_H
