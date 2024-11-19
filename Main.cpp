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
Exit* createExit(Room* a, Room* b, Item* key);

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

  strcpy(name, "Rust Dagger");
  strcpy(description, "Found on the floor of an unused cell,\
	 the edge is dull, but it's better than nothing.");
  Item* rustyDagger = createItem(Item::WEAPON, name, description, 1, 1, 1, 1, 1);
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
// (direction corresponds to cardinal directions: 0 = n, 1 = s, 2 = e, 3 = w)
void createExit(int side, Room* roomA, Room* roomB, Item* _key) {
  
  return exit;
}
