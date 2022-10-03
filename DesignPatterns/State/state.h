#pragma once
#include <iostream>
#include <typeinfo>
#define classname typeid(this).name()

class Engine;

class State {
protected:
  Engine* _engine;

public:
  virtual ~State() {}

  void set_engine(Engine* engine) {
    _engine = engine;
  }

  virtual void DoWorkA() = 0;
  virtual void DoWorkB() = 0;
};

class Engine {
private:
  State* _state;

public:
  Engine(State* state) : _state(nullptr) {
    TransitionTo(state);
  }

  ~Engine() { delete _state; }

  void TransitionTo(State* state) {
    if (_state) delete _state;
    _state = state;
    _state->set_engine(this);
  }

  void RequestA() { _state->DoWorkA(); }
  void RequestB() { _state->DoWorkB(); }
};

class ConcreteStateA : public State {
public:
  void DoWorkA() override {
    std::cout << classname << " called DoWorkA()\n";
  }
  void DoWorkB() override {
    std::cout << classname << " called DoWorkB()\n";
  }
};

class ConcreteStateB : public State {
public:
  void DoWorkA() override {
    std::cout << classname << " called DoWorkA()\n";
    _engine->TransitionTo(new ConcreteStateA);
  }
  void DoWorkB() override {
    std::cout << classname << " called DoWorkB()\n";
  }
};
