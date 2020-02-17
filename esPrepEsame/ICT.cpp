#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
enum laurea {Informatica, Ingegneria, Altro};
class ICTstaff {
    protected:
    double mensile;
    laurea tipoLaurea;
    bool magistrale;
    public:
    virtual ICTstaff* clone() const = 0;
    virtual double salary() const = 0;
    laurea getLaurea() const {return tipoLaurea;}
    bool getMagistrale() const {return magistrale;} 
};
class SwEngineer: public ICTstaff {
    private:
    static int aumento;
    private:
    bool sicurezza;
    public:
    SwEngineer* clone() const {
        return new SwEngineer(*this);
    }
    double salary() const {
        return (sicurezza==true?mensile+aumento: mensile);
    }
    bool getSicurezza() const {return sicurezza;}
};
int SwEngineer::aumento = 500;
class HwEngineer: public ICTstaff {
    private:
    int trasferte;
    public:
    HwEngineer* clone() const {
        return new HwEngineer(*this);
    };
    double salary() const {
        return mensile+300*trasferte;
    }
};
class Amazonia {
    class SmartP {
        public:
        ICTstaff*ptr;
        SmartP(ICTstaff* p=nullptr): ptr(p!=nullptr?p->clone(): nullptr) {}
        // ridefinzione costruttore di copia
        SmartP(const SmartP& s) {
            delete ptr;
            ptr = s.ptr->clone();
        }
        // ridefinzione assegnazione
        SmartP& operator= (const SmartP& s) {
            if(this!=&s) {
                delete ptr;
                if(s.ptr) {
                    ptr = s.ptr->clone();
                }
                else ptr=nullptr;
            }
            return *this;
        }
        ~SmartP() {delete ptr;}
        ICTstaff& operator* () const{
            return *ptr;
        }
        ICTstaff* operator->() const{
            return ptr;
        }
        public:
        vector<SmartP> vec;
        bool insert(SwEngineer*s, unsigned int k) {
            int i = 0;
            for(vector<SmartP>::iterator it=vec.begin(); it!=vec.end(); ++it) {
                auto* p = dynamic_cast<SwEngineer*>((*(it)).ptr);
                if(p&&p->getSicurezza())
                    i++; 
            }
            if(i<k) {
                vec.push_back(s); //usa il costruttore ad un parametro come convertitore implicito
                return true;
            }
            else return false;
        }
        
        vector<HwEngineer> fire(double s) {
            vector<HwEngineer> h;
            for(vector<SmartP>::iterator it=vec.begin(); it!=vec.end(); ++it) {
                auto *p = dynamic_cast<HwEngineer*>((*it).ptr);
                if(p&&p->salary()>s ) {
                    h.push_back(*(p->clone()));
                    vec.erase(it);
                }
                return h;
            }
        }
        vector<SwEngineer*> masterInf() const {
            vector<SwEngineer*>v;
            for(vector<SmartP>::const_iterator it=vec.begin(); it!=vec.end(); ++it) {
                auto *p = dynamic_cast<SwEngineer*>((*it).ptr);
                if(p&&p->getLaurea()==laurea::Informatica&&p->getMagistrale()) {
                    v.push_back(p);
                }
            }
            return v;
        }

    };
};