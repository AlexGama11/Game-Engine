#include <iostream>
#include <SDL.h>
#include "Screen.h"

bool isGameRunning = true;

int main(int argc, char* argv[])
{
    // Variable to call from screen class
	Screen Main;
	
	// initializes the game
	Main.Initialize();
	
	
	// makes the screen
	Main.Present();

	// Main Game Loop
	while (isGameRunning)

	{
		//refreshes the screen
		Main.Refresh();
	}


	// Shuts down the game
	Main.Shutdown();
	return 0;
}
