#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
	int flag = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		if (fullscreen)
			flag = SDL_WINDOW_FULLSCREEN;

		// if success to create the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flag);
		if (m_pWindow != 0)
		{
			std::cout << "Window creation success!\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				std::cout << "Renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			} else {
				std::cout << "Renderer init fail\n";
				return false;
			}
		} else {
			std::cout << "Window init fail\n";
			return false;
		}
	} else {
		std::cout << "SDL init fail\n";
		return false;
	}

	std::cout << "Init success\n";
	m_bRunning = true; // if everithing is ok start the game loop!

	return true;
}

void Game::render()
{
	// clear the buffer to draw the color
	SDL_RenderClear(m_pRenderer);

	// draw everything on the screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "Cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}