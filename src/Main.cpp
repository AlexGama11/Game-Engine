#include <iostream>
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

		// presents the screen
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	return 0;
}
