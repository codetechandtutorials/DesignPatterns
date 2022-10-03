#include "state.h"

int main() {
  Engine engine1(new ConcreteStateB);
  engine1.RequestA();
  engine1.RequestA();
}