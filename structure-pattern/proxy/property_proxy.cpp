template <typename T> struct Property {
    T value;
    Property(const T initial_value){
        *this = initial_value;
    }
    operator T(){
        return value;
    }

    T operator =(T new_value) {
        return value = new_value
    }
};

struct Creature{
    Property<int> strength{10};
};

int main(){
    Creature creature;
    creature.strength = 20;

    return 1;
}