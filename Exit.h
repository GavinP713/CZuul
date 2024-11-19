#ifndef EXIT_H
#define EXIT_H

#include "Room.h"
#include "Item.h"

class Room;
class Exit {
public:
  Room* a;
  Room* b;
  Item* key;
  bool locked;
};

#endif
