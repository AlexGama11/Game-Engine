#include <iostream>
#include "GameManager.h"
#include "Screen.h"
#include "Texture.h"
#include "Music.h"
#include "Text.h"
#include "Input.h"
#include "Keys.h"
#include "Player.h"
#include "Sound.h"
#include "Save.h"

bool isGameRunning = true;
bool isSoundPlayed = false;
float v = 0.5;
std::string musicSelected;
std::string gamerName = "Player 1";
Player player;
Keys keys;
Save save;

int GameManager::Initializer()
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
	m_screen.Initialize();

	m_swords.Load("../assets/Ubw.png", m_screen);
	m_swords.SetSourceDimension(1, 1, 1280, 720);
	m_swords.SetTextureDimension(1280, 720);
	m_swords.isAnimated(false);

	m_menu.Load("../assets/BGMenu.png", m_screen);
	m_menu.SetSourceDimension(1, 1, 1280, 720);
	m_menu.SetTextureDimension(1280, 720);
	m_menu.isAnimated(false);

	m_options.Load("../assets/OptionsMenu.png", m_screen);
	m_options.SetSourceDimension(1, 1, 1280, 720);
	m_options.SetTextureDimension(1280, 720);
	m_options.isAnimated(false);
	
	player.PlayerStart(m_screen);

	m_bgMusic.Initialize();
	m_bgMusic.Load(musicSelected);
	m_bgMusic.SetVolume(v);
	m_bgMusic.Play(Music::Loop::Ongoing);

	m_sfx.Load("../audio/button.wav");
	m_sfx.SetVolume(v);

	m_startText.Initialize();
	m_startText.Load("../fonts/SEGA_Skip-B.ttf");
	m_startText.SetSize(1200, 100);
	m_startText.SetColor(144, 115, 182);
	m_startText.SetString("Press Enter to Start The Game, and U to return from it. To access the options menu, click O");

	m_optionsText.Initialize();
	m_optionsText.Load("../fonts/SEGA_Skip-B.ttf");
	m_optionsText.SetSize(1200, 100);
	m_optionsText.SetColor(144, 115, 182);
	m_optionsText.SetString("Press P to exit the options menu, N to change your name, and the arrow or W and S keys to change the volume");

	m_volumeText.Initialize();
	m_volumeText.Load("../fonts/SEGA_Skip-B.ttf");
	m_volumeText.SetSize(600, 100);
	m_volumeText.SetColor(144, 115, 182);

	m_playerName.Initialize();
	m_playerName.Load("../fonts/SEGA_Skip-B.ttf");
	m_playerName.SetSize(600, 100);
	m_playerName.SetColor(144, 115, 182);

	return 0;
}

int GameManager::GameRunning()
{
	//refreshes the screen
	m_screen.Refresh();

	//returns pointer to class
	Input::Instance()->Update();

	////closes window
	isGameRunning = !(Input::Instance()->IsWindowClosed());

	keys.Controls();

	if (settings == true)
	{
		m_options.Render(m_screen, 0, 0);
		m_optionsText.Render(m_screen, 40, 40);
		std::string volumeString = std::to_string(v);
		m_volumeText.SetString("Current Volume: " + volumeString);
		m_volumeText.Render(m_screen, 40, 120);
		save.LoadFile();
		m_playerName.SetString("Player Name: " + gamerName);
		m_playerName.Render(m_screen, 40, 260);


		if (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true || Input::Instance()->IsKeyPressed(HM_KEY_S) == true && !isSoundPlayed)
		{
			v -= 0.01;
			std::string volumeString = std::to_string(v);
			m_volumeText.SetString("Current Volume: " + volumeString);
			m_bgMusic.SetVolume(v);
			m_sfx.SetVolume(v);
			m_sfx.Play();
			std::cout << "Music Volume:" << v << std::endl;
			isSoundPlayed = true;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true || Input::Instance()->IsKeyPressed(HM_KEY_W) == true && !isSoundPlayed)
		{
			v += 0.01;
			std::string volumeString = std::to_string(v);
			m_volumeText.SetString("Current Volume: " + volumeString);
			m_bgMusic.SetVolume(v);
			m_sfx.SetVolume(v);
			m_sfx.Play();
			std::cout << "Music Volume:" << v << std::endl;
			isSoundPlayed = true;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_N) == true && !isSoundPlayed)
		{
			m_sfx.Play();
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

			save.SaveFile();
			m_playerName.SetString("Player Name: " + gamerName);
			m_playerName.Render(m_screen, 40, 260);
			isSoundPlayed = true;
		}
	}

	if (ubw == true)
	{
		//new bg
		m_swords.Render(m_screen, 0, 0);
		player.PlayerRender(m_screen);
		player.PlayerMove();
		
	}

	if (start == true)
	{
		//base bg
		m_menu.Render(m_screen, 0, 0);
		m_startText.Render(m_screen, 40, 40);
	}

	if (v < 0)
	{
		v = 0.0;
	}

	if (v > 1)
	{
		v = 1.0;
	}

	m_screen.Present();

	return 1;
}

int GameManager::Shutdown()
{
	m_swords.Unload();
	m_menu.Unload();
	m_startText.Unload();
	m_optionsText.Unload();
	player.PlayerUnload();
	m_options.Unload();
	m_playerName.Unload();
	m_sfx.Unload();
	isGameRunning = false;
	return 2;
}

int GameManager::Quit()
{
	m_screen.Shutdown();
	m_startText.Shutdown();
	m_optionsText.Shutdown();
	m_playerName.Shutdown();
	return 3;
}

GameManager::~GameManager()
{
	m_swords.Unload();
	m_menu.Unload();
	m_startText.Unload();
	m_optionsText.Unload();
	m_options.Unload();
	m_playerName.Unload();
}
