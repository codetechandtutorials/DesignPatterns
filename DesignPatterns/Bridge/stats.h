// Stats for our RPG character along with some helper functions

#pragma once
struct Stats {
  int Power = 0;
  int Agility = 0;
  int Mental = 0;

  int MaxHP = 0;
  int MaxResource = 0;
};
typedef struct Stats Stats;

inline Stats& operator+=(Stats& lhs, const Stats& rhs) {
  lhs.Power += rhs.Power;
  lhs.Agility += rhs.Agility;
  lhs.Mental += rhs.Mental;
  lhs.MaxHP += rhs.MaxHP;
  lhs.MaxResource += rhs.MaxResource;
  return lhs;
};

inline void init_stats(Stats& stats) {
  stats.Power = stats.Agility = stats.Mental = 1;
  stats.MaxHP = stats.MaxResource = 100;
}
