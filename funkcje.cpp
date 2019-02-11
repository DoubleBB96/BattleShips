/**
 * \file funkcje.h
 * \brief Plik nagłówkowy modułu funkcje.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funkcje.h"

using namespace std;



void menu()
{
    cout<<"    ~~MENU~~"<<endl;
    cout<<"1.    Graj"<<endl;
    cout<<"2.    Wczytaj"<<endl;
    cout<<"3.    Ranking"<<endl;
    cout<<"4.    Wyjdz"<<endl;

}
void info(int &N,int &M, Statek *&tab,string &nick)  //funkcja pobierajaca info. WAZNA !!! W tablicy 1 wymiarowej dybnamicznej przechowywane sa rozmiary statków
{
    srand(time(0));
    cout<<"    Podaj nick: "<<endl;
    cin>>nick;
    cout<<"    Podaj rozmiar planszy (nie mniejsza niz 8x8): "<<endl;
    do
    {
        cin>>N;
    }while(!(N>=8));

    cout<<"    Podaj ilosc statkow (nie wieksza niz 8): "<<endl;
    do
    {
        cin>>M;
    }while(!(M<=8));

    cout<<"    Podaj rozmiar statkow (nie wiekszy niz 5): "<<endl;

    tab= new Statek [M];

    for(int i=0;i<M;i++)
    {
        do{                            //TUTAJ DOPRACOWAĆ ZABEZPIECZENIE DOTYCZACE ROZMIARU I ILOSCI STATKOW W STOSUNKU DO ROZMIARU PLANSZY!!!!
            cin>>tab[i].size;          //ustalenie rozmiarów statków
        if(tab[i].size>5)
            cout<<"Rozmiar nie moze przekraczac 5 masztow !!!"<<endl;

        }while(!(tab[i].size<=5));
    }

    ///Zmienna pom
    Statek *pom;
    pom= new Statek;

    for(int k=0;k<4;k++){

       for(int i=0;i<M-1;i++)
       {                                               //SORTOWANIE STATKÓW ZEBY POTEM LOSOWANIE ZACZAC OD NAJWIEKSZEGO
           if(tab[i+1].size>tab[i].size)
           {
               pom->size=tab[i].size;
               pom->dir=tab[i].dir;

               tab[i].size=tab[i+1].size;
               tab[i].dir=tab[i+1].dir;

               tab[i+1].size=pom->size;
               tab[i+1].dir=pom->dir;

           }
       }
    }
    delete pom;
}
