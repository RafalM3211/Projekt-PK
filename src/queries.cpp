#include "headers/queries.h"


std::vector<std::shared_ptr<Person>> Queries::resolveParents(){
  return getParents();
}

std::vector<std::shared_ptr<Person>> Queries::resolveMom(){
  return { getMom() };
}

std::vector<std::shared_ptr<Person>> Queries::resolveDad(){
  return { getDad() };
}

std::vector<std::shared_ptr<Person>> Queries::resolveGrandParents(){
  changeCurrentPersonTo(getDad());

  std::vector<std::shared_ptr<Person>> result{};
  result=joinVectors(result, getParents());

  changeCurrentPersonTo(getOriginalPerson());

  changeCurrentPersonTo(getMom());
  result=joinVectors(result, getParents());

  return result;
}



std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString){
  std::vector<std::shared_ptr<Person>> result{};

  Queries query(person);

  if (queryString=="mama"){
    result = query.resolveMom();
  }
  if (queryString=="dziadkowie"){
    result = query.resolveGrandParents();
  }

  std::cout << person->name << " query results: " << std::endl;
  for(const auto person: result){
    std::cout << person->name << std::endl;
  }

  return result;
}