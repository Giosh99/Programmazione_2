#include<iostream>
#include<typeinfo>
#include<vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
class Anomalia {
    public:
    Anomalia(char c){}
};
class Scheda{
    protected:
    float residuo;
    private:
    const string numero;
    int costoSMS;
    public:
    Scheda(string _numero=0, float _residuo=0, int costoSMS=0):numero(_numero){}
    virtual void telefonata(unsigned int)=0;
    virtual void connessione(double)=0;
    virtual void messaggioSMS(unsigned int)=0;
    float getResiduo() {
        return residuo;
    }
    string getNumero() {return numero;}
};
class Mensile : public Scheda{
    private:
    const unsigned int secDisponibili;
    unsigned int secUsati;
    double MBdisp;
    double MBusati;
    const unsigned int costo;
    public:
    Mensile(string _numero=0, float _residuo=0, int _costo=0):
    Scheda(_numero,_residuo,0.1), secDisponibili(6000), MBdisp(2096), costo(_costo) {}
    void telefonata(unsigned int m) {
        secUsati+=m;
        if(secUsati>secDisponibili)
            Anomalia('v');
    }
    void connessione(double mb) {
        MBusati+=mb;
        if(MBusati>MBdisp)
            Anomalia('d');
    }
    void messaggioSMS(unsigned int){}
};
class Consumo: public Scheda {
    public: //private
    float costoMB;
    float costoSec;
    public:
    Consumo(string _numero=0, float _residuo=0):Scheda(_numero,0,0.2), costoSec(0.01),costoMB(0.1){}
    void telefonata(unsigned int n) {
        (float)n*costoSec>(float)residuo ? Anomalia('v'): (residuo-n*costoSec);
    }
    void connessione(double mb) {
        (float)mb*costoMB>(float)residuo ? Anomalia('d'): (residuo-(float)mb*costoMB);
    }
    void messaggioSMS(unsigned int) {}
};
class P2 {
    public:
    vector<Scheda*> vec;
    public:
    P2() {}
    Consumo*cambioPiano(string s) {
        int i=0;
        Consumo* c=0;
        for(vector<Scheda*>::iterator it=vec.begin(); it!=vec.end(); ++it, i++) {
            if(auto a = dynamic_cast<Mensile*>(*(it))&&s==(*(*(it))).getNumero()) {
                c = new Consumo((*(it))->getNumero(),(*(it))->getResiduo() );
                vec.erase(it);
                if(c) vec.push_back(c);
            }
        }
        return c;
    }
};
int main() {
    P2 p;
    Mensile m = Mensile("1", 5.0, 10.0);
    Scheda* s1 = &m;
    Scheda*s2 = 0;
    p.vec.push_back(s1);
    p.cambioPiano("1");
    //cout<<dynamic_cast<Consumo*>(p.vec[0])->getNumero()<<endl;
}