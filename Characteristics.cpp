//
// Created by raduc on 19.04.2023.
//


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
Characteristics<T>::Characteristics(int a, int b, int c, int d) {
    characteristics[0].addRating(a);
    characteristics[1].addRating(b);
    characteristics[2].addRating(c);
    characteristics[3].addRating(d);
}
