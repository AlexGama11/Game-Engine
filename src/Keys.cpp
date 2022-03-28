#include "Keys.h"
#include <iostream>
#include "Input.h"
#include "Sound.h"
#include "GameManager.h"

bool settings = false;
bool ubw = false;
bool start = true;

int Keys::Controls()
{
	m_sfx.Load("../audio/button.wav");
	m_sfx.SetVolume(v);

	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN) == true && settings == false && !isSoundPlayed)
	{
		m_sfx.Play();
		isSoundPlayed = true;
		ubw = true;
		start = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_U) == true && settings == false && !isSoundPlayed)
	{
		m_sfx.Play();
		isSoundPlayed = true;
		start = true;
		ubw = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true && ubw == false && !isSoundPlayed)
	{
		m_sfx.Play();
		isSoundPlayed = true;
		settings = true;
		start = false;
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true && ubw == false && !isSoundPlayed)
	{
		m_sfx.Play();
		isSoundPlayed = true;
		start = true;
		settings = false;
	}

	static float time = 0.0f;
	time += 0.01;
	if (time > 0.65f)
	{
		isSoundPlayed = false;
		time = 0.0f;
	}

	return 0;
}
