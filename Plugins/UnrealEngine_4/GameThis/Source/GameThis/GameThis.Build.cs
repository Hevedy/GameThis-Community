/*
===========================================================================
This code is part of the "Source Code" content in
Game This - Community by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/GameThis-Community>

The MIT License (MIT)
Copyright (c) 2018-2019 David Palacios (Hevedy) <https://github.com/Hevedy>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================
*/

/*
================================================
GameThis.Build.cs
================================================
*/


using UnrealBuildTool;
using System.IO;

public class GameThis : ModuleRules
{
	public GameThis(ReadOnlyTargetRules Target) : base(Target)
	{
		
		//bEnforceIWYU = false;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add( Path.Combine( ModuleDirectory, "Public" ) );
        PrivateIncludePaths.Add( Path.Combine( ModuleDirectory, "Private" ) );

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Sockets",
				"Networking"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"RHI",
				"RenderCore",
				"HTTP",
				"UMG", "Slate", "SlateCore",
				"ImageWrapper"
				// ... add private dependencies that you statically link with here ...
			}
			);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
