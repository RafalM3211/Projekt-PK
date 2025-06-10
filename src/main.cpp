#include <iostream>
#include <memory>
#include <sstream>

#include "headers/fileHandler.h"
#include "headers/tree.h"
#include "headers/query.h"
#include "headers/queries.h"
#include "headers/cli.h"

int main(int argc, char* argv[]) {
  Tree tree;

  CliArgs* CliArgs = parseCliArguments(argc, argv);
  if(CliArgs->treeFilePath == "" || CliArgs->queriesFilePath == "" || CliArgs->outputFilePath == ""){
    std::cout << "specify all necessary arguments" << std::endl;

    return 0;
  }

  FIleHandler fileHandler(CliArgs->treeFilePath, CliArgs->queriesFilePath,
                          CliArgs->outputFilePath);

  std::string parentName, childName;
  while (fileHandler.treeStream >> parentName >> childName) {
    std::shared_ptr<Person> parent = tree.getOrCreatePerson(parentName);

    std::shared_ptr<Person> child = tree.getOrCreatePerson(childName);

    parent->addChild(child);
    child->addParent(parent);
  }

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