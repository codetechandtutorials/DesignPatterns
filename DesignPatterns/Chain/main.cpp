#include "chain.h"

int main() {
  HandleEvent1* handleevent1 = new HandleEvent1;
  HandleEvent2* handleevent2 = new HandleEvent2;
  HandleEvent3* handleevent3 = new HandleEvent3;
  handleevent1->SetNext(handleevent2)->SetNext(handleevent3);

  {
    std::cout << "TEST1\n";
    Event an_event;
    an_event.id = 1;
    an_event.message = "why hello there from TEST1";
    Event returned_event = handleevent1->Handle(an_event);
    std::cout << "returned event id: " << returned_event.id << std::endl;
  }

  {
    std::cout << "TEST2\n";
    Event an_event;
    an_event.id = 2;
    an_event.message = "why hello there from TEST2";
    Event returned_event = handleevent1->Handle(an_event);
    std::cout << "returned event id: " << returned_event.id << std::endl;
  }

  {
    std::cout << "TEST3\n";
    Event an_event;
    an_event.id = 3;
    an_event.message = "why hello there from TEST3";
    Event returned_event = handleevent1->Handle(an_event);
    std::cout << "returned event id: " << returned_event.id << std::endl;
  }


  {
    std::cout << "TEST4\n";
    Event an_event;
    an_event.id = 4;
    an_event.message = "why hello there from TEST4";
    Event returned_event = handleevent1->Handle(an_event);
    std::cout << "returned event id: " << returned_event.id << std::endl;
  }

}