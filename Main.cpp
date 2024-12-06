#include "Room.h"
#include "Item.h"
#include "Entity.h"

#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

Room* createLevel();
void createExit(Room* roomA, int index, Room* roomB, Item* key);
void enterRoom(Room* room, Room* currentRoom);
int oppositeExit(int exit);
void printCommands();

int main() {
  cout << "Welcome to Zuul!" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  printCommands();
  cout << "" << endl;
  cout << "" << endl;
  cout << "Type help to display these commands whenever you want" << endl;
  
  char name[64];
  char description[256];
  strcpy(name, "You");
  strcpy(description, "");
  
  Entity* player = new Entity(name, description, Entity::PLAYER);
  Room* currentRoom = NULL;
  
  Room* start = createLevel();
  enterRoom(start, currentRoom);

  // Game loop
  char input[64];
  while (true) {
    cin >> input;
    
    if (strcmp(input, "move") == 0) {
      cout << "direction: ";
      cin >> input;
      
      if (strcmp(input, "north") == 0) {
	      enterRoom(currentRoom->getRoom(0), currentRoom);
      }
      else if (strcmp(input, "south") == 0) {
        enterRoom(currentRoom->getRoom(1), currentRoom);
      }
      else if (strcmp(input, "east") == 0) {
        enterRoom(currentRoom->getRoom(2), currentRoom);
      }
      else if (strcmp(input, "west") == 0) {
        enterRoom(currentRoom->getRoom(3), currentRoom);
      }
      else if (strcmp(input, "cancel") == 0) {
        continue;
      }
    }
    else if (strcmp(input, "pickup") == 0) {
      cout << "item name: ";
      cin >> input;

      if (strcmp(input, "cancel") == 0) {
        continue;
      }
    }
    else if (strcmp(input, "quit") == 0) {
      cout << "good riddance" << endl;
      return;
    }
    else {
      cout << "Unkown command!" << endl;
    }
  }
  
  return 0;
}

void enterRoom(Room* room, Room* currentRoom) {
  cout << "" << endl;
  cout << "" << endl;

  // direction player attempted to go has no associated exit
  if (room == NULL) {
    cout << "Room doesnt exist" << endl;
  }
  // enter the new room
  else {
    currentRoom = room;

    // print room
    cout << room->name << "---------------------------" << endl;
    cout << room->description << endl;

    // print items
    cout << "" << endl;
    cout << "Items" << endl;
    if (room->items.size() == 0) cout << "No items" << endl;
    else foreach(Item* item in room->items) cout << item->name << ", " << endl;

    // print entities
    cout << "" << endl;
    cout << "Entities" << endl;
    if (room->entities.size() == 0) cout << "No entities" << endl;
    else foreach(Entity* entity in room->entities) cout << entity->name << ", " << endl;

    // print exits
    cout << "" << endl;
    cout << "Exits" << endl;
    if (room->getExit(0) != NULL) cout << "North: " << room->name << endl;
    if (room->getExit(1) != NULL) cout << "South: " << room->name << endl;
    if (room->getExit(2) != NULL) cout << "East: " << room->name << endl;
    if (room->getExit(3) != NULL) cout << "West: " << room->name << endl;
  }
}

