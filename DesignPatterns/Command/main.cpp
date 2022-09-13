#include "command.h"

int main(){
  // simple command demo
  LogCommand lc("this is my message to log");
  lc.Execute();

  // complex command demo
  Reciever rec;
  ComplexCommand cc(&rec, "string a", "string b");
  cc.Execute();

  // invoking sets of commands demo
  Invoker invoker;
  invoker.SetStartupCommand(new LogCommand("starting up"));
  invoker.SetMidCommand(&cc);
  invoker.SetShutdownCommand(new LogCommand("shutting down"));

  invoker.DoTheWork();
}