#ifndef GRA_H
#define GRA_H

#include <iostream>
#include <cstdlib>
#include "cialo.h"
#include "funkcje.h"
#include <fstream>

/** \brief Funkcja "strzelająca"
 *
 * Funkcja odpowiadająca za strzał Gracza w plansze przeciwnika i wypelnia pod wplywem tego strzału plansze Komputera
 * odpowiednimi wartosciami logicznymi oraz znakami
 * \param Who tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 */
void ruch_Gr(Plansza **&Who, int N );

/** \brief Funkcja "strzelająca"
 *
 * Funkcja odpowiadająca za strzał Komputera w plansze przeciwnika (losowe komorki) i wypelnia pod wplywem tego strzału plansze Gracza
 * odpowiednimi wartosciami logicznymi oraz znakami
 * \param tab tablica jednowymiarowa przechowująca informacje o statkach
 * \param Who tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 */
void ruch_Ko (Plansza **&Who,int N);

/** \brief Funkcja sprawdzająca
 *
 * Funkcja odpowiadająca za spradzenie czy nastapil koniec rozgrywki (czy wszytskie statki zostały zestrzelone)
 * \param tab tablica jednowymiarowa przechowująca informacje o statkach
 * \param Who tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 * \param M ilosc statkow (rozmiar rablicy tab)
 * \return koniec_gry
 */
int czy_koniec(Plansza **Who,Statek *tab,int N,int M); //sprawdza czy wszystkie statki zostaly zestrzelone

/** \brief Funkcja informująca
 *
 * Funkcja odpowiadająca za poinformowanie jaki statek został zestrzelony
 * \param tab tablica jednowymiarowa przechowująca informacje o statkach
 * \param Who tablica dwuwymiarowa - plansza Komputera badz Gracza
 * \param N rozmiar planszy
 * \param M ilosc statkow (rozmiar rablicy tab)
 */
void czy_zatopiony(Plansza **Who, Statek *tab,int N,int M);

/** \brief Funkcja zapisująca
 *
 * Funkcja odpowiadająca za zapisanie stanu gry do pliku tekstowego
 * \param Gr tablica dwuwymiarowa - Gracza
 * \param Ko tablica dwuwymiarowa - Komputera
 * \param N rozmiar planszy
 */
void zapisz(Plansza **Gr, Plansza **Ko, int N);

/** \brief Funkcja wczytująca
 *
 * Funkcja odpowiadająca za wczytanie stanu gry z pliku tekstowego
 * \param Gr tablica dwuwymiarowa - Gracza
 * \param Ko tablica dwuwymiarowa - Komputera
 * \param N rozmiar planszy
 */
void wczytaj(Plansza **&Gr, Plansza **&Ko, int N);

/** \brief Funkcja zliczająca
 *
 * Funkcja odpowiadająca za zliczenie ilosci wierszy z pliku zapis.txt co pozwala na odzyskanie wielkosci zapisanych planszy
 * \return ilosć_wierszy
 */
int ile_wierszy();

/** \brief Funkcja zapisująca tablice
 *
 * Funkcja odpowiadająca za zapisanie tablicy z informacjami o statkach do pliku
 * \param tab1 tablica jednowymiarowa z informacjami statkow Gracza
 * \param tab2 tablica jednowymiarowa z informacjami statkow Komputera
 * \param M ilosc statkow
 */
void statki_plik(Statek *tab1,Statek *tab2,int M);

/** \brief Funkcja odzyskująca parametr
 *
 * Funkcja odpowiadająca za odzyskanie wielkosci przechowujacej ilosc statkow
 * \param M ilosc statkow
 */
void get_M(int &M);

/** \brief Funkcja wczytujaca statki
 *
 * Funkcja odpowiadająca za odzyskanie informacji o statkach z pliku statki.txt
 * \param tab1 tablica jednowymiarowa z informacjami statkow Gracza
 * \param tab2 tablica jednowymiarowa z informacjami statkow Komputera
 * \param M ilosc statkow
 */
void get_ship(Statek *&tab1,Statek *&tab2,int M);


#endif // GRA_H
