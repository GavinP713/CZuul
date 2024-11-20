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
Item* createItem(Item::Type type, char name[64], char description[256], 
int weight, int cost, int damage, int defense, int heal,
int usesPerTurn, bool canDrop);
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
   - ATTACK 2, PERTURN 2, WEIGHT 1, VALUE 1g");
  Item* rustyDagger = createItem(Item::WEAPON, name, description, 1, 0, 1, 0, 0, 2, true);
  
  strcpy(name, "Dungeon Key");
  strcpy(description, "A small rusted key, unlocks the dungeon
  - WEIGHT 0, VALUE 1g")
  Item* dKey = new Item(Item::KEY, name, description, 0, 1, 0, 0, 0, 0, true);

  strcpy(name, "Leather ShoulderPads");
  strcpy(description, "Well worn shoulderpads. 
  - DEFENSE 1, WEIGHT 1, VALUE 5g")
  Item* leatherShoulderpads = new Item(Item::ARMOR, name, description, 2, 5, 0, 1, 0, 0, true);

  strcpy(name, "Bronze Chestplate");
  strcpy(description, "The sturdy chestplate of a powerful foe, still shiny. 
  - DEFENSE 4, WEIGHT 3, VALUE 50g");
  Item* bronzeChestplate = new Item(Item::ARMOR, name, description, 5, 50, 0, 4, 0, 0, true);

  strcpy(name, "Steel Dagger");
  strcpy(description, "Use it to stab stuff.
  - ATTACK 4, PERTURN 3, WEIGHT 1, VALUE 5g");
  Item* steelDagger = new Item(Item::WEAPON, name, description, 1, 5, 4, 0, 0, 3, true);

  strcpy(name, "Steel Sword");
  strcpy(description, "A sharp sword.
  - ATTACK 8, PERTURN 2, WEIGHT 2, VALUE 25g");
  Item* steelSword = new Item(Item::WEAPON, name, description, 2, 25, 8, 0, 0, 2, true);

  strcpy(name, "Bread");
  strcpy(description, "Stale and flavorless.
  - HEAL 2, WEIGHT 0, VALUE 5g");
  Item* bread = new Item(Item::CONSUMABLE, name, description, 0, 5, 0, 0, 2, 1, true);

  strcpy(name, "Royal Key");
  strcpy(description, "Shiny and golden. Fills you with a sense of granduer. Unlocks the throne room.
  - WEIGHT 0, VALUE 450g");
  Item* tKey = new Item(Item::KEY, name, description, 0, 450, 0, 0, 0, 0, true);

  strcpy(name, "Gem");
  strcpy(description, "A shiny stone.
  - VALUE 12g");
  Item* gem = new Item(Item::VALUABLE, name, description, 0, 12, 0, 0, 0, 0, true);

  strcpy(name, "Rare Gem");
  strcpy(description, "Even shinier, and quite rare.
  - VALUE 90g")
  Item* rareGem = new Item(Item::VALUABLE, name, description, 0, 90, 0, 0, 0, 0, true);

  strcpy(name, "Enemy Armor Weak");
  strcpy(description, "- DEFENSE 2");
  Item* enemyArmorWeak = new Item(Item::ARMOR, name, description, 0, 0, 0, 2, 0, 0, false);

  strcpy(name, "Enemy Armor Medium");
  strcpy(description, "- DEFENSE 5");
  Item* enemyArmorMedium = new Item(Item::ARMOR, name, description, 0, 0, 0, 5, 0, 0, false);

  strcpy(name, "Enemy Armor Strong");
  strcpy(description, "- DEFENSE 10");
  Item* enemyArmorStrong = new Item(Item::ARMOR, name, description, 0, 0, 0, 10, 0, 0, false);

  
  // create rooms and assign items and enemies
  Room* dCellA = new Room(); // start

  Room* dHall = new Room();

  Room* dCellB = new Room();
  dCellB->items.push_back(bread);
  dCellB->items.push_back(bread);

  Room* dCellC = new Room();
  dCellC->items.push_back(rustyDagger);

  Room* dCombat0 = new Room();
  Skeleton* dGuard = new Skeleton();
  dGuard->items.push_back(dKey);
  dGaurd->items.push_back(leatherShoulderpads);
  dGaurd->item.push_back(gem);

  Room* cStairs = new Room();

  Room* cHallWest = new Room();

  Room* cShop0 = new Room(); // shop
  cShop0->items.push_back(bread);
  Merchant cMerchant = new Merchant();
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(bread);
  cMerchant->items.push_back(steelSword);
  cMerchant->items.push_back(steelDagger);
  cMerchant->items.push_back(tKey);
  cShop0->entities.push_back(cMerchant);

  Room* cHallNorth = new Room();

  Room* cCombat0 = new Room();
  cCombat0Skeleton0 = new Skeleton();
  cCombat0Skeleton0->items.push_back(rustyDagger);
  cCombat0->entities.push_back(cCombat0Skeleton0);
  cCombat0Skeleton1 = new Skeleton();
  cCombat0Skeleton1->items.push_back(bread);
  cCombat0Skeleton1->items.push_back(enemyArmorWeak);
  cCombat0->entities.push_back(cCombat0Skeleton1);

  Room* cChest0 = new Room();
  cChest0->items.push_back(steelDagger);
  cChest0->items.push_back(gem);
  cChest0->items.push_back(gem);

  Room* cCombat1 = new Room();
  cCombat1Skeleton0 = new Skeleton();
  cCombat1Skeleton0->items.push_back(enemyArmorMedium);
  cCombat1Skeleton0->items.push_back(rustyDagger);
  cCombat1Skeleton1 = new Skeleton();
  cCombat1Skeleton1->items.push_back(enemyArmorWeak);
  cCombat1Skeleton1->items.push_back(steelDagger);
  cCombat1Skeleton2 = new Skeleton();
  cCombat1Skeleton2->items.push_back(enemyArmorWeak);
  cCombat1Skeleton2->items.push_back(gem);

  Room* cCombat2 = new Room();
  cCombat2Skeleton0 = new Skeleton();
  cCombat2Skeleton0->items.push_back(enemyArmorStrong);
  cCombat2Skeleton0->items.push_back(bronzeChestplate);
  cCombat2Skeleton0->items.push_back(steelDagger);
  cCombat2Skeleton1 = new Skeleton();
  cCombat2Skeleton1->items.push_back(enemyArmorMedium);
  cCombat2Skeleton1->items.push_back(steelSword);
  cCombat2Skeleton2 = new Skeleton();
  cCombat2Skeleton2->items.push_back(enemyArmorMedium);
  cCombat2Skeleton2->items.push_back(steelDagger);
  cCombat2Skeleton2->items.push_back(bread);

  Room* cChest1 = new Room();
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);

  Room* cHallEast = new Room();

  Room* cBoss = new Room(); // end
  cBossSkeleton = new Skeleton();
  cBossSkeleton->items

  // connect rooms together
  createExit(2, dCellA, dHall, NULL);
  createExit(3, dCellB, dHall, NULL);
  createExit(3, dCellC, dHall, NULL);
  createExit(0, dCombat0, dHall, NULL);
  createExit(1, cStairs, dHall, dKey);

  return dCellA;
}

Item* createItem(Item::Type _type, char _name[64], char _description[256], 
int _weight, int _cost, int _damage, int _defense, int _heal,
int _usesPerTurn, bool _canDrop) {
  Item* item = new Item();
  item->type = _type;
  strcpy(item->name, _name);
  strcpy(item->description, _description);
  item->weight = _weight;
  item->cost = _cost;
  item->damage = _damage;
  item->defense = _defense;
  item->heal = _heal;
  item->usesPerTurn = _usesPerTurn;
  item->canDrop = _canDrop;

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
