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

void QueryBase::changeCurrentPersonTo(std::shared_ptr<Person> person){
    currentPerson = person;
}



std::vector<std::shared_ptr<Person>> Queries::resolveMom(){
  return { getMom() };
}


std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString){
  std::vector<std::shared_ptr<Person>> result{};

  Queries query(person);

  if (queryString=="mama"){
    result = query.resolveMom();
  }

  for(const auto person: result){
    std::cout << person->name << std::endl;
  }

  return result;
}