// creates all rooms, items, and enemies and returns the starting room.
Room* createLevel() {
  // create items
  char name[64];
  char description[256];

  strcpy(name, "Rusty Dagger");
  strcpy(description, "Found on the floor of an unused cell,\
	 the edge is dull, but it's better than nothing.\
   - ATTACK 2, PERTURN 2, WEIGHT 1, VALUE 1g");
  Item* rustyDagger = new Item(Item::WEAPON, name, description, 1, 0, 1, 0, 0, 2, true);
  
  strcpy(name, "Dungeon Key");
  strcpy(description, "A small rusted key, unlocks the dungeon\
  - WEIGHT 0, VALUE 1g");
  Item* dKey = new Item(Item::KEY, name, description, 0, 1, 0, 0, 0, 0, true);

  strcpy(name, "Leather ShoulderPads");
  strcpy(description, "Well worn shoulderpads.\
- DEFENSE 1, WEIGHT 1, VALUE 5g");
  Item* leatherShoulderpads = new Item(Item::ARMOR, name, description, 2, 5, 0, 1, 0, 0, true);

  strcpy(name, "Bronze Chestplate");
  strcpy(description, "The sturdy chestplate of a powerful foe, still shiny.\
  - DEFENSE 4, WEIGHT 3, VALUE 50g");
  Item* bronzeChestplate = new Item(Item::ARMOR, name, description, 5, 50, 0, 4, 0, 0, true);

  strcpy(name, "Steel Dagger");
  strcpy(description, "Use it to stab stuff.\
  - ATTACK 4, PERTURN 3, WEIGHT 1, VALUE 5g");
  Item* steelDagger = new Item(Item::WEAPON, name, description, 1, 5, 4, 0, 0, 3, true);

  strcpy(name, "Steel Sword");
  strcpy(description, "A sharp sword.\
  - ATTACK 8, PERTURN 2, WEIGHT 2, VALUE 25g");
  Item* steelSword = new Item(Item::WEAPON, name, description, 2, 25, 8, 0, 0, 2, true);

  strcpy(name, "Bread");
  strcpy(description, "Stale and flavorless.\
  - HEAL 2, WEIGHT 0, VALUE 5g");
  Item* bread = new Item(Item::CONSUMABLE, name, description, 0, 5, 0, 0, 2, 1, true);

  strcpy(name, "Royal Key");
  strcpy(description, "Shiny and golden. Fills you with a sense of granduer.\
unlocks the throne room.\
  - WEIGHT 0, VALUE 450g");
  Item* tKey = new Item(Item::KEY, name, description, 0, 450, 0, 0, 0, 0, true);

  strcpy(name, "Gem");
  strcpy(description, "A shiny stone.\
  - VALUE 12g");
  Item* gem = new Item(Item::VALUABLE, name, description, 0, 12, 0, 0, 0, 0, true);

  strcpy(name, "Rare Gem");
  strcpy(description, "Even shinier, and quite rare.\
  - VALUE 90g");
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
  strcpy(name, "Your Cell");
  strcpy(description, "You awaken in a damp cell, confused, shivering, and having no memory of arriving here.");
  Room* dCellA = new Room(name, description); // start

  strcpy(name, "Cell 1");
  strcpy(description, "It's empty");
  Room* dHall = new Room(name, description);

  strcpy(name, "Cell 2");
  strcpy(description, "The skeleton of a prisoner long dead lay in the corner.");
  Room* dCellB = new Room(name, description);
  dCellB->items.push_back(bread);
  dCellB->items.push_back(bread);

  strcpy(name, "Cell 3");
  strcpy(description, "Small tick marks span the wall.");
  Room* dCellC = new Room(name, description);
  dCellC->items.push_back(rustyDagger);

  strcpy(name, "Warden's chamber");
  strcpy(description, "A small stone room with a wooden desk and bed");
  Room* dCombat0 = new Room(name, description);
  strcpy(name, "Skeleton Warden");
  strcpy(description, "It seems violent. Wears leather shoulder pads");
  Entity* dGuard = new Entity(name, description, Entity::ENEMY);
  dGuard->items.push_back(dKey);
  dGuard->items.push_back(leatherShoulderpads);
  dGuard->items.push_back(gem);

  strcpy(name, "Stair");
  strcpy(description, "Winding stone stairs that lead from the dungeon to the castle.");
  Room* cStairs = new Room(name, description);

  strcpy(name, "West Hall");
  strcpy(description, "A large stone hallway, darkness shrouds the path forward");
  Room* cHallWest = new Room(name, description);

  strcpy(name, "Shop");
  strcpy(description, "Looks to have been an armory before the merchant repurposed it");
  Room* cShop0 = new Room(name, description); // shop
  cShop0->items.push_back(bread);
  strcpy(name, "Merhcant");
  strcpy(description, "A friendly looking merchant");
  Entity* cMerchant = new Entity(name, description, Entity::MERCHANT);
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

  strcpy(name, "North Hall");
  strcpy(description, "torches line the wall, leading to a mysterious door");
  Room* cHallNorth = new Room(name, description);

  strcpy(name, "Chamber 1");
  strcpy(description, "An old bedroom");
  Room* cCombat0 = new Room(name, description);
  strcpy(name, "Skeleton A");
  strcpy(description, "wields a rusty dagger");
  Entity* cCombat0Skeleton0 = new Entity(name, description, Entity::ENEMY);
  cCombat0Skeleton0->items.push_back(rustyDagger);
  cCombat0->entities.push_back(cCombat0Skeleton0);
  strcpy(name, "Skeleton B");
  strcpy(description, "unarmed");
  Entity* cCombat0Skeleton1 = new Entity(name, description, Entity::ENEMY);
  cCombat0Skeleton1->items.push_back(bread);
  cCombat0Skeleton1->items.push_back(enemyArmorWeak);
  cCombat0->entities.push_back(cCombat0Skeleton1);

  strcpy(name, "Closet");
  strcpy(description, "A chest lies inside");
  Room* cChest0 = new Room(name, description);
  cChest0->items.push_back(steelDagger);
  cChest0->items.push_back(gem);
  cChest0->items.push_back(gem);

  strcpy(name, "Chamber 2");
  strcpy(description, "An older bedroom");
  Room* cCombat1 = new Room(name, description);
  strcpy(name, "Skeleton A");
  strcpy(description, "Wears medium armor, wields a rusty dagger");
  Entity* cCombat1Skeleton0 = new Entity(name, description, Entity::ENEMY);
  cCombat1Skeleton0->items.push_back(enemyArmorMedium);
  cCombat1Skeleton0->items.push_back(rustyDagger);
  strcpy(name, "Skeleton B");
  strcpy(description, "Wears weak armor, wields a steel dagger");
  Entity* cCombat1Skeleton1 = new Entity(name, description, Entity::ENEMY);
  cCombat1Skeleton1->items.push_back(enemyArmorWeak);
  cCombat1Skeleton1->items.push_back(steelDagger);
  strcpy(name, "Skeleton C");
  strcpy(description, "Wears weak armor, unarmed");
  Entity* cCombat1Skeleton2 = new Entity(name, description, Entity::ENEMY);
  cCombat1Skeleton2->items.push_back(enemyArmorWeak);
  cCombat1Skeleton2->items.push_back(gem);

  strcpy(name, "Chamber 3");
  strcpy(description, "The oldest bedroom");
  Room* cCombat2 = new Room(name, description);
  strcpy(name, "Skeleton A");
  strcpy(description, "Wears strong armor and a bronze chestplate, wields a steel dagger");
  Entity* cCombat2Skeleton0 = new Entity(name, description, Entity::ENEMY);
  cCombat2Skeleton0->items.push_back(enemyArmorStrong);
  cCombat2Skeleton0->items.push_back(bronzeChestplate);
  cCombat2Skeleton0->items.push_back(steelDagger);
  strcpy(name, "Skeleton B");
  strcpy(description, "Wears medium armor, wields a steel sword");
  Entity* cCombat2Skeleton1 = new Entity(name, description, Entity::ENEMY);
  cCombat2Skeleton1->items.push_back(enemyArmorMedium);
  cCombat2Skeleton1->items.push_back(steelSword);
  strcpy(name, "Skeleton C");
  strcpy(description, "Wears medium armor, wields a steel dagger");
  Entity* cCombat2Skeleton2 = new Entity(name, description, Entity::ENEMY);
  cCombat2Skeleton2->items.push_back(enemyArmorMedium);
  cCombat2Skeleton2->items.push_back(steelDagger);
  cCombat2Skeleton2->items.push_back(bread);

  strcpy(name, "Closet");
  strcpy(description, "A large chest lies inside");
  Room* cChest1 = new Room(name, description);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);
  cChest1->items.push_back(rareGem);

  strcpy(name, "Hallway East");
  strcpy(description, "A gilded stone hallway, large double doors lie at the end; the entrance to the castle");
  Room* cHallEast = new Room(name, description);

  strcpy(name, "Outside");
  strcpy(description, "The large doors swings open, light streams in, you have escaped the castle.");
  Room* cOutside = new Room(name, description); // end

  // connect rooms together
  createExit(dCellA, 2, dHall, NULL);
  createExit(dCellB, 3, dHall, NULL);
  createExit(dCellC, 3, dHall, NULL);
  createExit(dCombat0, 0, dHall, NULL);
  createExit(cStairs, 1, dHall, dKey);

  return dCellA;
}

