#pragma once

#include <string>

using namespace std;

class PersonBuilder;

class Person{
    //address
    string street_address, postcode, city;
    
    //employee
    string company_name, position;
    int annual_income{0};

public:
    static PersonBuilder create();
    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;
};