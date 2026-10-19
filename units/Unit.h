#include <iostream>

typedef struct {
  int x;
  int y;
} Position;

class Unit {
  private:
    int id;
    int teamId;
    int health;
    int damage;
    int speed;
    int range;
    int price;
    Position position;
  public:
    Unit(int id, int health, int damage, int speed, int range, int price);

    int getId() const;
    int getHealth() const;
    int getDamage() const;
    int getSpeed() const;
    int getRange() const;
    int getPrice() const;

    void setTeamId(int teamId);

    virtual void move(Position newPosition) = 0;
    virtual void attack(Unit enemy) = 0;
};