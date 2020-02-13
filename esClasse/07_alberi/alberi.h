#ifndef ALBERI_H
#define ALBERI_H
#include <iostream>
class nodo{
    friend class tree;//do a tree la possibilita' di accedere a nodo.
    private:
        char info;
        nodo *sx, *dx;
        nodo(char='*', nodo* =nullptr, nodo* =nullptr);//COSTRUTTORE DI NODO
    public:
        static void stampa(nodo*); //stampa prefissa
        //va messo su parte pubblica perché friend non è transitivo
};

class tree
{
    private:
        nodo* root;
        static void distruggi(nodo*);
        static nodo* copia(nodo*);
    public:
        tree(nodo* =nullptr);
        tree(const tree& t);//COSTRUTTORE DI COPIA
        ~tree();//DISTRUTTORE
        tree& operator=(const tree&);
};
#endif
