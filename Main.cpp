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
  std::shared_ptr<Team> team1 = std::make_unique<Team>(100);
  std::shared_ptr<Team> team2 = std::make_unique<Team>(100);

  int n = 5;
  int unitNum = n > max_height ? max_height : n;
  for (int i = 0; i < unitNum; i++) {
    int ySpawnPosition = (max_height / 2) - (unitNum / 2) + i;
    Position spawnPosition;

    spawnPosition.x = 3;
    spawnPosition.y = ySpawnPosition;
    std::shared_ptr<Tank> unit = std::make_unique<Tank>();
    unit->setTeamId(team1->getId());
    team1->addUnit(unit);
    mapa->addUnit(std::move(unit), spawnPosition);

    spawnPosition.x = max_width - 1;
    spawnPosition.y = ySpawnPosition;
    std::shared_ptr<Artillery> unit2 = std::make_unique<Artillery>();
    unit2->setTeamId(team2->getId());
    team2->addUnit(unit2);
    mapa->addUnit(std::move(unit2), spawnPosition);
  }

  mapa->addTeam(team1);
  mapa->addTeam(team2);

  mapa->renderMap();
  while(mapa->getIsRunning()) {
    mapa->simulateTurn();
  }
  
  return 0;
}