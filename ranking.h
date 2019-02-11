#ifndef RANKING_H
#define RANKING_H
#include <iostream>
#include <cstdlib>
#include "cialo.h"
#include "funkcje.h"
#include <fstream>

/** \brief Struktura opisująca element listy dynamicznej.
 *
* Definicja elementu jednokierunkowej dynamicznej listy przechowującej ranking graczy.
*/

struct Rank
{
    ///Nazwa Gracza
    string player;
    ///Wynik Gracza
    int score;
    ///Zmienna logiczna wykorzystywana w funkcji sortujacej - zapis_do_pliku()
    int uzyty;
    ///Wskażnik na następny element
    Rank *next;

};

/** \brief Funkcja dodająca nick
 *
 * Funkcja odpowiadająca za dodanie nicku podanego przez Gracza do listy jednokierunkowej przechowujacej ranking
 * \param glowa - wskaznik na liste jednokierunkowa przechowujaca ranking
 * \param nick
 * \param j - ilosc elementow listy
 */
void dodaj_nick(Rank *&glowa,string nick,int &j);

/** \brief Funkcja usuwająca liste

 * \param glowa - wskaznik na liste jednokierunkowa przechowujaca ranking
 */
void usun_liste(Rank *glowa);

/** \brief Funkcja zliczająca
 *
 * Funkcja odpowiadająca za zliczenie ilosci wierszow pliku ranking2.txt ktory bedzie iloscia elementow listy
 * \return ilosc
 */
int ile_();

/** \brief Funkcja tworząca
 *
 * Funkcja odpowiadająca za stworzenie listy jednokierunkowej za pomoca zapisanego pliku ranking2.txt
 * \param j - ilosc wierszy pliku (ilosc elementow listy)
 * \return glowa
 */
Rank *utworz_liste (int j);

/** \brief Funkcja dodająca wygraną
 *
 * \param glowa - wskaznik na liste jednokierunkowa przechowujaca ranking
 * \param nick
 */
void dodaj_wygrana(Rank *&glowa,string nick);

/** \brief Funkcja znajdująca max wartość
 *
 * Funkcja odpowiadająca za znalezienie maksymalnej wartości listy rankingu ktora juz wczesniej nie byla "uzyta" oraz oznaczenie jej jako "uzyta"
 * \param glowa - wskaznik na liste jednokierunkowa przechowujaca ranking
 * \return max - maksymalna wartosc z nieuzytych wczesniej
 */
Rank* znajdz_najwiekszy(Rank *glowa);

/** \brief Funkcja zapisująca liste
 *
 * Funkcja odpowiadająca za zapisanie listy do pliku w kolejnosci roznącej w czym pomaga jej funkcja znajdz_najwiekszy()
 * \param glowa - wskaznik na liste jednokierunkowa przechowujaca ranking
 * \param j - ilosc elementow listy
 */
void zapis_do_pliku(Rank *glowa, int j);

/** \brief Funkcja drukująca ranking
 *
 */
void drukuj_ranking();
//void drukuj_liste (Rank *glowa);

/** \brief Funkcja wczytująca nick
 *
 * Funkcja odpowiadająca za wczytanie nicku z pliku nick.txt ktory przechowuje nick gracza ktory zapisal stan swojej gry
 * \param nick
 */
void wczytaj_nick(string &nick);

/** \brief Funkcja zapisująca nick
 *
 * Funkcja odpowiadająca za zapisanie nicku do pliku nick.txt ktory bedzie przechowywal nick gracza ktory zapisal stan swojej gry
 * \param nick
 */
void zapisz_nick(string nick);

#endif // RANKING_H
