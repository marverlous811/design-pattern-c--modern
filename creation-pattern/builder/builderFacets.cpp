#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"
#include "PersonAddressBuilder.hpp"

using namespace std;

int main(){
    Person p = Person::create()
        .lives()
            .at("11 Phan Boi Chau")
            .with_postcode("100000")
            .in("Ha Noi")
        .works()
            .at("OWS corp")
            .as_a("developer")
            .earning(10e7);

    cout<<p<<endl;    

    return 0;
}