// Helper function that handles printing the Player Character Stats to the Console

#pragma once

#include "player.h"
#include <iostream>
#include <iomanip>

inline void PrintPlayerSheet(const Player& p) {
  std::cout << "------------------------------\n";
  std::cout << "Name    " << ": " << p._char_name << '\n';
  std::cout << "Race    " << ": " << p._race->GetRaceName() << '\n';
  std::cout << "Class   " << ": " << p._class->GetClassName() << '\n';
  std::cout << "HP      " << ": " << p.CurrentHP << " / " << p._stats.MaxHP << '\n';
  std::cout << std::left << std::setw(8) << p._class->GetResourceName() << ": " << p.CurrentResource << " / " << p._stats.MaxResource << '\n';
  std::cout << "Power   " << ": " << p._stats.Power << '\n';
  std::cout << "Agility " << ": " << p._stats.Agility << '\n';
  std::cout << "Mental  " << ": " << p._stats.Mental << std::endl;
}