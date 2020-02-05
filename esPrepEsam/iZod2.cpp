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
    WAV(int _freqCamp, bool _lossless, string _titolo="", double _dimensione=0):FileAudio(_titolo,_dimensione), freqCamp(_freqCamp), lossless(_lossless) {}
    WAV* clone() const {
        return new WAV(*this);
    }
    bool qualita() const {
        return (freqCamp>=96?true:false);
    }
};
class iZod {
    class Brano{
        private:
        void copy(const Brano&b){
            vec.erase(vec.begin(), vec.end());
            int i=0;
            for(vector<FileAudio*>::const_iterator it=b.vec.begin(); it!=b.vec.end(); ++it, i++){
                vec[i] = (*it)->clone();
            }
        }
        public:
        vector<FileAudio*> vec;
        Brano(FileAudio*f){
            vec.push_back(f->clone);
        }
        // copia profonda 
        Brano(const Brano&b){
            copy(b);
        }
        // assegnazione profonda 
        const Brano& operator=(const Brano& b) {
            if(this!=&b){
                copy(b);
            }
        }
        // distruzione profonda 
        ~Brano(){
            vec.erase(vec.begin(), vec.end());
        }
    };
    vector<Brano*> vec;
    vector<Mp3> mp3(double dim, int btr) const {
        vector<Mp3> mp3_vector;
        for(vector<Brano>::const_iterator it; it!= vec[0]->vec.begin(); ++it) {

        }
    } 
};