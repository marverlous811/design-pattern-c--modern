#pragma once

#include "Person.hpp"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase{
protected:
    Person& person;
public:
    PersonBuilderBase(Person& person);

    operator Person() const {
        return std::move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase{
    Person p;

public: 
    PersonBuilder();
};