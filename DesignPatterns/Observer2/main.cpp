#include "subject.h"

int main() {
  Subject* channel = new Subject();
  Subscriber* subscriber = new Subscriber();

  channel->Add(subscriber);
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  
  Subscriber* subscriber2 = new Subscriber();
  channel->Add(subscriber2);

  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();
  channel->AdvanceAndUpdateAll();



}