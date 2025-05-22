#pragma once

#include "tree.h"

class Query {
    private:
        Person currentPerson;
    public:
        std::shared_ptr<Person> getMom();
        std::shared_ptr<Person> getDad();
        std::vector<std::shared_ptr<Person>> getChildren();
}