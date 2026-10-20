#include <iostream>
#include "Unit.h"

#ifndef Soldier_H
#define Soldier_H

class Soldier : public Unit {
  public:
    Soldier(int id, int health, int damage, int speed, int range, int price);
};

#endif