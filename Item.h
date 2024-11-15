#ifndef ITEM_H
#define ITEM_H

class Item {
 public:
  char name[64] = "N/A";
  char description[256] = "N/A";
  int weight = 0;
  int cost = 0;
  int heal = 0;
  int damage = 0;
  int defense = 0;
  enum Type {
    WEAPON,
    ARMOR,
    CONSUMABLE,
    KEY
  };
  Type type;
};
#endif
