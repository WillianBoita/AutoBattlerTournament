#include <iostream>
#include "Unit.h"
#include "Militia.h"

Militia::Militia(Position position) : Unit(60, 5, 1, 1, 5, position, static_cast<int>(UnitType::Militia)) {}