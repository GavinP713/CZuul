#indef CREATURE_H
#define CREATURE_H

#include "Item.h"
#include <vector>

class Entity {
 public:
  int health;
  vector<Item*> items;
};

#endif
