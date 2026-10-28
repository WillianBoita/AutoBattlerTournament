#include <iostream>
#include "Unit.h"
#include "Militia.h"

Militia::Militia() : Unit(25, 5, 1, 1, 5, static_cast<int>(UnitType::Militia)) {}