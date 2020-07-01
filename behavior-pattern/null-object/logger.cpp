#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct Logger
{
    virtual ~Logger() = default;
    virtual void info(const string &s) = 0;
    virtual void warn(const string &s) = 0;
};

struct BankAccount
{
    std::shared_ptr<Logger> log;
    string name;
    int balance = 0;

    BankAccount(
        const std::shared_ptr<Logger> &logger,
        const string &name,
        int balance) : log{logger}, name{name}, balance{balance} {}

    void deposit(int amount);
};

void BankAccount::deposit(int amount)
{
    balance += amount;
    log->info("Deposited $" + lexical_cast<string>(amount) + " to " + name + ", balance is now $" + lexical_cast<string>(balance));
}

struct ConsoleLogger : Logger
{
    void info(const string &s) override
    {
        cout << "INFO: " << s << endl;
    }
    void warn(const string &s) override
    {
        cout << "WARNING: " << s << endl;
    }
};