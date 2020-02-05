#ifndef DLIST_H
#define DLIST_H
#include <ostream>
template <class T>
class dList;
template <class T>
std::ostream &operator<<(std::ostream &, const dList<T> &);
template <class T>
class dList
{
    friend std::ostream &operator<<<T>(std::ostream &, const dList &);

private:
    struct nodo
    {
        nodo(const T &_info = T(), nodo *_prev = 0, nodo *_next = 0) : info(_info), prev(_prev), next(_next) {}
        ~nodo() { delete next; }
        T info;
        nodo *prev, *next;
    }; //FINE CLASSE NODO

    //rule of three: costruttore di copia, assegnazione, distruttore
    nodo *first, *last;
    //PRE: lista(p) ben formata e p primo nodo della lista
    static nodo *copia(nodo *p, nodo *&last)
    {
        if (!p)
        {
            last = nullptr;
            return nullptr; //non ho più nulla da copiare
        }
        nodo *tmp = copia(p->next, last);
        nodo *aux = new nodo(p->info, nullptr, tmp);
        if (tmp)
            tmp->prev = aux;
        else
            last = aux;
        return aux;
    }
    //POST: ritorno puntatore a primo nodo di copia profonda lista(p) e per riferimento puntatore a ultimo nodo
public:
    dList() : first(nullptr), last(nullptr) {}
    ~dList() { delete first; }
    dList(const dList &L)
    {
        first = copia(L.first, last);
    }
    dList(int k, const T &t)
    { //costruisce una lista contenente k nodi tutti con il campo info t
        nodo *p = nullptr;
        nodo *tmp = nullptr; //puntatore al nodo precedente: serve per collegare la lista nel campo prec
        for (int i = 0; i < k; i++)
        {
            p = new nodo(t, tmp);
            tmp = p;
            if (i < k - 1)
                p = p->next;
        }
        //al termine di questo ciclo ho una lista collegata solo tramite prev, e p punta all'ultimo nodo
        last = p;
        //ora per collegare tutti i campi next utilizzo la tecnica all'inverso, sfruttando sempre il puntatore temporaneo tmp, ma in questo caso esso
        //punterà al nodo successivo a quello corrente
        for (int i = 0; i < k; i++)
        {
            if (i > 0)
                p->next = tmp;
            tmp = p;
            if (i < k - 1)
                p = p->prev;
        }
        first = p;
    }

    dList operator=(const dList &L)
    {
        if (this != &L) //NB: ricordati di controllare gli indirizzi (es x=x non devo fare niente)
        {
            delete first;
            first = copia(L.first, last);
        }
        return *this;
    }
    void insertFront(const T &t)
    {
        first = new nodo(t, nullptr, first);
        if (first->next)
            first->next->prev = first;
        else
            last = first;
    }
    void insertBack(const T &t)
    {
        nodo *tmp = last;
        last = new nodo(t, last, nullptr);
        if (tmp)
            tmp->next = last;
        else
            first = last;
    }
    bool operator<(const dList &L) const
    {
        nodo *p1 = first, *p2 = L.first;
        while (p1 && p2)
        {
            if (p1->info < p2->info)
                return true;
            if (p1->info > p2->info)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1 && !p2;
    }
    class const_iterator
    {
        friend class dList<T>;

    private:
        const nodo *p;
        bool pastTheEnd;
        const_iterator(nodo *x, bool b = false) : p(x), pastTheEnd(b) {} //convertitore da nodo* a const_iterator
    public:
        const_iterator() : p(nullptr), pastTheEnd(false) {}
        const_iterator operator++()
        { //prefisso
            if (!p)
                return *this;
            if (pastTheEnd || p->next)
                p = p->next;
            else
            {
                ++p;
                pastTheEnd = true;
            }
            return *this;
        }
        const_iterator operator++(int)
        { //postfisso
            const_iterator aux = *this;
            if (p)
            {
                if (pastTheEnd || p->next)
                    p = p->next;
                else
                {
                    ++p;
                    pastTheEnd = true;
                }
            }
            return aux;
        }
        const_iterator operator--()
        {
            if (!p)
                return *this;
            if (pastTheEnd)
            {
                --p;
                pastTheEnd = false;
            }
            else
                p = p->prev;
            return *this;
        }
        const_iterator operator--(int)
        {
            const_iterator aux = *this;
            if (p)
            {
                if (pastTheEnd)
                {
                    --p;
                    pastTheEnd = false;
                }
                else
                    p = p->prev;
            }
            return aux;
        }
        /* bool operator<(const_iterator& it) const //TODO - non funziona
                {
                    nodo *p1=first;
                    while(p1!=p && p1!=it.p)
                        p1=p1->next;
                    return p1==p && p1!=it.p;
                }
                bool operator<=(const const_iterator& it) const //TODO: non funziona
                {
                    if(p==it.p) return true;
                    nodo *p1=first;
                    while(p1!=p && p1!=it.p)
                        p1=p1->next;
                    return p1==p;
                }*/
        bool operator==(const const_iterator &it) const
        {
            return p == it.p && pastTheEnd == it.pastTheEnd;
        }
        bool operator!=(const const_iterator &it) const
        {
            return p != it.p && pastTheEnd != it.pastTheEnd;
        }
        const T &operator*() const //NB: const si riferisce al puntatore p, non all'oggetto puntato da p
        {
            return p->info;
        }
        const_iterator operator+(int n)
        {
            const_iterator aux = *this;
            for (int i = 0; i < n; i++)
                aux++;
            return aux;
        }
        const_iterator operator-(int n)
        {
            const_iterator aux = *this;
            for (int i = 0; i < n; i++)
                aux--;
            return aux;
        }
    }; //FINE CLASSE CONST_ITERATOR
    const_iterator begin() const
    {
        return first; //funziona grazie al costruttore di conversione dichiarato nella parte privata di const_iterator
    }
    const_iterator end() const
    {
        return last ? const_iterator(last + 1, true) : nullptr;
    }
    int size() const
    {
        int s = 0;
        const_iterator it = begin();
        for (; it != end(); it++)
            s++;
        return s;
    }
    bool empty() const
    {
        return size() == 0;
    }
}; //FINE CLASSE DLIST

template <class T>
std::ostream &operator<<(std::ostream &os, const dList<T> &L)
{
    typename dList<T>::nodo *p = L.first;
    while (p)
    {
        os << p->info << " ";
        p = p->next;
    }
    return os;
}
#endif
