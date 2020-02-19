#include<iostream>
using std::endl;
using std::cout;
template <class T>
class dList {
    class nodo {
        T value;
        nodo* prev;
        nodo* next;
        nodo(const T& t= T(), nodo* n=0, nodo* p = 0): value(t), next(n), preev(p) {}
        ~nodo() {
            delete next;
        }
    };
    nodo* first;
    nodo*last;
    void copy(nodo*n) {
        nodo* c = n;
        while(c) {
            insertBack(c);
            c = c->next;
        }
    }
    static isLess(nodo* d1, nodo* d2) {
        if(d2 == nullptr) 
            return true;
        if(d1==nullptr) 
            return false;
        return d1->value<d2->value || (d1->value==d2->value && isLess(d1->next,d2->next));
    }
    public:
    dList(const dList& l) {
        delete first;
        copy(l.first);
    }
    dList& operator=(const dList& l) {
        if(this!=&l) {
            delete first;
            copy(l.first);
        }
    }
    ~dList() {delete first;}
    dList(int k, const T& t): first(0), last(0){
        insertBack(t);
    }
    void insertBack(const T& t) {
        if(!first) {
            first = new nodo(t,0,0);
            last = first;
        }
        else {
            last = new nodo(t,0,last);
            (last->prev)->next = last;
        }
    }
    void insertFront(const T& t) {
        if(!first) {
            first = new nodo(t,0,0);
        }
        else {
            first = new nodo(t,first,0);
            (first->next)->prev = first;
        }
    }
    // overloading operatore di <
    bool operator< (const dList& l1, const dList& l2) {
        return isLess(l1.first, l2.first);
    }
    class const_iterator {
        friend dList;
        private:
        bool pastTheEnd;
        nodo* ptr;
        const_iterator(nodo* p=0, bool end=false): ptr(p), pastTheEnd(end){}
        public:
        const_iterator& operator++ () {
            if(ptr) {
                if(!pastTheEnd)  {
                    if(ptr->next)
                        ptr = ptr->next;
                    else {
                        ++ptr;
                        pastTheEnd = true;
                    }
                }
            }
            return *this;
        }
        const_iterator& operator--() {
            if(ptr) {
                if(pastTheEnd) {
                    --ptr;
                    pastTheEnd = false;
                }
                else 
                    ptr = ptr->prev;
            }
            return *this;
        }
        T operator*() const {
            return ptr->value;
        }
        T* operator -> () const {
            return ptr;
        }
        bool operator==(const const_iterator& x) const{
            return ptr==x.ptr;
        }
        bool operator!=(const const_iterator& x)const {
            return ptr!=x.ptr;
        }
    };
    const_iterator begin() const { // [ un const_iterator, non possiamo permettere di fargli assegnare cose
        return first;
    }
    const_iterator end() const {
        if(last==nullptr) nullptr;
        return const_iterator(last+1, true);
    }
};