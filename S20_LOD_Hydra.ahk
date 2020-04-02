
#NoEnv
#SingleInstance Force
#MaxThreadsPerHotkey 2
SendMode Input

cd_interval := 200
spell_2 := 0

#IfWinActive, Diablo III
{	
	Numpad2::
	{
		if(spell_2 == 0)
		{
			spell_2 := cd_interval
		}
		else
		{
			spell_2 := 0
		}
		SetTimer "Spell_2_On_CD", spell_2		
	}
	return
}

#if
{
	if(spell_2 != 0)
	{
		SetTimer "Spell_2_On_CD", 0	
	}
}


Spell_2_On_CD()
{
	color := PixelGetColor(X, Y , Mode)
	if(color == "")
	{
		Send "{2}"
	}
}
