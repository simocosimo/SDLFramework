#pragma once

#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

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

	// variables for texturing and animations
	int m_currentFrame;

	// GameObjects
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	std::vector<GameObject*> m_gameObjects;

};


#endif
