#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class GalloFile {
    double MB;
    public:
    virtual GalloFile* clone() const = 0;
    virtual bool hightQuality() const = 0;
    double getMB() const {return MB;}
    virtual ~GalloFile();
};

class Foto: public GalloFile {
    bool flash;
    unsigned int ISO;
    public:
    Foto* clone() const {
        return new Foto(*this);
    }
    bool hightQuality() const {
        return (ISO>=500?true:false);
    }
    bool getFlash() const {return flash;}
};
class Video: public GalloFile {
    unsigned int secondi;
    bool FullHD;
    public:
    Video* clone() const {
        return new Video(*this);
    }
    bool hightQuality() const {
        return FullHD;
    }
    unsigned int getSecondi() const {return secondi;}
};
class Gallo {
    private:
    vector<GalloFile*> g;
    public:
    vector<GalloFile*> selectHQ() const {
        vector<GalloFile*> ris;
        for(vector<GalloFile*>::const_iterator it = g.begin(); it!=g.end(); ++it) {
            if((*it)->hightQuality()) {
                auto *p = dynamic_cast<Foto*>(*it);
                if(p) {
                    if(p->getFlash()) {
                        ris.push_back(p);
                    }
                }
                else if(!p) {
                    ris.push_back(p);
                }
            }
        }
    }
    void removeNonFoto(double k) {
        bool deleted= false;
        for(vector<GalloFile*>::const_iterator it = g.begin(); it!=g.end(); ++it) {
            auto *p = dynamic_cast<Foto*>(*it);
            if(!p) {
                delete *it;
                g.erase(it);
                deleted = true;
            }
            else if(p->getMB()>k) {
                delete *it;
                g.erase(it);
                deleted = true;
            }
        }
    }
    const GalloFile* insert(const GalloFile* pf) {
        auto *p = dynamic_cast<const Video*>(pf);
        if(!p) {
            GalloFile* ptr = const_cast<GalloFile*>(pf);
            g.push_back(ptr);
        }
        else if(p->getSecondi()<60) {
            GalloFile* ptr = const_cast<GalloFile*>(pf);
            g.push_back(ptr);
        }
    }
};