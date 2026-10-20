#include <iostream>
#include <vector>
#include <memory>
#include "../units/Unit.h"
#include "Team.h"

Team::Team(int id, int budget) {
  this->id = id;
  this->budget = budget;
}

void Team::addUnit(std::unique_ptr<Unit> newUnit) {
  this->units.push_back(std::move(newUnit));
}

int Team::getId() {
  return this->id;
}

int Team::getBudget() {
  return this->budget;
}

const std::vector<std::unique_ptr<Unit>>& Team::getUnits() const {
  std::cout << "Units: \n";
  for (int i = 0; i < this->units.size(); i++) {
    std::cout << this->units.at(i).get() << "\n";
    std::cout << this->units.at(i).get()->getId() << "\n";
  }
  return this->units;
}