#pragma once
#include <string>

class Weapon {
protected:
  virtual void setWeapon() = 0;
public:
  std::string WeaponType{};
};

class MartialWeapon : public Weapon {
  void setWeapon() override { WeaponType = "Martial"; }
public:
  MartialWeapon() { setWeapon(); }
};

class CommonWeapon : public Weapon {
  void setWeapon() override { WeaponType = "Common"; }
public:
  CommonWeapon() { setWeapon(); }
};

class SimpleWeapon : public Weapon {
  void setWeapon() override { WeaponType = "Simple"; }
public:
  SimpleWeapon() { setWeapon(); }
};