i#ifndef ROOM_H
#define ROOM_H

//#include "Exit.h"
#include "Item.h"
#include "Entity.h"
#include <vector>

//class Exit;
class Room {
 public:
  vector<Item*> items;
  vector<Entity*> entities;

  // exits to other rooms
  struct Exit {
    Room* room;
    Item* key;
    bool locked;
    Exit(Room* _room, Item* _key, bool _locked) {
      room = _room;
      item = _key;
      locked = _locked;
    }
  };
  // corresponds to cardinal directions
  // i = 0: N
  // i = 1: S
  // i = 2: E
  // i = 3: W
  Exit exits[4];

  int getOppositeExit(int exit) {
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
};

#endif
