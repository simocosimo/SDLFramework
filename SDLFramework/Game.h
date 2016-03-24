#pragma once

#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <iostream>

class Game
{
public:

	Game() {}
	~Game() {}

	// TODO: better implementation for different flags, not just for fullscreen
	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

private:
	// variable for the window, renderer and the game cycle
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	bool m_bRunning;

	// variables for the textures
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
};


#endif
