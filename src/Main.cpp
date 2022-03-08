#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Image.h"
#include "Music.h" 
#include "Text.h"

bool isGameRunning = true;
int x = 640;
int y = 360;
bool ubw = false;
bool settings = false;
bool start = true;

int main(int argc, char* argv[])
{
	// initializes the screen
	Screen screen;
	screen.Initialize();

	Image swords(1280, 720);
	swords.Load("../assets/Ubw.png", screen);

	Image mainmenu(1280, 720);
	mainmenu.Load("../assets/BGMenu.png", screen);

	Image optionsmenu(1280, 720);
	optionsmenu.Load("../assets/OptionsMenu.png", screen);

	Image shirou(256, 256);
	shirou.Load("../assets/Shirou.gif", screen);

	Music ubwchant;
	ubwchant.Initialize();
	ubwchant.Load("../audio/shirouchant.mp3");
	ubwchant.SetVolume(0.5);
	ubwchant.Play(Music::Loop::Ongoing);

	Text menu;
	menu.Initialize();
	menu.Load("../fonts/SEGA_Skip-B.ttf");
	menu.SetSize(1200, 100);
	menu.SetColor(144, 115, 182);
	menu.SetString("Press Enter to Start The Game and O to load the Options Menu");

	Text options;
	options.Initialize();
	options.Load("../fonts/SEGA_Skip-B.ttf");
	options.SetSize(1200, 100);
	options.SetColor(144, 115, 182);
	options.SetString("Press P to exit the options menu, and press M to mute the music");

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
			mainmenu.Unload();
			shirou.Unload();
			ubwchant.Unload();
			menu.Unload();
			optionsmenu.Unload();
			isGameRunning = false;
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
		
		if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true)
		{
			ubw = true;
			start = false;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_I) == true)
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

		if (settings == true)
		{
			optionsmenu.Render(screen, 0, 0);
			options.Render(screen, 20, 10);

			if (Input::Instance()->IsKeyPressed(HM_KEY_M) == true)
			{
				/*ubwchant.Stop();*/
				ubwchant.SetVolume(0.0);
				std::cout << "Music Muted" << std::endl;
			}

			if (Input::Instance()->IsKeyPressed(HM_KEY_N) == true)
			{
				/*ubwchant.Play(Music::Loop::Ongoing);*/
				ubwchant.SetVolume(0.5);
				std::cout << "Music Unmuted" << std::endl;
			}

		}

		if (ubw == true)
		{
			//new bg
			swords.Render(screen, 0, 0);
			shirou.Render(screen, x, y);

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
		}

		if (start == true)
		{
			//base bg
			mainmenu.Render(screen, 0, 0);
			menu.Render(screen, 10, 10);
		}
		// presents the screen
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	ubwchant.Shutdown();
	menu.Shutdown();
	return 0;
}
