#ifndef ROOM_H
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
  Exit exits[4];
  /*
  Exit* north;
  Exit* south;
  Exit* east;
  Exit* west;*/
};

#endif
