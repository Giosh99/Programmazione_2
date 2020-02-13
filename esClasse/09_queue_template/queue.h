#ifndef QUEUE_H
#define QUEUE_H
#include <ostream>
template <class T> class queueItem{
    public:
        queueItem(): next(nullptr){}
        queueItem(const T& val, queueItem* n = nullptr):info(val), next(n){}
        T info;
        queueItem *next;
};
template <class T> class queue;

template <class T> std::ostream& operator<<(std::ostream&, const queue<T>&);

template <class T> class queue{
    friend std::ostream& operator<< <T>(std::ostream&, const queue<T>&); //amicizia in modalità associata
    /*
    NELLA DICHIARAZIONE DELL'OVERLOADING DELL' OPERATORE DI STAMPA <<, SOLAMENTE NELLA DICHIARAZIONE 
    ALL'INTERNO DELLA CLASSE PRESCELTA (DOVE VA LA DICHIARAZIONE DI AMICIZIA) VA SPECIFICATO IL PARAMETRO <T> PRECEDUTO DA UNO SPAZIO
    ALTRIMENTI IL COMPILATORE SEGNALA UN ERRORE.
    */
    public:
        queue():first(nullptr), last(nullptr){}
        ~queue(){svuota();}
        bool is_empty() const {return (!first && !last);}
        void add(const T& x){
            if(is_empty())
                first=last=new queueItem<T>(x);
            else{
                last->next=new queueItem<T>(x);
                last= last->next;
            }
        }
        T remove(){
            //PRE: coda non vuota
            T aux=first->info;
            queueItem<T> *tmp=first;
            first=first->next;
            if(!first)
                last=nullptr;
            delete tmp;
            return aux;
        }
        queue operator=(const queue& x){
            svuota();
            copia(x);
            return *this;
        }
        queue(const queue& x){
            first=last=nullptr;
            copia(x);
        }
    private:
        //rule of three, puntatori (costruttore di copia, assegnazione, distruttore)
        queueItem<T> *first, *last;
         void svuota(){
            while(!is_empty())
                remove();
            //first=last=nullptr;
        }
        //PRE: lista di invocazione è vuota
        void copia(const queue& a){
            queueItem<T>* p=a.first;
            while(p){
                add(p->info);
                p=p->next;
            }
        }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const queue<T>& x){
    queueItem<T> *p=x.first;
    while(p){
        os<<p->info<<" ";
        p=p->next;
    }
    return os;
}
#endif