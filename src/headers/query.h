#pragma once

#include "tree.h"

class Query {
    private:
        std::shared_ptr<Person> currentPerson;
        std::shared_ptr<Person> originalPerson;
    public:
        std::shared_ptr<Person> getMom();
        std::shared_ptr<Person> getDad();
        std::vector<std::shared_ptr<Person>> getParents();
        std::vector<std::shared_ptr<Person>> getChildren();
        std::shared_ptr<Person> getCurrentPerson();
        
        void changeCurrentPersonTo(std::shared_ptr<Person> person);

        Query(std::shared_ptr<Person> _person): currentPerson(_person), originalPerson(_person){}
};

/* 
    np. babcia
    changeCurrentPersonTo(getMom());
    changeCurrentPersonTo(getMom());
    return currentPerson
*/