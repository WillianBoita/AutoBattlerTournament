#include <iostream>
#include "Unit.h"
#include "Artillery.h"

Artillery::Artillery(Position position) : Unit(50, 40, 1, 2, 30, position, static_cast<int>(UnitType::Artillery)) {}