#pragma once

#include "tree.h"
#include "helpers.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

class QueryBase {
    private:
        std::shared_ptr<Person> currentPerson;
        std::shared_ptr<Person> originalPerson;
    public:
        std::shared_ptr<Person> getMom();
        std::shared_ptr<Person> getDad();
        std::vector<std::shared_ptr<Person>> getParents();
        std::vector<std::shared_ptr<Person>> getChildren();
        std::shared_ptr<Person> getCurrentPerson();
        std::shared_ptr<Person> getOriginalPerson();
        
        void changeCurrentPersonTo(std::shared_ptr<Person> person);

        QueryBase(std::shared_ptr<Person> _person): currentPerson(_person), originalPerson(_person){}
};
