#pragma once
#include <string>
class Armor {
protected:
  virtual void donArmor() = 0;
public:
  std::string ArmorType;
};

class HeavyArmor : public Armor {
  void donArmor() override {
    ArmorType = "Heavy";
  }
public:
  HeavyArmor() { donArmor(); }
};

class MediumArmor : public Armor {
  void donArmor() override {
    ArmorType = "Medium";
  }
public:
  MediumArmor() { donArmor(); }
};

class LightArmor : public Armor {
  void donArmor() override {
    ArmorType = "Light";
  }
public:
  LightArmor() { donArmor(); }
};

