#define _USE_MATH_DEFINES_
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>

using namespace std;

struct Address{
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite) : 
        street(street), city(city), suite(suite) {}

    Address(const Address& address) :
        street(address.street), city(address.city), suite(address.suite){}

    friend ostream &operator<<(ostream &os, const Address &address){
        os<<"street: "<<address.street<<", city: "<<address.city
          <<", suite: "<<address.suite<<endl;
        
        return os;
    }
};

struct Contact{
    string name;
    Address* address;

    Contact(const string &name, Address *address) : 
        name(name), address(address){}

    Contact(const Contact& contact): name(contact.name) ,
        address(new Address{*contact.address}){}

    friend ostream &operator<<(ostream &os, const Contact &contact){
        os<<"Name: "<<contact.name<<endl;
        os<<"Address: "<<*contact.address;

        return os;
    }
};

struct EmployeeFactory{
    static unique_ptr<Contact> newMainEmployee(const string& name, int suite){
        static Contact p{"", new Address{"11 Phan Boi Chau","Ha Noi",0}};
        return EmployeeFactory::newEmployee(name, suite, p);
    }
private:
    static unique_ptr<Contact> newEmployee(const string& name, int suite, const Contact& prototype){
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;

        return result;
    }

};

int main(){
    // Contact john{"John Doe", new Address{"11 Phan Boi Chau", "Ha Noi", 123}};
    // // Contact hieu{"Hieu Ngo", Address{"11 Phan Boi Chau", "Ha Noi", 100}};

    // //Contact hieu = john; //shallow copy
    // Contact hieu{john};
    // hieu.name = "Hieu Ngo";
    // hieu.address->suite = 100;

    auto john = EmployeeFactory::newMainEmployee("john", 234);
    auto hieu = EmployeeFactory::newMainEmployee("hieu",100);

    cout<<*john<<endl;
    cout<<*hieu<<endl;

    return 0;
}