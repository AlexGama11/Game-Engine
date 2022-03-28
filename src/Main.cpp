﻿#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Texture.h"
#include "Music.h"
#include "Text.h"
#include "UBW.h"
#include "Keys.h"

bool isGameRunning = true;
static float v = 0.5;
std::string musicSelected;
std::string gamerName = "Player 1";

int main(int argc, char* argv[])
{
	srand(static_cast<unsigned int>(time(0)));
	int BgAudio = rand() % 100 + 1;

	std::cout << "The Music Number is: " << BgAudio << std::endl;

	if (BgAudio <= 32)
	{
		musicSelected = "../audio/pressgardenact2.mp3";
	}

	else if (BgAudio > 32 && BgAudio <= 64)
	{
		musicSelected = "../audio/the-hot-wind-is-blowing-extended.mp3";
	}

	else if (BgAudio > 64 && BgAudio < 96)
	{
		musicSelected = "../audio/one-winged-angel-music.mp3";
	}

	else if (BgAudio >= 96)
	{
		musicSelected = "../audio/coracao-nao-tem-idade-vou-beijar.mp3";
		std::cout << "Congratulations! You just got the Easter Egg Music! It's a 4% Chance!" << std::endl;
	}

	// initializes the screen
	Screen screen;
	screen.Initialize();

	Texture swords(1280, 720);
	swords.Load("../assets/Ubw.png", screen);
	swords.SetSourceDimension(1, 1, 1280, 720);
	swords.SetTextureDimension(1280, 720);
	swords.isAnimated(false);

	Texture mainmenu(1280, 720);
	mainmenu.Load("../assets/BGMenu.png", screen);
	mainmenu.SetSourceDimension(1, 1, 1280, 720);
	mainmenu.SetTextureDimension(1280, 720);
	mainmenu.isAnimated(false);

	Texture optionsmenu(1280, 720);
	optionsmenu.Load("../assets/OptionsMenu.png", screen);
	optionsmenu.SetSourceDimension(1, 1, 1280, 720);
	optionsmenu.SetTextureDimension(1280, 720);
	optionsmenu.isAnimated(false);

	Texture shirou;
	shirou.Load("../assets/ShirouUBW-Sheet.png", screen);
	shirou.SetSourceDimension(5, 1, 160, 32);
	shirou.SetTextureDimension(64, 64);
	shirou.isAnimated(true);
	shirou.isAnimationLooping(true);
	shirou.SetAnimationSpeed(5.0f);

	Music bgmusic;
	bgmusic.Initialize();
	bgmusic.Load(musicSelected);
	bgmusic.SetVolume(v);
	bgmusic.Play(Music::Loop::Ongoing);

	Text menu;
	menu.Initialize();
	menu.Load("../fonts/SEGA_Skip-B.ttf");
	menu.SetSize(1200, 100);
	menu.SetColor(144, 115, 182);
	menu.SetString("Press Enter to Start The Game, and U to return from it. To access the options menu, click O");

	Text options;
	options.Initialize();
	options.Load("../fonts/SEGA_Skip-B.ttf");
	options.SetSize(1200, 100);
	options.SetColor(144, 115, 182);
	options.SetString("Press P to exit the options menu, N to change your name, and the arrow or W and S keys to change the volume");

	Text volume;
	volume.Initialize();
	volume.Load("../fonts/SEGA_Skip-B.ttf");
	volume.SetSize(600, 100);
	volume.SetColor(144, 115, 182);

	Text playerName;
	playerName.Initialize();
	playerName.Load("../fonts/SEGA_Skip-B.ttf");
	playerName.SetSize(600, 100);
	playerName.SetColor(144, 115, 182);

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
			options.Unload();
			optionsmenu.Unload();
			playerName.Unload();
			isGameRunning = false;
		}

		int commands = Controls();

		if (settings == true)
		{
			optionsmenu.Render(screen, 0, 0);
			options.Render(screen, 40,40);
			std::string volumeString = std::to_string(v);
			volume.SetString("Current Volume: " + volumeString);
			volume.Render(screen, 40, 120);
			playerName.SetString("Player Name: " + gamerName);
			playerName.Render(screen, 40, 260);


			if (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true || Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
			{
				v -= 0.01;
				std::string volumeString = std::to_string(v);
				volume.SetString("Current Volume: " + volumeString);
				bgmusic.SetVolume(v);
				std::cout << "Music Volume:" << v << std::endl;
			}

			if (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true || Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
			{
				v += 0.01;
				std::string volumeString = std::to_string(v);
				volume.SetString("Current Volume: " + volumeString);
				bgmusic.SetVolume(v);
				std::cout << "Music Volume:" << v << std::endl;
			}

			if (Input::Instance()->IsKeyPressed(HM_KEY_N) == true)
			{
				std::cout << "What is your new name?" << std::endl;
				std::cin >> gamerName;
				std::cin.get();
				while (std::cin.fail())
				{
					std::cout << "Your name cannot be used within the game!" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> gamerName;
				}

				playerName.SetString("Player Name: " + gamerName);
				playerName.Render(screen, 40, 260);
			}
		}

		if (ubw == true)
		{
			//new bg
			swords.Render(screen, 0, 0);
			shirou.Update();
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
