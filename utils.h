#pragma once

#ifndef UTILS_H
#define UTILS_H

#include "level.h"
#include "position.h"
#include "player.h"
#include "monster.h"

void pathFind(Position* start, Position* end);

int screenSetUp();
int printGameHub(Level* level);
int combat(Player* player, Monster* monster, int order);
// void printInventory(Player* player);

#endif