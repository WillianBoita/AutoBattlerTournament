#include <iostream>
#include "Unit.h"
#include "Soldier.h"

Soldier::Soldier() : Unit(100, 10, 1, 1, 15, static_cast<int>(UnitType::Soldier)) {}