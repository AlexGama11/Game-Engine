#pragma once
#include <SDL.h>

class Screen
{


public:

	//constructor
	Screen();
	//destructor
	~Screen();

	//functions
	bool Initialize();
	void Refresh();
	void Present();
	void Shutdown();


private:

	//pointers
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};

