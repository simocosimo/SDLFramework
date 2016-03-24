#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char **argv)
{
	//initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		// if success to create the window
		g_pWindow = SDL_CreateWindow("Chapter 1: Setting Up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	} else {
		return 1; // SDL could not initialize
	}

	// Everything succeeded lets draw the window
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);

	// display the window
	SDL_RenderPresent(g_pRenderer);

	// set a delay before quitting
	SDL_Delay(5000);

	// Quit SDL
	SDL_Quit();

	return 0;
}