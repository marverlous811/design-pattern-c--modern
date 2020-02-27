#include "iostream"
#include "string"

using namespace std;

struct Creature {
    string name;
    int atk, def;

    Creature(string name, int atk, int def ) : 
        name{name}, atk{atk}, def{def} {}

    friend ostream& operator<<(ostream& os, const Creature& obj){
        os<<"Creature: "<<obj.name<<", atk: "<<obj.atk<<", def: "<<obj.def<<endl;
        return os;
    }
};


/**
 * - The class take and store a reference to the Creature it plans to modify
 * - next member points to an optional modifier following this one
 * - function add() add another modifier to the chain. this is done recursively
 * - function handle() simply handles the next item in the chain
 * - the class doesn't really do much, but it's not abstract: all its member is implementations
**/
class CreatureModifier {
    CreatureModifier* next{nullptr};
protected:
    Creature& creature;
public:
    explicit CreatureModifier(Creature& creature) 
        : creature{creature} {}
    void add(CreatureModifier* cm){
        if(next) next->add(cm);
        else next = cm;
    }

    virtual void handle(){
        if(next) next->handle();
    }
};

class DoubleAttckModifier : public CreatureModifier {
public: 
    explicit DoubleAttckModifier(Creature& creature) 
        : CreatureModifier(creature) {}
    void handle() override {
        creature.atk *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefendseModifier : public CreatureModifier {
public:
    explicit IncreaseDefendseModifier(Creature& creature) 
        : CreatureModifier(creature) {}
    
    void handle() override {
        if(creature.atk <= 2) creature.def += 1;
        CreatureModifier::handle();
    }
};

class NoBonusesModifier : public CreatureModifier {
public:
    explicit NoBonusesModifier(Creature& creature) 
        : CreatureModifier(creature) {}
    
    void handle() override {}
};

int main(){
    Creature goblin{"Gobin", 1, 1};
    CreatureModifier root{ goblin };
    DoubleAttckModifier r1{ goblin };
    DoubleAttckModifier r1_2{goblin};
    IncreaseDefendseModifier r2{ goblin };

    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);

    root.handle();

    cout<<goblin <<endl;

    return 0;
}