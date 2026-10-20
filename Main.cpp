#include <iostream>
#include <memory>
#include <vector>
#include "map/Map.h"
#include "units/Unit.h"
#include "units/Militia.h"
#include "units/Artillery.h"
#include "units/Soldier.h"
#include "units/Tank.h"
#include "teams/Team.h"

int main() {
  std::unique_ptr<Map> mapa = std::make_unique<Map>();
  std::vector<std::unique_ptr<Unit>> units;
  std::vector<std::unique_ptr<Unit>> units2;
  for (int i = 0; i < 4; i++) {
    std::unique_ptr<Tank> unit = std::make_unique<Tank>(i);
    units.push_back(std::move(unit)); 
  }

  for (int i = 0; i < 4; i++) {
    std::unique_ptr<Artillery> unit2 = std::make_unique<Artillery>(i);
    units2.push_back(std::move(unit2)); 
  }
  
  mapa->addTeam(1, 200, std::move(units));
  mapa->addTeam(2, 200, std::move(units2));

  mapa->getTeams();

  //mapa->renderMap();
  return 0;
}