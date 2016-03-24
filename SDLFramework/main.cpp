#include "Game.h"
#include <Windows.h>

Game* g_game = 0;

int main(int argc, char **argv)
{
	AllocConsole();
	freopen("CON", "w", stdout);

	g_game = new Game();

	g_game->init("Chapter 1", 160, 130, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->clean();
	return 0;
}
