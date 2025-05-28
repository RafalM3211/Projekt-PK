#include <iostream>
#include <memory>

#include "headers/fileHandler.h"
#include "headers/tree.h"
#include "headers/query.h"

int main() {
  std::cout << "hello world" << std::endl << std::endl;

  Tree tree;

  FIleHandler fileHandler("../data/tree.txt", "../data/queries.txt",
                          "../data/output.txt");

  std::string parentName, childName;
  while (fileHandler.treeStream >> parentName >> childName) {
    std::shared_ptr<Person> parent = tree.getOrCreatePerson(parentName);

    std::shared_ptr<Person> child = tree.getOrCreatePerson(childName);

    parent->addChild(child);
    child->addParent(parent);
  }

  tree.printAllNodes();

  std::cout << "====" << std::endl;
  Query query(tree.getPerson("Piotr"));
  query.changeCurrentPersonTo(query.getDad());
  query.getCurrentPerson()->printInfo();

  std::shared_ptr<Person> person = query.getCurrentPerson();
  //std::cout << "name: " << performQuery(person, "mama").at(0)->name;

  return 0;
}