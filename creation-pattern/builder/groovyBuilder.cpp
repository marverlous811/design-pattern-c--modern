#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>

using namespace std;

namespace html{
    struct Tag{
        string name, text;
        vector<Tag> children;
        vector<pair<string, string>> attributes;

        friend std::ostream& operator<<(std::ostream& os, const Tag& tag){
            os<<"<"<<tag.name;
            for(const auto& att : tag.attributes)
                os<<" "<<att.first<<"=\""<<att.second<<"\"";
            
            if(tag.children.size() == 0 && tag.text.length() == 0){
                os<<"/>"<<endl;
            }
            else{
                os<<">"<<endl;

                if(tag.text.length())
                    os<<tag.text<<endl;
                
                for(const auto& child : tag.children)
                    os<<child;
                
                os<<"</"<<tag.name<<">"<<endl;
            }

            return os;
        }

    protected:
        Tag(const string& name, const string& text) : text(text), name(name){}
        Tag(const string& name, const vector<Tag>& children) : name(name), children(children){}
    };

    struct P : Tag{
        explicit P(const string& text) : Tag("p", text){}
        P(const initializer_list<Tag> &children) : Tag("p", children){}
    };

    struct IMG : Tag{
        explicit IMG(const string& url) : Tag("img", ""){
            attributes.emplace_back(make_pair("src", url));
        }
    };
}

int main(){
    using namespace html;
    cout<<P{IMG{ "http://google.png" }}<<endl;

    return 0;
}