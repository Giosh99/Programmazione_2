#include "bolletta.h"
#include <iostream>

//######### IMPLEMENTAZIONE CLASSE ITERATOR ##################################
bool bolletta::iterator::operator==(const iterator& x) const{
    return punt==x.punt;
}

bool bolletta::iterator::operator!=(const iterator& x) const{
    return punt!=x.punt;
}

bolletta::iterator& bolletta::iterator::operator++(){ //prefisso
    if(punt)
        punt=punt->next; //ha senso spostare il puntatore se c'è la possibilità che ci sia qualcosa oltre
    return *this;
}

bolletta::iterator bolletta::iterator::operator++(int){ //postfisso
    iterator aux=*this;
    if(punt)
        punt=punt->next;
    return aux;
}

bolletta::iterator bolletta::begin() const{
    iterator aux;
    aux.punt=first;
    return aux;
}

bolletta::iterator bolletta::end() const{
    iterator aux;
    aux.punt=nullptr;
    return aux;
}

telefonata& bolletta::operator[](const iterator& it) const{
    return (it.punt)->info;
    //NB: nessun controllo se punt=0, poichè sarà compito di chi usa la classe iterator
}

telefonata* bolletta::iterator::operator->() const{
    return &(punt->info);
    //ritorno il puntatore alla telefonata contenuta in quel nodo, poichè
    //mi aspetto di poter invocare -> più volte di fila
    //it->fine() = (it.operator->())->fine
}

telefonata& bolletta::iterator::operator*() const{
    return punt->info;
}
//###########################################################################

bolletta::bolletta():first(nullptr){}

//bolletta::~bolletta(){distruggi(first);} obsoleto

bolletta::nodo::nodo():info(), next(nullptr){}

bolletta::nodo::nodo(const telefonata& t, nodo* L):info(t), next(L){}

bolletta::nodo::~nodo(){ //distruttore ricorsivo dei nodi
    if (next!=0)        //chiamando una delete sul primo nodo (la quale invoca il distruttore)
        delete next;    //distruggendo cosi la lista ricorsivamente
}

bool bolletta::vuota() const{
    return !first ? true:false;
}

void bolletta::aggiungi_telefonata(telefonata t){
    first=new nodo(t, first);
}

void bolletta::togli_telefonata(const telefonata& t){
    nodo *p=first, *prec=nullptr;
    while(p){
        if(p->info==t){
            if(prec)
                prec->next=p->next;
            else
                first=p->next;
            delete p;
            p=0;
        }
        else{
            prec=p;
            p=p->next;
        }
    }
}
//Precondizione: lista(first) non vuota
telefonata bolletta::estrai_una(){
    telefonata aux=first->info;
    nodo* tmp=first->next;
    first->next=0;
    delete first;
    first=tmp;
    return aux;
}

//######### IMPLEMENTAZIONE DEEP COPY #############
bolletta& bolletta::operator=(const bolletta& x){
    if(this != &x){ //confronto gli indirizzi delle due bollette, in modo che se fosse la stessa non eseguo operazioni
        //distruggi(first); //NB: pulisco garbage nello heap
        delete first;
        first=copia(x.first);
    }
    return *this;
}

bolletta::bolletta(const bolletta& x):first(copia(x.first)){}

//PRE: lista(L) ben formata, possibilmente vuota
bolletta::nodo* bolletta::copia(nodo* L){
    if(!L) return nullptr;
    return new nodo(L->info, copia(L->next));
}
//POST: ritorna il puntatore ad una lista identica ma separata da lista(L)
void bolletta::distruggi(nodo* L){
    if(!L) return;
    distruggi(L->next);
    delete L;
}
//##################################################

std::ostream& operator<<(std::ostream& os, const bolletta& x){
    for(bolletta::iterator i=x.begin(); i!=x.end(); i++)
        os<<*i; //ok perchè * su iterator ritorna una telefonata
    return os;
}

orario bolletta::somma_durate() const{
    orario durata;
    for(iterator i=begin(); i!=end(); i++)
        durata=durata+i->Fine() - i->Inizio();
    return durata;
}