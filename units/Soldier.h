#include <iostream>
#include "Unit.h"

#ifndef Soldier_H
#define Soldier_H

class Soldier : public Unit {
  public:
    Soldier(Position position);
};

#endif