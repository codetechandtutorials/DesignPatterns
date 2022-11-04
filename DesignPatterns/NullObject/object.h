#pragma once
#include <iostream>

class IAnimal {
public:
  virtual ~IAnimal() = default;
  virtual void MakeSound() const = 0;
};

class Dog : public IAnimal {
public:
  virtual void MakeSound() const override {
    std::cout << "Wolf Bark Growl\n";
  }
};

class NullAnimal : public IAnimal {
public:
  virtual void MakeSound() const override {}
};

