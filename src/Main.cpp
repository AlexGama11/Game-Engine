#include <iostream>
#include "Input.h"
#include "Screen.h"

bool isGameRunning = true;

int main(int argc, char* argv[])
{
	// initializes the screen
	Screen screen;
	screen.Initialize();

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
			screen.Shutdown();
			isGameRunning = false;
		}


		// presents the screen
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	return 0;
}
