#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Skeleton.h"

#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

Room* createLevel();
Item* createItem(Item::Type type, char name[64], char description[256], int weight, int cost, int damage, int defense, int heal);
void createExit(int exit, Room* roomA, Room* roomB, Item* key);

int main() {
  Player player;
  Room* start = createLevel();
  
  return 0;
}

// creates all rooms, items, and enemies and returns the starting room.
Room* createLevel() {
  // create items
  char name[64];
  char description[256];

  strcpy(name, "Rusty Dagger");
  strcpy(description, "Found on the floor of an unused cell,\
	 the edge is dull, but it's better than nothing.
   - ATTACK 1, WEIGHT 1, COST 1");
  Item* rustyDagger = createItem(Item::WEAPON, name, description, 1, 0, 1, 0, 0);
  
  strcpy(name, "Dungeon Key");
  strcpy(description, "A small rusted key, unlocks the dungeon")
  Item* dKey = new Item();

  strcpy(name, "Leather ShoulderPads");
  strcpy(description, "Well worn shoulderpads. 
  - DEFENSE 1, WEIGHT 1, COST 5")
  Item* leatherShoulderpads = new Item(Item::ARMOR, name, description, 2, 5, 0, 1, 0);

  strcpy(name, "Bronze Chestplate");
  strcpy(description, "The sturdy chestplate of a powerful foe, still shiny. 
  - DEFENSE 4, WEIGHT 3, COST 50");
  Item* bronzeChestplate = new Item(Item::ARMOR, name, description, 5, 50, 0, 4, 0);
  
  // create rooms and assign items and enemies
  Room* dCellA = new Room(); // start
  Room* dHall = new Room();
  Room* dCellB = new Room();
  Room* dCellC = new Room();
  dCellC->items.push_back(rustyDagger);

  Room* dCombat0 = new Room();
  Skeleton* dGuard = new Skeleton();
  dGuard->items.push_back(dKey);
  
  Room* cStairs = new Room();
  Room* cHallWest = new Room();
  Room* cShop0 = new Room(); // shop
  Room* cHallNorth = new Room();
  Room* cCombat0 = new Room();
  Room* cChest0 = new Room();
  Room* cCombat1 = new Room();
  Room* cCombat2 = new Room();
  Room* cChest1 = new Room();
  Room* cHallEast = new Room();
  Room* cBoss = new Room(); // end

  // connect rooms together
  createExit(2, dCellA, dHall, NULL);
  createExit(3, dCellB, dHall, NULL);
  createExit(3, dCellC, dHall, NULL);
  createExit(0, dCombat0, dHall, NULL);
  createExit(1, cStairs, dHall, dKey);

  return dCellA;
}

Item* createItem(Item::Type _type, char _name[64], char _description[256], int _weight, int _cost, int _damage, int _defense, int _heal) {
  Item* item = new Item();
  item->type = _type;
  strcpy(item->name, _name);
  strcpy(item->description, _description);
  item->weight = _weight;
  item->cost = _cost;
  item->damage = _damage;
  item->defense = _defense;
  item->heal = _heal;

  return item;
}

// set key to null if the exit is not locked.
// (side corresponds to cardinal directions: 0 = n, 1 = s, 2 = e, 3 = w)
void createExit(int exit, Room* roomA, Room* roomB, Item* key) {
  bool locked = (key == null) ? false : true;
  roomA.exits[exit] = new Room::Exit(roomB, key, locked);
  roomB.exits[oppositeExit(exit)] = new Room::Exit(roomA, key, locked);
}

// get index of exit on opposite side of room
int oppositeExit(int exit) {
  // if exit is even, add to get opposite
  if (point % 2 == 0)
  {
      return point + 1;
  }
  // if exit is odd, subtract to get opposite
  else
  {
      return point - 1;
  }
}
