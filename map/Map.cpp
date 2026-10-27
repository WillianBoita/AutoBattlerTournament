#include <iostream>
#include <vector>
#include <memory>
#include "Map.h"

Map::Map() : height(max_height), width(max_width), isRunning(true) {}

void Map::renderMap() {
  std::cout << "Rendering...\n";
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      Unit* unit = grid.at(i).at(j).get();
      if (unit != nullptr) {
        std::cout << "[" << unit->getId() << "]";  
      } else {
        std::cout << "[-]";
      }
    }
    std::cout << "\n";
  }
}

int Map::getIsRunning() {
  return this->isRunning;
}

void Map::addUnit(std::shared_ptr<Unit> unit) {
  Position unitSpawnPosition = unit->getPosition();
  this->grid.at(unitSpawnPosition.y).at(unitSpawnPosition.x) = std::move(unit);
}

void Map::addTeam(std::unique_ptr<Team> team) {
  this->teams.push_back(std::move(team));
}

void Map::isEnemyInRange(Unit* unit) {
  Position currentPosition = unit->getPosition();
  int unitRange = unit->getRange();

  for (int i = -unitRange; i <= unitRange; i++) {
    for (int j = -unitRange; j <= unitRange; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      int x = currentPosition.x + j;
      int y = currentPosition.y + i;

      if (x < 0 || x >= max_width ||
          y < 0 || y >= max_height) {
          continue;
      }

      Unit* foundEnemy = this->grid.at(y).at(x).get();
      if (foundEnemy != nullptr && unit->getTeamId() != foundEnemy->getTeamId()) {
        unit->attack(foundEnemy);
        if (foundEnemy->getHealth() <= 0) {
          this->teams.at(foundEnemy->getTeamId())->removeUnit();
          grid.at(y).at(x).reset();
        }
        return;
      }
    }
  }
}

void Map::simulateTurn() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      Unit* unit = grid.at(i).at(j).get();
      if (unit != nullptr) {
        this->isEnemyInRange(unit);
      }
    }
  }

  this->renderMap();
  this->isMapRunning();
}

void Map::isMapRunning() {
  for (long unsigned int i = 0; i < this->teams.size(); i++) {
    Team* team = this->teams.at(i).get();
    if (team->getUnits() <= 0) {
      this->isRunning = false;
      return;
    }
  }

  this->isRunning = true;
}