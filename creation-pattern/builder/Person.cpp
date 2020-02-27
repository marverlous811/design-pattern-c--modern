#include "Person.hpp"
#include "PersonBuilder.hpp"
#include <iostream>

PersonBuilder Person::create(){
    return PersonBuilder{};
}

std::ostream &operator<<(std::ostream &os, const Person &person){
    os<< "street adress: "<<person.street_address<<std::endl;
    os<< "post code    : "<<person.postcode<<std::endl;
    os<< "city         : "<<person.city<<std::endl;
    os<< "company name : "<<person.company_name<<std::endl;
    os<< "position     : "<<person.position<<std::endl;
    os<< "salary       : "<<person.annual_income<<std::endl;

    return os;
}