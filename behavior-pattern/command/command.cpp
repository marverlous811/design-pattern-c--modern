#include "iostream"
#include "string"
#include "vector"
using namespace std;

struct BankAccount {
    int balance = 0;
    int overdraft_limit = -500;

    void desposit(int amount) {
        balance += amount;
        cout << "deposited " << amount << ", balance is now "<< balance << endl;
    }

    bool withdraw(int amount){
        if(balance - amount >= overdraft_limit) {
            balance -= amount;
            cout << "withdrew " << amount <<", balance is now "<< balance << endl;
            return true;
        }

        return false;
    }
};

struct Command {
    bool successed;
    virtual void call() = 0;
    virtual void undo() = 0;

    Command() : successed{false} {

    }
};

struct BankAccountCommand : Command {
    BankAccount& account;
    enum Action { deposit, withdraw } action;
    int amount;

    BankAccountCommand(BankAccount& account, const Action action, const int amount)
        : account{account}, action{action} , amount{amount}, Command()
    {
    }

    

    void call() override {
        switch(action) {
            case deposit:
                account.desposit(amount);
                successed = true;
                break;
            case withdraw:
                successed = account.withdraw(amount);
                break;
            default: break;
        }
    }

    void undo() override {
        if(!successed) return;
    
        switch(action) {
            case deposit: 
                account.withdraw(amount);
                break;
            case withdraw:
                if(successed) account.desposit(amount);
                break;
        }
    }
};

struct CompositeBankAccountCommand : vector<BankAccountCommand>, Command {
    CompositeBankAccountCommand(const initializer_list<value_type>& items) 
        :vector<BankAccountCommand>(items) {

        }

    void call() override {
        bool ok = true;
        for(auto& cmd: *this) {
            if(ok) {
                cmd.call();
                ok = cmd.successed;
            } else {
                cmd.successed = false;
            }
        }
    }

    void undo() override {
        for(auto it = rbegin(); it != rend(); ++it){
            it->undo();
        }
    }
};

struct MoneyTransferCommand : CompositeBankAccountCommand {
    MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount) 
        : CompositeBankAccountCommand {
            BankAccountCommand{from, BankAccountCommand::withdraw, amount},
            BankAccountCommand{to, BankAccountCommand::deposit, amount}
        } {}
};

int main(){
    BankAccount ba;
    BankAccount bb;
    MoneyTransferCommand trans(ba, bb, 400);
    trans.call();

    return 0;
}