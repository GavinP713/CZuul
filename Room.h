#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include "Entity.h"
#include <vector>

class Room;

class Room {
 public:
  // connects two rooms together
  struct Exit {
    Room* roomA;
    Room* roomB;
    Item* key;
    bool locked;
    
    Exit(Room* _roomA, Room* _roomB, Item* _key, bool _locked) {
      roomA = _roomA;
      roomB = _roomB;
      key = _key;
      locked = _locked;
    }
  };
  
  
  char name[64];
  char description[256];
  
  vector<Item*> items;
  vector<Entity*> entities;

  // corresponds to cardinal directions
  // i = 0: N
  // i = 1: S
  // i = 2: E
  // i = 3: W
  Exit* exits[4];
  
  Room(char _name[64], char _description[256]) {
    strcpy(name, _name);
    strcpy(description, _description);
  }

  Exit* getExit(int i) {
    return exits[i];
  }

  void setExit(int index, Exit* exit) {
    exits[index] = exit;
  }
};

#endif