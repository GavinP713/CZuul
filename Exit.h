#ifndef EXIT_H
#define EXIT_H

#include "Room.h"
#include "Item.h"

class Exit {
public:
  Room* a;
  Room* b;
  bool locked;
  Item* key;
};

#endif
