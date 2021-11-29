#include <iostream>
#include <SDL.h>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

bool isGameRunning = true;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not Initialize!" << std::endl;
		return -1;
	}
	
	SDL_CreateWindow("Alex's Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

	if (!window)
	{
		std::cout << "Game Window could not be created!" << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		std::cout << "Renderer could not be created!" << std::endl;
	}

	while (isGameRunning)

	{
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit;
	return 0;
}