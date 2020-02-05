class orario{
    private:
        int sec;
    public:
        static const int SEC_GIORNO=86400;
        int ore() const;
        int minuti() const;
        int secondi() const;
        orario(int=0, int=0, int=0);
        operator int() const; //ricordare const, poiché gli operatori espliciti
                            //di conversione non modificano l'oggetto di invocazione
        orario operator+(const orario&) const; //overloading +, metodo che restituisce oggetto di tipo orario
        orario operator-(const orario&) const;
        bool operator==(const orario&) const;
        bool operator<(const orario&) const;
        bool operator>(const orario&) const;
};