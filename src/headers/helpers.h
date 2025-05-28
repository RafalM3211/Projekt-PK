#pragma once

#include "tree.h"

#include <memory>
#include <vector>

template <typename Content>
std::vector<Content> joinVectors(std::vector<Content> v1, std::vector<Content> v2){
    v1.insert(v1.end(), v2.begin(), v2.end());

    return v1;
}

void erasePersonFromVector(std::shared_ptr<Person> personToErase, std::vector<std::shared_ptr<Person>>& people);