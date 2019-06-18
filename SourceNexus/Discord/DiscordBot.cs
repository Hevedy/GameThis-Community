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
using System.Linq;
using HEVLib;
using IniParser.Model;
using System.Threading.Tasks;

using Discord;
using Discord.Commands;
using Discord.WebSocket;
using System.Reflection;

namespace GameThisNexus.Discord {
	public class DiscordBot {
		private DiscordSocketClient DClient;
		private CommandService DCommands;
		private IServiceProvider DProvider;

		public static List<string> CommandsCurrentStrings;
		public static List<int> CommandsCurrentVotes;
		public static List<ulong> LogData;

		public static bool AcceptCommands = false;

		public static void CommandsReset() {
			CommandsCurrentStrings.Clear();
			CommandsCurrentVotes.Clear();
		}

		public static void CommandsCountReset() {
			for ( int i = 0; i < CommandsCurrentVotes.Count; i++ ) {
				CommandsCurrentVotes[i] = 0;
			}
		}

		public static void CommandsUpdate( string[] Commands ) {
			AcceptCommands = false;
			CommandsReset();
			for( int i = 0; i < Commands.Length; i++ ) {
				CommandsCurrentStrings.Add( Commands[i] );
				CommandsCurrentVotes.Add( 0 );
			}
			AcceptCommands = true;

		}

		public static string[] CommandsGetStatus() {
			int count = CommandsCurrentStrings.Count;
			string[] strings = new string[count];
			for ( int i = 0; i < count; i++ ) {
				strings[i] = "#" + i + " - " + CommandsCurrentStrings[i] + " - " + CommandsCurrentVotes[i];
			}
			return strings;

		}

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
			if ( !data.DataINIReadWrite( "Discord", "BotName", ref Instance.DiscordBotName ) ) status = false;
			if ( !data.DataINIReadWrite( "Discord", "BotToken", ref Instance.DiscordBotToken ) ) status = false;
			if ( !data.DataINIReadWrite( "Discord", "UserBlackList", ref Instance.DiscordUserBlackList ) ) status = false;
			if ( !data.DataINIReadWrite( "Discord", "BotBlackList", ref Instance.DiscordBotBlackList ) ) status = false;


			if ( !status ) {
				status = HEVIO.FileINIWrite( Instance.FileConfig, data );
			}
			return status;
		}

		public static bool ConfigValidate() {
			bool status = false;
			if ( !Instance.ConfDiscordBot ) { return status; }
			if ( !HEVText.Validate( Instance.DiscordGuild ) ) return status;
			if ( !HEVText.Validate( Instance.DiscordChannel ) ) return status;
			if ( !HEVText.Validate( Instance.DiscordUserName ) ) return status;
			if ( !HEVText.Validate( Instance.DiscordBotName ) ) return status;
			if ( !HEVText.Validate( Instance.DiscordBotToken ) ) return status;
			status = true;
			return status;
		}

		public static bool ConfigWrite() {
			bool status = false;
			IniData data = null;

			data["Discord"]["Guild"] = Instance.DiscordGuild;
			data["Discord"]["Channel"] = Instance.DiscordChannel;
			data["Discord"]["UserName"] = Instance.DiscordUserName;
			data["Discord"]["BotName"] = Instance.DiscordBotName;
			data["Discord"]["BotToken"] = Instance.DiscordBotToken;
			data["Discord"]["UserBlackList"] = HEVText.ToString( Instance.DiscordUserBlackList );
			data["Discord"]["BotBlackList"] = HEVText.ToString( Instance.DiscordBotBlackList );

			status = HEVIO.FileINIWrite( Instance.FileConfig, data );
			return status;
		}

		private async Task Launch() {
			DClient = new DiscordSocketClient( new DiscordSocketConfig
			{
				LogLevel = LogSeverity.Info
			} );

			DCommands = new CommandService( new CommandServiceConfig
			{
				CaseSensitiveCommands = true,
				DefaultRunMode = RunMode.Async,
				LogLevel = LogSeverity.Debug
			} );


			DClient.MessageReceived += MessageReceived;
			await DCommands.AddModulesAsync( Assembly.GetEntryAssembly(), null );

			DClient.Ready += Ready;
			DClient.Log += Log;

			await DClient.LoginAsync( TokenType.Bot, Instance.DiscordBotToken );
			await DClient.StartAsync();

			await Task.Delay( -1 );
		}

		private async Task Ready() {
			string streamURL = "";
			string userName = Instance.TwitchUserName;
			ActivityType activity = ActivityType.Playing;
			if ( userName != "" ) {
				streamURL = "https://www.twitch.tv/" + userName;
				activity = ActivityType.Streaming;
			} else {
				streamURL = "";
				activity = ActivityType.Playing;
			}
			await DClient.SetGameAsync( Instance.AppName, streamURL, activity );
		}

		private async Task Log( LogMessage _Message ) {
			HEVConsole.Print( $"{DateTime.Now} at {_Message.Source}] {_Message.Message}" );
			try {
				SocketGuild guild = DClient.Guilds.Where( x => x.Id == LogData[0] ).FirstOrDefault();
				SocketTextChannel channel = guild.Channels.Where( x => x.Id == LogData[1] ).FirstOrDefault() as SocketTextChannel;
				await channel.SendMessageAsync( $"{DateTime.Now} at {_Message.Source}] {_Message.Message}" );
			} catch { }
		}

		private async Task MessageReceived( SocketMessage _MessageParam ) {
			var message = _MessageParam as SocketUserMessage;
			SocketCommandContext context = new SocketCommandContext( DClient, message );

			if ( context.Message == null || context.Message.Content == "" ) return;
			if ( context.User.IsBot ) return;
			if ( !(context.Channel.Name == Instance.DiscordChannel || context.IsPrivate ) ) return;


			int argPos = 0;
			if ( !( message.HasStringPrefix( "!", ref argPos ) || message.HasMentionPrefix( DClient.CurrentUser, ref argPos ) ) ) return;



			bool q = CommandsCurrentStrings.Any( w => context.Message.Content.Contains( w ) );
			if ( q ) {

			} else {
				return;
			}

			var result = await DCommands.ExecuteAsync( context, argPos, DProvider );
		}


		private async Task SendRichEmbedAsync( SocketCommandContext _Context ) {
			var embed = new EmbedBuilder();
			embed.WithTitle( "Game Stats" );
			embed.AddField( "Test", "10", true );
			embed.WithThumbnailUrl( "url" );

			try {
				SocketGuild guild = DClient.Guilds.Where( x => x.Id == LogData[0] ).FirstOrDefault();
				SocketTextChannel channel = guild.Channels.Where( x => x.Id == LogData[1] ).FirstOrDefault() as SocketTextChannel;
				await channel.SendMessageAsync( "", false, embed.Build() );
			} catch { }
		}
	}
}
