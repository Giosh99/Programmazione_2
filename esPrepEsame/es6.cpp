#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class Cliente {
    protected:
    int minUsati; //mimnuti telefonate
    int ntelefonate;
    int smsInviati;
    int datiUsati; //in MB
    const float costoDati;
    public:
    Cliente(): costoDati(0.01), minUsati(0), ntelefonate(0), smsInviati(0), datiUsati(0) {}
    virtual double costoMeseCorrente() const =0;

    int getMinutiUsati() const {return minUsati;}
    void setMinutiUsati(int m=1) {minUsati+=m;}

    int getTelefonate() const {return ntelefonate;}
    void setTelefonate(int m=1) {ntelefonate+=m;}

    int getSmsInviati() const {return smsInviati;}
    void setSmsInviati(int m=1) {smsInviati+=m;}
    virtual Cliente* clone() const=0;
};
class AlMinuto:public Cliente {
    private:
    const float scattoRisposta;
    const float ctelefonata;
    const float costoSms;
    public:
    AlMinuto(): scattoRisposta(0.15), ctelefonata(0.2),costoSms(0.1) {}
    double costoMeseCorrente() const  {
        return minUsati*ctelefonata+scattoRisposta*ntelefonate+datiUsati*costoDati+smsInviati*costoSms;
    }
    AlMinuto* clone() const {
        return new AlMinuto(*this);
    }
};
class Abbonamento: public Cliente {
    float costoAbb;
    int minutiDisp;
    float costOltreSogliaTel;
    public:
    Abbonamento(float costo=0, int m=0): costoAbb(costo), minutiDisp(m), costOltreSogliaTel(0.3){} 
    double costoMeseCorrente() const {
        return costoAbb+datiUsati*costoDati+(minUsati>minutiDisp? (minUsati-minutiDisp)*costOltreSogliaTel : 0);
    }
    bool sogliaSuperata() {
        if(minUsati>minutiDisp)
            return true;
    }
    Abbonamento* clone() const{
        return new Abbonamento(*this);
    }
};
class sedeMoon{
    private:
    vector<Cliente*> vec;
    public: 
    sedeMoon(): vec(0) {}
    void aggiungiCliente(const Cliente& c){
        vec.push_back(c.clone());
    }
    double incassoMensileCorrente() const {
        double sum=0;
        for(vector<Cliente*>::const_iterator it= vec.begin(); it!= vec.end(); ++it) {
            sum+=(**it).costoMeseCorrente();
        }
        return sum;
    }
    int numClientiAbbonatiOltreSoglia() {
        int sum=0;
        for(vector<Cliente*>::const_iterator it= vec.begin(); it!=vec.end(); ++it) {
            if(auto*p=(dynamic_cast<Abbonamento*>(*it))) {
                if(p->sogliaSuperata()) sum++;
            }
        }
        return sum;
    }
};
int main() {
    sedeMoon s = sedeMoon();
    Abbonamento a1(10,2);
    Abbonamento a2(10,3);
    Abbonamento a3;
    Abbonamento a4;
    AlMinuto m1;
    AlMinuto m2;
    AlMinuto m3;
    AlMinuto m4;
    s.aggiungiCliente(a1);
    s.aggiungiCliente(m1);
        s.aggiungiCliente(a2);
    s.aggiungiCliente(m2);
        s.aggiungiCliente(a3);
    s.aggiungiCliente(m3);
        s.aggiungiCliente(a4);
    s.aggiungiCliente(m4);
    a1.setMinutiUsati(4);
    a2.setMinutiUsati(4);
    cout<<s.numClientiAbbonatiOltreSoglia()<<endl;
}