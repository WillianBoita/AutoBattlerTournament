#include <iostream>
#include <vector>
#include <memory>
#include "../units/Unit.h"
#include "Team.h"

Team::Team(int budget) {
  this->id = this->counter++;
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
    Unit* unit = this->units.at(i).get();
    
    std::cout << "Unit ID: " << unit->getId() << "\n";
    std::cout << "Unit Health: " << unit->getHealth() << "\n";
    std::cout << "Unit Damage: " << unit->getDamage() << "\n";
  }
  return this->units;
}