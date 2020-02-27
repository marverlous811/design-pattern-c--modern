#define _USE_MATH_DEFINES_
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>

#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"

using namespace std;

unique_ptr<HotDrink> _make_drink(string type){
    unique_ptr<HotDrink> drink;
    if(type == "tea"){
        drink = make_unique<Tea>();
        drink->prepare(200);
    }
    else{
        drink = make_unique<Coffee>();
        drink->prepare(200);
    }

    return drink;
};

int main(){
    //without factory
    auto d = _make_drink("tea");

    //with factory
    DrinkFactory df;
    auto c = df.make_drink("coffee");


    return 0;
}

