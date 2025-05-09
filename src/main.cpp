#include <iostream>
#include <memory>

#include "headers/tree.h"

int main() {
  std::cout << "hello world" << std::endl << std::endl;

  Tree tree;

  const std::string parentName = "Maria";
  const std::string childName = "Tomek";

  // create person
  // add person to tree
  // if child does not exist - create child
  // add child to children list
  // add person to child's parent list

  std::shared_ptr<Person> parent(new Person(parentName, WOMAN));
  tree.addPerson(parent);
  std::shared_ptr<Person> child = tree.getOrCreatePerson(childName);
  parent->addChild(child);
  child->addParent(parent);

  tree.printAllNodes();

  return 0;
}