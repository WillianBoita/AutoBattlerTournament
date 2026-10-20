#include <iostream>
#include <memory>
#include <vector>
#include "map/Map.h"
#include "units/Unit.h"
#include "teams/Team.h"

int main() {
  int health[5] = {90, 70, 50, 150, 100};
  int damage[5] = {8, 5, 30, 20, 10};
  int speed[5] = {2, 2, 1, 3, 2};
  int range[5] = {1, 1, 2, 1, 1};
  int price[5] = {10, 5, 30, 40, 15};
  std::unique_ptr<Map> mapa = std::make_unique<Map>();
  std::vector<std::unique_ptr<Unit>> units;
  std::vector<std::unique_ptr<Unit>> units2;
  int i;
  for (i = 0; i < 3; i++) {
    std::unique_ptr<Unit> unit = std::make_unique<Unit>(i, health[i], damage[i], speed[i], range[i], price[i]);
    units.push_back(std::move(unit)); 
  }

  for (; i < 5; i++) {
    std::unique_ptr<Unit> unit2 = std::make_unique<Unit>(i, health[i], damage[i], speed[i], range[i], price[i]);
    units2.push_back(std::move(unit2)); 
  }
  
  mapa->addTeam(1, 100, std::move(units));
  mapa->addTeam(2, 100, std::move(units2));

  mapa->getTeams();

  //mapa->renderMap();
  return 0;
}