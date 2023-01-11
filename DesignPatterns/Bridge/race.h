// Example RPG Game Races with an interface

#pragma once
#include "stats.h"
#include <string>

class Race {
public:
  virtual ~Race() = default;
  virtual std::string GetRaceName() = 0;
  Stats stats{};
};

class Dwarf : public Race {
public:
  Dwarf() { stats.Power += 1; stats.MaxHP += 1; }
  std::string GetRaceName() override { return "Dwarf"; }
};

class Elf : public Race {
public:
  Elf() { stats.Agility += 1; }
  std::string GetRaceName() override { return "Elf"; }
};


class Gnome : public Race {
public:
  Gnome() { stats.Mental += 1; }
  std::string GetRaceName() override { return "Gnome"; }
};