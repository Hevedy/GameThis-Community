{
"ActionResultTypes":
	[
		{
		"Name":			"SUCCESS",
		"Description":	"",
		"IsPositive":	true
		},
		{
		"Name":			"FAIL",
		"Description":	"",
		"IsPositive":	false
		}
	]
"Actions":
	[
		{
		"Name":				"Attack",
		"Description":		"",
		"Command":			"Attack",
		"InputNeeded":		true
		"InputDefault":		""
		"GroupsLocked":		[ "" ]
		"CharacterLocked":	[ "Hunter" ]
		"Reply":			[ "" ]
		"Effects":
				[
					{
						"Name":			"",
						"Description":	"",
						"Type":			"SUCCESS",
						"DiceMin":		1,
						"DiceMax":		10,
						"Reply":		[ "You hit the enemmy successfully!" ]
					},
					{
						"Name":			"",
						"Description":	"",
						"Type":			"FAIL",
						"DiceMin":		11,
						"DiceMax":		20,
						"Reply":		[ "You missed at attack the enemy." ]
					}
				]
			
		}
	]
}