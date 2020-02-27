#include "iostream"
#include "sstream"  
#include "string"
#include <boost/bimap.hpp>
#include "boost/flyweight.hpp"

using namespace std;
using namespace boost;
using namespace flyweights;

typedef uint32_t key;
static key seed = 0;
static bimap<key, string> names;
static key add(const string& s){
    auto it = names.right.find(s);
    if (it == names.right.end()){
        names.insert({++seed, s});
        return seed;
    }
    return it->second;
}
static void mapInfo(){
    for(auto entry : names.left) {
        cout << "Key: " << entry.first << ", Value: "<< entry.second << endl;
    }
}

struct User{
    User(const string& first_name, const string& last_name) :
        first_name{add(first_name)}, last_name{add(last_name)}{
        }

    friend ostream& operator<<(ostream& os, const User& obj){
        return os << "fisrt name: "<< obj.get_first_name() << " last name: " << obj.get_last_name();
    }

    const string& get_first_name() const {
        return names.left.find(first_name)->second;
    }

    const string& get_last_name() const {
        return names.left.find(last_name)->second;
    }
protected:
    key first_name, last_name;
};

struct BoostUser{
    flyweight<string> first_name, last_name;
    BoostUser(const string& first_name, const string& last_name) : 
        first_name{first_name}, last_name{last_name}{}
};

void naive_flyweight(){
    const User myProfile{"hieu", "ngo quang"};
    const User myBrother{"ha", "ngo quang"};
    cout<<"hieu: "<<myProfile<<endl;
    cout<<"ha: "<< myBrother<<endl;

    mapInfo();
}

void boost_flyweight(){
    const BoostUser myProfile{"hieu", "ngo quang"};
    const BoostUser myBrother{"ha", "ngo quang"};

    cout << boolalpha << (&myProfile.last_name.get() == &myBrother.last_name.get());
}

int main(){
    cout<<"hello"<<endl;
    naive_flyweight();
    boost_flyweight();

    return 0;
}