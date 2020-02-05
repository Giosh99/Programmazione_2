class complesso{
    public:
        double re, im;
        complesso(double=0, double=0);
        double modulo() const;
        complesso operator+(const complesso&) const;
        complesso operator-(const complesso&) const;
        bool operator==(const complesso&) const;
        void stampa() const;
};