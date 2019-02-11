/**
 * \file ranking.h
 * \brief Plik nagłówkowy modułu ranking.
 */
#include <cstdlib>
#include <ctime>
#include "cialo.h"
#include "funkcje.h"
#include "gra.h"
#include "ranking.h"
#include <fstream>

int ile_()                      //tutaj licze ile w istenijacy pliku ranking bedzie elementow listy
{
    ///Zmienna i
    int i=0;
    ///Zmienna plikowa plik

    ifstream plik;
    plik.open("ranking2.txt");
    ///Zmienna s
    string s;

    while(!plik.eof())
    {
        getline(plik,s);
        i++;
    }
    plik.close();
    return i;
}

Rank *utworz_liste (int j)                        //TWORZENIE LISTY ZA POMOCA ISTNIEJACEGO PLIKU RANKING
{
  ///Wskażniki typu strukturalnego Rank
  Rank   *aktualny, *glowa, *ogon;
  ///Zmienna liczba
  int liczba=0;
    aktualny = NULL;
    glowa = NULL;



    ///Zmienna s
    string s;
    ///Zmienna plikowa plik
    ifstream plik;
    plik.open("ranking2.txt");


    while (liczba<j)
    {
      ogon = aktualny;


      aktualny = new Rank;

      plik>>aktualny->score;

      ///Zmienna k wczytujaca nick Gracza
      string k;


      plik>>aktualny->player;
      aktualny->uzyty=0;
      aktualny->next = NULL;


      if (ogon == NULL)
          glowa = aktualny;
       else
          ogon->next = aktualny;
       liczba++;
  }
      plik.close();
      return glowa;
}




void dodaj_nick(Rank *&glowa,string nick,int &j)
{
    ///Wskaznik tym typu strukturalnego Rank
   Rank *tym;
   tym=glowa;
   ///Zmienna i
   int i=0;
   while(tym!=NULL)       //zlicza ilosc elementow listy
   {
       i++;
       tym=tym->next;
   }
   if(i!=0)
   {
       tym=glowa;
       ///Zmienna wyst - sprawdza czy podany nick juz wystapił
       int wyst=0;
       while(tym!=NULL)
       {
           if(tym->player==nick)         //zliczanie czy taki nick juz wystapil
           wyst++;
           tym=tym->next;
       }
       if(wyst==0)          //jezeli nie wystepuje
       {
           tym=glowa;
           while(tym->next!=NULL)           //dojechanie do konca listy
           tym=tym->next;
           ///Wskaznik pom typu strukturalnego Rank
           Rank *pom;
           pom=new Rank;
           pom->uzyty=0;
           pom->player=nick;                     //dodanie na koniec listy informacji o graczu
           pom->score=0;
           tym->next=pom;
           pom->next=0;
           j++;
           tym=glowa;
          // delete pom;
       }
   }else                                   //jezeli ranking jest pusty dodajemy na poczatek dane o graczu
   {
       glowa= new Rank;
       glowa->player=nick;
       glowa->score=0;
       glowa->uzyty=0;

       glowa->next=NULL;
       j++;
   }
}

void usun_liste(Rank *glowa)
{
    ///Wskaznik tym typu strukturalnego Rank
    Rank *tym;


    while(glowa!=NULL)
    {
        tym=glowa;
        glowa=glowa->next;
        delete tym;

    }
}

void dodaj_wygrana(Rank *&glowa,string nick)             //funkcja dodajaca punkt wygranej osobie
{
    ///Wskaznik tym typu strukturalnego Rank
    Rank *tym;

    tym=glowa;

    while((tym->next!=NULL)&&(tym->player!=nick))
        tym=tym->next;

    tym->score++;

}

Rank* znajdz_najwiekszy(Rank *glowa){           //funkcja przechodzaca po calej liscie (rankingu), znajdujaca element z najwieksza liczba zwyciestw i zwracajaca go jako wskaznik
    ///Wskaznik max typu strukturalnego Rank
    Rank *max;
    ///Zmienna maks
    int maks = 0;
    while(glowa != NULL){
        if(glowa->score > maks){
            if(glowa->uzyty == 0){
                max = glowa;
                maks = glowa->score;
                }
        }
        glowa = glowa->next;
    }
    max->uzyty=1;
    return max;

}


void zapis_do_pliku(Rank *glowa, int j){          //funkcja zapisujaca ranking do pliku
    ///Zmienna plikowa plik
    ofstream plik;
    plik.open("ranking2.txt");
    ///Wskaznik pom typu strukturalnego Rank
    Rank *pom;
    for(int i=0; i<j-1; i++){
        pom = znajdz_najwiekszy(glowa);
        plik<<pom->score<<" "<<pom->player<<endl;
    }
    pom = znajdz_najwiekszy(glowa);

     plik<<pom->score<<" "<<pom->player;
    plik.close();
}

void drukuj_ranking()
{
    ///Zmienna plikowa plik
    ifstream plik;
    plik.open("ranking2.txt");
    ///Zmienna s
    string s;
    ///Zmienna a
    int a;

    while(!plik.eof())
    {
        plik>>a;
        plik>>s;
        cout<<a<<"   "<<s<<endl;
         cout<<endl;
    }
    plik.close();
}

void drukuj_liste (Rank *glowa)
{
    while(glowa!=NULL)
    {
        cout<<glowa->score<<glowa->player<<endl;
        glowa=glowa->next;
    }
}
void wczytaj_nick(string &nick)
{
    ///Zmienna plikowa plik
    ifstream plik;
    plik.open("nick.txt");       //zapisanie nicku do pliku
    plik>>nick;
    plik.close();
}
void zapisz_nick(string nick)
{
    ///Zmienna plikowa plik_wy
    ofstream plik_wy;
    plik_wy.open("nick.txt");       //zapisanie nicku do pliku
    plik_wy<<nick;
    plik_wy.close();
}
