#include "iostream"

using namespace std;

struct BankAccount {
    int balance = 0;
    int overdraft_limit = -500;

    void desposit(int amount) {
        balance += amount;
        cout << "deposited " << amount << ", balance is now "<< balance << endl;
    }

    void withdraw(int amount){
        if(balance - amount >= overdraft_limit) {
            balance -= amount;
            cout << "withdrew " << amount <<", balance is now "<< balance << endl;
        }
    }
};

int main(){
    BankAccount a;
    a.desposit(100);
    a.withdraw(300);

    return 0;
}