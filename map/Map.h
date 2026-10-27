#include <iostream>
#include <vector>
#include <memory>
#include "../units/Unit.h"
#include "../teams/Team.h"

#ifndef Map_H
#define Map_H

const int max_height = 10;
const int max_width = 10;

class Map {
  private:
    int height;
    int width;
    std::array<std::array<std::shared_ptr<Unit>, max_width>, max_height> grid;
    std::vector<std::unique_ptr<Team>> teams;
    bool isRunning;
  public:
    Map();

    int getIsRunning();

    void addUnit(std::shared_ptr<Unit> unit);
    void addTeam(std::unique_ptr<Team> team);

    void isEnemyInRange(Unit* unit);

    void renderMap();
    void simulateTurn();
    void isMapRunning();
};

#endif