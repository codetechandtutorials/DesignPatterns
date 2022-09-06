#pragma once
#include <string>
#include <iostream>
#include "subject.h"

class SubscriberInterface {
public:
  virtual ~SubscriberInterface() {}
friend class Subject;
protected:
  virtual void Update(const std::string& message) = 0;
};

class Subscriber : public SubscriberInterface {
public:
  Subscriber() {
    _unique_id = ++_unique_subscribers;
  }

  ~Subscriber() {}

protected:
  void Update(const std::string& message) override {
    std::cout << "SUBID: \"" << _unique_id << "\" recieved message -> " << message << std::endl;
  };

private:
  int _unique_id = -1;
  static int _unique_subscribers;
};

int Subscriber::_unique_subscribers = 0;
