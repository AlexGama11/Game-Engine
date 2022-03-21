#include <iostream>
#include "Input.h"
#include "GameManager.h"


int main(int argc, char* argv[])
{
	GameManager gameManager;
	gameManager.Initializer();

	while (isGameRunning)
	{
		isGameRunning = !(Input::Instance()->IsWindowClosed());

		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
		{
			gameManager.Shutdown();
		}
		gameManager.GameRunning();
	}

	// Shuts down the game
	gameManager.Quit();
	return 0;
}