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
    std::vector<std::unique_ptr<Unit>> units;
  public:
    Team(int budget);
    void addUnit(std::unique_ptr<Unit> newUnit);

    int getId();
    int getBudget();
    const std::vector<std::unique_ptr<Unit>>& getUnits() const;
};

#endif