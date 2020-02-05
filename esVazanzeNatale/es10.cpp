#ifndef MultiInfo_H
#define MultiInfo_H
#include <iostream>
template< class T1, unsigned int size=0>
class C {
    friend std::ostream& operator<<(std::ostream&,const C&);
    private:
    class MultiInfo {
        public:
        T1 info;
        T1 *next;
        MultiInfo(): next(0){}
        MultiInfo(const T1& i,*n=0): info(i), next(n){}
        ~MultiInfo() {
            delete next;
        }
    };
    MultiInfo *informazione;
    MultiInfo* copia(MultiInfo* m) {
        if(!m) return 0;
        MultiInfo*primo = new MultiInfo(m->info, new MultiInfo());
        MultiInfo*q = primo;
        while(m->next) {
            q->next = MultiInfo(m->next->info, new MultiInfo());
            q=q->next;
            m = m->next;
        }
        q->next = 0;
        return primo;
    }
    public:
    C(T1 t,size) {
        informazione = new MultiInfo();
    }
    // costruttore di copia profondo
    C(const C& c): informazione(copia(c->informazione)){}
    // distruttore profondo
    ~C() {
        delete informazione;
    }
    //ridefinizione di assegnazione
    const C& operator =(const C& c) {
        if(this!=&c) {
            delete informazione;
            informazione = copia(c.informazione);
            return *this;
        }
    }
    T1* operator [] (int i) {
        if(0<=i<size) {
            MultiInfo*p=informazione;
            while(i>0) {
                p = p->next;
                i--;
            }
            return p;
        }
    }
    int occorrenze(const T1& t) {
        MultiInfo*p = informazione;
        int c = 0;
        while(p) {
            if(p->info == t->info)
                c++;
            p = p->next;
        }
        return c;
    }
};
template< class T1, unsigned int size=0>
std::ostream& operator<<(std::ostream& s,const C<T1,size>& c){
    int i =0;
    while(c[i]!=0) {
        s<<c[i]->info;
    }
    return s;
}
#endif