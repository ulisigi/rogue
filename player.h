#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "position.h"
#include "item.h"

int MAX_ITEMS;

typedef struct Player
{
	Position* position;
	int health;
	int attack;
	int gold;
	int maxHealth;
	int exp;
	int numberItems;
	// Room* room;
	Item** items;
} Player;

Player* playerSetUp();
Position* handleInput(int input, Player* user);
int playerMove(Position* newPosition, Player* user, char** level);
void drawPlayer(Player* player);

#endif