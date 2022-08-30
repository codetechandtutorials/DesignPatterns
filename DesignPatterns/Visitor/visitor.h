#pragma once

class ComponentA;
class ComponentB;
class ComponentC;

class Visitor {
public:
  virtual void VisitComponentA(const ComponentA* comp) const = 0;
  virtual void VisitComponentB(const ComponentB* comp) const = 0;
  virtual void VisitComponentC(const ComponentC* comp) const = 0;
};

class Component {
public:
  virtual ~Component() {}
  virtual void Accept(Visitor* visitor) const = 0;
};

#include <string>
class ComponentA : public Component {
public:
  virtual void Accept(Visitor* visitor) const override {
    visitor->VisitComponentA(this);
  }
  std::string ComponentAFunc() const {
    return "ComponentA";
  }
};

class ComponentB : public Component {
public:
  virtual void Accept(Visitor* visitor) const override {
    visitor->VisitComponentB(this);
  }
  std::string ComponentBFunc() const {
    return "ComponentB";
  }
};


class ComponentC : public Component {
public:
  virtual void Accept(Visitor* visitor) const override {
    visitor->VisitComponentC(this);
  }
  std::string ComponentCFunc() const {
    return "ComponentC";
  }
};

#include <iostream>
class Visitor1 : public Visitor {
public:
  void VisitComponentA(const ComponentA* comp) const {
    std::cout << "visited" << comp->ComponentAFunc() << "from Visitor1\n";
  }
  void VisitComponentB(const ComponentB* comp) const {
    std::cout << "visited" << comp->ComponentBFunc() << "from Visitor1\n";
  }
  void VisitComponentC(const ComponentC* comp) const {
    std::cout << "visited" << comp->ComponentCFunc() << "from Visitor1\n";
  }
};

class Visitor2 : public Visitor {
public:
  void VisitComponentA(const ComponentA* comp) const {
    std::cout << "visited" << comp->ComponentAFunc() << "from Visitor2\n";
  }
  void VisitComponentB(const ComponentB* comp) const {
    std::cout << "visited" << comp->ComponentBFunc() << "from Visitor2\n";
  }
  void VisitComponentC(const ComponentC* comp) const {
    std::cout << "visited" << comp->ComponentCFunc() << "from Visitor2\n";
  }
};