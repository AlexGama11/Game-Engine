#pragma once
#include <string>
#include "SDL_mixer.h"
class Sound
{

public:

	Sound();

	bool Load(const std::string& filename);
	void Unload(const std::string& tag = "");
	void SetVolume(float volume);
	bool Play(int loop = 0);

private:
	Mix_Chunk* m_sound;
};

