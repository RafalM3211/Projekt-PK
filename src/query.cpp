#include "./headers/query.h"


std::shared_ptr<Person> Query::getMom(){
  std::shared_ptr<Person> mom = nullptr;

  for(const auto parent: parents){
    if(parent->sex==WOMAN){
      mom=parent;
    }
  }

  return mom;
}

std::shared_ptr<Person> Query::getDad(){
  std::shared_ptr<Person> dad = nullptr;

  for(const auto parent: parents){
    if(parent->sex==MAN){
      dad=parent;
    }
  }

  return dad;
}