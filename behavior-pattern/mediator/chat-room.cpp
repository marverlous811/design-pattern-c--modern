#include "iostream"
#include "string"
#include "vector"

using namespace std;

struct ChatRoom;

struct Person {
    string name;
    ChatRoom* room = nullptr;
    vector<string> chat_log;

    Person(const string& name) : name(name){}
    void receive(const string& origin, const string& message);
    void say(const string& message) const;
    void pm(const string& who, const string& message) const;
};

struct ChatRoom {
    vector<Person*> people;

    void join(Person* p);
    void boardcast(const string& origin, const string& message);
    void message(const string& origin, const string& who, const string& message);
};

void ChatRoom::join(Person* p) {
    string join_msg = p->name + " joins the chat";
    boardcast("room", join_msg);
    p->room = this;
    people.push_back(p);
}

void ChatRoom::boardcast(const string& origin, const string& message) {
    for (auto p : people) {
        if (p->name != origin) p->receive(origin, message);
    }
}

void ChatRoom::message(const string& origin, const string& who, const string& message) {
    auto target = find_if(begin(people), end(people), [&](const Person* p) {
        return p->name == who;
    });

    if(target != end(people)) {
        (*target)->receive(origin, message);
    }
}

void Person::say(const string& message) const {
    room->boardcast(name, message);
}

void Person::pm(const string& who, const string& message) const {
    room->message(name, who, message);
}

void Person::receive(const string& origin, const string& message) {
    string s{origin + ": \""+ message +"\""};
    cout<< "[" << name << "'s chat session] "<< s <<endl;
    chat_log.emplace_back(s);
}

int main(){
    ChatRoom room;
    Person john{"john"};
    Person jane{"jane"};

    room.join(&john);
    room.join(&jane);
    john.say("hi room");
    jane.say("oh, hey john");

    Person simon("simon");
    room.join(&simon);
    simon.say("hi everyone!");

    jane.pm("simon", "glad you could join us, simon");

    return 0;
}