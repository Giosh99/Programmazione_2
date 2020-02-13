//PROGRAMMA DUE
#include <iostream>
#include <string>
using namespace std;

class C{
    public:
        string s;
        C(string x="1"):s(x){}
        ~C() {cout<<s<<"~C ";}
};
C F(C& p) {return p;}
C w("3");
class D{
    static C c;
};
C D::c("4");

int main(){
    cout<<"PROGRAMMA DUE"<<endl;
    C x("5"), y("6");
    D d;
    y=F(x); cout<<"UNO"<<endl;
    C z=F(x); cout<<"DUE"<<endl;
    return 0;
}
/*STAMPE:
senza ottimizzazione:
    5~C -> distrutto oggetto anonimo di ritorno da F
    5~C -> ancora F
    5~C 5~C 5~C -> distrutti in ordine z-y-x
    4~C -> distrutto D
    3~C -> distrutto w
con ottimizzazione: viene omessa la creazione (e annessa distruzione) dell'anonimo di ritorno di F
                    la seconda volta che questa viene eseguita
*/