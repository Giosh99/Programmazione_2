#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

class Workout {
    private:
    int durata; // in minuti
    public:
    virtual Workout* clone() const =0;
    virtual int calorie() const =0;
    virtual ~Workout() {}
    int getDurata() const {
        return durata;
    } 
};

class Corsa: public Workout {
    int distanza;
    public:
    Corsa* clone() const {
        return new Corsa(*this);
    } 
    int calorie() const {
        return (500*distanza^2)/getDurata();
    }
};

class Nuoto: public Workout {
    private:
    int nVasche;
    public:
    Nuoto* clone() const =0; // occhio che qui non posso ridefinirla ritornando un new Nuoto(*this) perche la classe e' astratta
    int getNumeroVasche() const {return nVasche;}
};

class StileLibero: public Nuoto {
    public:
    StileLibero* clone() const {
        return new StileLibero(*this);
    }
    int calorie() const {
        return (getDurata()<10? 35*getNumeroVasche(): 40*getNumeroVasche());
    }
};

class Dorso: public Nuoto {
    public:
    Dorso* clone() const {
        return new Dorso(*this);
    }
    int calorie() const {
        return (getDurata()<15?30*getNumeroVasche():35*getNumeroVasche());
    }
};

class Rana: public Nuoto {
    public:
    Rana* clone() const {return new Rana(*this);}
    int calorie() const {
        return 25*getNumeroVasche();
    }
};
class InForma {
    private:
    vector<const Workout*> vec;
    public:
    vector<Nuoto*> vasche(int v) {
        vector<Nuoto*> n;
        for(vector<const Workout*>::const_iterator it = vec.begin(); it!=vec.end(); ++it) {
            auto *p = dynamic_cast<const Nuoto*>(*it); // attenzione che non posso castarlo a Nuoto* perche dynamic_cast non toglie il cast
            if(p&&p->getNumeroVasche>v) {
                n.push_back((const_cast<Nuoto*>(p))->clone()); //
            } 
        }
        return n;
    }
    vector<Workout*> calorie(int x) {
        vector<Workout*> n;
        for(vector<const Workout*>::const_iterator it = vec.begin(); it!=vec.end(); ++it) {
            auto *p = dynamic_cast<const Rana*>(*it); // attenzione che non posso castarlo a Nuoto* perche dynamic_cast non toglie il cast
            if(!p&&(*it)->calorie()>x) {
                n.push_back(const_cast<Workout*>(*it)->clone());
            }
        }
        return n;
    }
    void removeNuoto() {
        int max = 0;
        for(vector<const Workout*>::const_iterator it = vec.begin(); it!=vec.end(); ++it) {
            auto *p = dynamic_cast<const Nuoto*>(*it); // attenzione che non posso castarlo a Nuoto* perche dynamic_cast non toglie il cast
            if(p) {
                if(max<p->calorie())
                    max = p->calorie();
            }
        }
        for(vector<const Workout*>::const_iterator it = vec.begin(); it!=vec.end(); ++it) {
            auto *p = dynamic_cast<const Nuoto*>(*it); // attenzione che non posso castarlo a Nuoto* perche dynamic_cast non toglie il cast
            if(p) {
                if(max==p->calorie()) {
                    delete p; // importante, perche altrimenti vec::erase libera lo spazio occupato dal puntatore ma non l'oggetto nello heap
                    vec.erase(it);
                }
            }
        }
    }
};
int main() {
}