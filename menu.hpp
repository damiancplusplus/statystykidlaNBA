#ifndef menu_hpp
#define menu_hpp
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdio.h>


using namespace std;
enum wydarzenie {za1_celny, za1_niecelny, za2_celny, za2_niecelny, za3_celny, za3_niecelny, zbiorka_atak,
zbiorka_obrona, asysta, faul_atak, faul_obrona, strata, przechwyt};

//definicje funkcji
void Dodaj(enum wydarzenie akcje);
void Zapisz();

int i=0; // zlicza statystyki

//pojedyncza akcja
struct akcja
{
	int zawodnik;
	int czas;
	enum wydarzenie zmeczu;
};

//generujemy kontener na zapis akcji
akcja akcja[500];

#endif
