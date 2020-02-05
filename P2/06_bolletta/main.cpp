#include "bolletta.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    telefonata t1(orario(), orario(0,3,5), "123456"), 
    t2(orario(12,3,4), orario(13), "2437449"), t3;
    bolletta b;
    b.aggiungi_telefonata(t1);
    b.aggiungi_telefonata(t2);
    b.aggiungi_telefonata(t3);
    cout<<b;
    cout<<"Durata totale: "<<b.somma_durate()<<endl;
    return 0;
}