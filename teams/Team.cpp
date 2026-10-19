#include <iostream>
#include <vector>
#include "Unit.h"
#include "Team.h"

Team::Team(int id, int budget) {
  this->id = id;
  this->budget = budget;
}

void Team::addUnit(Unit& newUnit) {
  this->units.push_back(newUnit);
}