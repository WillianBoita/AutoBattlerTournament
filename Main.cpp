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
  int n = 5;
  int unitNum = n > max_height ? max_height : n;
  for (int i = 0; i < unitNum; i++) {
    int ySpawnPosition = (max_height / 2) - (unitNum / 2) + i;
    Position spawnPosition;

    spawnPosition.x = 3;
    spawnPosition.y = ySpawnPosition;
    std::unique_ptr<Tank> unit = std::make_unique<Tank>(spawnPosition);
    units.push_back(std::move(unit));

    Position enemySpawnPosition;

    enemySpawnPosition.x = max_width - 1;
    enemySpawnPosition.y = ySpawnPosition;
    std::unique_ptr<Artillery> unit2 = std::make_unique<Artillery>(enemySpawnPosition);
    units2.push_back(std::move(unit2)); 
  }

  mapa->renderMap();
  return 0;
}