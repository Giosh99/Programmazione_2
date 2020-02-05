#include<iostream>
#include <vector>
#include<typeinfo>
using std::cout;
using std::endl;
using std::vector;
class Workout {
    protected:
    int minuti;
    public:
    virtual Workout* clone() const = 0;
    virtual int calorie() const =0; //ritorna il numero di calorie consumate con questo allenamento
    virtual ~Workout(){}
};
class Corsa: public Workout{
    private:
    int distanza;
    public:
    Corsa(int d=0, int m=0):distanza(d){minuti=m;} // da controllare se cal non si pu; inserire nella lista di inizializzazion perche di un altra classe
    Corsa* clone() const {
        Corsa* c = new Corsa(*this);
        return c;
    }
    int calorie() const {
        return 500*distanza^2/minuti;
    }
    ~Corsa(){}
};
class Nuoto: public Workout{
    public:
    int nvasche;
    Nuoto(): nvasche(0){}
};
class StileLibero: public Nuoto{
    StileLibero(int vasche=0){nvasche = vasche;}
    StileLibero* clone() const {
        StileLibero* s = new StileLibero(*this);
    }
    int calorie() const {
        if(minuti<10)
            return 35*nvasche;
        else return 40*nvasche;
    }
};
class Dorso: public Nuoto{
    public:
    Dorso(int vasche=0) {nvasche = vasche;}
    Dorso* clone() const {
        Dorso* s = new Dorso(*this);
    }
    int calorie() const {
        if(minuti<15)
            return 30*nvasche;
        else return 35*nvasche;
    }
};
class Rana: Nuoto{
    public:
    Rana(int vasche=0) {nvasche = vasche;}
    Rana* clone() const {
        Rana* s = new Rana(*this);
    }
    int calorie() const {
        return 25*nvasche;
    }
};
class InForma {
    const Workout *primo;
    vector<Nuoto*> vasche(int v) const   {
        const Workout *p = primo;
        const vector<Nuoto*> vec;
        if(primo) {
            while(p) {
                if(typeid(*p)==typeid(Nuoto)) {
                    const Nuoto* n = dynamic_cast<const Nuoto*>(p);
                    if(n->nvasche >= v) {
                        vec.back = n->clone();
                    }
                }
                p++;
            }
        }
        return vec;
    }
    vector<Workout*> calorie(int c) const {
        const Workout *p = primo;
        const vector<Workout*> vec;
        if(primo) {
            while(p) {
                if(typeid(*p)!=typeid(Rana)) {
                    if(p->calorie() >= c) {
                        vec.back = p->clone();
                    }
                }
                p++;
            }
        }
        return vec;
    }
    
};
int main() {
    Rana r(5);
    cout<<r.calorie()<<endl;
    Rana *copia = r.clone();
    cout<<copia->calorie()<<endl;
}