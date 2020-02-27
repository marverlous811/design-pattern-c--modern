#include "iostream"
#include "sstream"  
#include "string"

using namespace std;

struct Shape{
    virtual string str() const = 0;
};

struct Circle : Shape{
    float radius;
    explicit Circle (const float radius) : radius(radius) {}

    void resize(float factor) { this->radius *= factor; }

    string str() const override {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};

struct ColoredShape : Shape {
    Shape& shape;
    string color;

    ColoredShape(Shape& shape, string color) : shape(shape), color(color) {}

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape {
    Shape& shape;
    uint8_t transparency;

    TransparentShape(Shape& shape, uint8_t transparency) : shape(shape), transparency(transparency) {}

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.0f * 100.0f << " % transparency";
        return oss.str();
    }
};

template <typename T> struct ColoredShapeStatic : T {
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");

    string color;
    template<typename... Args>
    ColoredShapeStatic(const string color, Args ...args) : 
        T(std::forward<Args>(args)...) , color{color} {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

template <typename T> struct TransparentShapeStatic : T {
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");

    uint8_t transparency;
    template<typename... Args>
    TransparentShapeStatic(const uint8_t transparency, Args ...args) : 
        T(std::forward<Args>(args)...) , transparency {transparency} {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has " << static_cast<float>(transparency) / 255.0f * 100.0f << " % transparency";
        return oss.str();
    }
};



int main(){
    Circle circle{0.5f};
    ColoredShape redShape {circle, "RED"};
    cout << redShape.str() << endl;

    TransparentShape myCircle {
        redShape, 64
    };

    cout<< myCircle.str() << endl;

    ColoredShapeStatic<TransparentShapeStatic<Circle>> sq = {"red", 51, 5};
    cout << sq.str() << endl;
    return 0;
}