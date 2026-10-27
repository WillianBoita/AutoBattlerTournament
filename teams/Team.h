#include <iostream>
#include <vector>
#include <memory>
#include "../units/Unit.h"

#ifndef Team_H
#define Team_H

class Team {
  private:
    inline static int counter = 0;
    int id;
    int budget;
    std::vector<std::shared_ptr<Unit>> units;
  public:
    Team(int budget);

    int getId();
    int getBudget();
    int getUnits();

    void addUnit(std::shared_ptr<Unit> unit);
    void removeUnit();
};

#endif