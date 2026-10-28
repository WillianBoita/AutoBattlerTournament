#include <iostream>
#include "Unit.h"
#include "Soldier.h"

Soldier::Soldier() : Unit(50, 10, 1, 1, 10, static_cast<int>(UnitType::Soldier)) {}