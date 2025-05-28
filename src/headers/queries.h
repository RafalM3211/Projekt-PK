#pragma once

#include "tree.h"
#include "query.h"
#include "helpers.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

/* queries to do:
    -mama       done
    -tata       done
    -rodzice    done
    -dziadkowie done
    -babcie     done
    -brat
    -siostra
    -rodzenstwo
    -kuzynka
    -kuzyn
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
        std::vector<std::shared_ptr<Person>> resolveGrandDads();
        std::vector<std::shared_ptr<Person>> resolveGrandMoms();
        std::vector<std::shared_ptr<Person>> resolveSiblings();
        std::vector<std::shared_ptr<Person>> resolveSisters();
        std::vector<std::shared_ptr<Person>> resolveBrothers();

        Queries(std::shared_ptr<Person> _person): QueryBase(_person){};
};


std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString);

std::vector<std::shared_ptr<Person>> filterBySex(std::vector<std::shared_ptr<Person>> people, Sex sex);

