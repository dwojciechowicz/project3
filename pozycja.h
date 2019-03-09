//plik naglowkowy klasy pozycja
#ifndef POZYCJA_H_
#define POZYCJA_H_
#include <iostream>
#include <string>
class Lista;
//klasa abstrakcyjna
class Pozycja
{
public:
    const std::string nazwa;
    Pozycja* poprzedni;
    Pozycja* nastepny;
    Lista* rodzic;
    virtual void klik()=0;
    Pozycja(std::string s);
    Pozycja()=delete;
    ~Pozycja() {};
    /*
    void ustawPoprzednik(Pozycja a);
    */
    friend std::ostream & operator<<(std::ostream & os, const Pozycja & p);
};
#endif

