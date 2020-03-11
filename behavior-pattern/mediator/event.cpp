#include "iostream"
#include "string"
#include "vector"
#include "boost/signals2/signal.hpp"

using namespace std;
using namespace boost;

struct EventData {
    virtual ~EventData() = default;
    virtual void print() const = 0;
};

struct PlayerScoredData : EventData {
    string player_name;
    int goals_Scored_so_far;
    PlayerScoredData(const string& player_name, const int goals_scored_so_far) 
        : player_name{player_name}, goals_Scored_so_far{goals_Scored_so_far} 
        {

        }

    void print() const override {
        cout << player_name << " has scored (their " << goals_Scored_so_far << " goal)" << endl;
    }
};

struct Game {
    signals2::signal<void(EventData*)> events;
};

struct Player {
    string name;
    int goals_scored = 0;
    Game& game;
    Player(const string& name, Game& game) 
        : name(name), game(game) {}

    void score(){
        goals_scored++;
        PlayerScoredData ps {name, goals_scored};
        game.events(&ps);
    }
};

struct Coach {
    Game& game;
    explicit Coach(Game& game) : game(game) {
        game.events.connect([](EventData* e) {
            PlayerScoredData* ps = dynamic_cast<PlayerScoredData*>(e);
            if (ps && ps ->goals_Scored_so_far < 3) {
                cout<<"coach says: well done, " << ps->player_name<<endl;
            }
        });
    }
};

int main(){
    Game game;
    Player player{"Sam", game};
    Coach coach{game};

    player.score();
    player.score();
    player.score();

    return 0;
}