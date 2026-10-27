#include <iostream>
#include "Tank.h"

Tank::Tank(Position position) : Unit(160, 20, 1, 1, 40, position, static_cast<int>(UnitType::Tank)) {}