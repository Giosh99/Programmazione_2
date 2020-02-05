#ifndef TELEFONO_H
#define TELEFONO_H
#include "orario.h"
#include <iostream>
#include <string>
using std::string;

class telefonata{
  private:
    orario inizio, fine;
    const string num;
  public:
    telefonata();
    telefonata(const orario&, const orario&, const string);
    orario Inizio() const;
    orario Fine() const;
    string Numero() const;
    bool operator==(const telefonata&) const;
};
std::ostream& operator<<(std::ostream&, const telefonata&);
#endif
