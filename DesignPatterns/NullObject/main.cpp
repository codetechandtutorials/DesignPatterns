#include "object.h"

void control_animal(const IAnimal& animal) {
  animal.MakeSound();
}


int main() {
  NullAnimal nullanimal;
  Dog dog1;
  control_animal(nullanimal);
}