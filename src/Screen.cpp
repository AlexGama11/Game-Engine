#include <iostream>
#include <SDL.h>
#include "Screen.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

bool Screen::Initialize()
{

	//initializes
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not Initialize!" << std::endl;
		return -1;
	}

    return false;
}

void Screen::Refresh()
{

	//Clears the Screen
	SDL_RenderClear(renderer);

	//Swaps the Frame buffer
	SDL_RenderPresent(renderer);

}

void Screen::Present()
{

	//makes window
	window = SDL_CreateWindow("Alex's Game Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		0);

	//if no window
	if (!window)
	{
		std::cout << "Game Window could not be created!" << std::endl;
	}

	// makes renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//if no renderer
	if (!renderer)
	{
		std::cout << "Renderer could not be created!" << std::endl;
	}

}

void Screen::Shutdown()
{
	//shutdown game
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit;

}
