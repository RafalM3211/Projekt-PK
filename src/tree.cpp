#include "headers/tree.h"

// Tree
void Tree::addPerson(std::shared_ptr<Person> person) {
  if (!personExists(person->name)) {
    _graph.insert({person->name, person});
  };
};

bool Tree::personExists(std::string name) { return _graph.contains(name); }

std::shared_ptr<Person> Tree::getPerson(std::string name) {
  return _graph.at(name);
}

std::shared_ptr<Person> Tree::getOrCreatePerson(std::string name) {
  std::shared_ptr<Person> person;

  // todo: function for predicting sex from name

  if (!personExists(name)) {
    person = std::make_shared<Person>(name);
    addPerson(person);
  } else {
    person = getPerson(name);
  }

  return person;
}

void Tree::printAllNodes() {
  for (const auto node : _graph) {
    std::cout << "node " << node.first << std::endl;
    node.second->printInfo();
  }
}

// Person

Sex Person::getSexFromName(){
  char lastChar=name[name.length()-1];
  if(lastChar=='a' && name!="Kuba"){
    return Sex::WOMAN;
  }
  else{
    return Sex::MAN;
  }
}

void Person::addChild(std::shared_ptr<Person> child) {
  children.push_back(child);
}
void Person::addParent(std::shared_ptr<Person> parent) {
  parents.push_back(parent);
}


bool Person::operator==(std::shared_ptr<Person> person){
  return person.get()==this;
}


void Person::printInfo() {
  std::cout << "name: " << name << ", sex: " << getSexFromName() << std::endl;
  std::cout << "children: ";

  for (const auto child : children) {
    std::cout << child->name << ", ";
  }

  std::cout << std::endl << "parents: ";

  for (const auto parent : parents) {
    std::cout << parent->name << ", ";
  }

  std::cout << std::endl << std::endl;
};