// set key to null if the exit is not locked.
// (side corresponds to cardinal directions: 0 = n, 1 = s, 2 = e, 3 = w)
void createExit(Room* roomA, int index, Room* roomB, Item* key) {
  bool locked = (key == NULL) ? false : true;
  
  Room::Exit* exit = new Room::Exit(roomA, roomB, key, locked);
  roomA->setExit(index, exit);
  roomB->setExit(oppositeExit(index), exit);
  //roomB->exits[getOppositeExit(exit)] = new Room::Exit(roomA, key, locked);
}

// get index of exit on opposite side of room
int oppositeExit(int exit) {
  // if exit is even, add to get opposite
  if (exit % 2 == 0)
  {
      return exit + 1;
  }
  // if exit is odd, subtract to get opposite
  else
  {
      return exit - 1;
  }
}

void printCommands() {
  cout << "" << endl;
  cout << "Commands" << endl;
  
  cout << "help: display a list of valid commands" << endl;
  cout << "move: moves into room at direction if it exists" << endl;
  cout << "     EX" << endl;
  cout << "     move north" << endl;
  cout << "     move south" << endl;
  cout << "     move east" << endl;
  cout << "     move west" << endl;
  cout << "pickup: puts an item in the current room into your inventory" << endl;
  cout << "     EX" << endl;
  cout << "     pickup Bread" << endl;
  cout << "     pickup Key" << endl;
  cout << "attack: attempt to damage a hostile entity of the name provided in the current room, the amount of damage is the sum of damage values from the weapons in your inventory" << endl;
  cout << "     EX" << endl;
  cout << "     attack Skeleton" << endl;
  cout << "inventory: display the items in your inventory" << endl;
  cout << "scan: display the items and entities in the current room" << endl;
}