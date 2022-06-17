#include "spawner.h"
#include <iostream>
int main() {
  // basic creature test
  DogSpawner ds;
  CatSpawner cs;
  MouseSpawner ms;

  Creature* creature[3] = {nullptr, nullptr, nullptr};

  creature[0]  = ds.spawn();
  creature[1] = cs.spawn();
  creature[2] = ms.spawn();
  
  // casting creatures to proper type
  for (int i = 0; i < 3; i++) {
    Dog* dog = dynamic_cast<Dog*>(creature[i]);
    if (dog) {
      dog->Bark();
    }
    
    Cat* cat = dynamic_cast<Cat*>(creature[i]);
    if (cat) {
      cat->Meow();
    }

    Mouse* mouse = dynamic_cast<Mouse*>(creature[i]);
    if (mouse) {
      mouse->Squeak();
    }

  }


  // spawn a pack of dogs test
  std::vector<Creature*> dogpack;
  ds.spawnPack(dogpack);
  // casting creatures to proper type
  for (const auto& thing : dogpack) {
    Dog* dog = dynamic_cast<Dog*>(thing);
    if (dog) {
      dog->Bark();
    }

    Cat* cat = dynamic_cast<Cat*>(thing);
    if (cat) {
      cat->Meow();
    }

    Mouse* mouse = dynamic_cast<Mouse*>(thing);
    if (mouse) {
      mouse->Squeak();
    }
  }


  // clone test
  LizardSpawner ls;
  Creature* lizc = ls.spawn();

  // test dyanmic cast
  Lizard* liz = dynamic_cast<Lizard*>(lizc);
  if (liz) {
    liz->Hiss();
  }
  
  Creature* cloned_lizard = lizc->Clone();
  // test dyanmic casting the clone
  Lizard* lizard_clone = dynamic_cast<Lizard*>(cloned_lizard);
  if (lizard_clone) {
    lizard_clone->Hiss();
  }


  return EXIT_SUCCESS;
}