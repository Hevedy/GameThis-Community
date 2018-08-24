{
"DiceCommands":
	[
		{
			"Name":				"Dice",
			"Command":			[ "Dice", "Roll" ],
			"InputNeeded":		"true",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ]
			"DiceGroupCall":	[ "Default" ]
		}
	],
"SkillCommands":
	[
		{
			"Name":				"Attack",
			"Command":			[ "Attack" ],
			"InputNeeded":		"true",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"SkillCall":		[ "" ]
		}
	],
"Commands":
	[
		{
			"Name":				"Ping",
			"Description":		"",
			"Command":			[ "Ping" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ "" ]
		},
		{
			"Name":				"RandomBool",
			"Description":		"",
			"Command":			[ "GetRandomBool", "RandBool" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ "True", "False" ]
		},
		{
			"Name":				"RandomNumber",
			"Description":		"",
			"Command":			[ "GetRandomNum", "RandNum" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ ".RandomNum()" ]
		},
		{
			"Name":				"Join",
			"Description":		"",
			"Command":			[ "Join" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ ".JoinGame()" ]
		},
		{
			"Name":				"Leave",
			"Description":		"",
			"Command":			[ "Leave" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ ".LeaveGame()" ]
		},
		{
			"Name":				"GetCharacter",
			"Description":		"",
			"Command":			[ "GetCharacter", "NewCharacter" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ ".GetNewPlayerCharacter()" ]
		},
		{
			"Name":				"GetCharacter",
			"Description":		"",
			"Command":			[ "Character" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[ "" ],
			"Text":				[ ".GetPlayerCharacter()" ]
		}
	]
}