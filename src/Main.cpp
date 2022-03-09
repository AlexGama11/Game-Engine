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
float v = 0.5;

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
	ubwchant.SetVolume(v);
	ubwchant.Play(Music::Loop::Ongoing);

	Music button;
	button.Initialize();
	button.Load("../audio/Button.wav");
	button.SetVolume(v);

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
	options.SetString("Press P to exit the options menu and change the volume with the arrow keys or the W and S keys");

	// Main Game Loop
	while (isGameRunning)

	{
		//refreshes the screen
		screen.Refresh();

		//returns pointer to class
		Input::Instance()->Update();

		//closes window
		isGameRunning = !(Input::Instance()->IsWindowClosed());

		if (!button.Play())
		{
			ubwchant.Resume();
		}

		else if (button.Play())
		{
			ubwchant.Pause();
		}

		//alternate way I made as a test to close the game.
		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
		{
			swords.Unload();
			mainmenu.Unload();
			shirou.Unload();
			ubwchant.Unload();
			menu.Unload();
			optionsmenu.Unload();
			button.Unload();
			isGameRunning = false;
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
		
		if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN) == true)
		{
			ubw = true;
			start = false;
			button.Play(Music::Loop::Once);
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true)
		{
			start = true;
			ubw = false;
			button.Play(Music::Loop::Once);
		}

		else if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true)
		{
			settings = true;
			start = false;
			button.Play(Music::Loop::Once);
		}

		else if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true)
		{
			start = true;
			settings = false;
			button.Play(Music::Loop::Once);
		}

		if (settings == true)
		{
			optionsmenu.Render(screen, 0, 0);
			options.Render(screen, 40,40);

			if (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true || Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
			{
				v -= 0.1;
				ubwchant.SetVolume(v);
				button.SetVolume(v);
				std::cout << "Music Volume:" << v <<  std::endl;
				button.Play(Music::Loop::Once);
			}

			if (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true || Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
			{
				v += 0.1;
				ubwchant.SetVolume(v);
				button.SetVolume(v);
				std::cout << "Music Volume:" << v << std::endl;
				button.Play(Music::Loop::Once);
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

			if (Input::Instance()->IsKeyPressed(HM_KEY_F) == true)
			{
				std::cout << "Image position is:" << x << ", " << y << std::endl;
			}

		}

		if (start == true)
		{
			//base bg
			mainmenu.Render(screen, 0, 0);
			menu.Render(screen, 40, 40);
		}

		if (v < 0)
		{
			v = 0;
		}

		if (v > 1)
		{
			v = 1;
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
