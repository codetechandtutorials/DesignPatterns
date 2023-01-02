#pragma once
#include "strats.h"

class Player { 
public:
  Player(Strategy* strat) {
    level_strat = strat;
  }

  void SetStrat(Strategy* strat) { 
    level_strat = strat;
  }

  int MeleeAttack(int base_dmg, int stat_bonus) {
    return level_strat->meleeattack(base_dmg, stat_bonus);
  }

  int RangedAttack(int base_dmg, int stat_bonus) {
    return level_strat->rangedattack(base_dmg, stat_bonus);
  }

private:

  Strategy* level_strat;
};