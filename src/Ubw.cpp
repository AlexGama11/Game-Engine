#include "Ubw.h"
#include <iostream>
#include "Input.h"


int x = 640;
int y = 360;


int UBWControls()
{

	if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)
	{
		x += 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)
	{
		x -= 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
	{
		y -= 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
	{
		y += 1;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_F) == true)
	{
		std::cout << "Image position is:" << x << ", " << y << std::endl;
	}

	if (x > 1280)
	{
		x = 0;
	}

	if (x < 0)
	{
		x = 1280;
	}

	if (y > 720)
	{
		y = 0;
	}

	if (y < 0)
	{
		y = 720;
	}

	return 1;
}