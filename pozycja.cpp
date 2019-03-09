//implementacja metod klasy pozycja
#include "pozycja.h"
#include <iostream>

using namespace std;
Pozycja::Pozycja(string s):nazwa(s)
{
    nastepny=NULL;
    poprzedni=NULL;
    rodzic=NULL;
}

ostream & operator<<(ostream & os, const Pozycja & p)
{
    cout<<p.nazwa;
    return os;
}

