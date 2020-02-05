#ifndef RAZ_H
#define RAZ_H
#include <iostream>
class Raz{
    private:
        //INVARIANTE: den!=0
        int num, den;
    public:
        Raz(int=0, int=1);
        Raz inverso() const;
        operator double() const;
        Raz operator+(const Raz&) const;
        Raz operator*(const Raz&) const;
        Raz& operator++(); //operatore ++ PREFISSO
        Raz operator++(int); //operatore ++ POSTFISSO
        bool operator==(const Raz&) const;
        static Raz unTerzo();
};
std::ostream& operator<<(std::ostream&, const Raz&);
#endif