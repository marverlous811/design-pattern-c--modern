#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>

using namespace std;

/**
 * A. High-level modules should not depend on low-level modules
 *    Both should depend on the abstractions
 * B. Abstractions should not depend on details
 *    Details should depend on the Abstractions 
 * 
 **/

enum class Relationship{
    parent,
    child,
    sibling
};

struct Person{
    string name;
};

struct RelationshipBrowser{
    virtual vector<Person> all_child_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser{ //low-level
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child){
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> all_child_of(const string& name) override{
        vector<Person> temp;
        for(auto&& [first, rel, second] : relations){
            if(first.name == name && rel == Relationship::parent){
                temp.push_back(second);
            }
        }

        return temp;
    }
};

struct Research{ //high-level
    // Research(Relationships& relationships){
    //     auto& relations = relationships.relations;
    //     for(auto&& [first, rel, second] : relations){
    //         if(first.name == "Hieu" && rel == Relationship::parent){
    //             cout<<"Hieu has a child called "<<second.name<<endl;
    //         }
    //     }
    // }

    Research(RelationshipBrowser& browser){
        vector<Person> temp = browser.all_child_of("Hieu");
        for(auto& person: temp){
            cout<<"Hieu has a child called "<<person.name<<endl;
        }
    }
};


int main(){
    Person p1{"Hieu"};
    Person p2{"Long"}, p3{"Vu"};

    Relationships relationships;
    relationships.add_parent_and_child(p1, p2);
    relationships.add_parent_and_child(p1, p3);

    Research r{relationships};
    return 0;
}