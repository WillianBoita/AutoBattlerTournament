#include <iostream>
#include "Team.h"

Team::Team(int budget) :
  id(this->counter++),
  budget(budget) {}

int Team::getId() {
  return this->id;
}

int Team::getBudget() {
  return this->budget;
}

int Team::getUnits() {
  return this->units.size();
}

void Team::addUnit(std::shared_ptr<Unit> unit) {
  this->units.push_back(unit);
}

void Team::removeUnit() {
  this->units.pop_back();
}