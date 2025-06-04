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
    -wnukostwoxD
    -wnuki
    -wnuczki
    -brat       done
    -siostra    done
    -rodzenstwo done
    -kuzynka    done
    -kuzyn      done
    -kuzynostwo done
    -wujkowie   done
    -ciocie     done
*/

class Queries: public QueryBase{
    public:
        std::vector<std::shared_ptr<Person>> resolveParents();
        std::vector<std::shared_ptr<Person>> resolveDad();
        std::vector<std::shared_ptr<Person>> resolveMom();
        std::vector<std::shared_ptr<Person>> resolveGrandParents();
        std::vector<std::shared_ptr<Person>> resolveGrandDads();
        std::vector<std::shared_ptr<Person>> resolveGrandMoms();
        std::vector<std::shared_ptr<Person>> resolveGrandChildren();
        std::vector<std::shared_ptr<Person>> resolveGrandDauthers();
        std::vector<std::shared_ptr<Person>> resolveGrandSons();
        std::vector<std::shared_ptr<Person>> resolveSiblings();
        std::vector<std::shared_ptr<Person>> resolveSisters();
        std::vector<std::shared_ptr<Person>> resolveBrothers();
        std::vector<std::shared_ptr<Person>> resolveAllUncles();
        std::vector<std::shared_ptr<Person>> resolveUncles();
        std::vector<std::shared_ptr<Person>> resolveAunts();
        std::vector<std::shared_ptr<Person>> resolveCousinship();
        std::vector<std::shared_ptr<Person>> resolveFemaleCousins();
        std::vector<std::shared_ptr<Person>> resolveMaleCousins();
        

        Queries(std::shared_ptr<Person> _person): QueryBase(_person){};
};


std::vector<std::shared_ptr<Person>> performQuery(std::shared_ptr<Person> person, std::string queryString);

std::vector<std::shared_ptr<Person>> filterBySex(std::vector<std::shared_ptr<Person>> people, Sex sex);

