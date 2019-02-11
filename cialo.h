#ifndef CIALO_H
#define CIALO_H

#include <iostream>
#include <cstdlib>
#include "cialo.h"
#include "funkcje.h"

using namespace std;

/** \brief Funkcja losująca
 *
 * Funkcja odpowiadająca za rozlosowanie statków odwołująca się do  podfunkcji: losuj_dir(),check_dir(),surround(),wypelnij()
 * \param tab tablica jednowymiarowa przechowująca informacje o statkach
 * \param Gr tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param M ilosc wszystkich statkow podana przez Gracza
 * \param N rozmiar planszy
 * \param czy - wartosc logiczna czy udalo sie rozstawic statki po planszy
 */

void losuj(Statek *&tab, Plansza **&Gr,int N,int M,int &czy );  //funkcja losujaca miejsca statkow

/** \brief Funkcja tworząca plansze
 *
 * Funkcja generuje plansze Komputera oraz Gracza. Wymiary tworzonej planszy są wieksze od rozmiaru podanego od gracza
 *  dzieki czemu w "otoczke" planszy moga być wpisane wartosci logiczne (3) umożliwiające system losowania miejsc dla statków
 * \param Ko tablica dwuwymiarowa - plansza Komputera
 * \param Gr tablica dwuwymiarowa - plansza Gracza
 * \param N rozmiar planszy
 */

void tworz_plansze(Plansza **&Gr,Plansza **&Ko, int N);

/** \brief Funkcja losująca położenie
 *
 * Funkcja losuje położenie (komórkę) początku pojedynczego statku
 * \param pom jedna kmorka tablicy jednowymiarowa przechowującej informacje o statkach (pom przechowuje informacje o jednym ze statkow)
 * \param Gr tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 */

void losuj_dir(Statek &pom,int N);

/** \brief Funkcja sprawdzająca
 *
 * Funkcja losująca jeden z 4 możliwych kierunków rozchodzenia się statków oraz
 *  sprawdzająca możliwość rozchodzenia się statków w określonym kierunku zwraca wartosc 1 jezeli moze rozchodzic sie w wylosowanym kierunku
 *  0-gdy jest to niemożliwe
 * \param pom jedna kmorka tablicy jednowymiarowa przechowującej informacje o statkach (pom przechowuje informacje o jednym ze statkow)
 * \param Gr tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 * \return kierunek
 */

int check_dir(Statek pom,Plansza **Gr,int N);

/** \brief Funkcja wypełniająca
 *
 * Funkcja wypełnia pola na których znajduje się statek wartosciami (1)
 * \param pom jedna kmorka tablicy jednowymiarowa przechowującej informacje o statkach (pom przechowuje informacje o jednym ze statkow)
 * \param Gr tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 */

void wypelnij(Statek pom,Plansza **&Gr,int N);

/** \brief Funkcja okrążająca
 *
 * Funkcja wypełnia pola wokół statku wartościami logicznymi (3) dzieki którym prawidłowo przebiega system losowania statków
 * \param pom jedna kmorka tablicy jednowymiarowa przechowującej informacje o statkach (pom przechowuje informacje o jednym ze statkow)
 * \param Gr tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 */
void surround(Statek pom,Plansza **&Gr,int N);

/** \brief Funkcja drukująca
 *
 * Funkcja drukuje plansze Gracza
 * \param Gr tablica dwuwymiarowa - plansza gracza
 * \param N rozmiar planszy
 */

void drukuj_Gr(Plansza **Gr,int N);

/** \brief Funkcja drukująca
 *
 * Funkcja drukuje plansze Komputera
 * \param Gr tablica dwuwymiarowa - plansza Komputera
 * \param N rozmiar planszy
 */
void drukuj_Ko(Plansza **Gr,int N); //drukuje plansze komputera

#endif // CIALO_H
