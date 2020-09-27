#include "rogue.h"
#include "monster.h"

Monster* selectMonster(int level)
{
	int monster = 0;
	switch (level)
	{
		case 1:
		case 2:
		case 3:
			monster = (rand() % 2) + 1;
			break;

		case 4:
		case 5:
			monster = (rand() % 2) + 2;
			break;

		case 6:
			monster = 3;
			break;
	}

	switch (monster)
	{
		case 1:
			return createMonster('X', 2, 1, 1, 1, 1);
		case 2:
			return createMonster('G', 5, 3, 1, 1, 2);
		case 3:
			return createMonster('T', 15, 5, 1, 1, 1);
	}
}

Monster* createMonster(char symbol, int health, int attack, int speed, int defense, int pathfinding)
{
	Monster* newMonster;
	newMonster = malloc(sizeof(Monster));

	newMonster->symbol = symbol;
	newMonster->health = health;
	newMonster->attack = attack;
	newMonster->speed = speed;
	newMonster->defense = defense;
	newMonster->pathfinding = pathfinding;
	newMonster->alive = 1;

	sprintf_s(newMonster->string, "%c", symbol);

	newMonster->position = malloc(sizeof(Position));

	return newMonster;
}

int killMonster(Monster* monster)
{
	monster->alive = 0;

	return 1;
}

int pathfindingRandom(Position* position)
{
	int random;
	random = rand() % 5;

	switch (random)
	{
		case 0:
			if (mvinch(position->y - 1, position->x) == '.')
			{
				position->y = position->y - 1;
			}
			break;
		case 1:
			if (mvinch(position->y + 1, position->x) == '.')
			{
				position->y = position->y + 1;
			}
			break;
		case 2:
			if (mvinch(position->y, position->x - 1) == '.')
			{
				position->x = position->x - 1;
			}
			break;
		case 3:
			if (mvinch(position->y, position->x + 1) == '.')
			{
				position->x = position->x + 1;
			}
			break;
		case 4:
			break;
	}

	return 1;
}

int pathfindingSeek(Position* start, Position* destination)
{
	if ((abs((start->x - 1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x - 1) == '.'))
	{
		start->x = start->x - 1;
	}

	else if ((abs((start->x + 1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x + 1) == '.'))
	{
		start->x = start->x + 1;
	}

	else if ((abs((start->y + 1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y + 1, start->x) == '.'))
	{
		start->y = start->y + 1;
	}

	else if ((abs((start->y - 1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y - 1, start->x) == '.'))
	{
		start->y = start->y - 1;
	}
	else 
	{
		// do nothing
	}

	return 1;
}

Monster* getMonsterAt(Position* position, Monster** monsters)
{
	int x;
	for (x = 0; x < 6; x++)
	{
		if ((position->y == monsters[x]->position->y) && (position->x == monsters[x]->position->x))
		{
			return monsters[x];
		}
	}

	return NULL;
}

void drawMonster(Monster* monster)
{
	if (monster->alive)
	{
		mvprintw(monster->position->y, monster->position->x, monster->string);
	}
}