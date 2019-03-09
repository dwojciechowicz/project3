//plik naglowkowy klasy wybor
#ifndef WYBOR_H_
#define WYBOR_H_
#include <string>
#include "pozycja.h"

class Wybor:public Pozycja
{
private:
    bool zaznaczone;
public:
    Wybor(std::string nazwa);
    ~Wybor();
    virtual void klik();
    void zmienstan();
};

#endif
