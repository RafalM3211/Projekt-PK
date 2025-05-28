#pragma once

#include "tree.h"
#include "query.h"
#include "helpers.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

/* 
    np. babcia
    changeCurrentPersonTo(getMom());
    changeCurrentPersonTo(getMom());
    return currentPerson
*/

/* queries to do:
    -mama   done
    -tata
    -rodzice
    -dziadkowie
    -babcie
    -brat
    -siostra
    -rodzenstwo
    -kuzynostwo
    -wujkowie
    -ciocie
*/

class Queries: public QueryBase{
    public:
        std::vector<std::shared_ptr<Person>> resolveParents();
        std::vector<std::shared_ptr<Person>> resolveDad();
        std::vector<std::shared_ptr<Person>> resolveMom();
        std::vector<std::shared_ptr<Person>> resolveGrandParents();
        //std::vector<std::shared_ptr<Person>> resolveGrandDads();
       // std::vector<std::shared_ptr<Person>> resolveGrandMoms();

        Queries(std::shared_ptr<Person> _person): QueryBase(_person){};
};



std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString);

