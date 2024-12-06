#ifndef Entity_H
#define Entity_H

#include "Item.h"
#include <vector>

using namespace std;

class Entity {
 public:
  char name[64] = "N/A";
  char description[256] = "N/A";
  int health = 10;
  vector<Item*> items;
  enum Type {
    PLAYER,
    ENEMY,
    MERCHANT
  };
  Type type;

  Entity(char _name[64], char _description[256], Type _type) {
    strcpy(name, _name);
    strcpy(description, _description);
    type = _type;
  };

  void damage(int value);
  void heal(int value);
};
#endif