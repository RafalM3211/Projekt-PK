#include "./headers/query.h"


std::shared_ptr<Person> Query::getMom(){
  std::shared_ptr<Person> mom = nullptr;

  for(const auto parent: currentPerson->parents){
    if(parent->sex==WOMAN){
      mom=parent;
    }
  }

  return mom;
}

std::shared_ptr<Person> Query::getDad(){
  std::shared_ptr<Person> dad = nullptr;

  for(const auto parent: currentPerson->parents){
    if(parent->sex==MAN){
      dad=parent;
    }
  }

  return dad;
}

std::vector<std::shared_ptr<Person>> Query::getChildren(){
    return currentPerson->children;
}

std::vector<std::shared_ptr<Person>> Query::getParents(){
    return currentPerson->parents;
}

std::shared_ptr<Person> Query::getCurrentPerson(){
    return currentPerson;
}

void Query::changeCurrentPersonTo(std::shared_ptr<Person> person){
    currentPerson = person;
}



std::vector<std::shared_ptr<Person>> MomQuery::resolve(){
  std::vector<std::shared_ptr<Person>> result {};
  result.push_back(getMom());

  return result;
}


std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString){
  std::vector<std::shared_ptr<Person>> result{};

  if (queryString=="mama"){
    MomQuery query(person);
    result = query.resolve();
  }

  for(const auto person: result){
    std::cout << person->name << std::endl;
  }

  return result;
}