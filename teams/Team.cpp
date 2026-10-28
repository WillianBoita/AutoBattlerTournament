#include <iostream>
#include "Team.h"

Team::Team(int budget) :
  id(this->counter++),
  budget(budget) {}

int Team::getId() const {
  return this->id;
}

int Team::getBudget() const {
  return this->budget;
}

int Team::getUnitQuantity() const {
  return this->units.size();
}

std::vector<std::shared_ptr<Unit>> Team::getUnits() {
  return this->units;
}

void Team::addUnit(std::shared_ptr<Unit> unit) {
  this->units.push_back(unit);
}

void Team::removeUnit() {
  this->units.pop_back();
}