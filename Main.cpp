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
  int n = 5;
  int unitNum = n > max_height ? max_height : n;
  for (int i = 0; i < unitNum; i++) {
    int ySpawnPosition = (max_height / 2) - (unitNum / 2) + i;
    Position spawnPosition;

    spawnPosition.x = 6;
    spawnPosition.y = ySpawnPosition;
    std::unique_ptr<Tank> unit = std::make_unique<Tank>(spawnPosition);
    mapa->addUnit(std::move(unit));

    Position enemySpawnPosition;

    enemySpawnPosition.x = max_width - 1;
    enemySpawnPosition.y = ySpawnPosition;
    std::unique_ptr<Artillery> unit2 = std::make_unique<Artillery>(enemySpawnPosition);
    mapa->addUnit(std::move(unit2)); 
  }

  mapa->renderMap();
  return 0;
}