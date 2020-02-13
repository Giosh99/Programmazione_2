#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;
class FileAudio {
    private:
    string titolo;
    double dimensione;
    public:
    double getDimensione() {
        return dimensione;
    }
    string getTitolo(){
        return titolo;
    }
    FileAudio(string _titolo="", double _dimensione=0): dimensione(_dimensione), titolo(_titolo){}
    virtual FileAudio* clone() const =0;
    virtual bool qualita() const=0;
    virtual bool operator==(const FileAudio& f) {
        return (titolo==f.titolo&&dimensione==f.dimensione?true:false);
    }
    virtual ~FileAudio(){}
};
class Mp3: public FileAudio{
    private:
    const int sogliaQual;
    int bitRate;
    public:
    int getBitRate() {
        return bitRate;
    }
    Mp3(int _bitRate=0, string _titolo="", double _dimensione=0) : sogliaQual(192), bitRate(_bitRate), FileAudio(_titolo,_dimensione){}
    Mp3* clone() const{
        return new Mp3(*this);
    }
    bool qualita() const{
        return (bitRate>=sogliaQual ? true: false);
    }
};
class WAV: public FileAudio{
    private:
    int freqCamp;
    bool lossless;
    public:
    bool getLossless(){
        return lossless;
    }
    WAV(int _freqCamp, bool _lossless, string _titolo="", double _dimensione=0):FileAudio(_titolo,_dimensione), freqCamp(_freqCamp), lossless(_lossless) {}
    WAV* clone() const {
        return new WAV(*this);
    }
    bool qualita() const {
        return (freqCamp>=96?true:false);
    }
    bool operator==(const FileAudio& f) {
        auto a = dynamic_cast<const WAV*>(&f);;
        a&&FileAudio::operator==(f)&&a->freqCamp==freqCamp&&lossless=a->lossless?true:false;
    }
};
class iZod {
    class Brano{
        public:
        FileAudio*p;
        Brano(FileAudio*f=0){
            f!=0? p = f->clone(): p=0;
        }
        // copia profonda 
        Brano(const Brano&b){
            delete p;
            p = b.p->clone();
        }
        // assegnazione profonda 
        const Brano& operator=(const Brano& b) {
            if(this!=&b){
                delete p;
                p = b.p->clone();
            }
        }
        // distruzione profonda 
        ~Brano(){
            delete p;
        }
    };
    vector<Brano*> vec;
    vector<Mp3*> mp3(double dim, int btr) const {
        vector<Mp3*> mp3_vector;
        for(vector<Brano*>::const_iterator it; it!= vec.begin(); ++it) {
            if(auto* a=dynamic_cast<Mp3*>((*it)->p)) {
                if(a->getDimensione()>=dim&&a->getBitRate()>=btr){
                    mp3_vector.push_back(a);
                }
            }
        }
        return mp3_vector;
    } 
    vector<FileAudio*> braniQul() const{
        vector<FileAudio*> wav_vector;
        for(vector<Brano*>::const_iterator it; it!= vec.begin(); ++it) {
            if(auto* a=dynamic_cast<WAV*>((*it)->p)) {
                if(a->qualita()&&a->getLossless) {
                    wav_vector.push_back(a);
                }
            }
        }
        return wav_vector;
    }
};