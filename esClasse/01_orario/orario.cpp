#include<iostream>
#include "orario.h"
using namespace std;
orario::orario(int h, int m, int s){ //costruttore
    if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
        sec=0;
    else
        sec=h*3600+m*60+s;
}
int orario::ore() const{return sec/3600;}
int orario::minuti() const{return (sec/60)%60;}
int orario::secondi() const{return sec%60;}
orario::operator int() const{return sec;} //operatore esplicito di conversione
orario orario::operator+(const orario& op) const{ //NB scoping va prima di operator
    orario aux;
    aux.sec=(sec+op.sec)%SEC_GIORNO;
    return aux;
}

orario orario::operator-(const orario& op) const{
    orario aux=*this;
    aux.sec=(aux.sec-op.sec)%SEC_GIORNO;
    return aux;
}

bool orario::operator==(const orario& op) const{return sec==op.sec ? true:false;}
bool orario::operator<(const orario& op) const{return sec<op.sec ? true:false;}
bool orario::operator>(const orario& op) const{return sec>op.sec ? true:false;}

int main(){
   /* const orario LE_DUE(14);
    cout<<LE_DUE.ore()<<":"<<LE_DUE.minuti()<<":"<<LE_DUE.secondi()<<endl;
    const orario mezzanotte;
    cout<<mezzanotte.ore()<<":"<<mezzanotte.minuti()<<":"<<mezzanotte.secondi()<<endl; //ricordarsi parentesi su incovazione metodo
    int test=LE_DUE; //converte le due in secondi
    cout<<test<<endl;
    orario adesso(17,30,25);
    const orario quarto_dora(0,15);
    orario avanti=adesso+quarto_dora;
    cout<<"Adesso più un quarto d'ora: "<<avanti.ore()<<":"<<avanti.minuti()<<":"<<
    avanti.secondi()<<endl;
    orario indietro=adesso-quarto_dora;
    cout<<"Adesso meno un quarto d'ora:"<<indietro.ore()<<":"<<indietro.minuti()<<
    ":"<<indietro.secondi()<<endl;

    cout<<"Test overloading operatori confronto... ";
    if(mezzanotte==LE_DUE || adesso<indietro || adesso>avanti)
        cout<<"Something went wrong..."<<endl;
    else
        cout<<"Passed!"<<endl;*/
    orario c = 5;
    std::cout<<c.ore();
    return 0;
}