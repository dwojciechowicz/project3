//implementacja metod klasy jednoznaczny
#include "pozycja.h"
#include "jednoznaczny.h"
#include <iostream>
#include <string>

using namespace std;

Jednoznaczny::Jednoznaczny(string nazwa):Pozycja(nazwa)
{
    string s;
    cout<<"Wpisz tresc ktora ma wyswietlac funkcja"<<endl;
    getline(cin,s);
    tekst=s;
}
void Jednoznaczny::klik()
{
    cout<<tekst<<endl;
}
