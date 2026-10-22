#include <iostream>
#include <memory>
#include "../units/Unit.h"

#ifndef Map_H
#define Map_H

const int max_height = 10;
const int max_width = 10;

class Map {
  private:
    int height;
    int width;
    std::array<std::array<std::shared_ptr<Unit>, max_width>, max_height> units;
  public:
    Map();

    void renderMap();
    void addUnit(int budget, std::unique_ptr<Unit> unit);
};

#endif