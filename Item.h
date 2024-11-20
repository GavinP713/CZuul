#ifndef ITEM_H
#define ITEM_H

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
};
#endif
