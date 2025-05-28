#include "./headers/query.h"


std::shared_ptr<Person> QueryBase::getMom(){
  std::shared_ptr<Person> mom = nullptr;

  for(const auto parent: currentPerson->parents){
    if(parent->sex==WOMAN){
      mom=parent;
    }
  }

  return mom;
}

std::shared_ptr<Person> QueryBase::getDad(){
  std::shared_ptr<Person> dad = nullptr;

  for(const auto parent: currentPerson->parents){
    if(parent->sex==MAN){
      dad=parent;
    }
  }

  return dad;
}

std::vector<std::shared_ptr<Person>> QueryBase::getChildren(){
    return currentPerson->children;
}

std::vector<std::shared_ptr<Person>> QueryBase::getParents(){
    return currentPerson->parents;
}

std::shared_ptr<Person> QueryBase::getCurrentPerson(){
    return currentPerson;
}

std::shared_ptr<Person> QueryBase::getOriginalPerson(){
    return originalPerson;
}

void QueryBase::changeCurrentPersonTo(std::shared_ptr<Person> person){
  currentPerson = person;
}


