#include <iostream>
#include "Screen.h"

//constructor
Screen::Screen()
{
	//pointers
    m_window = nullptr;
    m_renderer = nullptr;
}

//destructor
Screen::~Screen()
{

}

bool Screen::Initialize()
{

	//initializes
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not Initialize!" << std::endl;
		return -1;
	}

	//makes window
	m_window = SDL_CreateWindow("Alex's Game Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		0);

	//if no window
	if (!m_window)
	{
		std::cout << "Game Window could not be created!" << std::endl;
	}
	// makes renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	//if no renderer
	if (!m_window)
	{
		std::cout << "Renderer could not be created!" << std::endl;
	}

    return false;
}



void Screen::Refresh()
{

	//Clears the Screen
	SDL_RenderClear(m_renderer);

}

void Screen::Present()
{
	//Swaps the Frame buffer
	SDL_RenderPresent(m_renderer);
}

void Screen::Shutdown()
{
	//shutdown game
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit;

}
