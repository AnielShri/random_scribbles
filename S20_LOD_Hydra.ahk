#SingleInstance Force
#MaxThreadsPerHotkey 2
SendMode Input

cd_interval := 200
spell_2 := 0

#If WinActive("Diablo III")
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

Spell_2_On_CD()
{
	color := PixelGetColor(482, 668)
	if(color == "0x75735D")
	{
		Send "{2}"
	}
}
