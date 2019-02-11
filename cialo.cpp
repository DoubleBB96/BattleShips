/**
 * \file cialo.h
 * \brief Plik nagłówkowy modułu cialo.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cialo.h"
#include "funkcje.h"

using namespace std;


void tworz_plansze(Plansza **&Gr,Plansza **&Ko,int N)
{
    Gr = new Plansza *[N+2];
    for(int i=0;i<N+2;i++)
    {
        Gr[i]=new Plansza [N+2];
    }
    Ko = new Plansza *[N+2];
    for(int i=0;i<N+2;i++)
    {
        Ko[i]=new Plansza [N+2];
    }
    for(int i=0;i<N+2;i++)
    {
        for(int j=0;j<N+2;j++)
        {
            if(i==0)
            {
                Gr[i][j].boat_ex=3;
                Gr[i][j].show='X';
            } else if(j==0)
            {
                Gr[i][j].boat_ex=3;
                Gr[i][j].show='X';
            }else if (i==N+1)
            {
                Gr[i][j].boat_ex=3;
                Gr[i][j].show='X';
            }else if (j==N+1)
            {
                Gr[i][j].boat_ex=3;
                Gr[i][j].show='X';
            }else
            {
                Gr[i][j].boat_ex=0;
                Gr[i][j].show='~';
            }
        }
    }
    for(int i=0;i<N+2;i++)
    {
        for(int j=0;j<N+2;j++)
        {
            if(i==0)
            {
                Ko[i][j].show='X';
                Ko[i][j].boat_ex=3;
            } else if(j==0)
            {
                Ko[i][j].boat_ex=3;
                Ko[i][j].show='X';
            }else if (i==N+1)
            {
                Ko[i][j].boat_ex=3;
                Ko[i][j].show='X';
            }else if (j==N+1)
            {
                Ko[i][j].boat_ex=3;
                Ko[i][j].show='X';
            }else
            {
                Ko[i][j].boat_ex=0;
                Ko[i][j].show='~';
            }
        }
    }
}
void losuj_dir(Statek &pom,int N)
{  
    pom.wsp_i=1+rand()%N;
    pom.wsp_j=1+rand()%N;
}
void losuj(Statek *&tab, Plansza **&Gr,int N,int M,int &czy)
{
    Statek pom;
    ///Zmienna k
    int k=0;


    while(k<M)
    {
        pom=tab[k];
        pom.size=tab[k].size;
          ///Zmienna kierunek
          int kierunek= 0;
          ///Zmienna how
          int how=0;

             while(kierunek==0)
             {
                losuj_dir(pom,N);              
                kierunek=check_dir(pom,Gr,N);
                how++;

                if(how>100)
                {
                    czy=1;
                    break;
                }

             }
             tab[k].wsp_i=pom.wsp_i;
             tab[k].wsp_j=pom.wsp_j;

             if(kierunek<13)
             {
                 if(kierunek==10)      //gora
                 {
                     pom.dir=8;
                     tab[k].dir=8;
                     wypelnij(pom,Gr,N);
                     surround(pom,Gr,N);
                 }else if(kierunek==11)     //prawo
                 {
                     pom.dir=6;
                     tab[k].dir=6;
                     wypelnij(pom,Gr,N);
                     surround(pom,Gr,N);
                 }else if(kierunek==12)      //gora+prawo
                 {
                            ///Zmienna t
                            int t=rand()%2;
                            if(t==0)
                            {   pom.dir=8;   //gora
                                tab[k].dir=8;                               
                                wypelnij(pom,Gr,N);
                                surround(pom,Gr,N);
                            }else
                            {
                                pom.dir=6;                 //prawo
                                tab[k].dir=6;
                                wypelnij(pom,Gr,N);
                                surround(pom,Gr,N);
                            }
                 }
             }else
             {
                 if(kierunek==13)          //dol
                 {
                     pom.dir=5;
                     tab[k].dir=5;                    
                     wypelnij(pom,Gr,N);
                     surround(pom,Gr,N);
                 }else if(kierunek==14)     //lewo
                 {
                    pom.dir=4;
                    tab[k].dir=4;                   
                    wypelnij(pom,Gr,N);
                    surround(pom,Gr,N);
                 }else if(kierunek==15)      //dol+lewo
                 {
                     ///Zmienna t
                     int t=rand()%2;
                            if(t==0)             //dol
                            {
                                pom.dir=5;
                                tab[k].dir=5;
                                wypelnij(pom,Gr,N);
                                surround(pom,Gr,N);

                            }else                  //lewo
                            {
                                pom.dir=4;
                                tab[k].dir=4;                              
                                wypelnij(pom,Gr,N);
                                surround(pom,Gr,N);
                            }
                 }
             }
        k++;
    }
}

int check_dir(Statek pom,Plansza **Gr,int N){

    ///Zmienna W
    int W=rand()%2;

    if((pom.wsp_j%2)==W)
    {                   //Zmienna losowa W odpowiada za kierunki rozchodzenia statkow bo w zaleznosci //od jej parzystosci statki rozchodza sie w kierunkach:
            ///Zmienna ile
            int ile=0;                  //gora    Zmienne ile odpowiadaja za odpowiedz logiczna za pomoca ktorej jestem w stanie okreslic mozliwy kierunek rozchodzenia sie statkow
            ///Zmienna j
            int j=pom.wsp_j;
            ///Zmienna k
            int k=pom.wsp_i;

                 for(int i=pom.wsp_i;i>1;i--)
                 {
                    if(Gr[i][j].boat_ex==0)
                        ile++;
                    if((Gr[i][j].boat_ex==1)||(Gr[i][j].boat_ex==3))
                        ile=ile-20;
                 }
                      ///Zmienna ile2
                      int ile2=0;          //prawo

                        for(int q=pom.wsp_j;q<N;q++)
                       {
                         if(Gr[k][q].boat_ex==0)
                         ile2++;
                         if((Gr[k][q].boat_ex==1)||(Gr[k][q].boat_ex==3))
                            ile2=ile2-20;
                       }

             if((ile==pom.size)||(ile2==pom.size))
             {
                    if((ile==pom.size) &&(ile2==pom.size))   //prawo+gora
                        return 12;
                   else if(ile==pom.size)   //gora
                         return 10;
                    else if(ile2==pom.size)  //prawo
                        return 11;
             }else
              return 0;
    }else
    {
               ///Zmienna ile1
               int ile1=0;              //dol
                    ///Zmienna k
                    int k=pom.wsp_j;
                    ///Zmienna m
                    int m=pom.wsp_i;

                      for(int i=pom.wsp_i;i<N;i++)
                       {
                         if(Gr[i][k].boat_ex==0)
                             ile1++;
                         if((Gr[i][k].boat_ex==1)||(Gr[i][k].boat_ex==3))
                             ile1=ile1-20;
                         }
                    ///Zmienna ile3
                    int ile3=0;                     //lewo

                    for(int j=pom.wsp_j;j>0;j--)
                    {
                         if(Gr[m][j].boat_ex==0)
                               ile3++;
                         if((Gr[m][j].boat_ex==1)||(Gr[m][j].boat_ex==3))
                               ile3=ile3-20;
                    }

                         if((ile1==pom.size)||(ile3==pom.size))
                         {
                                if((ile1==pom.size) &&(ile3==pom.size))   //d+l
                                    return 15;
                               else if(ile1==pom.size)   //d
                                     return 13;
                                else if(ile3==pom.size)  //l
                                    return 14;
                         }else
                          return 0;
    }

}

void wypelnij(Statek pom,Plansza **&Gr,int N)
{
    if(pom.dir==8)               //gora
    {
        ///Zmienna j
        int j=pom.wsp_j;
             for(int i=pom.wsp_i;i>0;i--)
             {
                   Gr[i][j].boat_ex=1;
             }
    }
    else if(pom.dir==5)           //dol
    {
        ///Zmienna k
        int k=pom.wsp_j;

           for(int i=pom.wsp_i;i<N+1;i++)
           {
             Gr[i][k].boat_ex=1;
           }
    }
    else if(pom.dir==6)                 //prawo
    {
        ///Zmienna l
        int l=pom.wsp_i;

        for(int j=pom.wsp_j;j<N+1;j++)
         {
           Gr[l][j].boat_ex=1;
         }
    }
    else if(pom.dir==4)                      //lewo
    {
        ///Zmienna m
        int m=pom.wsp_i;

        for(int j=pom.wsp_j;j>0;j--)
         {
           Gr[m][j].boat_ex=1;
         }
    }
}

void surround(Statek pom,Plansza **&Gr,int N )
{
    if(pom.dir==8)                           // otoczenie 3 dla kierunku: gora
    {
        ///Zmienna k
        int k=pom.wsp_i;
        ///Zmienna l
        int l=pom.wsp_j;

        for(int i=k+1;i>= k-pom.size;i--)
        {
           for(int j=0;j<l+2;j++)
           {
               if(j==l-1)
                   Gr[i][j].boat_ex=3;
               if((j==l)&&(i==k+1))
                   Gr[i][j].boat_ex=3;
               if(j==l+1)
                   Gr[i][j].boat_ex=3;
               if((j==l)&&(i==k-pom.size))
                   Gr[i][j].boat_ex=3;
           }
        }
    }
    else if(pom.dir==5)               //dol
    {
        ///Zmienna k
        int k=pom.wsp_i;
        ///Zmienna l
        int l=pom.wsp_j;

        for(int i=k-1;i<= k+pom.size;i++)
        {
           for(int j=0;j<l+2;j++)
           {
               if(j==l-1)
                   Gr[i][j].boat_ex=3;
               if((j==l)&&(i==k-1))
                   Gr[i][j].boat_ex=3;
               if(j==l+1)
                   Gr[i][j].boat_ex=3;
               if((j==l)&&(i==k+pom.size))
                   Gr[i][j].boat_ex=3;
           }
        }

    }
    else if(pom.dir==6)                 //prawo
    {
        ///Zmienna k
        int k=pom.wsp_i;
        ///Zmienna l
        int l=pom.wsp_j;

        for(int i=k-1;i<= k+1;i++)
        {
           for(int j=1;j<=l+pom.size;j++)
           {
               if(j==l+pom.size)
                   Gr[i][j].boat_ex=3;
               if((i==k-1)&&(j>=l-1))
                   Gr[i][j].boat_ex=3;
               if((i==k+1)&&(j>=l-1))
                   Gr[i][j].boat_ex=3;
               if(j==l-1)
                   Gr[i][j].boat_ex=3;
           }
        }
    }
    else if(pom.dir==4)                   //lewo
    {
        ///Zmienna k
        int k=pom.wsp_i;
        ///Zmienna l
        int l=pom.wsp_j;

        for(int i=k-1;i<= k+1;i++)
        {
           for(int j=1;j<=l+1;j++)
           {
               if(j==l-pom.size)
                   Gr[i][j].boat_ex=3;
               if((i==k-1)&&(j>=l-pom.size))
                   Gr[i][j].boat_ex=3;
               if((i==k+1)&&(j>=l-pom.size))
                   Gr[i][j].boat_ex=3;
               if(j==l+1)
                   Gr[i][j].boat_ex=3;

           }
        }
    }
}

void drukuj_Gr(Plansza **Gr,int N){

    for(int i=0;i<N+2;i++)
    {
        for(int j=0;j<N+2;j++)
        {
            if(i==0||j==0||i==N+1||j==N+1)
               cout<<Gr[i][j].show<<" ";
            else if(Gr[i][j].boat_ex==1){
                Gr[i][j].show='0';
             cout<<Gr[i][j].show<<" ";
            }else if(Gr[i][j].boat_ex==3){
                Gr[i][j].show='~';
             cout<<Gr[i][j].show<<" ";
            }
             else
              cout<<Gr[i][j].show<<" ";
        }
        cout<<endl;
    }
   cout<<endl<<endl;
}

void drukuj_Ko(Plansza **Gr,int N){            //funkcja drukujaca plansze gracza

    for(int i=0;i<N+2;i++)
    {
        for(int j=0;j<N+2;j++)
        {
            cout<< Gr[i][j].show<<" ";
        }
        cout<<endl;
    }
   cout<<endl<<endl;
}
