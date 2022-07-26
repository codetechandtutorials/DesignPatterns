#include <cstdlib>
#include <iostream>
#include <memory>
#include "shape.h"
#include "webpage.h"
int main() {
  
  // shape test
  Circle circle;
  ColoredShape colored_shape("red", &circle);
  std::cout << colored_shape.GetName() << std::endl;
  auto *circle_casted = dynamic_cast<Circle*>(colored_shape.shape);
  if (circle_casted) {
    circle_casted->Resize(10.f);
    std::cout << "Resized!\n";
  }


//webpage test
    std::unique_ptr<WebPage> myPage = std::make_unique<BasicWebPage>();

    myPage = std::make_unique<AuthorizedWebPage>(std::move(myPage));
    myPage = std::make_unique<AuthenticatedWebPage>(std::move(myPage));
    myPage->display();
    std::cout << std::endl;

  return EXIT_SUCCESS;
}