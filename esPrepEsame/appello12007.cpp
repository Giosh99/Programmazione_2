#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class Biglietto {
    private:
    int distanza;
    static double prezzoKm;
    public: 
    int getDistanza() {return distanza;}
    static int getPrezzoKm() {return prezzoKm;}
    Biglietto(int d=0): distanza(d){};
    virtual double prezzo()=0;
    virtual ~Biglietto() {}
};
double Biglietto::prezzoKm = 0.1;

class BigliettoPrimaClasse: public Biglietto {
    public:
    BigliettoPrimaClasse(int d=0):Biglietto(d) {}
    double prezzo() {
        int perc = 0;
        if(getDistanza()<100)
            perc = 30;
        else perc = 20;
        return getDistanza()*getPrezzoKm()+ ((getDistanza()*getPrezzoKm())/100)*perc;
    }
};
class BigliettoSecondaClasse: public Biglietto {
    private:
    bool prenotazione;
    public:
    BigliettoSecondaClasse(int d=0, bool p=false): prenotazione(p), Biglietto(d){};
    double prezzo() {
        if(prenotazione)
            return getDistanza()*getPrezzoKm()+5;
        else return getDistanza()*getPrezzoKm();
    }
};
class BigliettoSmart: public Biglietto {
    public:
    Biglietto* b;
    BigliettoSmart(const Biglietto& bi) { b = const_cast<Biglietto*>(&bi) ;}
};
class TrenoPieno {
    bool pieno;
    public:
    TrenoPieno(bool p=false): pieno(p) {}
};
class Treno {
    private:
    vector<BigliettoSmart*> venduti;
    unsigned int n_primaClasse;
    unsigned int n_secondaClasse_prenota;   
    public:
    int* bigliettiVenduti() const {
        int prima=0;
        int seconda_p=0;
        int seconda=0;
        for(vector<BigliettoSmart*>::const_iterator it = venduti.begin();it!=venduti.end(); ++it) {
            if(dynamic_cast<)
        }
    }
};
int main(){}