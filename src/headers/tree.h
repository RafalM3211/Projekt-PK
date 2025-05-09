#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Person;

using Graph = std::unordered_map<std::string, std::shared_ptr<Person>>;

enum Sex { WOMAN, MAN };

class Tree {
 private:
  Graph _graph;

 public:
  void addPerson(std::shared_ptr<Person> person);
};

class Person {
 public:
  std::string name;
  Sex sex;
  std::vector<std::shared_ptr<Person>> children{};
  std::vector<std::shared_ptr<Person>> parents{};

  Person(std::string _name, Sex _sex) : name(_name), sex(_sex) {};

  void printInfo();
};