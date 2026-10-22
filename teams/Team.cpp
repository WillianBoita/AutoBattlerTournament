#include <iostream>
#include "Team.h"

Team::Team(int budget) :
  id(this->counter++),
  budget(budget) {}

int Team::getId() {
  return this->id;
}

int Team::getBudget() {
  return this->budget;
}