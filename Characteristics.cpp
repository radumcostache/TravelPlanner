//
// Created by raduc on 19.04.2023.
//

#include "Characteristics.h"

template<class T>
float Characteristics<T>::getMatching(const Characteristics<T> &c) {
    float ret = 0;
    for (int i = 0; i < 4; i++)
        ret += this->characteristics[i].getVal() * c.characteristics[i].getVal();
    ret -= abs(tier - c.tier);
    return ret;
}

template <class T>
void Characteristics<T>::updateCharacteristics(const Characteristics<T> &extra, int multiplier) {
    for (int i = 0; i < 4; i++)
        if (extra.characteristics[i].getVal() != 0)
        for (int j = 0; j < multiplier; j++)
            this->characteristics[i].addRating(extra.characteristics[i].getVal());
    tier = (tier + extra.tier) / 2;
}

template<class T>
Characteristics<T>::Characteristics(int a, int b, int c, int d, T t) {
    characteristics[0].addRating(a);
    characteristics[1].addRating(b);
    characteristics[2].addRating(c);
    characteristics[3].addRating(d);
    tier = t;
}



template<>
Characteristics<char>::Characteristics(int a, int b, int c, int d) {
    characteristics[0].addRating(a);
    characteristics[1].addRating(b);
    characteristics[2].addRating(c);
    characteristics[3].addRating(d);
    tier = 'A';
}
template<>
Characteristics<int>::Characteristics(int a, int b, int c, int d) {
    characteristics[0].addRating(a);
    characteristics[1].addRating(b);
    characteristics[2].addRating(c);
    characteristics[3].addRating(d);
    tier = 1;
}

template class Characteristics<char>;
template class Characteristics<int>;

template<typename T>
std::ostream & operator<< (std::ostream &out, const Characteristics<T> &c) {
    out << "Tier: " << c.tier << "\n";
    return out;
}

template
std::ostream& operator<< <>(std::ostream& o, const Characteristics<int>& x);
template
std::ostream& operator<< <>(std::ostream& o, const Characteristics<char>& x);
