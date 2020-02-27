#include "iostream"
#include "sstream"  
#include "string"
#include "vector"

using namespace std;

class FormattedText {
    string plainText;
    bool *caps;
public:
    explicit FormattedText(const string& plainText) 
        : plainText{plainText} {
        caps = new bool[plainText.length()];
    }
    ~FormattedText(){
        delete[] caps;
    }

    void capitalize(int start, int end) {
        for(int i = start; i <= end; ++i) 
            caps[i] = true;
    }

    friend ostream& operator<<(ostream& os, const FormattedText& obj){
        string s;
        for(int i = 0; i < obj.plainText.length(); ++i) {
            char c = obj.plainText[i];
            s += (obj.caps[i] ? toupper(c) : c);
        }
        return os<<s;
    }
};

class BetterFormattedText{
public:
    BetterFormattedText(const string& plainText) : plain_text(plainText) {

    }
    struct TextRange{
        int start, end;
        bool capitalize;
        //other options like bold, italic, etc...

        bool covers(int position) const {
            return position >= start && position <= end;
        }
    };

    TextRange& get_range(int start, int end){
        formating.emplace_back(TextRange{start, end});
        return *formating.rbegin();
    }

    friend ostream& operator<<(ostream& os, const BetterFormattedText& obj){
        string s;
        for(size_t i = 0; i < obj.plain_text.length(); i++){
            auto c = obj.plain_text[i];
            for(const auto& rng : obj.formating) {
                if(rng.covers(i) && rng.capitalize) 
                    c = toupper(c);
                s += c;
            }
        }

        return os << s;
    }

private:
    string plain_text;
    vector<TextRange> formating;
};

int main(){
    FormattedText ft("This is a brave new world");
    ft.capitalize(10, 15);
    cout << ft << endl;

    cout<<"======================================================"<<endl;
    BetterFormattedText bft("This is a brave new world");
    bft.get_range(10, 15).capitalize = true;
    cout<<bft<<endl;

    return 0;
}