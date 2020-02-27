#include "iostream"
#include "string"
#include "boost/signals2/signal.hpp"

using namespace std;
using namespace boost;

struct Query {
    string creature_name;
    enum Argument { atk, def } argument;
    int result;

    Query(const string creature_name, Argument arg, int result) 
        : creature_name{creature_name}, argument{arg}, result{result} 
        {}
};

struct Game //mediator
{
    signals2::signal<void(Query&)> queries;
};

class Creature {
    Game& game;
    int atk, def;
public:
    string name;
    Creature(Game& game, string name, int atk, int def) : 
        game{game}, name{name}, atk{atk}, def{def} {}

    int get_atk() const;

    friend ostream& operator<<(ostream& os, const Creature& obj){
        os<<"Creature: "<<obj.name<<", atk: "<<obj.get_atk()<<", def: "<<obj.def<<endl;
        return os;
    }
};

int Creature::get_atk() const {
    Query q{ name, Query::Argument::atk, atk};
    game.queries(q);
    return q.result;
}

class CreatureModifier {
    Game& game;
    Creature& creature;
public:
    CreatureModifier(Game& game, Creature& creature) 
        : game{game}, creature{creature} {}
};

class DoubleAttackModifier : public CreatureModifier {
    signals2::connection conn;
public:
    DoubleAttackModifier(Game& game, Creature& creature)
        : CreatureModifier(game, creature)
    {
        conn = game.queries.connect([&](Query& q) {
            if(q.creature_name == creature.name && q.argument == Query::Argument::atk)
                q.result *= 2;
        });
    }

    ~DoubleAttackModifier() { conn.disconnect(); }
};

int main(){
    Game game;
    Creature goblin{game, "Strong goblin", 2, 2};
    cout<< goblin << endl;

    {
        DoubleAttackModifier dam{game, goblin};
        cout<< goblin << endl;
    }

    cout<<goblin <<endl;

    return 0;
}