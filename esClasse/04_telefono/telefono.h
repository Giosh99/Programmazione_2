#ifndef TELEFONO_H
#define TELEFONO_H
#include "orario.h"
#include <iostream>
class telefonata{
  private:
    orario inizio, fine;
    const char* num;
    bool confrontaNumeri(const char* const) const;
  public:
    telefonata();
    telefonata(const orario&, const orario&, char*);
    orario Inizio() const;
    orario Fine() const;
    const char* Numero() const;
    bool operator==(const telefonata&) const;
};
std::ostream& operator<<(std::ostream&, const telefonata&);
#endif
