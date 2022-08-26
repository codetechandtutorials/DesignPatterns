#include "grass_placer_flyweight.h"
#include <vector>


int main() {

  grass_instant.Init();


  std::vector<grass_overhead> grasses;

  for(int i = 0; i < 10; i++) 
    for (int j = 0; j < 10; j++) {
      grass_overhead tmp(i,j);
      grasses.push_back(tmp);
    }

  bool running = true;

  while (running) {
    for (const auto& grass : grasses) 
      grass_instant.Draw(grass);
  }
}