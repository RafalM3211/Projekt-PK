#include "headers/tree.h"

#include <iostream>

void Tree::addPerson(std::shared_ptr<Person> person) {
  if (!_graph.contains(person->name)) {
    _graph.insert({person->name, person});
  }
};

void Tree::printAllNodes() {
  for (const auto node : _graph) {
    std::cout << "node " << node.first << std::endl;
    node.second->printInfo();
  }
}

void Person::printInfo() {
  std::cout << "name: " << name << ", sex: " << sex << std::endl;
  std::cout << "children: " << std::endl;

  for (const auto child : children) {
    std::cout << child->name << ", ";
  }

  std::cout << std::endl << "parents: " << std::endl;

  for (const auto parent : parents) {
    std::cout << parent->name << ", ";
  }

  std::cout << std::endl;
};