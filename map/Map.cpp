#include <iostream>
#include <vector>
#include <memory>
#include "Map.h"

Map::Map() : height(max_height), width(max_width), isRunning(true) {}

void Map::renderMap() {
  std::cout << "Rendering...\n";
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      Unit* unit = grid.at(y).at(x).get();
      if (unit != nullptr) {
        std::cout << "[" << unit->getUnitType() << "-" << unit->getId() << "]";  
      } else {
        std::cout << "[---]";
      }
    }
    std::cout << "\n";
  }
}

int Map::getIsRunning() {
  return this->isRunning;
}

void Map::addUnit(std::shared_ptr<Unit> unit, Position unitSpawnPosition) {
  this->grid.at(unitSpawnPosition.y).at(unitSpawnPosition.x) = std::move(unit);
}

void Map::addTeam(std::shared_ptr<Team> team) {
  this->teams.push_back(team);
}

void Map::updateUnitPositions(Unit* unit, Position currentPosition) {
  int x = currentPosition.x + unit->getSpeed() >= max_width ? max_width - 1 : currentPosition.x + unit->getSpeed();

  this->grid.at(currentPosition.y).at(x).swap(this->grid.at(currentPosition.y).at(currentPosition.x));
}

bool Map::isEnemyInRange(Unit* unit, Position currentPosition) {
  int unitRange = unit->getRange();

  for (int i = -unitRange; i <= unitRange; i++) {
    for (int j = -unitRange; j <= unitRange; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      int x = currentPosition.x + i;
      int y = currentPosition.y + j;

      if (x < 0 || x >= max_width ||
          y < 0 || y >= max_height) {
          continue;
      }

      Unit* foundEnemy = this->grid.at(y).at(x).get();
      if (foundEnemy != nullptr && unit->getTeamId() != foundEnemy->getTeamId()) {
        //std::cout << foundEnemy->getId() << "\n";
        unit->attack(foundEnemy);
        if (foundEnemy->getHealth() <= 0) {
          this->teams.at(foundEnemy->getTeamId())->removeUnit();
          grid.at(y).at(x).reset();
        }
        return true;
      }

    }
  }
  this->updateUnitPositions(unit, currentPosition);
  return false;
}

void Map::simulateTurn() {
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      Unit* unit = grid.at(y).at(x).get();
      if (unit != nullptr) {
        bool attacked = this->isEnemyInRange(unit, Position {x, y});
        if (!attacked) {
          x += unit->getSpeed() + 1;
        }
        
      }
    }
  }
  
  this->renderMap();
  this->isMapRunning();
}

void Map::isMapRunning() {
  for (long unsigned int i = 0; i < this->teams.size(); i++) {
    Team* team = this->teams.at(i).get();
    if (team->getUnitQuantity() <= 0) {
      this->isRunning = false;
      return;
    }
  }

  this->isRunning = true;
}