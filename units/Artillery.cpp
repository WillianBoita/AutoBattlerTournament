#include <iostream>
#include "Unit.h"
#include "Artillery.h"

Artillery::Artillery() : Unit(50, 35, 1, 3, 35, static_cast<int>(UnitType::Artillery)) {}