#ifndef BOLLETTA_H
#define BOLLETTA_H
#include "telefono.h"
#include <iostream>
class bolletta{
    private:
        struct nodo{
            nodo();
            nodo(const telefonata&, nodo*);
            ~nodo();
            telefonata info;
            nodo* next;
        };
        nodo* first;
        static nodo* copia(nodo*); //metodi ausiliari per operare sulle liste
        static void distruggi(nodo*);//distrugge l'oggetto di partenza (garbage)
                                    //OBSOLETO in quanto dichiarato distruttore di nodo
                                    //per distruggere la lista si usa la keyword delete
    public:
        class iterator{ //dichiaro una sottoclasse che avrà accesso alla parte privata di bolletta, friend omissibile
            friend class bolletta; //garantisco accesso alla classe privata alla classe padre (bolletta)
            private:
                bolletta::nodo* punt; //nodo puntato dall'iteratore
            public:
                bool operator==(const iterator&) const;
                bool operator!=(const iterator&) const;
                iterator& operator++();     //op ++ prefisso
                iterator operator++(int); //op ++ postfisso
                telefonata* operator->() const; //necessario definirlo interno poichè ha solo un operatore e deve essere quello di invocazione di tipo iterator
                telefonata& operator*() const; //come operator->
        };
        bolletta();
        //~bolletta(); ora il distruttore di bolletta è obsoleto, in quanto è stato dichiarato quello di nodo
                    //che è l'unico elemento appartenente alla classe
        bool vuota() const;
        void aggiungi_telefonata(telefonata); //va necessariamente passato per valore
        void togli_telefonata(const telefonata&);
        telefonata estrai_una();
        bolletta& operator=(const bolletta&); //ridefinisco operatore di assegnazione e costruttore di copia
        bolletta(const bolletta&);             //poiché se uso una lista nello heap la shallow copy di default crea interferenza tra oggetti.
                                            //è necessario quindi implementare una deep copy
        friend std::ostream& operator<<(std::ostream& os, const bolletta&);
        //metodi che usano iteratore
        iterator begin() const;
        iterator end() const;
        telefonata& operator[](const iterator& it) const; //va definito in bolletta e non in iterator poichè il primo operatore è una bolletta, il secondo un iteratore
        orario somma_durate() const;
};
#endif