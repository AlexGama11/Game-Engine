#include <iostream>
#include "Screen.h"
#include <SDL_image.h>

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

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
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
	// if VSYNC is added, movement should be made faster
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED /* | SDL_RENDERER_PRESENTVSYNC */ );

	//if no renderer
	if (!m_renderer)
	{
		std::cout << "Renderer could not be created!" << std::endl;
	}

	srand(static_cast<unsigned int>(time(0)));
	int IconVersion = rand() % 100 + 1;

	//std::cout << "The Icon Number is: " << IconVersion % 2 << std::endl;

	if (IconVersion % 2 == 0)
	{
		SDL_Surface* m_icon = IMG_Load("../assets/ShirouIconCaladbolg.png");

		SDL_SetWindowIcon(m_window, m_icon);
	}

	else if (IconVersion % 2 == 1)
	{
		SDL_Surface* m_icon = IMG_Load("../assets/ShirouIconExcalibur.png");

		SDL_SetWindowIcon(m_window, m_icon);
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
