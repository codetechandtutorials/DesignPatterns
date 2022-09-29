#pragma once
#include <string>
struct Event {
  int id = -1;
  std::string message = "";
};

class IHandler {
public:
  virtual ~IHandler() {}
  virtual IHandler* SetNext(IHandler* handler) = 0;
  virtual Event Handle(Event event) = 0;
};

class BaseHandler : public IHandler {
private:
  IHandler* next_handler;
public:
  BaseHandler() : next_handler(nullptr) {}

  IHandler* SetNext(IHandler* handler) override {
    next_handler = handler;
    return handler;
  }

  Event Handle(Event event) override {
    if (next_handler) {
      return next_handler->Handle(event);
    }

    return event;
  }
};

#include <iostream>
class HandleEvent1 : public BaseHandler {
public:
  Event Handle(Event event) override {
    if (event.id == 1) {
      std::cout << "-> handling event with id 1\n";
      std::cout << "   event message: " << event.message << std::endl;
      return event;
    }
    return BaseHandler::Handle(event);
  }
};

class HandleEvent2 : public BaseHandler {
public:
  Event Handle(Event event) override {
    if (event.id == 2) {
      std::cout << "-> handling event with id 2\n";
      std::cout << "   event message: " << event.message << std::endl;
      return event;
    }
    return BaseHandler::Handle(event);
  }
};

class HandleEvent3 : public BaseHandler {
public:
  Event Handle(Event event) override {
    if (event.id == 3) {
      std::cout << "-> handling event with id 3\n";
      std::cout << "   event message: " << event.message << std::endl;
      return event;
    }
    return BaseHandler::Handle(event);
  }
};









