// Example RPG Game Player that has dynamically allowed Race and Class

#pragma once
#include "race.h"
#include "class.h"

class Player {
public:
  Player() = delete;
  Player(Race* race, Class* c, std::string char_name) {
    _char_name = char_name;
    _race = race;
    _class = c;
    init_stats(_stats);
    _stats+=_race->stats;
    _stats+=_class->stats;
  }
private:
  friend void PrintPlayerSheet(const Player&);
  std::string _char_name = "unset";
  Race* _race = nullptr;
  Class* _class = nullptr;
  Stats _stats{};
  int CurrentHP = 0;
  int CurrentResource = 0;
};

