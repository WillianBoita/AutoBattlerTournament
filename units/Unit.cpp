#include <iostream>
#include "Unit.h"
#include "../map/Map.h"

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

Position Unit::getPosition() const {
  return this->position;
}

void Unit::move(Direction direction) {
  switch (direction) {

  case Direction::up:
    if (this->position.y + this->getSpeed() >= max_height) {
      this->position.y = max_height;
      return;
    }
    
    this->position.y += this->getSpeed();
    break;
  
  case Direction::right:
    if (this->position.x + this->getSpeed() >= max_width) {
      this->position.x = max_width;
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

void Unit::attack(std::unique_ptr<Unit> enemy) {
  Position enemyPosition = enemy.get()->getPosition();
  if (abs(enemyPosition.x - this->getPosition().x) <= this->getRange() || abs(enemyPosition.y - this->getPosition().y) <= this->getRange()) {
    enemy.get()->health -= this->getDamage();
  }
}