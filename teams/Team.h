#include <iostream>

#ifndef Team_H
#define Team_H

class Team {
  private:
    inline static int counter = 0;
    int id;
    int budget;
  public:
    Team(int budget);

    int getId();
    int getBudget();
};

#endif