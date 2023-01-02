#pragma once

class Strategy {
public:
  virtual ~Strategy() = default;
  virtual int meleeattack(int base, int bonus) = 0;
  virtual int rangedattack(int base, int bonus) = 0;
};

class Level1Strategy : public Strategy {
public:
  int meleeattack(int base, int bonus) override {
    return base + bonus;
  }
  int rangedattack(int base, int bonus) override {
    return base + bonus;
  }
};

class Level2Strategy : public Strategy {
public:
  int meleeattack(int base, int bonus) override {
    return base + bonus + 2;
  }
  int rangedattack(int base, int bonus) override {
    return base + bonus + 2;
  }
};

class Level3Strategy : public Strategy {
public:
  int meleeattack(int base, int bonus) override {
    return base + bonus + 4;
  }
  int rangedattack(int base, int bonus) override {
    return base + bonus + 4;
  }
};
