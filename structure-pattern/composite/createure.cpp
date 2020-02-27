#include "iostream"
#include "algorithm"
#include "array"
#include <numeric>  

using namespace std;

/*
Kiểu impl này sẽ gây khó chịu bởi 1 vài lý do sau:
- Khi tính tổng sẽ dễ bị quên 1 vài thuộc tính 
- Khi tính trung bình thì sẽ phải biết con số 3
- khi tính max sẽ phải compare từng cặp 1
=> Sẽ thảm hoạ mỗi lần thêm 1 thông số vào
*/
class Creature_ {
    int strength, agility, intelligence;
public:
    int get_strength () const {
        return strength;
    }

    void set_strength(int strength) {
        this->strength = strength;
    }

    int sum() const  {
        return strength + agility + intelligence;
    }

    double average() const {
        return sum() / 3.0;
    }

    int max() const {
        return std::max(std::max(strength, agility), intelligence);
    }
};

class Creature {
    enum Abilities { str, agl, intl, count};
    array<int, count> abilities;
    int get_strength () const {
        return abilities[str];
    }
    void set_strength (int value) {
        abilities[str] = value;
    }

    int sum() const {
        return accumulate(abilities.begin(), abilities.end(), 0);
    }

    double average(){
        return sum() / (double) count;
    }

    int max() const {
        return *max_element(abilities.begin(), abilities.end());
    }
};