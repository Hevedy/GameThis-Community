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

using System;
using System.Collections.Generic;
using System.Text;
using HEVLib;
using GameThisNexus.Discord;
using GameThisNexus.Twitch;
using GameThisNexus.Chat;

namespace GameThisNexus {
	public class Manager {
		private ChatManager Chat;


		public bool Start() {

			HEVConsole.LineJump();
			HEVConsole.Print( "-- (Settings) --" );
			bool settingsLoad = Settings.ConfigRead();
			if ( settingsLoad ) {
				HEVConsole.Print( "-> Loaded.", EPrintType.eSuccess );
			} else {
				HEVConsole.Print( "-> Failed.", EPrintType.eError );
			}
			HEVConsole.LineJump();
			HEVConsole.Print( "-- (Config) --" );
			bool configLoad = Config.ConfigRead();
			if ( configLoad ) {
				HEVConsole.Print( "-> Loaded.", EPrintType.eSuccess );
			} else {
				HEVConsole.Print( "-> Failed.", EPrintType.eError );
			}
			HEVConsole.LineJump();
			HEVConsole.Print( "-- (Discord) --" );
			Instance.DiscordSDKReady = DiscordSDK.ConfigValidate();
			if ( Instance.DiscordSDKReady ) {
				HEVConsole.Print( "-> User Enabled.", EPrintType.eSuccess );
			} else {
				HEVConsole.Print( "-> User Disabled.", EPrintType.eWarning );
			}
			Instance.DiscordBotReady = DiscordBot.ConfigValidate();
			if ( Instance.DiscordBotReady ) {
				HEVConsole.Print( "-> Bot Enabled.", EPrintType.eSuccess );
			} else {
				HEVConsole.Print( "-> Bot Disabled.", EPrintType.eWarning );
			}
			HEVConsole.LineJump();

			// Not implemented
			HEVConsole.Print( "-- (Twitch) --" );
			Instance.TwitchSDKReady = TwitchSDK.ConfigValidate();
			if ( Instance.TwitchSDKReady ) {
				HEVConsole.Print( "-> User Enabled.", EPrintType.eSuccess );
			} else {
				HEVConsole.Print( "-> User Disabled.", EPrintType.eWarning );
			}
			Instance.TwitchBotReady = TwitchBot.ConfigValidate();
			if ( Instance.TwitchBotReady ) {
				HEVConsole.Print( "-> Bot Enabled.", EPrintType.eSuccess );
			} else {
				HEVConsole.Print( "-> Bot Disabled.", EPrintType.eWarning );
			}
			HEVConsole.LineJump();

			// Now checks every one before

			if ( !settingsLoad ) return false;
			if ( !Settings.ConfigValidate() ) return false;

			if ( !configLoad ) return false;
			if ( !Config.ConfigValidate() ) return false;

			Chat = new ChatManager();
			Chat.Start();

			return true;
		}

		public void Update() {

			Chat.Update();
		}
	}
}
