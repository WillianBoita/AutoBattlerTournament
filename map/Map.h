#include <iostream>
#include <vector>
#include "Team.h"

class Map {
  private:
    int height;
    int width;
    std::vector<Team> teams;
  public:
    Map(int height, int width);

    std::vector<Team> getTeams();
};