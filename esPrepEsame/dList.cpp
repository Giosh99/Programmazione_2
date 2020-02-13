#include<iostream>
using std::cout;
using std::endl;
template <class T> 
class dList{
    class nodo {
        public:
        T value;
        nodo* next;
        nodo(): next(0){}
        nodo(T _value, nodo* _next=0): value(_value), next(_next){} 
        ~nodo() {
            delete next;
        }
    };
    nodo* first;
    nodo* last;
    nodo* copy(nodo* n) {
        if(n)
            nodo *first = new nodo(n->value);
        else return 0;
        nodo*i = first;
        while(n->next) {
            i->next = new nodo(n->next->value);
            i = i->next;
            n = n->next;
        }
        last = i;
        return first;
    }
    public:
    dList(int k, const T& t): first(0), last(0){
        if(!first) {
            first = new nodo(t);
            k--;
        }
        nodo* i = first;
        while(k>0) {
            i->next = new nodo(t);
            i = i->next;
            k--;
        }
        last = i;
    }
    void insertFront(const T& t) {
        first = new nodo(t, first);
    }
    void insertBack(const T& t){
        last->next = new nodo(t);
        last = last->next;
    } 
    // ridefinizione operatore di assegnazione
    const dList& operator=(const dList& d) {
        if(this!=&d) {
            delete first;
            first = copy(d->first);
        }
        return *this;
    }
    // ridefinizione del costruttore di copia
    dList(const dList& d) {
        delete first;
        first = copy(d->first);
    }
    class const_iterator {
        friend dList;
        nodo*current;
        bool pastTheEnd;
        const_iterator(): current(0), pastTheEnd(false){} 
        const_iterator(nodo*p): current(p), pastTheEnd(false){}
        public:
        const T& operator*() {
            return current->value;
        }
        const_iterator& operator++() {
            if(current) {
                if(!pastTheEnd) {
                    if(current->next)
                        current++;
                    
                }
            }
        }
    };
    const_iterator begin() {
        return first; // conversione implicitatramite costruttore ad un parametro 
    }
    const_iterator end() {
        return last;
    }
    const_iterator size() {

    }
};
int main() {
    dList<int> l(3,100);
    dList<int>::const_iterator it = l.begin();
    cout<<(*(it));
}