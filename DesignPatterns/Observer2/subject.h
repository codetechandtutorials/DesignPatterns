#pragma once
#include "subscriber.h"
#include <list>

// A pattern to allow notifications to be sent to anyone who subscribes.
// Overall the point is to not have users manually check something,
// but rather be sent a notification whenever a certain event happens 
// to a subject. 
class SubjectInterface {
public:
  virtual ~SubjectInterface() {};
  virtual void Add(SubscriberInterface* sub) = 0;
  virtual void Remove(SubscriberInterface* sub) = 0;
  virtual void Notify() = 0;
};

class Subject : public SubjectInterface {
public:
  void Add(SubscriberInterface* sub) override {
    _subs.push_back(sub);
  };
  void Remove(SubscriberInterface* sub) override {
    _subs.remove(sub);
  };
  void Notify() override {
    if (_subs.empty())
      return;
    std::list<SubscriberInterface*>::iterator it = _subs.begin();
    while (it != _subs.end()) {
      (*it)->Update(_latest_message);
      it++;
    }
  };

  void AdvanceAndUpdateAll() {
    static int num_updates = 0;
    _latest_message = "Update Number \"";
    _latest_message += std::to_string(++num_updates);
    _latest_message += "\" Processed!";
    Notify();
  }
private:
  std::list<SubscriberInterface*> _subs;
  std::string _latest_message = "default message";
};
