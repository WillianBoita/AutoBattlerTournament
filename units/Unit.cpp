#include <iostream>
#include "Unit.h"
#include "../map/Map.h"

Unit::Unit(int health, int damage, int speed, int range, int price, Position position, int unitType) : 
  id(this->counter++),
  health(health),
  damage(damage),
  speed(speed),
  range(range),
  price(price),
  unitType(unitType) ,
  position(position) {}

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

Position Unit::getPosition() const {
  return this->position;
}

int Unit::getUnitType() const {
  return this->unitType;
}

void Unit::move(Direction direction) {
  switch (direction) {

  case Direction::up:
    if (this->position.y + this->getSpeed() >= max_height - 1) {
      this->position.y = max_height - 1;
      return;
    }
    
    this->position.y += this->getSpeed();
    break;
  
  case Direction::right:
    if (this->position.x + this->getSpeed() >= max_width - 1) {
      this->position.x = max_width - 1;
      return;
    }

    this->position.x += this->getSpeed();
    break;

  case Direction::down:
    if (this->position.y - this->getSpeed() <= 0) {
      this->position.y = 0;
      return;
    }
    
    this->position.y -= this->getSpeed();
    break;

  case Direction::left:
    if (this->position.x - this->getSpeed() <= 0) {
      this->position.x = 0;
      return;
    }

    this->position.x -= this->getSpeed();
    break;
  
  default:
    break;
  }
}

void Unit::attack(Unit* enemy) {
  enemy->health -= this->getDamage();
}

void Unit::setTeamId(int teamId) {
  this->teamId = teamId;
}