/**
 * \file gra.h
 * \brief Plik nagłówkowy modułu gra.
 */
#include <cstdlib>
#include <ctime>
#include "cialo.h"
#include "funkcje.h"
#include "gra.h"
#include <fstream>

int ile_wierszy()
{
    ///Zmienna how
    int how=0;
    ///Zmienna s
    string s;
    ///Zmienna ile - zmienna pikowa
    ifstream ile;
    ile.open("zapis.txt");
    getline(ile,s);
    how=s.size();
    ile.close();
    return how;
}

void zapisz(Plansza **Gr, Plansza **Ko, int N)
{
      ///Zmienna plik_wy- zmienna plikowa
      ofstream plik_wy;
      plik_wy.open("zapis.txt");
      for(int i=0;i<N+2;i++)
      {
          for(int j=0;j<N+2;j++)
          {
              plik_wy<<Gr[i][j].show<<Gr[i][j].boat_ex;
          }
          plik_wy<<endl;
      }

      for(int i=0;i<N+2;i++)
      {
          for(int j=0;j<N+2;j++)
          {
              plik_wy<<Ko[i][j].show<<Ko[i][j].boat_ex;
          }
          plik_wy<<endl;
      }
      plik_wy.close();
}

void wczytaj(Plansza **&Gr, Plansza **&Ko, int N)
{
    ///Zmienna plik_we - zmienna plikowa
    ifstream plik_we;
    plik_we.open("zapis.txt");

    if(!plik_we.is_open())
        cout<<"Blad otwarcia pliku";
    else
    {
        ///Zmienna s
        string s;
        ///Zmienna i
        int i=0;
        while(i<N+2)
        {
            ///Zmienna m
            int m=0;
            getline(plik_we,s);
            ///Zmienna n
            int n=0;
            while(n<(2*N)+2)
            {
                    Gr[i][m].show=s[n];
                    n++;
                    Gr[i][m].boat_ex=s[n]-48;  //-48  bo sa to kody ASCII
                    n++;
                    m++;
            }
             i++;
         }

        ///Zmienna j
        int j=0;
        while(j<N+2)
        {
            ///Zmienna m
            int m=0;
            getline(plik_we,s);
            ///Zmienna n
            int n=0;
            while(n<(2*N)+2)
            {
                    Ko[j][m].show=s[n];
                    n++;
                    Ko[j][m].boat_ex=s[n]-48;
                    n++;
                    m++;
            }
             j++;
            }
     }
    plik_we.close();
}

void ruch_Gr (Plansza **&Who,int N)
{  
    ///Zmienna k,l
    int k,l;
    cout<<"Podaj wspolrzedne [i,j]:"<<endl;

    do{
    cin>>k;
    }while((!(k<=N))||(k==0));

     do{
     cin>>l;
     }while((!(l<=N))||(l==0));

    cout<<"Gracz:"<<endl;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(Who[k][l].boat_ex==1)
            {
                Who[k][l].boat_ex=2;
                cout<<"Trafiony!"<<endl;
                Who[k][l].show='#';

            }else if(Who[k][l].boat_ex==0)
            {
                Who[k][l].boat_ex=4;
                cout<<"Pudlo!"<<endl;
                Who[k][l].show='X';

            }else if(Who[k][l].boat_ex==3)
            {
                 Who[k][l].boat_ex=4;
                cout<<"Pudlo!"<<endl;
                Who[k][l].show='X';

            }
        }
    }
}

void ruch_Ko (Plansza **&Who,int N) //ruch gracza
{
    ///Zmienna k,l
    int k,l;

    do{
    k=1+rand()%N;
    l=1+rand()%N;

    }while((Who[k][l].boat_ex==4)||(Who[k][l].boat_ex==2));

    cout<<"Komputer:"<<endl;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(Who[k][l].boat_ex==1)
            {
                Who[k][l].boat_ex=2;
                cout<<"Trafiony!"<<endl;
                Who[k][l].show='#';
            }else if(Who[k][l].boat_ex==0)
            {
                Who[k][l].boat_ex=4;
                cout<<"Pudlo!"<<endl;
                Who[k][l].show='X';

            }else if(Who[k][l].boat_ex==3)
            {
                Who[k][l].boat_ex=4;
                cout<<"Pudlo!"<<endl;
                Who[k][l].show='X';

            }
        }
    }
}

