#include <cstdlib>
#include <iostream>
#include "warehouse.h"
int main() {
  Warehouse* pool = Warehouse::getInstance();
  Resource* one;
  Resource* two;
  /* Resources will be created. */
  one = pool->getResource();
  one->setValue(10);
  std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
  two = pool->getResource();
  two->setValue(20);
  std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
  pool->returnResource(one);
  pool->returnResource(two);
  /* Resources will be reused.
   * Notice that the value of both resources were reset back to zero.
   */
  one = pool->getResource();
  std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
  two = pool->getResource();
  std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;



  return EXIT_SUCCESS;
}