#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Skeleton.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

Room* createLevel();
Exit* createExit(Room* a, Room* b, Item* key);

int main() {
  Player player;
  Room* start = createRooms();
  
  return 0;
}

// creates all rooms, items, and enemies and returns the starting room.
Room* createLevel() {
  // create items
  Item* rustyDagger = createItem(Item::Type.WEAPON, "Rusty Dagger", "Found on the floor of an unused cell", "The edge is dull, but it's better than nothing.", 1, 2, 3);
  Item* dKey = new Item();
  Item* leatherShoulderpads = new Item();
  Item* bronzeChestplate = new Item();
  
  // create rooms and assign items and enemies
  Room* dCellA = new Room();
  Room* dHall = new Room();
  Room* dCellB = new Room();
  Room* dCellC = new Room();

  // connect rooms together
  Exit* dCellA_dHall = createExit(dCellA, dHall, NULL);
  return dCellA;
}

Item* createItem(Item::Type type, char[64] name, char[256] description, int weight, int cost, int heal, int damage, int defense) {
  
}

// set key to null if the exit is not locked
Exit* createExit(Room* a, Room* b, Item* key) {
  Exit* exit = new Exit()
}
