#pragma once
#include "creature.h"
#include <vector>

// whoever spawns the creatures is responsible for the memory
class Spawner {
public:
  virtual ~Spawner() {}
  virtual Creature* spawn() = 0; 
};

class DogSpawner : public Spawner {
public:
  Creature* spawn() { return new Dog(); }
  void spawnPack(std::vector<Creature*>& out_pack) {
    for (int i = 0; i < 5; i++) {
      out_pack.push_back(new Dog());
    }
  }
};

class CatSpawner : public Spawner {
public:
  Creature* spawn() { return new Cat(); }
};

class MouseSpawner : public Spawner {
public:
  Creature* spawn() { return new Mouse(); }
};

class LizardSpawner : public Spawner {
public:
  Creature* spawn() { return new Lizard(645, 654, 5436); }
};

