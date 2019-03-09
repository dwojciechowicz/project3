//Menu okienkowe
//Dorota Wojciechowicz
#include <iostream>
#include <string>
#include <limits>
#include <typeinfo>
#include "pozycja.h"
#include "lista.h"
#include "jednoznaczny.h"
#include "wybor.h"

using namespace std;

void menu();
string opcja();
void utworz();
void usun();
void wybierz();
void wroc();
void usunpoz();
void usunliste(Lista * l);
Pozycja* wyszukaj(string nazwa);

Pozycja* teraz;
int licznik=0;

int main()
{
    menu();
    return 0;
}
void menu()
{
    string komenda="";
    Pozycja *pos;
    cout<<"Program symulujacy menu okienkowe"<<endl;
    cout<<"W celu korzystania z programu wpisz najpierw jedna z ponizszych komend."<<endl;
    cout<<"Nastepnie stosuj sie do kolejnych polecen"<<endl;
    while(komenda!="koniec")
    {
        cout<<"Aby utworzyc nowa pozycje wpisz \"utworz\" "<<endl;
        cout<<"Aby usunac pozycje wpisz \"usun\" "<<endl;
        cout<<"Aby skorzystac z wybranej pozycji wpisz \"wybierz\" "<<endl;
        cout<<"Aby wrocic do poprzedniego menu wpisz \"wroc\" "<<endl;
        cout<<"Aby zakonczyc program wpisz \"koniec\" "<<endl;
        try
        {
            if(teraz!=NULL)
            {
                if(teraz->rodzic==NULL)
                {
                    cout<<endl;
                    for(pos=teraz; pos!=NULL; pos=pos->nastepny)
                        cout<<*pos<<endl;
                }
            }
            komenda=opcja();
        }
        catch(string s)
        {
            cout<<s<<" nie jest komenda"<<endl;
        }
    }
    usunpoz();
}
string opcja()
{
    string komenda;
    cin>>komenda;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try
    {
        if(komenda=="utworz")
        {
            utworz();
        }
        else if(komenda=="usun")
        {
            usun();
        }
        else if(komenda=="wybierz")
        {
            wybierz();
        }
        else if(komenda=="wroc")
        {
            wroc();
        }
        else if(komenda=="koniec") {}
        else
        {
            throw komenda;
        }
        return komenda;
    }
    catch(int)
    {
        cout<<"Menu jest puste. Musisz najpierw utworzyc pozycje."<<endl;
    }
}
void wybierz()
{
    string nazwa;
    Pozycja * pos;
    if(teraz==NULL)
    {
        int a=1;
        throw a;
    }
    cout<<"Wpisz nazwe pozycji jaka chcesz wybrac"<<endl;
    cin>>nazwa;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try
    {
        pos=wyszukaj(nazwa);
        pos->klik();
        if(typeid(*pos)==typeid(Lista))
        {
            if((static_cast<Lista*>(pos))->syn!=NULL)
            {
                teraz=(static_cast<Lista*>(pos))->syn;
            }
        }
    }
    catch(string s)
    {
        cout<<"W tym menu nie ma pozycji o nazwie "<<s<<endl;
    }

}
void wroc()
{
    Pozycja * pos;
    //czyszczenie ekranu
    if(teraz==NULL)
    {
        int a=1;
        throw a;
    }
    if(teraz->rodzic!=NULL)
    {
        teraz=teraz->rodzic;
        pos=teraz;
        while(pos->poprzedni!=NULL)
        {
            pos=pos->poprzedni;
        }
        teraz=pos;
        (*teraz->rodzic).wyswietl(teraz);
    }
    else
    {
        cout<<"Nie mozna cofnac sie do poprzedniego menu, poniewaz ono nie istnieje."<<endl;
    }
}
void utworz()
{
    int i;
    cout<<"Jaki typ nowej pozycji chcesz utworzyc? Wpisz odpowiednia cyfre."<<endl;
    cout<<"1.Podmenu"<<endl;
    cout<<"2.Wybor jednoznaczny"<<endl;
    cout<<"3.Pole wyboru"<<endl;
    if(!(cin>>i))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Wpisano bledne dane.Nie wykonano zadnego polecenia."<<endl;
    }
    else
    {
        string nazwa;
        int k;
        cout<<"Chcesz dodac nowa pozycje w tym menu czy w nastepnym? Wpisz odpowiednia cyfre."<<endl;
        cout<<"1.W tym."<<endl;
        cout<<"2.W nastepnym."<<endl;
        if(!(cin>>k))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Wpisano bledne dane.Nie wykonano zadnego polecenia."<<endl;
            return;
        }
        switch (k)
        {
        case 1:
        {
            cout<<"Wpisz nazwe nowej pozycji"<<endl;
            cin>>nazwa;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (i)
            {
            case 1:
            {
                Lista * l=new Lista(nazwa);
                if(licznik==0)
                    teraz=l;
                else
                {
                    l->rodzic=teraz->rodzic;
                    l->poprzedni=NULL;
                    l->nastepny=teraz;
                    teraz->poprzedni=l;
                    teraz=l;
                }
                licznik++;
                break;
            }
            case 2:
            {
                Jednoznaczny * j=new Jednoznaczny(nazwa);
                if(licznik==0)
                    teraz=j;
                else
                {
                    j->rodzic=teraz->rodzic;
                    j->poprzedni=NULL;
                    j->nastepny=teraz;
                    teraz->poprzedni=j;
                    teraz=j;
                }
                licznik++;
                break;
            }
            case 3 :
            {
                Wybor * w=new Wybor(nazwa);
                if(licznik==0)
                    teraz=w;
                else
                {
                    w->rodzic=teraz->rodzic;
                    w->poprzedni=NULL;
                    w->nastepny=teraz;
                    teraz->poprzedni=w;
                    teraz=w;
                }
                licznik++;
                break;
            }
            default :
            {
                cout<<"Taka opcja nie istnieje."<<endl;
                return;
            }
            }
            break;
        }
        case 2:
        {
            if(licznik==0)
            {
                cout<<"Nie mozna utworzyc pozycji, poniewaz nie powstalo jeszcze zadne podmenu"<<endl;
                return;
            }
            string list;
            Pozycja * podmenu;
            Lista * r;
            cout<<"Wpisz nazwe podmenu w ktorym chcesz utworzyc pozycje"<<endl;
            cin>>list;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            try
            {
                podmenu=wyszukaj(list);
                if(typeid(*podmenu)!=typeid(Lista))
                {
                    cout<<"Podana pozycja nie jest podmenu nie mozna wiec dodac nowej pozycji"<<endl;
                    return;
                }
                cout<<"Wpisz nazwe nowej pozycji"<<endl;
                cin>>nazwa;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                r=static_cast<Lista*>(podmenu);
                switch (i)
                {
                case 1:
                {
                    Lista * l=new Lista(nazwa);
                    licznik++;
                    if(r->syn!=NULL)
                        r->syn->poprzedni=l;
                    l->nastepny=r->syn;
                    l->poprzedni=NULL;
                    r->syn=l;
                    l->rodzic=r;
                    break;
                }
                case 2:
                {
                    Jednoznaczny * j=new Jednoznaczny(nazwa);
                    licznik++;
                    if(r->syn!=NULL)
                        r->syn->poprzedni=j;
                    j->nastepny=r->syn;
                    j->poprzedni=NULL;
                    r->syn=j;
                    j->rodzic=r;
                    break;
                }
                case 3 :
                {
                    Wybor * w=new Wybor(nazwa);
                    licznik++;
                    if(r->syn!=NULL)
                        r->syn->poprzedni=w;
                    w->nastepny=r->syn;
                    w->poprzedni=NULL;
                    r->syn=w;
                    w->rodzic=r;
                    break;
                }
                default :
                {
                    cout<<"Taka opcja nie istnieje."<<endl;
                    return;
                }

                }
            }
            catch(string)
            {
                cout<<"W tym menu nie ma pozycji o tej nazwie."<<endl;
            }
        }
        break;
        default:
        {
            cout<<"Taka opcja nie istnieje."<<endl;
            return;
        }
        }
    }
}
void usun()
{
    string nazwa;
    Pozycja * pos;
    Pozycja * pomoc;
    if(teraz==NULL)
    {
        int a=1;
        throw a;
    }
    cout<<"Wpisz nazwe pozycji ktora chcesz usunac"<<endl;
    cin>>nazwa;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    try
    {
        pos=wyszukaj(nazwa);
        if(typeid(*pos)==typeid(Lista))
        {
            usunliste(static_cast<Lista*>(pos));
        }
        if(teraz!=pos)
        {
            if((pos->nastepny==NULL)&&(pos->poprzedni==NULL))
            {
                pos->rodzic->syn=NULL;
            }
            else if(pos->nastepny!=NULL)
            {
                pomoc=pos->nastepny;
                pomoc->poprzedni=pos->poprzedni;
                if(pos->poprzedni!=NULL)
                    pos->poprzedni->nastepny=pomoc;
            }
            else
            {
                if(pos->poprzedni!=NULL)
                    pos->poprzedni->nastepny=NULL;
            }
        }
        else
        {
            if(pos->nastepny!=NULL)
            {
                pos->nastepny->poprzedni=NULL;
                teraz=pos->nastepny;
            }
            else
            {
                if(pos->rodzic!=NULL)
                {
                    pos->rodzic->syn=NULL;
                    teraz=pos->rodzic;
                    pomoc=teraz;
                    while(pomoc->poprzedni!=NULL)
                    {
                        pomoc=pomoc->poprzedni;
                    }
                    teraz=pomoc;
                }
                else
                {
                    teraz=NULL;
                }
            }
        }
        delete pos;
        licznik--;
    }
    catch(string s)
    {
        cout<<"W tym menu nie ma pozycji o nazwie "<<s<<endl;
    }

}
Pozycja* wyszukaj(string nazwa)
{
    Pozycja * pos;
    for(pos=teraz; pos!=NULL; pos=pos->nastepny)
    {
        if(pos->nazwa==nazwa)
            return pos;
    }
    throw nazwa;
}
void usunpoz()
{
    Pozycja *pos;
    if(teraz==NULL)
        return;
    else
    {
        while (teraz->rodzic!=NULL)
        {
            teraz=teraz->rodzic;
        }
        pos=teraz;
        while(pos->poprzedni!=NULL)
        {
            pos=pos->poprzedni;
        }
        teraz=pos;
        while(teraz->nastepny!=NULL)
        {
            if(typeid(*teraz)==typeid(Lista))
                usunliste(static_cast<Lista*>(teraz));
            teraz=teraz->nastepny;
            delete teraz->poprzedni;
            licznik--;
            teraz->poprzedni=NULL;
        }
        delete teraz;
        licznik--;
    }
}
void usunliste(Lista * l)
{
    Pozycja * p;
    p=l->syn;
    if(p==NULL)
        return;
    else
    {
        if(typeid(*p)==typeid(Lista))
        {
            usunliste(static_cast<Lista*>(p));
            delete p;
            l->syn=NULL;
            licznik--;
        }
        else
        {
            while((p->nastepny)!=NULL)
            {
                if(typeid(*p)==typeid(Lista))
                    usunliste(static_cast<Lista*>(p));
                p=p->nastepny;
                delete p->poprzedni;
                licznik--;
                p->poprzedni=NULL;
            }
            delete p;
            l->syn=NULL;
            licznik--;
        }
    }
}

