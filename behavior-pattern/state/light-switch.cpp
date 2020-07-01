#include <iostream>
#include <string>

using namespace std;

class LightSwitch;
struct State
{
    virtual void on(LightSwitch *ls)
    {
        cout << "Light is already on" << endl;
    }
    virtual void off(LightSwitch *ls)
    {
        cout << "Ligth is already off" << endl;
    }
};

struct OnState : State
{
    OnState() { cout << "Ligth turned on\n"; }
    void off(LightSwitch *ls) override;
};

struct OffState : State
{
    OffState() { cout << "Ligth turned off\n"; }
    void on(LightSwitch *ls) override;
};

class LightSwitch
{
    State *state;

public:
    LightSwitch()
    {
        state = new OffState();
    }
    void set_state(State *state)
    {
        this->state = state;
    }
    void on() { state->on(this); }
    void off() { state->off(this); }
};

void OnState::off(LightSwitch *ls)
{
    cout << "Swithing light off...\n";
    ls->set_state(new OffState());
    delete this;
}

void OffState::on(LightSwitch *ls)
{
    cout << "Swithing light on...\n";
    ls->set_state(new OnState());
    delete this;
}

int main()
{
    LightSwitch light;
    light.on();
    light.off();
    return 0;
}