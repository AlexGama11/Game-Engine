#include "Keys.h"
#include <iostream>
#include "Input.h"
#include "Music.h" 

bool settings = false;
bool ubw = false;
bool start = true;

int Controls()
{
	
	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN) == true)
	{
		ubw = true;
		start = false;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true)
	{
		start = true;
		ubw = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true)
	{
		settings = true;
		start = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true)
	{
		start = true;
		settings = false;
	}

return 1;
}
