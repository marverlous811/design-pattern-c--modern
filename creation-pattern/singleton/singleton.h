#define _USE_MATH_DEFINES_
#define _HAS_AUTO_PTR_ETC 1
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>

#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

class Database {
public:
    virtual int get_population(const string& name) = 0;
};

class SingletonDatabase : public Database{
    SingletonDatabase(){
        cout<<"Initialize database\n";
        ifstream ifs("capitals.txt");
        string s, s2;

        while(getline(ifs, s)){
            getline(ifs, s2);
            int pop = lexical_cast<int>(s2);

            capticals[s] = pop;

        }
    }
    map<string, int> capticals;
public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator= (SingletonDatabase const&) = delete;

    static SingletonDatabase& get(){
        static SingletonDatabase db;
        return db;
    }

    int get_population(const string& name) override{
        return capticals[name];
    }
};

class DummyDatabase: public Database{
    map<string, int> capticals;
public:
    DummyDatabase(){
        capticals["alpha"] = 1;
        capticals["beta"] = 2;
        capticals["gamma"] = 3;
    }
    int get_population(const string& name) override{
        return capticals[name];
    }
};

struct ConfiguratableRecordFinder{
    Database& db;

    ConfiguratableRecordFinder(Database& db) : db(db){

    }

    int total_population(vector<string> names){
        int result{0};
        for (auto& name: names){
            result += db.get_population(name);
        }

        return result;
    }    
};

struct SingletonRecordFinder{
    int total_population(vector<string> names){
        int result{0};
        for (auto& name: names){
            result += SingletonDatabase::get().get_population(name);
        }

        return result;
    }
};