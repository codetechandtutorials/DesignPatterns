// Example RPG Game Classes with an interface

#pragma once
#include "stats.h"
#include <string>

class Class {
public:
  virtual ~Class() = default;
  virtual std::string GetClassName() = 0;
  virtual std::string GetResourceName() = 0;
  Stats stats{};
};

class Warrior : public Class {
public:
  Warrior() { stats.Power += 1; stats.MaxHP += 2; }
  std::string GetClassName() override { return "Warrior"; }
  std::string GetResourceName() override { return "Rage"; }
};

class Wizard : public Class {
public:
  Wizard() { stats.Mental += 1; stats.MaxResource += 2; }
  std::string GetClassName() override { return "Wizard"; }
  std::string GetResourceName() override { return "Mana"; }
};

class Rogue : public Class {
public:
  Rogue() { stats.Agility += 2; }
  std::string GetClassName() override { return "Rogue"; }
  std::string GetResourceName() override { return "Energy"; }
};


class Monk : public Class {
public:
  Monk() { stats.Agility += 1; stats.Mental += 1; stats.MaxHP += 1; }
  std::string GetClassName() override { return "Monk"; }
  std::string GetResourceName() override { return "Ki"; }
};


