#include <string>
#include <iostream>

class BaseComponent;

class Controller {
  public:
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent { 
protected:
  Controller* _controller;
public:
  BaseComponent(Controller* controller = nullptr) : _controller(controller) {}

  void set_controller(Controller* controller) { _controller = controller; }
};

class Component1 : public BaseComponent {
public:
  void NotifyControllerOfThing() {
    std::cout << "Component1 is notifying controller about Thing\n";
    _controller->Notify(this, "Thing");
  }
  void NotifyControllerOfDirection() {
      std::cout << "Component1 is notifying controller about Direction\n";

    _controller->Notify(this, "Direction");
  }
};

class Component2 : public BaseComponent {
public:
  void NotifyControllerOfDoodad() {
        std::cout << "Component2 is notifying controller about Doodad\n";
    _controller->Notify(this, "Doodad");
  }
  void NotifyControllerOfGrass() {
        std::cout << "Component2 is notifying controller about Grass\n";
    _controller->Notify(this, "Grass");
  }
};

class ConcreteController : public Controller {
private:
  Component1 *comp1;
  Component2 *comp2;
public:
  ConcreteController(Component1 *c1, Component2 *c2) : comp1(c1), comp2(c2) {
    comp1->set_controller(this);
    comp2->set_controller(this);
  }
  void Notify(BaseComponent* sender, std::string event) const override {
    std::cout << "controller recieved event: " << event << std::endl;

    if (event == "Thing") {
      comp2->NotifyControllerOfGrass();
    }

    if (event == "Doodad") {
      comp1->NotifyControllerOfDirection();
    }
  }
};


int main() {
  Component1* c1 = new Component1;
  Component2* c2 = new Component2;

  ConcreteController* controller = new ConcreteController(c1, c2);

  c1->NotifyControllerOfThing();

  delete c1;
  delete c2;
  delete controller;
  return 0;
}