#include <iostream>
#include <vector>
#include "Unit.h"

class Team {
  private:
    int id;
    int budget;
    std::vector<Unit> units;

  public:
    Team(int id, int budget);

    void addUnit(Unit& newUnit);
};