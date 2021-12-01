#include <iostream>
#include <SDL.h>
#include "Screen.h"

bool isGameRunning = true;

int main(int argc, char* argv[])
{
	// initializes the game
	Screen Init;
	Init.Initialize();
	
	
	// makes the screen
	Screen Presenter;
	Presenter.Present();

	// Main Game Loop
	while (isGameRunning)

	{
		//refreshes the screen
		Screen Refresher;
		Refresher.Refresh();
	}


	// Shuts down the game
	Screen Quitting;
	Quitting.Shutdown();
	return 0;
}