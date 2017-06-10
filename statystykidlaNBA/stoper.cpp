#include "sort.hpp"
#include "menu.hpp"
#include "stoper.hpp"


// odpalanie/zatrzymywanie zegara
void stoper()
{
    if (stan_zegara == false)
    {
        czas_start = obliczSekundy(clock());
        stan_zegara = true;
        cout << "Czas wystartowa³ od:" << endl;
        actual_time_sec_to_min(sekundy);
        cout << "Wcisnij ENTER" << endl;
    }
    else
    {
        czas_do_pauzy = obliczSekundy(clock()) - czas_start;
        suma_do_pauzy = suma_do_pauzy + czas_do_pauzy;
        stan_zegara = false;
        cout << "Czas zatrzymany na:" << endl;
        actual_time_sec_to_min(sekundy);
        cout << "Wcisnij ENTER" << endl;
    }
}

//zlicza czas, ktory uplynal od uruchomienia zegara
int obliczSekundy(clock_t czas)
{
    return static_cast <double>(czas) / CLOCKS_PER_SEC;
}

//wskazuje aktualny sekunde meczu
int pobierz_czas(clock_t czas)
{
    if (stan_zegara == false)
    {
        return suma_do_pauzy;
    }
    else
    {
        return obliczSekundy(clock()) - czas_start + suma_do_pauzy;
    }

}

//przelicza sekundy na minuty i wyswietla je
void actual_time_sec_to_min(int sekundy)
{

        sekundy = pobierz_czas(clock());
        if (sekundy >= 60)
        {
            minuty = sekundy / 60;
            sec = sekundy % 60;
        }
        else
        {
            minuty = 0;
            sec = sekundy;
        }

    cout << minuty << ":" << sec << endl;
}
