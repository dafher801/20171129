#include "Game.h"
#include "TextureManager.h"

Game * game = 0;

int main(int argc, char * argv[])
{
	game = new Game;
	game->init("PP08.SingletonTM", 100, 100, 640, 480, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}