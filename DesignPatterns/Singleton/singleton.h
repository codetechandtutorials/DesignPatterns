#include "tea.h"
#include <vector>

// example of a singleton manager
class Manager {
public: 
  // call this to get access to the public functions
  static Manager& Instance() {
    static Manager* instance = new Manager();  // inits once (lazy)
    return *instance;
  }

  void Add(Tea tea) {
    teas.push_back(tea);
  }

  [[nodiscard]] std::vector<Tea> GetTeaList() {
    return teas;
  }

private:
  std::vector<Tea> teas;
};
