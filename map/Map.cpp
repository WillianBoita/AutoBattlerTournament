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

void Map::addTeam(int budget, std::vector<std::unique_ptr<Unit>> units) {
  std::unique_ptr<Team> newTeam = std::make_unique<Team>(budget);
  for (long unsigned int i = 0; i < units.size(); i++) {
    units.at(i).get()->setTeamId(newTeam.get()->getId());
    newTeam->addUnit(std::move(units.at(i)));
  }

  this->teams.push_back(std::move(newTeam));
}

void Map::renderMap() {
  const auto& teams = this->getTeams();
  std::vector<Position> unitPositions;

  for (const auto& team : teams) {
    const auto& teamUnits = team->getUnits();
    for (const auto& unit : teamUnits) {
      unitPositions.push_back(unit->getPosition());
    }
  }
  

  std::cout << "Rendering...\n";
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      bool flag = false;
      for (const auto& pos : unitPositions) {
        if (pos.x == j && pos.y == i) {
          flag = true;
          break;
        }
      }
      
      if (flag) {
        std::cout << "[0]";
      } else {
        std::cout << "[-]";
      }
      
    }
    std::cout << "\n";
  }
  
}

const std::vector<std::unique_ptr<Team>>& Map::getTeams() const {
  return this->teams;
}