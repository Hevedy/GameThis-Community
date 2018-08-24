{
"SkillResults":
	[
		{
			"Name":			"Fail",
			"Description":	"Total fail at execute the action.",
			"IsPositive":	"false",
			"Text":			"FAIL"
		},
		{
			"Name":			"Close",
			"Description":	"Missed for a bit.",
			"IsPositive":	"false",
			"Text":			"CLOSE"
		},
		{
			"Name":			"Approved",
			"Description":	"On target.",
			"IsPositive":	"true",
			"Text":			"APPROVED"
		},
		{
			"Name":			"Success",
			"Description":	"Complete success",
			"IsPositive":	"true",
			"Text":			"SUCCESS"
		}
	]
"Skills": 
	[
		{
			"Name":			"Attack",
			"Description":	"",
			"Input": 		[ "Inp0", "Inp1" ],
			"InputType": 	[ "int", "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"0",
			"Level":		"Inp1",
			"LevelDefault":	"0",
			"LevelMax":		"10"
			"NeedItem":		"true",
			"ValidItem":	[ "" ]
			"Text":			[ "@User Attack the player @Target and " ]
			"OnUse":		
			[
				{
					"Level": 		[ "0", "1", "2" ],
					"Result": 
					[
						{
							"DiceValues":	[ "0-6" ],
							"Type":			"Fail",
							"Text":			[ "missed at hit the target" ]
						},
						{
							"DiceValues":	[ "7", "8", "9", "10" ],
							"Type":			"Approved",
							"Text":			[ "hit the target, but that was a close one." ]
						},
						{
							"DiceValues":	[ "11", "12" ],
							"Result":			"Success",
							"Text":			[ "total hit the target." ]
						}
					]
				}
				{
					"Level": 		[ "3", "4", "5" ],
					"Result": 
					[
						{
							"DiceValues":	[ "0-5" ],
							"Type":			"Fail",
							"Text":			[ "missed at hit the target" ]
						},
						{
							"DiceValues":	[ "6-10" ],
							"Type":			"Approved",
							"Text":			[ "hit the target, but that was a close one." ]
						},
						{
							"DiceValues":	[ "11-12" ],
							"Type":			"Success",
							"Text":			[ "total hit the target." ]
						}
					]
				}
			]
		},
		{
			"Name":			"Walk",
			"Description":	"",
			"Input": 		[ "Inp0", "Inp1" ],
			"InputType": 	[ "int", "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"0",
			"Level":		"Inp1",
			"LevelDefault":	"0",
			"LevelMax":		"10"
			"NeedItem":		"false",
			"ValidItem":	[ "" ]
		},
		{
			"Name":			"Drink",
			"Description":	"",
			"Input": 		[ "Inp0", "Inp1" ],
			"InputType": 	[ "int", "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"0",
			"Level":		"Inp1",
			"LevelDefault":	"0",
			"LevelMax":		"10"
			"NeedItem":		"true",
			"ValidItem":	[ "" ]
		},
		{
			"Name":			"Eat",
			"Description":	"",
			"Input": 		[ "Inp0", "Inp1" ],
			"InputType": 	[ "int", "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"0",
			"Level":		"Inp1",
			"LevelDefault":	"0",
			"LevelMax":		"10"
			"NeedItem":		"true",
			"ValidItem":	[ "" ]
		},
		{
			"Name":			"Craft",
			"Description":	"",
			"Input": 		[ "Inp0", "Inp1" ],
			"InputType": 	[ "int", "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"0",
			"Level":		"Inp1",
			"LevelDefault":	"0",
			"LevelMax":		"10"
			"NeedItem":		"true",
			"ValidItem":	[ "" ]
		}
	],
"Attributes": 
	[
		{
			"Name":			"Athletics",
			"Description":	"",
			"Input": 		[ "Inp0" ],
			"InputType": 	[ "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"-0"
		},
		{
			"Name":			"Strength",
			"Description":	"",
			"Input": 		[ "Inp0" ],
			"InputType": 	[ "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"10"
		},
		{
			"Name":			"Cooking",
			"Description":	"",
			"Input": 		[ "Inp0" ],
			"InputType": 	[ "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMax":	"-0"
		}
	],
"Stats": 
	[
		{
			"Name":			"Health",
			"Description":	"",
			"Input": 		[ "Inp0" ],
			"InputType": 	[ "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"100",
			"AmountMin":	"-0",
			"AmountMax":	"-0"
		},
		{
			"Name":			"Armor",
			"Description":	"",
			"Input": 		[ "Inp0" ],
			"InputType": 	[ "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"0",
			"AmountMin":	"0",
			"AmountMax":	"100"
		},
		{
			"Name":			"Stamina",
			"Description":	"",
			"Input": 		[ "Inp0" ],
			"InputType": 	[ "int" ],
			"Amount:		"Inp0",
			"AmountDefault:	"100",
			"AmountMin":	"0",
			"AmountMax":	"100"
		}
	],
"Traits":
	[
		{
			"Name":			"Pacifist",
			"Description":	"",
			"IsPositive":	"true"
		},
		{
			"Name":			"Anemic",
			"Description":	"",
			"IsPositive":	"false"
		}
	],
"CharacterClasses":
	[
		{
			"Name":			"Assasin",
			"Description":	"",
			"Stats":		[ ["Health", "100"], ["Armor", "10"], ["Stamina"] ],
			"Attributes":	[ ["Athletics", "1"], ["Strength", "2"] ],
			"Skills":		[ ["Walk"], ["Drink"] ],
			"Slots":		[ "Head", "Chest" ],
			"Inventory":	[ "" ]
		},
		{
			"Name":			"Thief",
			"Description":	"",
			"Stats":		[ ["Health", "100"], ["Armor", "10"], ["Stamina"] ],
			"Attributes":	[ ["Athletics", "1"], ["Strength", "2"] ],
			"Skills":		[ ["Walk"], ["Drink"] ],
			"Slots":		[ "Head", "Chest" ],
			"Inventory":	[ "" ]
		}
	],
"CharacterRank":
	[
		{
			"Name":			"Easy",
			"Description":	"",
			"Level":		"0"
		},
		{
			"Name":			"Default",
			"Description":	"",
			"Level":		"1"
		},
		{
			"Name":			"Hard",
			"Description":	"",
			"Level":		"2"
		},
		{
			"Name":			"Boss",
			"Description":	"",
			"Level":		"3"
		}
	]
"Characters":
	[
		{
			"Name":				"Alex the Assasin",
			"Description":		"",
			"Class":			"Assasin",
			"Traits":			[ ],
			"Inventory":		[ "" ]
		
		}
		{
			"Name":				"Harry the Thief",
			"Description":		"",
			"Class":			"Thief",
			"Traits":			[ "Pacifist" ],
			"Inventory":		[ "" ]
		
		}
	],
}