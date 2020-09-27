#include "rogue.h"
#include "utils.h"

int combat(Player* player, Monster* monster, int order)
{
	if (order == 1)
	{
		monster->health -= player->attack;
		if (monster->health > 0)
		{
			player->health -= monster->attack;
		}
		else
		{
			killMonster(monster);
			player->exp++;
		}
	}
	else
	{
		player->health -= monster->attack;
		if (player->health > 0)
		{
			monster->health -= player->attack;
		}
	}

	return 1;
}