class ICommand {
public:
  virtual ~ICommand() {}
  virtual void Execute() const = 0;
};

#include <string>
#include <iostream>
// example of a simple command
class LogCommand : public ICommand {
  private: 
    std::string pay_load_;

  public:
    LogCommand(std::string data) : pay_load_(data) {}
    void Execute() const override {
      std::cout << "printstring: " << pay_load_ << '\n';
    }
};

// example of a more complex command
class Reciever {
public:
  void ProcessA(const std::string &proc_a_stuff) {
    std::cout << "Reciever(ProcessA) is working on: " << proc_a_stuff << '\n';
  }
  void ProcessB(const std::string &proc_b_stuff) {
    std::cout << "Reciever(ProcessB) is working on: " << proc_b_stuff << '\n';
  }
  //... todo: more business logic
};

class ComplexCommand : public ICommand {
private:
  Reciever* reciever_;  // not owned- probably should be refactored to a shared ptr
  std::string proc_a_details;
  std::string proc_b_details;

public:
  ComplexCommand(Reciever* receiver, std::string a, std::string b) 
    : reciever_(receiver), proc_a_details(a), proc_b_details(b)
  {}

  void Execute() const override {
    reciever_->ProcessA(proc_a_details);
    reciever_->ProcessB(proc_b_details);
  }
};

class Invoker {
private:
  ICommand *on_startup_command;
  ICommand *on_mid_command;
  ICommand *on_shutdown;

public:
  ~Invoker() {
    delete on_startup_command;
    delete on_mid_command;
    delete on_shutdown;
  }

  void SetStartupCommand(ICommand* command) {
    on_startup_command = command;
  }
  void SetMidCommand(ICommand* command) {
    on_mid_command = command;
  }
  void SetShutdownCommand(ICommand* command) {
    on_shutdown = command;
  }

  void DoTheWork() {
    if (on_startup_command) {
      on_startup_command->Execute();
    }   
    if (on_mid_command) {
      on_mid_command->Execute();
    }  
    if (on_shutdown) {
      on_shutdown->Execute();
    }
  }
};
