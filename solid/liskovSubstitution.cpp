#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Liskov Substitution: Subtypes must be substituable for their base types.
 **/

class Rectangle{
protected:
    int width, height;

public:
    Rectangle(int width, int height) : width(width), height(height){}
    virtual void setWidth(int width){
        this->width = width;
    }
    virtual void setHeight(int height){
        this->height = height;
    }
    int getWidth(){
        return this->width;
    }
    int getHeight(){
        return this->height;
    }
    int area() const { return width * height;}
};

class Square : public Rectangle{
public:
    Square(int size) : Rectangle(size, size){}

    void setWidth(int w) override{
        this->width = this->height = w;
    }

    void setHeight(int h) override{
        this->width = this->height = h;
    }
};


/**
 * This is resolution 
 **/
struct RectangleFactory{
    static Rectangle create_rectangle(int w, int h){
        Rectangle r{w, h};
        return r;
    }

    static Rectangle create_square(int size){
        Square r{size};
        return r;
    }
};

void process(Rectangle& r){
    int w = r.getWidth();
    r.setHeight(10);

    cout<<"expected area = " << (w*10) <<", got "<<r.area()<<endl;
}

int main(){
    RectangleFactory factory;
    Rectangle r{3,4};
    process(r);

    /**
     * It's broken the liskov Subsititution because 
     * it can't replace its parent object
     **/
    Square sq{5};
    process(sq);

    Rectangle _sq = factory.create_square(5);
    process(_sq);

    return 0;
}