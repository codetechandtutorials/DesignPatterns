#include "visitor.h"
#include <array>

int main() {
  std::array<const Component*, 3> components = { new ComponentA, new ComponentB, new ComponentC };
  Visitor1 *v1 = new Visitor1;
  Visitor2 *v2 = new Visitor2;

  for (const Component* comp : components) {
    comp->Accept(v1);
  }

  for (const Component* comp : components) {
    comp->Accept(v2);
  }


  // cleanup
  for (const Component* comp : components) {
    delete comp;
  }

  delete v1;
  delete v2;

  return 0;

}