{
"DiceCommands":
	[
		{
			"Name":				"Dice",
			"Command":			[ "Dice", "Roll" ],
			"InputNeeded":		"true",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
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
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"SkillCall":		[  ]
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
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[  ]
		},
		{
			"Name":				"RandomBool",
			"Description":		"",
			"Command":			[ "GetRandomBool", "RandBool" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[ "True", "False" ]
		},
		{
			"Name":				"RandomNumber",
			"Description":		"",
			"Command":			[ "GetRandomNum", "RandNum" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[ ".RandomNum()" ]
		},
		{
			"Name":				"Join",
			"Description":		"",
			"Command":			[ "Join" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[ ".JoinGame()" ]
		},
		{
			"Name":				"Leave",
			"Description":		"",
			"Command":			[ "Leave" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[ ".LeaveGame()" ]
		},
		{
			"Name":				"GetCharacter",
			"Description":		"",
			"Command":			[ "GetCharacter", "NewCharacter" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[ ".GetNewPlayerCharacter()" ]
		},
		{
			"Name":				"GetCharacter",
			"Description":		"",
			"Command":			[ "Character" ],
			"InputNeeded":		"false",
			"InputDefault":		"",
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ],
			"Text":				[ ".GetPlayerCharacter()" ]
		}
	],
"AutoCommands":
	[
		{
			"Name":				"Web",
			"Command":			[ "Web" ],
			"Text":				[ "Visit our website http://www.hevedy.com/" ],
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ]
		},
		{
			"Name":				"Store",
			"Command":			[ "Store" ],
			"Text":				[ "Check our products https://hevedy.itch.io/" ],
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ]
		},
		{
			"Name":				"Twitter",
			"Command":			[ "Twitter" ],
			"Text":				[ "Follow us on Twitter https://twitter.com/Hevedy" ],
			"GroupsLocked":		[  ],
			"RanksLocked":		[  ]
		},
	]
}