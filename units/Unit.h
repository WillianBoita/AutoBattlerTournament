#include <iostream>
#include <memory>

#ifndef Unit_H
#define Unit_H

typedef struct {
  int x;
  int y;
} Position;

enum class UnitType {
  Soldier = 1,
  Militia = 2,
  Artillery = 3,
  Tank = 4
};

class Unit {
  private:
    inline static int counter = 0;
    int id;
    int teamId;
    int health;
    int damage;
    int speed;
    int range;
    int price;
    int unitType;
  public:
    Unit(int health, int damage, int speed, int range, int price, int unitType);

    int getId() const;
    int getTeamId() const;
    int getHealth() const;
    int getDamage() const;
    int getSpeed() const;
    int getRange() const;
    int getPrice() const;
    int getUnitType() const;

    void attack(Unit* enemy);
    void setTeamId(int teamId);
};

#endif