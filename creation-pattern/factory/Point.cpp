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

using namespace std;

enum PointType{
    cartesia,
    polar
};

class Point{
    //Point(float x, float y) : x(x) , y(y){}

    //Not Allow this
    //Point(float rho, float theta){}

    /**
     * Refactor code to use many constructor
     * But this is not clear because we don't know the mean of variable a, b
    **/
    // Point(float a, float b, PointType type = cartesia){
    //    if(type == cartesia){
    //        x = a;
    //        y = b;
    //    }
    //    else{
    //        x = a * cos(b);
    //        y = a * sin(b);
    //    }
    // }
    // friend class PointFactory; // it break OCP, can change all of this to public
private:
    class PointFactory{
        PointFactory(){}
    public: 
        static Point NewCartesia(float x, float y){
            return {x, y};
        }

        static Point NewPolar(float r, float theta){
            return {r * cos(theta), r * sin(theta)};
        }
    };
    Point(float x, float y) : x(x) , y(y){}
    float x, y;
public:
    friend ostream &operator<<(ostream &os, const Point &point){
        os << "x: "<< point.x << ",y: "<< point.y <<endl;
        return os;
    }

    static PointFactory Factory;
};

int main(){
    auto p = Point::Factory.NewPolar(5, M_PI_4);
    cout<< p<< endl;

    return 0;
}