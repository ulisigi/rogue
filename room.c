#include "rogue.h"
#include "room.h"

Room* createRoom(int grid, int numberOfDoors)
{
	Room* newRoom;
	newRoom = malloc(sizeof(Room));
	newRoom->numberOfDoors = numberOfDoors;

	switch (grid)
	{
		case 0:
			newRoom->position.x = 0;
			newRoom->position.y = 0;
			break;
		case 1:
			newRoom->position.x = 33;
			newRoom->position.y = 0;
			break;
		case 2:
			newRoom->position.x = 66;
			newRoom->position.y = 0;
			break;
		case 3:
			newRoom->position.x = 0;
			newRoom->position.y = 14;
			break;
		case 4:
			newRoom->position.x = 33;
			newRoom->position.y = 14;
			break;
		case 5:
			newRoom->position.x = 66;
			newRoom->position.y = 14;
			break;
	}

	newRoom->height = rand() % 6 + 4;
	newRoom->width = rand() % 14 + 4;

	newRoom->position.x += rand() % (30 - newRoom->width) + 1;
	newRoom->position.y += rand() % (10 - newRoom->height) + 1;

	newRoom->doors = malloc(sizeof(Door*) * numberOfDoors);
	for (int i = 0; i < numberOfDoors; i++)
	{
		newRoom->doors[i] = malloc(sizeof(Door));
		newRoom->doors[i]->connected = 0;
	}

	// Top door
	newRoom->doors[0]->position.x = rand() % (newRoom->width - 2) + newRoom->position.x + 1;
	newRoom->doors[0]->position.y = newRoom->position.y;

	// Left door
	newRoom->doors[1]->position.y = rand() % (newRoom->height - 2) + newRoom->position.y + 1;
	newRoom->doors[1]->position.x = newRoom->position.x;

	// Bottom door
	newRoom->doors[2]->position.x = rand() % (newRoom->width - 2) + newRoom->position.x + 1;
	newRoom->doors[2]->position.y = newRoom->position.y + newRoom->height - 1;

	// Right door
	newRoom->doors[3]->position.y = rand() % (newRoom->height - 2) + newRoom->position.y + 1;
	newRoom->doors[3]->position.x = newRoom->position.x + newRoom->width - 1;

	return newRoom;
}

int drawRoom(Room* room)
{
	int x;
	int y;

	// Top and bottom
	for (x = room->position.x; x < room->position.x + room->width; x++)
	{
		mvprintw(room->position.y, x, "-");
		mvprintw(room->position.y + room->height - 1, x, "-");
	}

	for (y = room->position.y + 1; y < room->position.y + room->height - 1; y++)
	{
		// Side walls
		mvprintw(y, room->position.x, "|");
		mvprintw(y, room->position.x + room->width - 1, "|");

		// Floors
		for (x = room->position.x + 1; x < room->position.x + room->width - 1; x++)
		{
			mvprintw(y, x, ".");
		}
	}

	// Doors
	mvprintw(room->doors[0]->position.y, room->doors[0]->position.x, "+");
	mvprintw(room->doors[1]->position.y, room->doors[1]->position.x, "+");
	mvprintw(room->doors[2]->position.y, room->doors[2]->position.x, "+");
	mvprintw(room->doors[3]->position.y, room->doors[3]->position.x, "+");

	return 1;
}

int placePlayer(Room** rooms, Player* user)
{
	user->position->x = rooms[3]->position.x + 1;
	user->position->y = rooms[3]->position.y + 1;

	// move(user->position->y, user->position->x);
	return 1;
}

int setStartingPosition(Monster* monster, Room* room)
{
	monster->position->x = (rand() % (room->width - 2)) + room->position.x + 1;
	monster->position->y = (rand() % (room->height - 2)) + room->position.y + 1;

	return 1;
}