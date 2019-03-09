//plik naglowkowy klasy jednoznaczny
#ifndef JEDNOZNACZNY_H_
#define JEDNOZNACZNY_H_

#include "pozycja.h"
#include <string>

class Jednoznaczny:public Pozycja
{
private:
    std::string tekst;
public:
    Jednoznaczny(std::string nazwa);
    ~Jednoznaczny();
    virtual void klik();
};

#endif
