#include <iostream>
#include <memory>

#include "headers/tree.h"

int main() {
  std::cout << "hello world" << std::endl;

  std::shared_ptr<Person> maria(new Person("maria", WOMAN));
  maria->printInfo();

  return 0;
}