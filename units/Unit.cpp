#include <iostream>
#include "Unit.h"

Unit::Unit(int id, int health, int damage, int speed, int range, int price) {
  this->id = id;
  this->health = health;
  this->damage = damage;
  this->speed = speed;
  this->range = range;
  this->price = price;
}

int Unit::getId() const {
  return this->id;
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

void Unit::setTeamId(int teamId) {
  this->teamId = teamId;
}