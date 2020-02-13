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
C& F(C& p) {return p;}
C w("3");
class D{
    static C c;
};
C D::c("4");

int main(){
    cout<<"PROGRAMMA TRE"<<endl;
    C x("5"), y("6");
    D d;
    y=F(x); cout<<"UNO"<<endl;
    C z=F(x); cout<<"DUE"<<endl;
    return 0;
}
/*STAMPE:
senza ottimizzazione:
    5~C 5~C 5~C-> distrutti z-y-x poichè y e z non sono dichiarati come alias
    4~C -> distrutto D
    3~C -> distrutto w
con ottimizzazione: uguale
*/