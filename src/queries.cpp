#include "headers/queries.h"


std::vector<std::shared_ptr<Person>> Queries::resolveParents(){
  return getParents();
}

std::vector<std::shared_ptr<Person>> Queries::resolveMom(){
  if(getMom()==nullptr){
    return {};
  }
  return { getMom() };
}

std::vector<std::shared_ptr<Person>> Queries::resolveDad(){
  if(getDad()==nullptr){
    return {};
  }
  return { getDad() };
}

std::vector<std::shared_ptr<Person>> Queries::resolveGrandParents(){
  std::vector<std::shared_ptr<Person>> result{};

  if(getDad()!=nullptr){
    changeCurrentPersonTo(getDad());
    result=joinVectors(result, getParents());
    changeCurrentPersonTo(getOriginalPerson());
  }
  
  if(getMom()!=nullptr){
    changeCurrentPersonTo(getMom());
    result=joinVectors(result, getParents());
    changeCurrentPersonTo(getOriginalPerson());
  }
  
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
  std::shared_ptr<Person> initialPerson=getCurrentPerson();

  if(getDad()==nullptr) return {};
  changeCurrentPersonTo(getDad());
  std::vector<std::shared_ptr<Person>> siblings=getChildren();
    
  erasePersonFromVector(initialPerson, siblings);

  changeCurrentPersonTo(initialPerson);
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

std::vector<std::shared_ptr<Person>> Queries::resolveAllUncles(){
  std::vector<std::shared_ptr<Person>> allUncles{};

  if(getDad()!=nullptr){
    changeCurrentPersonTo(getDad());
    allUncles=joinVectors(allUncles, resolveSiblings());
    //std::cout << getCurrentPerson()->name << " dad: " << getDad()->name << " \n";
    erasePersonFromVector(getCurrentPerson(), allUncles);

    changeCurrentPersonTo(getOriginalPerson());
  }
  
  if(getMom()!=nullptr){
    changeCurrentPersonTo(getMom());

    allUncles=joinVectors(allUncles, resolveSiblings());
    erasePersonFromVector(getCurrentPerson(), allUncles);
    
    changeCurrentPersonTo(getOriginalPerson());
  }
  
  return allUncles;
}

std::vector<std::shared_ptr<Person>> Queries::resolveUncles(){
  std::vector<std::shared_ptr<Person>> allUncles = resolveAllUncles();

  return filterBySex(allUncles, MAN);
}

std::vector<std::shared_ptr<Person>> Queries::resolveAunts(){
  std::vector<std::shared_ptr<Person>> allUncles = resolveAllUncles();

  return filterBySex(allUncles, WOMAN);
}

std::vector<std::shared_ptr<Person>> Queries::resolveCousinship(){
  std::vector<std::shared_ptr<Person>> uncles = resolveUncles();

  std::vector<std::shared_ptr<Person>> cousins{};

  for(const auto uncle: uncles){
    cousins = joinVectors(cousins, uncle->children);
  }

  return cousins;
}

std::vector<std::shared_ptr<Person>> Queries::resolveFemaleCousins(){
  std::vector<std::shared_ptr<Person>> allCousins = resolveCousinship();

  return filterBySex(allCousins, WOMAN);
}

std::vector<std::shared_ptr<Person>> Queries::resolveMaleCousins(){
  std::vector<std::shared_ptr<Person>> allCousins = resolveCousinship();

  return filterBySex(allCousins, MAN);
}


std::vector<std::shared_ptr<Person>> Queries::resolveGrandChildren(){
  std::vector<std::shared_ptr<Person>> children = getChildren();

  std::vector<std::shared_ptr<Person>> grandChildren{};
  for(const auto child: children){
    grandChildren = joinVectors(grandChildren, child->children);
  }

  return grandChildren;
}

std::vector<std::shared_ptr<Person>> Queries::resolveGrandDauthers(){
  std::vector<std::shared_ptr<Person>> grandChildren = resolveGrandChildren();

  return filterBySex(grandChildren, WOMAN);
}

std::vector<std::shared_ptr<Person>> Queries::resolveGrandSons(){
  std::vector<std::shared_ptr<Person>> grandChildren = resolveGrandChildren();

  return filterBySex(grandChildren, MAN);
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
  if (queryString=="wnuczkowie"){
    result = query.resolveGrandChildren();
  }
  if (queryString=="wnuki"){
    result = query.resolveGrandSons();
  }
  if (queryString=="wnuczki"){
    result = query.resolveGrandDauthers();
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
  if (queryString=="wujkowie"){
    result = query.resolveUncles();
  }
  if (queryString=="ciotki"){
    result = query.resolveAunts();
  }
  if (queryString=="kuzynostwo"){
    result = query.resolveCousinship();
  }
  if (queryString=="kuzynki"){
    result = query.resolveFemaleCousins();
  }
  if (queryString=="kuzyni"){
    result = query.resolveMaleCousins();
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