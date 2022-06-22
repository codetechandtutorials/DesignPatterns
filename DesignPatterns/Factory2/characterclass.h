#pragma once
#include <string>
class CharacterClass {
protected:
  virtual void setClassStats() = 0;
public:
  std::string classname;
  int hp = 1;
};

class Rogue : public CharacterClass {
  void setClassStats() override { classname = "Rogue"; hp = 6; }
public:
  Rogue() { setClassStats(); }
};

class Warrior : public CharacterClass {
  void setClassStats() override { classname = "Warrior"; hp = 10; }
public:
  Warrior() { setClassStats(); }
};

class Wizard : public CharacterClass {
  void setClassStats() override { classname = "Wizard"; hp = 4; }
public:
  Wizard() { setClassStats(); }
};

