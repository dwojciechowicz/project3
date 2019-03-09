//implementacja metod klasy lista
#include "pozycja.h"
#include "lista.h"
#include <iostream>

using namespace std;

Lista::Lista(string nazwa):Pozycja(nazwa)
{
    syn=NULL;
}
void Lista::wyswietl(Pozycja * pos)
{
    Pozycja * tu;
    cout<<endl;
    for(tu=pos; tu!=NULL; tu=tu->nastepny)
    {
        cout<<*tu<<endl;
    }
}
void Lista::klik()
{
    wyswietl(this->syn);
}
