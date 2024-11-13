#ifndef ITEM_H
#define ITEM_H
class Item {
 public:
  char name[64];
  char description[256];
  int weight;
};
#endif

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
class Weapon : Public Item {
  float damage;
};
#endif
