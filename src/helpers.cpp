#include "headers/helpers.h"


void erasePersonFromVector(std::shared_ptr<Person> personToErase, std::vector<std::shared_ptr<Person>>& people){
    std::vector<std::shared_ptr<Person>> temp{};

    int index=-1;
    int i=0;
    for(const auto person: people){
        if(person->name==personToErase->name){
            index=i;
            break;
        }
        i++;
    }

    if(index!=-1){
        people.erase(people.begin()+index);
    }
}