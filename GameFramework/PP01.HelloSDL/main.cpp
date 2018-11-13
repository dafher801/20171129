#include "Game.h"

Game * game = 0;

int main(int argc, char * argv[])
{
	game = new Game;
	game->init("Chapter 1", 100, 100, 640, 480, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	SDL_Delay(5000);
	game->clean();

	return 0;
}