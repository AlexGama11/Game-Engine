#pragma once
#include "Screen.h"
#include "Texture.h"
#include "Music.h"
#include "Text.h"

class Player
{

public:
	int PlayerStart(Screen& screen);
	int PlayerRender(Screen& screen);
	int PlayerMove();
	int PlayerUnload();

private:
	Texture m_shirou;

};

extern int x;
extern int y;

