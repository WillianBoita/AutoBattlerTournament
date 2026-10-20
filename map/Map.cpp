#include <iostream>
#include <vector>
#include <memory>
#include "Map.h"
#include "../teams/Team.h"
#include "../units/Unit.h"

Map::Map() {
  this->height = max_height;
  this->width = max_width;
}

void Map::addTeam(int teamId, int budget, std::vector<std::unique_ptr<Unit>> units) {
  std::unique_ptr<Team> newTeam = std::make_unique<Team>(teamId, budget);
  for (int i = 0; i < units.size(); i++) {
    newTeam->addUnit(std::move(units.at(i)));
  }

  this->teams.push_back(std::move(newTeam));
}

void Map::renderMap() {
  std::cout << "Rendering...\n";
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::cout << "[]";
    }
    std::cout << "\n";
  }
  
}

const std::vector<std::unique_ptr<Team>>& Map::getTeams() const {
  for (int i = 0; i < this->teams.size(); i++) {
    std::cout << this->teams.at(i).get()->getId() << "\n";
    std::cout << this->teams.at(i).get()->getBudget() << "\n";
    this->teams.at(i).get()->getUnits();
    std::cout << "-------------------\n";
  }
  
  return this->teams;
}