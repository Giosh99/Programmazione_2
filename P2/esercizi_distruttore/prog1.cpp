//PROGRAMMA UNO
#include <iostream>
using namespace std;

class C{
    public:
        char c;
        C(char x='1'):c(x){}
        ~C(){cout<<c<<"~C ";}
};
C F(C p){return p;};
C w('3');
class D{
    static C c;
};
C D::c('4');

int main(){
    cout<<"PROGRAMMA UNO"<<endl;
    C x('5'), y('6');
    D d;
    y=F(x); cout<<"UNO"<<endl;
    C z=F(x); cout<<"DUE"<<endl;
    return 0;
}
/*STAMPE PREVISTE:
- senza ottimizzazione compilatore:
    5~C -> return p di F
    5~C -> parametro p di F
    5~C 5~C -> ancora invocata F
    5~C -> distrutto z
    5~C -> distrutto y
    5~C -> distrutto x
    4~C -> distrutto D
    3~C -> distrutto w
- con ottimizzazione compilatore: uguale

NB: - prima variabili locali al termine della funzione/main;
    - poi distrutti gli oggetti anonimi una volta assegnati
    - infine i parametri di F passati per valore da destra verso sinistra
    - variabili distrutte sempre in ordine inverso alla costruzione
    - gli oggetti statici e globali al termine del programma
*/