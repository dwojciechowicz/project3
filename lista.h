//plik naglowkowy klasy lista
#ifndef LISTA_H_
#define LISTA_H_
#include <string>
#include "pozycja.h"

class Lista:public Pozycja
{
public:
    Pozycja * syn;
    Lista (std::string nazwa);
    ~Lista() {};
    virtual void klik();
    void wyswietl(Pozycja * pos);
};
#endif
