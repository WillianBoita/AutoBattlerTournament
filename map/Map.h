#include <iostream>
#include <vector>
#include <memory>
#include "../teams/Team.h"
#include "../units/Unit.h"

#ifndef Map_H
#define Map_H

const int max_height = 20;
const int max_width = 20;

class Map {
  private:
    int height;
    int width;
    std::vector<std::unique_ptr<Team>> teams;
  public:
    Map();

    void renderMap();
    void addTeam(int teamId, int budget, std::vector<std::unique_ptr<Unit>> units);

    const std::vector<std::unique_ptr<Team>>& getTeams() const;
};

#endif