#include "sort.hpp"
#include "menu.hpp"
#include "stoper.hpp"


// funkcja wyswietla statysyki zawodnikow oraz ogolna liczbe punktow
void showstats()
{
    cout << "Nr " << "| za1: C/N %  " << "| za2: C/N %  "<< "| za3: C/N %  " << "| zbiorka: A/O " << "| Faul: A/O "
    << "| Straty" << "| Przechwyty" << "| Asysty" << "| Punkty" << "| Eval" <<endl;

        for(int p=0; p<Bulls.zawodnicy.size(); p++)
            {   Bulls.zawodnicy[p].licz_punkty();
                Bulls.zawodnicy[p].licz_eval();
                Bulls.zawodnicy[p].liczp_za1();
                Bulls.zawodnicy[p].liczp_za2();
                Bulls.zawodnicy[p].liczp_za3();
                cout <<"" << Bulls.zawodnicy[p].nr
                <<  "       " << Bulls.zawodnicy[p].za1_celny
                <<  "/" << Bulls.zawodnicy[p].za1_niecelny
                <<  " " << Bulls.zawodnicy[p].za1_p
                <<  "      " << Bulls.zawodnicy[p].za2_celny
                <<  "/"<< Bulls.zawodnicy[p].za2_niecelny
                <<  " " << Bulls.zawodnicy[p].za2_p
                <<  "        " << Bulls.zawodnicy[p].za3_celny
                <<  "/"<< Bulls.zawodnicy[p].za3_niecelny
                <<  " " << Bulls.zawodnicy[p].za3_p
                <<  "            " << Bulls.zawodnicy[p].zbiorka_atak
                <<  "/"<<  Bulls.zawodnicy[p].zbiorka_obrona
                <<  "         " << Bulls.zawodnicy[p].faul_atak
                <<  "/"<<  Bulls.zawodnicy[p].faul_obrona
                <<  "     " << Bulls.zawodnicy[p].strata
                <<  "         " << Bulls.zawodnicy[p].przechwyt
                <<  "         " << Bulls.zawodnicy[p].asysta
                <<  "         " << Bulls.zawodnicy[p].punkty
                <<  "     " << Bulls.zawodnicy[p].eval
                <<  "   " << endl;
    }
    Bulls.licz_punkty_druzyny();
    cout<<endl;
    cout << "Suma punktow: " << Bulls.suma_punktow;

    Bulls.sortuj_eval();
    cout<<endl;
    cout<<endl;
    cout << "Wybierz i potwierdz sposob sortowania: ";
    cout<<endl;
    cout << "| 6 - Eval | 7 - za 1 | 8 - za 2 | 9 - za 3 |";
    cout<<endl;
     cout<<endl;
    cout << "Obecnie sortuje wedlug: " << actual_sort_value;
    cout<<endl;
    for(int p=0; p<Bulls.zawodnicy.size(); p++)
            {   cout
                <<  "   " << Bulls.zawodnicy[p].nr
                <<endl;
            }
}


/* funkcja na przypisuje poszczegolne statstyki zawodnikom
poszczegolny case sprawdza czy zawodnik jest w bazie, jesli tak dodajemy statystyke, jesli nie generujemy
zawpdnika w strukturze */
void stats_to_player()
    {
        Bulls.zawodnicy.clear();
        for (int k = 0; k < i; k++)
                {
                    switch(akcja[k].zmeczu)
                {
                case za1_celny:
                    {
                    bool i = false;
                    int z=0;
                        {
                        for (z; z < Bulls.zawodnicy.size(); z++)
                        {
                            if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                        {
                            ++Bulls.zawodnicy[z].za1_celny;
                        i=true;
                        break;
                        }
                        }
                    }
                    if(i == false)
                        {
                        zawodnik c;
                        c.nr = akcja[k].zawodnik;
                        c.za1_celny = 1;
                        Bulls.zawodnicy.push_back(c);
                        }
                }
            break;
        case za1_niecelny:
                {
                bool i = false;
                int z=0;
                    {
                    for (z; z < Bulls.zawodnicy.size(); z++)
                        {
                        if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                        {
                    ++Bulls.zawodnicy[z].za1_niecelny;
                    i=true;
                    break;
                    }
                }
                }
                if(i == false)
                    {
                    zawodnik c;
                    c.nr = akcja[k].zawodnik;
                    c.za1_niecelny = 1;
                    Bulls.zawodnicy.push_back(c);
                    }
            }
        break;
        case za2_celny:
            {
            bool i = false;
            int z=0;
                {
                for (z; z < Bulls.zawodnicy.size(); z++)
                    {
                        if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                    {
                    ++Bulls.zawodnicy[z].za2_celny;
                    i=true;
                    break;
                    }
                }
                }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.za2_celny = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case za2_niecelny:
                {
                bool i = false;
                int z=0;
                {
                for (z; z < Bulls.zawodnicy.size(); z++)
                {
                    if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].za2_niecelny;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.za2_niecelny = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case za3_celny:
            {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].za3_celny;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.za3_celny = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case za3_niecelny:
                {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].za3_niecelny;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.za3_niecelny = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case zbiorka_atak:
            {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].zbiorka_atak;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.zbiorka_atak = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case zbiorka_obrona:
             {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].zbiorka_obrona;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.zbiorka_obrona = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case asysta:
              {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].asysta;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.asysta = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case faul_atak:
                {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].faul_atak;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.faul_atak = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case faul_obrona:
                  {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].faul_obrona;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.faul_obrona = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case strata:
                  {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].strata;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.strata = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
        case przechwyt:
                {
            bool i = false;
            int z=0;
            {
            for (z; z < Bulls.zawodnicy.size(); z++)
            {
                if(Bulls.zawodnicy[z].nr == akcja[k].zawodnik)
                {
                    ++Bulls.zawodnicy[z].przechwyt;
                    i=true;
                    break;
                }
            }
            }
            if(i == false)
              {
              zawodnik c;
              c.nr = akcja[k].zawodnik;
              c.przechwyt = 1;
              Bulls.zawodnicy.push_back(c);
              }
            }
        break;
    }
    }
}
