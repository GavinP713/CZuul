#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include "Entity.h"
#include <vector>

class Room;

// exits to other rooms
struct Exit {
  Room* room;
  Item* key;
  bool locked;

  /*
  Exit(){
    room = NULL;
    key = NULL;
    locked = false;
    };*/
  Exit(Room* _room, Item* _key, bool _locked) {
    room = _room;
    key = _key;
    locked = _locked;
    }
};

class Room {
 public:
  char name[64];
  char description[256];
  
  vector<Item*> items;
  vector<Entity*> entities;

  // corresponds to cardinal directions
  // i = 0: N
  // i = 1: S
  // i = 2: E
  // i = 3: W
  Exit exits[4];
  
  Room(char _name[64], char _description[256]) {
    strcpy(name, _name);
    strcpy(description, _description);
  }

  void setExit(int exit, Room* room, Item* key, bool locked) {
    exits[exit] = new Exit(room, key, locked);
  }
};

#endif
