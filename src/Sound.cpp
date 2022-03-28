#include <algorithm>
#include <iostream>
#include <assert.h>
#include "Sound.h"

Sound::Sound()
{
	m_sound = nullptr;
}

bool Sound::Load(const std::string& filename)
{
	m_sound = Mix_LoadWAV(filename.c_str());
	if (!m_sound)
	{
		std::cout << "Error loading sfx." << std::endl;
		return false;
	}

	return true;
}

void Sound::Unload(const std::string& tag)
{
	Mix_FreeChunk(m_sound);
}

void Sound::SetVolume(float volume)
{
	volume = std::clamp(volume, 0.0f, 1.0f);
	Mix_VolumeChunk(m_sound, static_cast<int>(volume * 128.0f));
}

bool Sound::Play(int loop)
{
	if (Mix_PlayChannel(-1, m_sound, loop) == -1)
	{
		std::cout << "Error playing sfx." << std::endl;
		return false;
	}
	return true;
}
