#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Person;

using Graph = std::unordered_map<std::string, std::shared_ptr<Person>>;

enum Sex { WOMAN, MAN };


class Tree {
 private:
  Graph _graph{};

 public:
  void addPerson(std::shared_ptr<Person> person);
  bool personExists(std::string name);
  std::shared_ptr<Person> getPerson(std::string name);
  std::shared_ptr<Person> getOrCreatePerson(std::string name);

  void printAllNodes();
};

class Person {
 private:
  Sex getSexFromName();
 public:
  const std::string name;
  const Sex sex;
  std::vector<std::shared_ptr<Person>> children{};
  std::vector<std::shared_ptr<Person>> parents{};

  void addChild(std::shared_ptr<Person> child);
  void addParent(std::shared_ptr<Person> parent);
  
  Person(std::string _name) : name(_name), sex(getSexFromName()) {};

  void printInfo();
};