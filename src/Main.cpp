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

	//	gets mouse coords
		/*auto mousePosition = Input::Instance()->GetMousePosition();

	    std::cout << "Mouse Position: " << mousePosition.x << ", " << mousePosition.y << std::endl;*/

		/*gets mouse movement*/
		/*auto mouseMotion = Input::Instance()->GetMouseMotion();

	    std::cout << "Mouse Motion: " << mouseMotion.x << ", " << mouseMotion.y << std::endl;*/

	//	gets mouse wheel movement
		/*auto mouseWheel = Input::Instance()->GetMouseWheel();

		std::cout << "Mouse Wheel: " << mouseWheel << std::endl;*/

		//checks if space is clicked
		if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE) == true)
		{
			std::cout << "Spacebar" << std::endl;
		}

		//prints the key thats pressed. Works good with printable keys only.
		std::cout << Input::Instance()->GetKey() << std::endl;

		//checks if left mouse is clicked
		if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == true)
		{
			std::cout << "Left Mouse Click" << std::endl;
		}

		//alternate way I made as a test to close the game.
		/*if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)
		{
			screen.Shutdown();
		}*/


		// presents the screen
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	return 0;
}
