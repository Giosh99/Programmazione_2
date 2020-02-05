#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
class GalloFile {
    private:
    double MB;
    public:
    virtual GalloFile* clone() const = 0;
    virtual bool highQuality() const  =0;
    virtual ~GalloFile(){}
    GalloFile(double _MB=0):MB(_MB){} 
    double getMB(){return MB;}
};
class Foto: public GalloFile {
    private:
    unsigned int iso;
    bool flash;
    public:
    Foto* clone() const {return new Foto(*this);}
    bool highQuality() const {return(iso>=500?true:false);}
    Foto(unsigned int _iso=0, bool _flash=false, double MB=0): iso(_iso), flash(_flash), GalloFile(MB){}
    bool getFlash() {return flash;}
};
class Video: public GalloFile {
    private:
    unsigned int sec;
    bool FullHD;
    public:
    Video* clone() const {return new Video(*this);}
    bool highQuality()const {
        return (FullHD?true:false);
    }
    Video(unsigned int _sec=0, bool _FullHD=false, double _MB=0): sec(_sec), FullHD(_FullHD), GalloFile(_MB) {}
    bool getFullHD() const {return FullHD;}
    unsigned int getDurata() const {return sec;}
};
class Gallo {
    private:
    vector<GalloFile*> g;
    public:
    vector<GalloFile*> selectHQ() {
        vector<GalloFile*> vec;
        for(vector<GalloFile*>::const_iterator it=g.begin(); it!=g.end();++it) {
            if((*(it))->highQuality) {
                if(auto a = dynamic_cast<Foto*>(*(it))){
                    if(a->getFlash)
                        vec.push_back(*(it));
                    else continue;
                }
                vec.push_back(*(it));
            }
        }
    }
    void removeNonFoto(double size) {
        int i =0;
        for(vector<GalloFile*>::const_iterator it=g.begin(); it!=g.end();++it) {
            if(typeid(*(*(it)))!= typeid(Foto) || (*(it))->getMB()>size) {
                g.erase(it);
                i++;
            }
        }
        if(i==0) std::logic_error("NoRemove");
    }
    const GalloFile* insert(const GalloFile* pf){
        if(typeid(*pf)!=typeid(Video*) || (typeid(*pf)==typeid(Video*)&& dynamic_cast<const Video*>(pf)->getDurata()>60)) {
            GalloFile*p = pf->clone();
            g.push_back(p);
            return p;
        }
    }
} ;