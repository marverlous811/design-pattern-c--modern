#include "header.hpp"

class Printer{
    static int id;
public:
    int get_id(){ return id }
    void set_id(int id){
        this->id = id;
    }
};

int main(){
    Printer p;
    int i = p.get_id();

    Printer p2;
    
    return 0;
}