#pragma once

#include <string>
#include <SDL_mixer.h>

class Music
{

public:
	enum class Loop
	{
		//types of loops
		Once = 1,
	    Ongoing = -1
	};

	Music();
	// stereo frequency, chunks is how big data chunks are by default
	bool Initialize(int frequency = 44100, int chunkSize = 1024);
    //loading needs a filename, second part is saying that it needs a tag
	bool Load(const std::string& filename/*, const std::string& tag*/);
    //need to check out tags
	void Unload(/*const std::string& tag = ""*/);
	//shuts down
	void Shutdown();

	//volume
	void SetVolume(float volume);

	//player loops once by default
	bool Play(Loop loop = Loop::Once);
	void Pause();
	void Resume();
	void Stop();

private:

	//pointer to music data
	Mix_Music* m_music;

};

