#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <iostream>
#include <fstream>
#include "funkcje.h"

using namespace std;


/** \brief Struktura opisująca element tablicy.
 *
* Definicja elementu tablicy jednowymiarowej dynamicznej przechowującej informacje o statkach na planszy.
*/

struct Statek{
    ///Współrzędna wiersza przechowującego komórkę z początkiem statku
    int wsp_i;
    ///Współrzędna kolumny przechowującej komórkę z początkiem statku
    int wsp_j;
    ///Rozmiar statku
    int size;
    ///Kierunek rozchodzenie sie statku
    int dir;
};

/** \brief Struktura opisująca element tablicy.
 *
* Definicja elementu tablicy dwywymiarowej dynamicznej służącej za plansze.
*/

struct Plansza{
  ///Logiczna wartosc informująca o tym że:0-pole jest wolne,1-w komorce znajduje sie statek, 2-maszt statku jest zatopiony, 3-w komorce nie mozna rozstawic statku, 4-strzał nietrafiony
  int boat_ex;
  ///Wyświetlany znak na planszy: 0-maszt statku; ~-wolne pole; X-strzał nietrafiony; #-strzał trafiony
  char show;
};
/** \brief Funkcja menu
 *
 *   Funkcja wyswietlajaca MENU
 */
void menu();
/** \brief Funkcja zbierajaca informacje
 *
 * Funkcja pobiera informacje od Gracza o jego nicku,rozmiarze planszy,ilosci statkow oraz ich wielkosci
 * \param N rozmiar planszy
 * \param M rozmiar tablicy jednowymiarowej
 * \param tab tablica jednowymiarowa przechowujaca informacje o wszytskich statkach
 * \param nick
 */
void info(int &N,int &M,Statek *&tab,string &nick);

#endif // FUNKCJE_H
