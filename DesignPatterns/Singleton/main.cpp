#include "singleton.h"
#include <cstdlib>
#include <iostream>
int main() {

  // test our singleton manager
  {
    Tea tea{};
    tea.cost = 1;
    tea.strength = 2;
    tea.quantity = 3;

    Manager::Instance().Add(tea);
  }

  auto tealist = Manager::Instance().GetTeaList();

  int count = 1;
  for (const auto& t : tealist) {
    std::cout << count << ". cost:" << t.cost << ", str:" << t.strength << ", quat:" << t.quantity << '\n';

  }


  return EXIT_SUCCESS;
}