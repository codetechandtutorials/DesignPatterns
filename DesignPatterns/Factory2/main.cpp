#include <cstdlib>
#include <iostream>
#include "characterfactory.h"

// test our abstract factory
int main() {
  PlayerCharacter* Bob_The_Rogue = CharacterFactory::create("Rogue");
  if (Bob_The_Rogue) {
    std::cout << "classname: " << Bob_The_Rogue->getClass() << '\n';
    std::cout << "hp: " << Bob_The_Rogue->getHP() << '\n';
    std::cout << "armor: " << Bob_The_Rogue->getArmor() << '\n';
    std::cout << "weapon: " << Bob_The_Rogue->getWeapon() << '\n';
  }
  delete Bob_The_Rogue;  // we are done with bob

  PlayerCharacter* Chet_The_Warrior = CharacterFactory::create("Warrior");
  if (Chet_The_Warrior) {
    std::cout << "classname: " << Chet_The_Warrior->getClass() << '\n';
    std::cout << "hp: " << Chet_The_Warrior->getHP() << '\n';
    std::cout << "armor: " << Chet_The_Warrior->getArmor() << '\n';
    std::cout << "weapon: " << Chet_The_Warrior->getWeapon() << '\n';
  }
  delete Chet_The_Warrior;


  return EXIT_SUCCESS;
}