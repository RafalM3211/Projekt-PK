#include "headers/tree.h"

#include <iostream>

void Person::printInfo() {
  std::cout << "name: " << name << " sex: " << sex << std::endl;
  std::cout << "children: " << std::endl;

  for (const auto child : children) {
    std::cout << child->name << ", ";
  }

  std::cout << std::endl << "parents: " << std::endl;

  for (const auto parent : parents) {
    std::cout << parent->name << ", ";
  }
};