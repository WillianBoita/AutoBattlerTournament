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
        std::cout << "[" << unit.get()->getHealth() << "]";
      } else {
        std::cout << "[---]";
      }
    }
    std::cout << "\n";
  }
}

void Map::addUnit(std::unique_ptr<Unit> unit) {
  Position unitSpawnPosition = unit.get()->getPosition();
  this->grid.at(unitSpawnPosition.y).at(unitSpawnPosition.x) = std::move(unit);
}