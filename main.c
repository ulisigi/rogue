#include "rogue.h"
#include "game.h"
#include "utils.h"



int main(void)
{
	Game game;
	game.currentLevel = 0;

	screenSetUp();
	gameLoop(&game);
	endwin();
	return 0;
}




