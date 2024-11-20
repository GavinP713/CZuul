#ifndef Entity_H
#define Entity_H

#include "Item.h"
#include <vector>

using namespace std;

class Entity {
 public:
  int health;
  vector<Item*> items;
  
  void damage(int value);
  void heal(int value);
  void giveItem(Item item);
  void removeItem(Item item);
};
#endif
