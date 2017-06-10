#ifndef stoper_hpp
#define stoper_hpp
#include <time.h>

// Deklaracje funkcji zegara
void stoper();
int pobierz_czas(clock_t czas);
int obliczSekundy(clock_t czas);
void actual_time_sec_to_min(int sekundy);

//zmienne zegara - warto przerobiæ na strukture chocby sec/min/
bool stan_zegara = false;
int czas_start = 0;
int czas_do_pauzy = 0;
int suma_do_pauzy = 0;
int sec = 0;
int minuty = 0;
int sekundy = 0;

#endif
