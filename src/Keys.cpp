#include "Keys.h"
#include <iostream>
#include "Input.h"
#include "Music.h" 

bool settings = false;
bool ubw = false;
bool start = true;

int Controls()
{
	
	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN) == true && settings == false)
	{
		ubw = true;
		start = false;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true && settings == false)
	{
		start = true;
		ubw = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true && ubw == false)
	{
		settings = true;
		start = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true && ubw == false)
	{
		start = true;
		settings = false;
	}

return 1;
}
