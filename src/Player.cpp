#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "Screen.h"
#include "Texture.h"
#include "Music.h"
#include "Text.h"
#include "Input.h"

int x = 640;
int y = 360;

int Player::PlayerStart(Screen& screen)
{

	m_shirou.Load("../assets/ShirouUBW-Sheet.png", screen);
	m_shirou.SetSourceDimension(5, 1, 160, 32);
	m_shirou.SetTextureDimension(64, 64);
	m_shirou.isAnimated(true);
	m_shirou.isAnimationLooping(true);
	m_shirou.SetAnimationSpeed(5.0f);

	return 0;
}

int Player::PlayerRender(Screen& screen)
{
	m_shirou.Update();
	m_shirou.Render(screen, x, y);
	return 0;
}

int Player::PlayerMove()
{
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

	return 0;
}

int Player::PlayerUnload()
{
	m_shirou.Unload();
	return 0;
}
