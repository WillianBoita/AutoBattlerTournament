#include <iostream>
#include <memory>
#include "Map.h"
#include "../units/Unit.h"

Map::Map() : height(max_height), width(max_width) {
  for (int i = 0; i < max_height; i++) {
    this->units.at(i).fill(nullptr);
  }
}

void Map::renderMap() {

  std::cout << "Rendering...\n";
  for (int i = 0; i < this->height; i++) {
    for (int j = 0; j < this->width; j++) {
      std::shared_ptr<Unit> unit = units.at(i).at(j);
      if (unit != nullptr) {
        std::cout << "[0]";
      } else {
        std::cout << "[-]";
      }
    }
    std::cout << "\n";
  }
  
}