int czy_koniec(Plansza **Who,Statek *tab,int N,int M)
{
    ///Ilość masztów na planszy
    int ile_masztow=0;

    for(int k=0;k<M;k++)
        ile_masztow+=tab[k].size;

    ///Zmienna ilosci trafionych masztow
    int ile_trafionych=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(Who[i][j].boat_ex==2)
                ile_trafionych++;
        }
    }
    if(ile_trafionych==ile_masztow)       //zwraca 1 jezeli wszytskie maszty zostaly zestrzelone
        return 1;
    else
        return 0;                           //zwraca 0 jezeli jeszcze gra ma sie toczyc
}

void czy_zatopiony(Plansza **Who, Statek *tab,int N,int M)
{
    ///Zmienna m - ilosci powtorzen
    int m=0;
    ///Zmienna k,l
    int k,l;
    while(m<M)
    {
        k=tab[m].wsp_i;
        l=tab[m].wsp_j;
        ///Zmienna zliczajaca zestrzelenia
        int ile=0;
        ///Rozmiar statku
        int size=tab[m].size;

        if(tab[m].dir==8)
        {
            for(int i=k;i>k-size;i--)
            {
                if(Who[i][l].boat_ex==2)
                    ile++;
            }
            if(ile==size)
                cout<<"Zatopiony "<<size<<" -masztowiec!! "<<endl;
        }else if(tab[m].dir==5)
            {
                for(int i=k;i<k+size;i++)
                {
                    if(Who[i][l].boat_ex==2)
                        ile++;
                }
                if(ile==size)
                    cout<<"Zatopiony "<<size<<" -masztowiec!! "<<endl;
         }else if(tab[m].dir==6)
          {
            for(int i=l;i<l+size;i++)
            {
                if(Who[k][i].boat_ex==2)
                    ile++;
            }
            if(ile==size)
                cout<<"Zatopiony "<<size<<" -masztowiec!! "<<endl;
          }
            else if(tab[m].dir==4)
         {
          for(int i=l;i>l-size;i--)
          {
              if(Who[k][i].boat_ex==2)
                  ile++;
          }
          if(ile==size)
              cout<<"Zatopiony "<<size<<" -masztowiec!! "<<endl;
         }
       m++;
    }
}

void statki_plik(Statek *tab1,Statek *tab2,int M)
{
    ///Zmienna plikowa plik_wy
    ofstream plik_wy;
    plik_wy.open("statki.txt");

    for(int i=0;i<M;i++)
    {
        plik_wy<<tab1[i].wsp_i<<tab1[i].wsp_j<<tab1[i].size<<tab1[i].dir;
    }
    plik_wy<<endl;

    for(int i=0;i<M;i++)
    {
        plik_wy<<tab2[i].wsp_i<<tab2[i].wsp_j<<tab2[i].size<<tab2[i].dir;      
    }
    plik_wy.close();
}

void get_M(int &M)
{
    ///Zmienna plikowa plik_we
    ifstream plik_we;
    plik_we.open("statki.txt");

    if(!plik_we.is_open())
        cout<<"Blad otwarcia pliku";
    else{
    ///Zmienna s
    string s;
    getline(plik_we,s);
    M=s.size()/4;
    plik_we.close();
   }
}

void get_ship(Statek *&tab1,Statek *&tab2,int M)
{
    ///Zmienna plikowa plik_we
    ifstream plik_we;
    plik_we.open("statki.txt");

    if(!plik_we.is_open())
        cout<<"Blad otwarcia pliku";

    else
    {
       ///Zmienna s
       string s;
       getline(plik_we,s);
       ///Zmienna n
       int n=0;
       ///Zmienna i
       int i=0;
       while(n<M*4)
       {
            tab1[i].wsp_i=s[n]-48;
            n++;
            tab1[i].wsp_j=s[n]-48;
            n++;
            tab1[i].size=s[n]-48;
            n++;
            tab1[i].dir=s[n]-48;
            n++;
            i++;
      }
       getline(plik_we,s);

       ///Zmienna m
       int m=0;
       ///Zmienna j
       int j=0;
       while(m<M*4)
       {
            tab2[j].wsp_i=s[m]-48;
            m++;
            tab2[j].wsp_j=s[m]-48;
            m++;
            tab2[j].size=s[m]-48;
            m++;
            tab2[j].dir=s[m]-48;
            m++;
            j++;
      }
    }
    plik_we.close();
}
