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
  std::unique_ptr<Team> team1 = std::make_unique<Team>(100);
  std::unique_ptr<Team> team2 = std::make_unique<Team>(100);

  int n = 5;
  int unitNum = n > max_height ? max_height : n;
  for (int i = 0; i < unitNum; i++) {
    int ySpawnPosition = (max_height / 2) - (unitNum / 2) + i;
    Position spawnPosition;

    spawnPosition.x = 7;
    spawnPosition.y = ySpawnPosition;
    std::shared_ptr<Tank> unit = std::make_unique<Tank>(spawnPosition);
    unit->setTeamId(team1->getId());
    mapa->addUnit(std::move(unit));
    team1->addUnit(unit);

    Position enemySpawnPosition;

    enemySpawnPosition.x = max_width - 1;
    enemySpawnPosition.y = ySpawnPosition;
    std::shared_ptr<Artillery> unit2 = std::make_unique<Artillery>(enemySpawnPosition);
    unit2->setTeamId(team2->getId());
    mapa->addUnit(std::move(unit2));
    team2->addUnit(unit2);
  }

  mapa->addTeam(std::move(team1));
  mapa->addTeam(std::move(team2));

  mapa->renderMap();
  while(mapa->getIsRunning()) {
    mapa->simulateTurn();
  }
  
  return 0;
}