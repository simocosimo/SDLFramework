#pragma once 

#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

class TextureManager
{
public:

	~TextureManager() {}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	// draw functions
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// static box that can let us use this as a Singleton (class that can only have one instance)
	static TextureManager* s_pInstance;
	static TextureManager* Instance()
	{
		if (s_pInstance == NULL)
			s_pInstance = new TextureManager();

		return s_pInstance;
	}

private:

	// constructor is private because this is a Singleton!
	TextureManager() {}
	std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif