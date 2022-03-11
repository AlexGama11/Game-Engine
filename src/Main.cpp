﻿#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Image.h"
#include "Music.h"
#include "Text.h"
#include "UBW.h"
#include "Keys.h"

bool isGameRunning = true;
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

	Music bgmusic;
	bgmusic.Initialize();
	bgmusic.Load("../audio/pressgardenact2.mp3");
	bgmusic.SetVolume(v);
	bgmusic.Play(Music::Loop::Ongoing);

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

		//alternate way I made as a test to close the game.
		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
		{
			swords.Unload();
			mainmenu.Unload();
			shirou.Unload();
			menu.Unload();
			optionsmenu.Unload();
			isGameRunning = false;
		}

		int commands = Controls();

		if (settings == true)
		{
			optionsmenu.Render(screen, 0, 0);
			options.Render(screen, 40,40);

			if (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true || Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
			{
				v -= 0.01;
				bgmusic.SetVolume(v);
				std::cout << "Music Volume:" << v << std::endl;
			}

			if (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true || Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
			{
				v += 0.01;
				bgmusic.SetVolume(v);
				std::cout << "Music Volume:" << v << std::endl;
			}
		}

		if (ubw == true)
		{
			//new bg
			swords.Render(screen, 0, 0);
			shirou.Render(screen, x, y);

			int controls = UBWControls();

		}

		if (start == true)
		{
			//base bg
			mainmenu.Render(screen, 0, 0);
			menu.Render(screen, 40, 40);
		}

		if (v < 0)
		{
			v = 0.0;
		}

		if (v > 1)
		{
			v = 1.0;
		}

		// presents the screen
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	menu.Shutdown();
	return 0;
}
