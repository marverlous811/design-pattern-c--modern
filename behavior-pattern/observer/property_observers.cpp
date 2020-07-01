#include <iostream>
#include <string>
#include <any>
#include <mutex>
#include <vector>

using namespace std;

//one approach
// struct PersonListener
// {
//     virtual void person_changed(Person &p, const string &property_name, const any new_value) = 0;
// };

template <typename T>
struct Observer
{
public:
    virtual void field_changed(T &source, const string &field_name) = 0;
};

template <typename T>
struct Observable
{
public:
    void notify(T &sourcce, const string &name)
    {
        scoped_lock<mutex> lock{mtx};
        for (auto obs : observers)
            obs->field_changed(sourcce, name);
    }
    void subscribe(Observer<T> &f)
    {
        scoped_lock<mutex> lock{mtx};
        observers.push_back(&f);
    }
    void unsubscribe(Observer<T> &f)
    {
        scoped_lock<mutex> lock{mtx};
        observers.erase(
            remove(observers.begin(), observers.end(), &f),
            observers.end());
    }

private:
    vector<Observer<T> *> observers;
    mutex mtx;
};

struct Person : public Observable<Person>
{
    int get_age() const { return age; }
    void set_age(const int value)
    {
        if (this->age == value)
            return;

        auto old_vote = can_vote();
        this->age = value;
        notify(*this, "age");

        if (old_vote != can_vote())
        {
            notify(*this, "can_vote");
        }
    }
    bool can_vote()
    {
        return this->age >= 16;
    }
    Person(int age) : age{age} {}

private:
    int age;
};

struct ConsolePersonObserver : public Observer<Person>
{
    void field_changed(Person &source, const string &field_name) override
    {
        cout << "Person's " << field_name << " has changed to " << source.get_age() << ".\n";
    }
};

int main()
{
    cout << "hello" << endl;

    Person p{15};
    ConsolePersonObserver cpo;
    p.subscribe(cpo);
    p.set_age(21);
    p.set_age(22);
    return 0;
}