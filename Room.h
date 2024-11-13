#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include "Entity.h"
#include <vector>

class Room {
 public:
  vector<Item*> items;
  vector<Entity*> entities;
  Exit north;
  Exit south;
  Exit east;
  Exit west;
  Exit up;
  Exit down;
};

#endif
