#include <iostream>
#include <memory>
#include "Map.h"
#include "../units/Unit.h"

Map::Map() : height(max_height), width(max_width) {
  for (int i = 0; i < max_height; i++) {
    this->grid.at(i).fill(nullptr);
  }
}

void Map::renderMap() {
  std::cout << "Rendering...\n";
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::shared_ptr<Unit> unit = grid.at(i).at(j);
      if (unit != nullptr) {
        std::cout << "[" << unit->getId() << "]";
      } else {
        std::cout << "[-]";
      }
    }
    std::cout << "\n";
  }
}

void Map::addUnit(std::unique_ptr<Unit> unit) {
  Position unitSpawnPosition = unit->getPosition();
  this->grid.at(unitSpawnPosition.y).at(unitSpawnPosition.x) = std::move(unit);
}

void Map::isEnemyInRange(std::shared_ptr<Unit> unit) {
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

      std::shared_ptr<Unit> foundEnemy = this->grid.at(y).at(x);
      if (foundEnemy != nullptr && unit->getTeamId() != foundEnemy->getTeamId()) {
        unit->attack(foundEnemy);
        std::cout << unit->getId() << " Atingiu " << foundEnemy->getId() << "\n";
        std::cout << "Unit " << foundEnemy->getId() << " Vida restante: " << foundEnemy->getHealth() << "\n";
        return;
      }
    }
  }
  
  std::cout << unit->getId() << " não encontrou nenhum inimigo.\n";
}

void Map::simulateTurn() {
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::shared_ptr<Unit> unit = grid.at(i).at(j);
      if (unit != nullptr) {
        this->isEnemyInRange(unit);
      }
    }
  }
}