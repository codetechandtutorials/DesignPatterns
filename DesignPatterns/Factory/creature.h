#pragma once
class Creature {
public:
  virtual ~Creature() {};
  virtual Creature* Clone() { return nullptr; };
  int getHP() { return HitPoints; }
  int getSpeed() { return Speed; }
  int getAttack() { return Attack; }
protected:
  int HitPoints = 0;
  int Speed = 0;
  int Attack = 0;
};

#include <iostream>

class Dog : public Creature {
public:
  Dog() { HitPoints = 3; Speed = 3; Attack = 3; }
  void Bark() { std::cout << "arf!!!\n"; };
};
class Cat : public Creature {
public:
  Cat() { HitPoints = 2; Speed = 2; Attack = 2; }
  void Meow() { std::cout << "meow!!!\n"; };
};
class Mouse : public Creature {
public:
  Mouse() { HitPoints = 1; Speed = 1; Attack = 1; }
  void Squeak() { std::cout << "eekekkeke!!!\n"; };
};


//prototype creature

class Lizard : public Creature {
public:
  Lizard(int hp, int speed, int attack) {
    HitPoints = hp; Speed = speed; Attack = attack;
  }

  Creature* Clone() { return new Lizard(HitPoints, Speed, Attack); }

  void Hiss() { std::cout << "ssssssssss!!!\n"; };

};

