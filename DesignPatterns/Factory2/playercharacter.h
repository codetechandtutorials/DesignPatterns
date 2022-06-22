#pragma once
#include "armor.h"
#include "characterclass.h"
#include "weapon.h"

class PlayerCharacter {
public:
  friend class CharacterFactory;
  std::string getClass() { 
    if (class_)
      return class_->classname;
    else
      return "not set";
  }
  int getHP() {
    if (class_)
      return class_->hp;
    else
      return -1;
  }
  std::string getArmor() {
    if (armor_)
      return armor_->ArmorType;
    else
      return "not set";
  }
  std::string getWeapon() {
    if (weapon_)
      return weapon_->WeaponType;
    else
      return "not set";
  }
  ~PlayerCharacter() {
    if (class_)
      delete class_;
    if (armor_)
      delete armor_;
    if (weapon_)
      delete weapon_;
  }
private:
  CharacterClass* class_;
  Armor* armor_;
  Weapon* weapon_;
};