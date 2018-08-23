{
"ItemSlots":
	[
		{
			"Name":			"Default",
			"Description":	""
		},
		{
			"Name":			"World",
			"Description":	""
		},
		{
			"Name":			"Inventory",
			"Description":	""
		},
		{
			"Name":			"Head",
			"Description":	""
		},
		{
			"Name":			"Chest",
			"Description":	""
		},
		{
			"Name":			"RightHand",
			"Description":	""
		},
		{
			"Name":			"LeftHand",
			"Description":	""
		},
		{
			"Name":			"Special",
			"Description":	""
		},
		{
			"Name":			"RightLeg",
			"Description":	""
		},
		{
			"Name":			"LeftLeg",
			"Description":	""
		},
		{
			"Name":			"RightFoot",
			"Description":	""
		},
		{
			"Name":			"LeftFoot",
			"Description":	""
		}
	],
"ItemActions":
	[
		{
			"Name":				"DamagePlayer",
			"Description":		"",
			"Input": 			[ "Inp0", "Inp1" ],
			"InputType": 		[ "int", "int" ],
			"IsPositive":		"false",
			"AffectPlayers":	[ ],
			"AffectItems":		[ ],
			"AffectStats":		[ [ "Health", "Inp0" ] ],
			"AffectAttributes":	[ ],
			"AffectSkills":		[ ]
		},
		{
			"Name":				"DamageSelf",
			"Description":		"",
			"Input": 			[ "Inp0", "Inp1" ],
			"InputType": 		[ "int", "int" ],
			"IsPositive":		"false",
			"AffectPlayers":	[ ],
			"AffectItems":		[ ],
			"AffectStats":		[ [ "Health", "Inp0" ] ],
			"AffectAttributes":	[ ],
			"AffectSkills":		[ ]
		},
		{
			"Name":				"HealthPlayer",
			"Description":		"",
			"Input": 			[ "Inp0", "Inp1" ],
			"InputType": 		[ "int", "int" ],
			"IsPositive":		"true",
			"AffectPlayers":	[ ],
			"AffectItems":		[ ],
			"AffectStats":		[ [ "Health", "Inp0" ] ],
			"AffectAttributes":	[ ],
			"AffectSkills":		[ ]
		},
		{
			"Name":				"HealthSelf",
			"Description":		"",
			"Input": 			[ "Inp0", "Inp1" ],
			"InputType": 		[ "int", "int" ],
			"IsPositive":		"true",
			"AffectPlayers":	[ ],
			"AffectItems":		[ ],
			"AffectStats":		[ [ "Health", "Inp0" ] ],
			"AffectAttributes":	[ ],
			"AffectSkills":		[ ]
		},
		{
			"Name":				"DropItem",
			"Description":		"",
			"Input": 			[ ],
			"InputType": 		[ ],
			"IsPositive":		"~",
			"AffectPlayers":	[ ],
			"AffectItems":		[ ".()self" ],
			"AffectStats":		[ ],
			"AffectAttributes":	[ ],
			"AffectSkills":		[ ]
		}
	],
"Items":
	[
		{
		"Name":			"Knife",
		"Description":	"",
		"Uses":			"",
		"IsReady":		"true",
		"Load":			"0",
		"ItemLoad":		"",
		"Weight":		"",
		"ValidSlots":	[ "" ],
		"Actions": 
			[
				{
					"Skill": [ "Attack" ],
					"Actions": [ ["DamagePlayer", ""] ]
				},
				{
					"Skill": [ "Drop" ],
					"Actions": [ ["DropItem"] ]
				}
			]
		},
		{
		"Name":			"Dagger",
		"Description":	"",
		"Weight":
		},
		"Name":			"Blunderbuss",
		"Description":	"",
		"Weight":
		},
		{
		"Name":			"Hammer",
		"Description":	"",
		"IsPositive":	false
		},
		{
		"Name":			"Canteen",
		"Description":	"",
		"IsPositive":	true
		},
		{
		"Name":			"Cake",
		"Description":	"",
		"IsPositive":	true
		},
		{
		"Name":			"Egg",
		"Description":	"",
		"IsPositive":	true
		}
	]
}