#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

class CodeBuilder{
private:
    string class_name;
    vector<pair<string, string>> properties;
public: 
    CodeBuilder(const string& class_name) : class_name(class_name){}
    CodeBuilder& add_field(const string& name, const string& type){
        properties.emplace_back(make_pair(name, type));
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj){
        os<<"class "<<obj.class_name<<endl;
        os<<"{"<<endl;
        for(auto property: obj.properties){
            os<<" "<<property.second<<" "<<property.first<<";"<<endl;
        }

        os<<"};"<<endl;

        return os;
    }

};

int main(){
    auto cb = CodeBuilder{"Person"}.add_field("name","string").add_field("age","int");

    cout<<cb<<endl;

    return 0;
}