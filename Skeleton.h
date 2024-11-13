#ifndef SKELETON_H
#define SKELETON_H

#include "Enity.h"
#include <iostream>
using namespace std;

class Skeleton : Public Entity {
 public:
  int damage;

  virtual void encounterMessage();
  virtual void deathMessage();
};
