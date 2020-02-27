#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

struct HtmlBuilder;

class HtmlElement{
    //what is friend class ??? 
    friend class HtmlBuilder;

    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement(){}
    HtmlElement(const string &name, const string &text) 
        : name(name), text(text)
    {

    }

public:
    string str(int indent = 0) const {
        ostringstream oss;
        string i (indent_size * indent, ' ');
        oss<<i<<"<"<<name<<">"<<endl;
        if(text.size() > 0)
            oss << string(indent_size*(indent+2), ' ') << text<<endl;
        for(const auto& e : elements)
            oss<<e.str(indent+1);
        
        oss<<i<<"</"<<name<<">"<<endl;
        return oss.str();
    }

    //
    static unique_ptr<HtmlBuilder> create(string root_name)
    {
        return make_unique<HtmlBuilder>(root_name);
    }


};

class HtmlBuilder{
    HtmlElement root;

public:
    HtmlBuilder(const string& name) {
        root.name = name;
    }

    /**
     * normal method 
     **/
    // void add_child(string child_name, string child_text){
    //     HtmlElement e{child_name, child_text};
    //     root.elements.emplace_back(e);
    // }

    /**
     * Implement Fluent interface
     **/
    HtmlBuilder& add_child(string child_name, string child_text){
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);

        return *this;
    }

    HtmlBuilder* _add_child(string child_name, string child_text){
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);

        return this;
    }

    HtmlElement build(){
        return root;
    }    

    string str() const {
        return root.str();
    }

    //why can do this ??? this operator meaning ???
    operator HtmlElement() const { return root; }
};

int main(){
    HtmlBuilder builder{"ul"};
    string words[] = {"hello", "world"};
    //use normal 
    // for (auto w: words)
    //     builder.add_child("li", w);

    //use fluent interface
    builder.add_child("li",words[0]).add_child("li", words[1]);
    
    cout<<builder.str()<<endl;

    // auto _builder = HtmlElement::build("ul").add_child("li","hihi").add_child("li","haha");
    HtmlElement _builder = HtmlElement::create("ul")->add_child("li","hihi").add_child("li","haha");
    cout<<_builder.str()<<endl;

    auto builder2 = HtmlElement::create("ul")->_add_child("li","haha")->build();

    return 0;
}