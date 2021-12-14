#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Image.h"

bool isGameRunning = true;
int x = 640;
int y = 360;
bool ubw = false;

int main(int argc, char* argv[])
{
	// initializes the screen
	Screen screen;
	screen.Initialize();

	Image swords(1280, 720);
	swords.Load("../assets/UBW.jpg", screen);

	Image fuyuki(1280, 720);
	fuyuki.Load("../assets/fuyuki.jpg", screen);

	Image shirou(100, 100);
	shirou.Load("../assets/Shirou.png", screen);

	// Main Game Loop
	while (isGameRunning)

	{
		//refreshes the screen
		screen.Refresh();

		//returns pointer to class
		Input::Instance()->Update();

		//closes window
		isGameRunning = !(Input::Instance()->IsWindowClosed());


		//alternate way I made as a test to close the game.
		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
		{
			swords.Unload();
			fuyuki.Unload();
			shirou.Unload();
			screen.Shutdown();
			isGameRunning = false;
		}

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

		if (Input::Instance()->IsKeyPressed(HM_KEY_I) == true)
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
		
		if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true)
		{
            ubw = true;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_F) == true)
		{
			ubw = false;
		}


		if (ubw == true)
		{
			//new bg
			swords.Render(screen, 0, 0);
			shirou.Render(screen, x, y);
		}
		else if (ubw == false)
		{
			//base bg
			fuyuki.Render(screen, 0, 0);
			shirou.Render(screen, x, y);

			// presents the screen
		}
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	return 0;
}
