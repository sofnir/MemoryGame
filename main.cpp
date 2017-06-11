#include "Game.h"
#include "GameStateMenu.h"

int main()
{
	Game game;
	game.pushState(new GameStateMenu(&game));
	game.gameLoop();

	return 0;
}