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

std::vector<std::shared_ptr<Person>> Queries::resolveGrandDads(){
  std::vector<std::shared_ptr<Person>> grandParents = resolveGrandParents();

  return filterBySex(grandParents, MAN);
}

std::vector<std::shared_ptr<Person>> Queries::resolveGrandMoms(){
  std::vector<std::shared_ptr<Person>> grandParents = resolveGrandParents();

  return filterBySex(grandParents, WOMAN);
}


std::vector<std::shared_ptr<Person>> Queries::resolveSiblings(){
  changeCurrentPersonTo(getDad());
  std::vector<std::shared_ptr<Person>> siblings=getChildren();
  
  erasePersonFromVector(getOriginalPerson(), siblings);

  return siblings;
}

std::vector<std::shared_ptr<Person>> Queries::resolveSisters(){
  std::vector<std::shared_ptr<Person>> siblings = resolveSiblings();

  return filterBySex(siblings, WOMAN);
}

std::vector<std::shared_ptr<Person>> Queries::resolveBrothers(){
  std::vector<std::shared_ptr<Person>> siblings = resolveSiblings();

  return filterBySex(siblings, MAN);
}



//===

std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString){
  std::vector<std::shared_ptr<Person>> result{};

  Queries query(person);

  if (queryString=="mama"){
    result = query.resolveMom();
  }
  if (queryString=="tata"){
    result = query.resolveDad();
  }
  if (queryString=="dziadkowie"){
    result = query.resolveGrandDads();
  }
  if (queryString=="babcie"){
    result = query.resolveGrandMoms();
  }
  if (queryString=="rodzenstwo"){
    result = query.resolveSiblings();
  }
  if (queryString=="siostry"){
    result = query.resolveSisters();
  }
  if (queryString=="bracia"){
    result = query.resolveBrothers();
  }

  std::cout << person->name << " query results: " << std::endl;
  for(const auto person: result){
    std::cout << person->name << std::endl;
  }

  return result;
}

std::vector<std::shared_ptr<Person>> filterBySex(std::vector<std::shared_ptr<Person>> people, Sex sex){
    std::vector<std::shared_ptr<Person>> result{};
    for(const auto person: people){
        if(person->sex==sex){
            result.push_back(person);
        }
    }

    return result;
}