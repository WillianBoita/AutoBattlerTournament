#include <iostream>
#include "Unit.h"
#include "../map/Map.h"

Unit::Unit(int health, int damage, int speed, int range, int price, int unitType) : 
  id(this->counter++),
  health(health),
  damage(damage),
  speed(speed),
  range(range),
  price(price),
  unitType(unitType) {}

int Unit::getId() const {
  return this->id;
}

int Unit::getTeamId() const {
  return this->teamId;
}

int Unit::getHealth() const {
  return this->health;
}

int Unit::getDamage() const {
  return this->damage;
}

int Unit::getSpeed() const {
  return this->speed;
}

int Unit::getRange() const {
  return this->range;
}

int Unit::getPrice() const {
  return this->price;
}

int Unit::getUnitType() const {
  return this->unitType;
}

void Unit::attack(Unit* enemy) {
  enemy->health -= this->getDamage();
}

void Unit::setTeamId(int teamId) {
  this->teamId = teamId;
}