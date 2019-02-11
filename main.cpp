#include <iostream>
#include "funkcje.h"
#include "cialo.h"
#include "gra.h"
#include "ranking.h"
#include <cstdlib>
#include <ctime>
 #include <windows.h>
#include <fstream>


using namespace std;
/**
 * \mainpage
 * \par Gra w statki
 * Program polegajacy na grze w statki z komputerem
 * \author Bartłomiej Bujniak
 * \date 2016-05-18
 */


int main()
{
    //srand(time(0));

   ///Plansza dwuwymiarowa Gracza
   Plansza **Gr;
   ///Plansza dwuwymiarowa Gracza
   Plansza **Ko;

   ///Wskaznik na liste z rankingiem
   Rank *lista;
   lista=NULL;                                  //zalokowanie pamiecie na liste rankingu
   lista = new Rank;

while(1==1)
{
    menu();
    ///Zmienna czy1
    int czy1=0;
    ///Zmienna czy2
    int czy2=0;
    ///Zmienna a
    int a;
    cout<<endl;
    cin>>a;

            if(a==1)
            {      //wybrana opcja GRAJ

                  system( "cls" );
                  ///Zmienne N,M;
                  int N,M;
                  ///Tablica statków Komputera
                  Statek *tab;
                  ///Zmienna przechowująca nick Gracza
                  string nick;

                  info(N,M,tab,nick);
                  ///Zmienna j
                  int j=ile_(); // pod j jest ilosc komorek listy
                  lista=utworz_liste(j);     //utworzenie listy

                  system( "cls" );

                  tworz_plansze(Gr,Ko,N);
                  cout<<endl;
                  ///Tablica statków Gracza
                  Statek *tab_Gr;
                  tab_Gr = new Statek [M];

                  losuj(tab,Gr,N, M,czy1);

                  for(int i=0;i<M;i++)
                  {
                       tab_Gr[i].size=tab[i].size;
                       tab_Gr[i].dir=tab[i].dir;
                       tab_Gr[i].wsp_i=tab[i].wsp_i;
                       tab_Gr[i].wsp_j=tab[i].wsp_j;
                  }

                  losuj(tab,Ko,N,M,czy2);

                  if((czy1==0)&&(czy2==0))
                  {                                             //jezeli losowanie przebieglo pomyslnie cale cialo gry znajduje sie tutaj
                       cout<<"Gracz: "<<endl;
                       drukuj_Gr(Gr,N);

                       cout<<"Komputer: "<<endl;
                       drukuj_Ko(Ko,N);

                       ///Zmienna Gr_wygr odpowiadająca za przekazanie informacji że wygrał Gracz
                       int Gr_wygr=0;
                       ///Zmienna Ko_wygr odpowiadająca za przekazanie informacji że wygrał Komputer
                       int Ko_wygr=0;
                       ///Zmienna ODP
                       char ODP;
                       while(Gr_wygr==0 && Ko_wygr==0)
                       {

                            ruch_Gr(Ko,N);                      //graczowi udostepniam plansze Who2 (plansza komputera) i strzela w nia
                            Gr_wygr=czy_koniec(Ko,tab,N,M);
                            cout<<endl;

                            ruch_Ko(Gr,N);
                            Ko_wygr=czy_koniec(Gr,tab_Gr,N,M);

                           Sleep(3000);
                           system("cls");

                           cout<<"Gracz: "<<endl;
                           czy_zatopiony(Ko,tab,N,M);
                           cout<<endl;
                           cout<<"Komputer: "<<endl;

                           czy_zatopiony(Gr,tab_Gr,N,M);
                           cout<<endl;
                           cout<<"Gracz: "<<endl;
                           drukuj_Gr(Gr,N);

                           cout<<"Komputer: "<<endl;
                           drukuj_Ko(Ko,N);

                           if((Gr_wygr!=1)&&(Ko_wygr!=1))
                           {
                                   cout<<"Jezeli chcesz zapisac stan GRY i wyjsc nacisnij t"<<endl;
                                   cin>>ODP;

                                   if(ODP=='t')
                                   {
                                          zapisz(Gr,Ko,N);
                                          statki_plik(tab_Gr,tab,M);
                                          zapisz_nick(nick);
                                          break;
                                   }
                           }

                      }
                      if(Gr_wygr==1)
                      {
                           cout<<"WYGRYWA GRACZ!!"<<endl;
                           dodaj_nick(lista,nick,j);
                           dodaj_wygrana(lista,nick);
                           zapis_do_pliku(lista,j);
                      }
                      else if(Ko_wygr==1)
                      {
                           cout<<"WYGRYWA KOMPUTER!!"<<endl;
                      }

                  }else if((czy1==1)||(czy2==1))        //jezeli nie udalo sie rozlosowac pozycji statkow
                  {
                      cout<<"Nie udalo sie rozmiescic  statkow... Sprobuj ponownie!"<<endl<<endl;
                  }
                  cout<<endl<<endl;
                  cout<<endl;

                  delete []tab;
                  delete []tab_Gr;

                  for(int i=0;i<N+2;i++)
                  delete []Gr[i];
                  delete []Gr;
                  for(int i=0;i<N+2;i++)
                  delete []Ko[i];
                  delete []Ko;
                  usun_liste(lista);

            }else if(a==2)   //wybrana opcja WCZYTAJ
            {

                ///Zmienna N
                int N=(ile_wierszy()/2)-2;
                ///Zmienna j
                int j=ile_();
                ///Zmienna nick
                string nick;
                wczytaj_nick(nick);         //wczytuje nick zapisanej gry
                lista=utworz_liste(j);     //utworzenie listy
                tworz_plansze(Gr,Ko,N);
                wczytaj(Gr,Ko,N);
                system("cls");
                cout<<"Gracz: "<<endl;
                drukuj_Gr(Gr,N);
                cout<<"Komputer: "<<endl;
                drukuj_Ko(Ko,N);
                ///Zmienna M
                int M=0;
                get_M(M);
                ///Tablica statków Gracza
                Statek *tab_Gr;
                tab_Gr = new Statek [M];
                ///Tablica statków Komputera
                Statek *tab;
                tab = new Statek [M];

                get_ship(tab_Gr,tab,M);
                ///Zmienna Gr_wygr odpowiadająca za przekazanie informacji że wygrał Gracz
                int Gr_wygr=0;
                ///Zmienna Ko_wygr odpowiadająca za przekazanie informacji że wygrał Komputer
                int Ko_wygr=0;
                ///Zmienna ODP
                char ODP;

                while(Gr_wygr==0 && Ko_wygr==0)
                {
                    ruch_Gr(Ko,N);                      //graczowi udostepniam plansze Who2 (plansza komputera) i strzela w nia
                    Gr_wygr=czy_koniec(Ko,tab,N,M);
                    cout<<endl;
                    ruch_Ko(Gr,N);
                    Ko_wygr=czy_koniec(Gr,tab,N,M);
                    Sleep(3000);
                    system("cls");
                    cout<<"Gracz: "<<endl;

                    czy_zatopiony(Ko,tab,N,M);
                    cout<<endl;
                    cout<<"Komputer: "<<endl;

                    czy_zatopiony(Gr,tab_Gr,N,M);

                    cout<<endl;
                    cout<<"Gracz: "<<endl;
                    drukuj_Gr(Gr,N);
                    cout<<"Komputer: "<<endl;
                    drukuj_Ko(Ko,N);                 //DLA TESTOW ZAMIAST drukuj_Ko wstaw drukuj_Gr


                    if((Gr_wygr!=1)&&(Ko_wygr!=1))
                    {
                            cout<<"Jezeli chcesz zapisac stan GRY i wyjsc nacisnij t"<<endl;
                            cin>>ODP;

                            if(ODP=='t')
                            {
                                   zapisz(Gr,Ko,N);
                                   statki_plik(tab_Gr,tab,M);
                                   break;
                            }
                    }

                    if(Gr_wygr==1)
                    {
                            cout<<"WYGRYWA GRACZ!!"<<endl;
                            dodaj_wygrana(lista,nick);
                            zapis_do_pliku(lista,j);

                   }else if(Ko_wygr==1)
                   {
                            cout<<"WYGRYWA KOMPUTER!!"<<endl;
                            dodaj_wygrana(lista,nick);
                            zapis_do_pliku(lista,j);
                   }

               }

                 for(int i=0;i<N+2;i++)
                 delete []Gr[i];
                 delete []Gr;
                 for(int i=0;i<N+2;i++)
                 delete []Ko[i];
                 delete []Ko;
                 delete []tab;
                 delete []tab_Gr;
                 usun_liste(lista);

            }
            else if(a==3)      //wybrana opcja RANKING
            {
                system("cls");
                drukuj_ranking();
                ///Zmienna n
                char n;
                cout<<endl<<endl;
                cout<<"Nacisnij dowolny przycisk aby wrocic do menu"<<endl;
                cin>>n;
                system("cls");

            }
            else if(a==4)        //wybrana opcja WYJDZ
            {
                break;
            }

}
    return 0;
}

