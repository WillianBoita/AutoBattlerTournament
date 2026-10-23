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
    std::array<std::array<std::unique_ptr<Unit>, max_width>, max_height> grid;
    bool isRunning;
  public:
    Map();

    void renderMap();
    void addUnit(std::unique_ptr<Unit> unit);
    void isEnemyInRange(Unit* unit);
    void simulateTurn();
};

#endif