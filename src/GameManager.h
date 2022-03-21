#pragma once
#include "Screen.h"
#include "Texture.h"
#include "Music.h"
#include "Text.h"

class GameManager
{

public:
	int Initializer();
	int GameRunning();
	int Shutdown();
	int Quit();

	GameManager();
	~GameManager();
private:

	Screen m_screen;
	Texture m_swords;
	Texture m_menu;
	Texture m_options;
	Texture m_shirou;
	Music m_bgMusic;
	Text m_startText;
	Text m_optionsText;
	Text m_volumeText;
	Text m_playerName;

};

extern bool isGameRunning;