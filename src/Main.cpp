﻿#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Image.h"
#include "Music.h" 
#include "Text.h"

bool isGameRunning = true;
int x = 640;
int y = 360;
bool ubw = false;
int keypress = 0;

int main(int argc, char* argv[])
{
	// initializes the screen
	Screen screen;
	screen.Initialize();

	Image swords(1280, 720);
	swords.Load("../assets/UBW.jpg", screen);

	Image fuyuki(1280, 720);
	fuyuki.Load("../assets/fuyuki.jpg", screen);

	Image shirou(100, 100);
	shirou.Load("../assets/Shirou.png", screen);

	Music ubwchant;
	ubwchant.Initialize();
	ubwchant.Load("../audio/shirouchant.mp3");
	ubwchant.SetVolume(0.5f);

	Text chant;
	chant.Initialize();
	chant.Load("../fonts/SEGA_Skip-B.ttf");
	chant.SetSize(800, 50);
	chant.SetColor(213, 217, 153);
	chant.SetString("Press WASD to move, and U to be the bone of your sword!");

	Text KoH;
	KoH.Initialize();
	KoH.Load("../fonts/SEGA_Skip-B.ttf");
	KoH.SetSize(1280, 100);
	KoH.SetColor(213, 217, 153);
	KoH.SetString("Here I come, King of Heroes. Do you have enough weapons in stock?");

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
			fuyuki.Unload();
			shirou.Unload();
			ubwchant.Unload();
			chant.Unload();
			isGameRunning = false;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)
		{
			x += 10;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)
		{
			x -= 10;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_W) == true)
		{
			y -= 10;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_S) == true)
		{
			y += 10;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true)
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
			//music, inside parenthese is for a loop
			ubwchant.Play(/*Music::Loop:Ongoing*/);
			SDL_Delay(27000);
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_I) == true)
		{
				ubw = false;
				ubwchant.Stop();
		}


		if (ubw == true)
		{
			//new bg
			swords.Render(screen, 0, 0);
			shirou.Render(screen, x, y);
			KoH.Render(screen, 10, 10);
		}
		else if (ubw == false)
		{
			//base bg
			fuyuki.Render(screen, 0, 0);
			shirou.Render(screen, x, y);
			chant.Render(screen, 10, 10);

			// presents the screen
		}
		screen.Present();
	}

	// Shuts down the game
	screen.Shutdown();
	ubwchant.Shutdown();
	chant.Shutdown();
	return 0;
}
