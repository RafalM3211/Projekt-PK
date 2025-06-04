#include <iostream>
#include <memory>
#include <sstream>

#include "headers/fileHandler.h"
#include "headers/tree.h"
#include "headers/query.h"
#include "headers/queries.h"

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

  std::string personName, queryString;
  while (fileHandler.queriesStream >> personName >> queryString){
    std::shared_ptr<Person> person = tree.getPerson(personName);
    std::vector<std::shared_ptr<Person>> result = performQuery(person, queryString);

    fileHandler.outputStream << personName << " " << queryString << ": ";
    for(const auto person: result){
      fileHandler.outputStream << person->name << " ";
    }

    fileHandler.outputStream << std::endl;
  }
  
  

  return 0;
}