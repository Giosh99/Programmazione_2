#include "alberi.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

nodo::nodo(char c, nodo* s, nodo* d):info(c), sx(s), dx(d){}

void tree::distruggi(nodo* r){
    if(!r) return;
    distruggi(r->sx); //garanzia di accesso ai campi privati della classe nodo
    distruggi(r->dx);
    delete r;
}

nodo* tree::copia(nodo* r){
    if(!r) return nullptr;
    return new nodo(r->info,copia(r->sx),copia(r->dx));
}

//SE TREE PASSATO PER RIFERIMENTO E' NULLO, COPIA UN ALBERO NULLO,
//ALTRIMENTI VIENE COPIATO TALE ALBERO
tree::tree(const tree& t):root(copia(t.root)){} 

//OVERLOADING OPERATORE DI ASSEGNAZIONE
tree& tree::operator=(const tree& r){
    distruggi(root);
    copia(r.root);
    return *this;
}

tree::tree(nodo* r):root(copia(r)){}

/*tree::~tree(){
    distruggi(root);
}*/

void nodo::stampa(nodo* r){
    if(!r)
        cout<<"_";
    else{
        cout<<r->info<<"(";
        stampa(r->sx);
        cout<<",";
        stampa(r->dx);
        cout<<")";
    }
}