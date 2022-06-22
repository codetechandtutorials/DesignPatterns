#pragma once
#include "playercharacter.h"

class CharacterFactory {
public:
  static PlayerCharacter* create(std::string classtype) {
    if (classtype == "Rogue") {
      PlayerCharacter* cc = new PlayerCharacter();
      cc->class_ = new Rogue();
      cc->armor_ = new MediumArmor();
      cc->weapon_ = new CommonWeapon();
      return cc;
    } else if (classtype == "Warrior") {
      PlayerCharacter* cc = new PlayerCharacter();
      cc->class_ = new Warrior();
      cc->armor_ = new HeavyArmor();
      cc->weapon_ = new MartialWeapon();
      return cc;
    } else if (classtype == "Wizard") {
      PlayerCharacter* cc = new PlayerCharacter();
      cc->class_ = new Wizard();
      cc->armor_ = new LightArmor();
      cc->weapon_ = new SimpleWeapon();
      return cc;
    } else {
      return NULL;
    }
  }
};
