#pragma once

#include "tree.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

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



/* NIE ROB TAK. zrob osobne funkcje na to a nie klasy. albo funkcje statyczne w klasye ktora dziedziczy z query zeby bylo */
class MomQuery: public Query{
    public:
        std::vector<std::shared_ptr<Person>> resolve();

        MomQuery(std::shared_ptr<Person> _person): Query(_person){}
};





std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString);