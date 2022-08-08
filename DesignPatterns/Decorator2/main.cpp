#include "item.h"
#include <iostream>

int main() {
  ConcreteWeapon weapon1("Basic Sword", 3);
  MagicDecorator magic_weapon1(&weapon1, 2);
  MagicDecorator x2_magic_weapon1(&magic_weapon1, 2);


  magic_weapon1.SetName("Armageddon");

  std::cout << weapon1.GetName() << " damage: " << weapon1.GetDamage() << '\n';  
  std::cout << magic_weapon1.GetName() << " damage: " << (weapon1.GetDamage() + magic_weapon1.GetMagicMod()) << '\n';
  std::cout << x2_magic_weapon1.GetName() << " damage: " << (weapon1.GetDamage() + x2_magic_weapon1.GetMagicMod()) << '\n';


  /*
  MagicWeapon weapon2("Magic Sword", 3, 2);
  std::cout << weapon2.GetName() << " damage: " << weapon2.GetDamage() << '\n';*/
}