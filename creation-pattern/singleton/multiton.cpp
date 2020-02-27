#include <map>
#include <memory>
#include <iostream>

using namespace std;

enum class Importance{
    primary,
    secondary,
    teritial
};

template <typename T, typename Key = std::string>
class Mutilton{

public:
    static shared_ptr<T> get(const Key& key){
        const auto it = instances.find(key);
        if(it != instances.end()){
            return it->second;
        }

        auto instance = make_shared<T>();
        instances[key] = instance;
        
        return instance;
    }

private:
    static map<Key, shared_ptr<T>> instances;
};

template <typename T, typename Key>
map<Key, shared_ptr<T>> Mutilton<T, Key>::instances;


class Printer{

public:
    Printer(){
        ++Printer::totalInstanceCount;
        cout << "A total of "
             << Printer::totalInstanceCount
             <<" instances created so far\n";
    }

private:
    static int totalInstanceCount;
};

int Printer::totalInstanceCount = 0;

int main(){
    typedef Mutilton<Printer, Importance> mt;

    auto main = mt::get(Importance::primary);
    auto aux = mt::get(Importance::secondary);
    auto aux2 = mt::get(Importance::teritial);

    return 0;
}