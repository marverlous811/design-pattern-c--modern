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

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
  Point(const Point& point) : x(point.x), y(point.y) {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }
  
  Line(const Line& line) : start(new Point(*line.start)), end(new Point(*line.end)){}

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    // TODO
    return Line(*this);
  }
};

int main(){
    Point start{0,0};
    Point end{0,2};

    Line line{&start, &end};
    return 0;
}