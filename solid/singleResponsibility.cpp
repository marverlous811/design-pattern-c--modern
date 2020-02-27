#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * single responsibility is that a class should have a single reason to change
 * Other words, a class should have a primary responsibility and shouldn't take up other 
 * 
**/

struct Journal{
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title){}

    void add_entry(const string& entry){
        static int count = 1;
        entries.push_back(to_string(count++) + ": " + entry);
    }

    /**
     * it not good for change
    **/
    void save(const string& filename){
        ofstream ofs(filename);
        for (auto& e: entries){
            ofs << e << endl;
        }
    }
};

struct PersistenceManager{
    static void save(const Journal& j, const string& filename){
        ofstream ofs(filename);
        for (auto& e: j.entries){
            ofs << e << endl;
        }
    }
};

int main(){
    Journal jounal{"Dear diary"};
    jounal.add_entry("I ate a bug");
    jounal.add_entry("I cried today");

    //journal.save("diary.txt");

    PersistenceManager pm;
    pm.save(jounal, "diary.txt");

    return 0;
}