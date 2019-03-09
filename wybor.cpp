//implementacja metod klasy wybor
#include "pozycja.h"
#include "wybor.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;
Wybor::Wybor(string nazwa):Pozycja(nazwa)
{
    zaznaczone=false;
}
void Wybor::klik()
{
    cout<<"Aktualny stan:";
    if(zaznaczone)
        cout<<" zaznaczony"<<endl;
    else
        cout<<" odznaczony"<<endl;
    cout<<"Czy chcesz zmienic stan?"<<endl;
    cout<<"1-TAK    2-NIE"<<endl;
    try
    {
        int c;
        cin>>c;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(c==2)
            return;
        if(c==1)
            zmienstan();
        else throw c;
    }
    catch(int)
    {
        cout<<"Niepoprawne dane. Stan pozostal niezmieniony"<<endl;
    }
}
void Wybor::zmienstan()
{
    if(zaznaczone)
        zaznaczone=false;
    else
        zaznaczone=true;
}

