#ifndef ITEM_H
#define ITEM_H

#include <cstring>

class Item {
 public:
  char name[64] = "N/A";
  char description[256] = "N/A";
  int weight;
  int cost;
  int damage;
  int defense;
  int heal; // how much health it heals when consumed
  int usesPerTurn; // how many times it can be used per turn in combat
  bool canDrop; 
  enum Type {
    WEAPON,
    ARMOR,
    CONSUMABLE,
    KEY,
    VALUABLE
  };
  Type type;

  Item(Type _type, char _name[64], char _description[256], int _weight, int _cost, int _damage, int _defense, int _heal, int _usesPerTurn, bool _canDrop) {
    type = _type;
    strcpy(name, _name);
    strcpy(description, _description);
    weight = _weight;
    cost = _cost;
    damage = _damage;
    defense = _defense;
    heal = _heal;
    usesPerTurn = _usesPerTurn;
    canDrop = _canDrop;
  };
};
#endif