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
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
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

	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animation.bmp");
	if (pTempSurface == NULL)
		std::cout << "Can't load the BMP file, check the file path or the image extension!";
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	//SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	// std::cout << m_sourceRectangle.h ;
	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 80;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	return true;
}

void Game::render()
{
	// clear the buffer to draw the color
	SDL_RenderClear(m_pRenderer);

	// here in the middle i can apply textures
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

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

void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}
