#include <iostream>
#include <memory>

#include "headers/tree.h"

int main() {
  std::cout << "hello world" << std::endl;

  Tree tree;

  std::shared_ptr<Person> maria(new Person("maria", WOMAN));

  tree.addPerson(maria);
  tree.printAllNodes();

  return 0;
}