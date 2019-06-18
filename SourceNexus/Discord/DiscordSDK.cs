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

using Discord;
using Discord.Commands;
using Discord.WebSocket;
using System.Reflection;

namespace GameThisNexus.Discord {
	public class DiscordSDK {

		public static bool Status() {
			return false;
		}

		public static bool ConfigRead() {
			bool status = false;
			IniData data = null;
			(data, status) = HEVIO.FileINIRead( Instance.FileConfig );
			if ( !status ) {
				if ( !ConfigWrite() ) {
					return false;
				} else {
					return true;
				}
			}

			if ( !data.DataINIReadWrite( "Discord", "Guild", ref Instance.DiscordGuild ) ) status = false;
			if ( !data.DataINIReadWrite( "Discord", "Channel", ref Instance.DiscordChannel ) ) status = false;
			if ( !data.DataINIReadWrite( "Discord", "UserName", ref Instance.DiscordUserName ) ) status = false;


			if ( !status ) {
				status = HEVIO.FileINIWrite( Instance.FileConfig, data );
			}
			return status;
		}

		public static bool ConfigValidate() {
			bool status = false;
			if ( !Instance.ConfDiscordSDK ) { return status; }
			if ( !HEVText.Validate( Instance.DiscordGuild ) ) return status;
			if ( !HEVText.Validate( Instance.DiscordChannel ) ) return status;
			if ( !HEVText.Validate( Instance.DiscordUserName ) ) return status;
			status = true;
			return status;
		}

		public static bool ConfigWrite() {
			bool status = false;
			IniData data = null;

			data["Discord"]["Guild"] = Instance.DiscordGuild;
			data["Discord"]["Channel"] = Instance.DiscordChannel;
			data["Discord"]["UserName"] = Instance.DiscordUserName;

			status = HEVIO.FileINIWrite( Instance.FileConfig, data );
			return status;
		}
	}
}
