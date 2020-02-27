#include <functional>
#include <iostream>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    // TODO
    auto instance = factory();
    return instance == this;
    // return false;
  }
};

int main(){
    SingletonTester tester;

    const bool value = tester.is_singleton<SingletonTester>([&]() -> SingletonTester* {
        return &tester;
    });

    const bool value2 = tester.is_singleton<SingletonTester>([]() {
        return new SingletonTester();
    });

    cout<<"result "<<value<<endl;
    cout<<"result2 "<<value2<<endl;

    return 0;
}