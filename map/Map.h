#include <iostream>
#include <vector>
#include <memory>
#include "../teams/Team.h"
#include "../units/Unit.h"

#ifndef Map_H
#define Map_H

const int max_height = 10;
const int max_width = 10;

class Map {
  private:
    int height;
    int width;
    std::vector<std::unique_ptr<Team>> teams;
  public:
    Map();

    void renderMap();
    void addTeam(int budget, std::vector<std::unique_ptr<Unit>> units);

    const std::vector<std::unique_ptr<Team>>& getTeams() const;
};

#endif