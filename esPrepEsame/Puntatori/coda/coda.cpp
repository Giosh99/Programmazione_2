#include<iostream>
using std::cout;
using std::endl;
int main();
template <class T=double> 
class coda{
    friend int main();
    class nodo{
        public:
        T value;
        nodo* next;
        nodo* prev;
        nodo(): prev(0), next(0){}
        nodo(const T& v, nodo*n=0, nodo*p=0): value(v), next(n), prev(p) {}
        ~nodo() {
            delete next;
        }
    };
    nodo* first;
    nodo*last;
    static bool isLess(nodo* d1, nodo* d2) {
        return d1->info<d2->info||(d1->info==d2->info && isLess(d1,d2));
    }
    public:
    coda(): first(0), last(0){}
    coda(int k, const T& t) {
        for(int i = 0; i<k;i++) {
            insert(t);
        }
    }
    void insert(const T& t) {
        if(!first) {
            first = new nodo(t);
            last = first;
        }
        else {
            last = new nodo(t,0,last);
            (last->prev)->next = last;
        }
    }
    T removeNext() {
        if(first!=0) {
            nodo* old = first;
            first = first->next;
            old->next = 0;
            T t= old->value;
            delete old;
            return t;
        }
        else return NULL;
    }
    T* getNext() const {
        return (first!=0?new T(first->value):0);
    }
    bool operator<(const coda&c) const {
        return isLess(this->first, c.first);
    }
    coda& operator+(const coda&c) {
        nodo*n = c.first;
        while(n) {
            insert(n->value);
            n = n->next;
        }
        return *this;
    }
        // iteratore
    class const_iterator {
        friend coda;
        private:
        nodo* ptr;
        bool pastTheEnd;
        // permette la conversione da nodo a const_iterator
        const_iterator(nodo*n=0, bool p=false): ptr(n), pastTheEnd(p) {}
        public:
        const_iterator& operator++(){
            if(ptr!=0) {
                if(!pastTheEnd) {
                    if(ptr->next==0){
                        pastTheEnd = true;
                        ++ptr;
                    }
                    else ptr=ptr->next;
                }
            }
            return *this;
        }
        const_iterator& operator--(){
            if(ptr!=0){
                if(pastTheEnd) {
                    --ptr;
                    pastTheEnd = false;
                }
                else 
                    ptr = ptr->prev;
            }
            return *this;
        }
        bool operator != ( const const_iterator& c) const {
            return ptr!=c.ptr;
        }
        T& operator*() {
            return ptr->value;
        }
    };
    const_iterator begin() const {
        return first;
    }
    const_iterator end() const {
        if(last==nullptr) return nullptr;
        return const_iterator(last+1,true);
    }
};
int main() {
    //coda<int> c1(5,5);
   // coda<int> c2(5,6);
    //<int> result = c1+c2;
    coda<int> c3;
    c3.insert(1);
    c3.insert(2);
    c3.insert(3);
    c3.insert(4);
    for(coda<int>::const_iterator it = c3.begin(); it!=c3.end(); ) {
        cout<<"ok"<<endl;
        cout<<*it<<endl;
        ++it;
    }
}