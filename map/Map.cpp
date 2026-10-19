#include <iostream>
#include <vector>
#include "Map.h"

Map::Map(int height, int width) {
  this->height = height;
  this->width = width;
}

std::vector<Team> Map::getTeams() {
  return this->teams;
}