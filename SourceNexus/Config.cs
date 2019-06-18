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


using System;
using System.Collections.Generic;
using System.Text;
using HEVLib;
using IniParser.Model;
using GameThisNexus.Discord;
using GameThisNexus.Twitch;

namespace GameThisNexus {
	class Config {

		public static bool Status() {
			return false;
		}

		public static bool SetupConfig() {
			bool status = false;

			// Get defaults texts
			if ( !HEVIO.ResourcesTextReadString( Instance.DefaultFileConfigURL, out Instance.DefaultFileConfigText ) ) return false;
			// Create new files if missing
			if ( !HEVIO.FileValidate( Instance.FileConfig ) ) {
				if ( !HEVIO.FileTextWriteString( Instance.FileConfig, Instance.DefaultFileConfigText ) ) {
					HEVConsole.Print( "Cannot write a new file for Config.", EPrintType.eError );
					return false;
				}
			}
			status = true;
			return status;
		}

		public static bool ConfigRead() {
			bool status = false;
			IniData data = null;
			if ( !SetupConfig() ) return false;
			(data, status) = HEVIO.FileINIRead( Instance.FileConfig );
			if ( !status ) {
				if ( !ConfigWrite() ) {
					return false;
				} else {
					return true;
				}
			}

			HEVConsole.Print("1");


			if ( !data.DataINIReadWrite( "Profile", "UserName", ref Instance.ConfUserName ) ) status = false;
			if ( !data.DataINIReadWrite( "Profile", "Website", ref Instance.ConfWebsite ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "Language", ref Instance.ConfLanguage ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "DiscordUser", ref Instance.ConfDiscordSDK ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "DiscordBot", ref Instance.ConfDiscordBot ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "TwitchUser", ref Instance.ConfTwitchSDK ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "TwitchBot", ref Instance.ConfTwitchBot ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "ComputerRank", ref Instance.ConfComputerRank ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "UserBlackListString", ref Instance.UserBlackList ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "BotBlackListString", ref Instance.BotBlackList ) ) status = false;
			if ( !data.DataINIReadWrite( "Configuration", "RPGGame", ref Instance.ConfRPGGame ) ) status = false;

			if ( !status ) {
				status = HEVIO.FileINIWrite( Instance.FileConfig, data );
			}

			// Get the settings of every system
			if ( !DiscordSDK.ConfigRead() ) return false;
			if ( !DiscordBot.ConfigRead() ) return false;
			if ( !TwitchSDK.ConfigRead() ) return false;
			if ( !TwitchBot.ConfigRead() ) return false;
			return status;
		}

		public static bool ConfigValidate() {
			bool status = false;


			status = true;
			return status;
		}

		public static bool ConfigWrite() {
			bool status = false;
			IniData data = null;

			data["Profile"]["UserName"] = Instance.ConfUserName;
			data["Profile"]["Website"] = Instance.ConfWebsite;

			data["Configuration"]["Language"] = Instance.ConfLanguage;

			data["Configuration"]["DiscordUser"] = Instance.ConfDiscordSDK.ToString();
			data["Configuration"]["DiscordBot"] = Instance.ConfDiscordBot.ToString();
			data["Configuration"]["TwitchUser"] = Instance.ConfTwitchSDK.ToString();
			data["Configuration"]["TwitchBot"] = Instance.ConfTwitchBot.ToString();

			data["Configuration"]["ComputerRank"] = Instance.ConfComputerRank.ToString();

			data["Configuration"]["UserBlackListString"] = HEVText.ToString( Instance.UserBlackList.ToArray() ).ToString();
			data["Configuration"]["BotBlackListString"] = HEVText.ToString( Instance.BotBlackList.ToArray() ).ToString();

			data["Configuration"]["RPGGame"] = Instance.ConfRPGGame.ToString();


			status = HEVIO.FileINIWrite( Instance.FileConfig, data );
			return status;
		}
	}
}
