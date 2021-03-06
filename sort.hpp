#ifndef sort_hpp
#define sort_hpp
#include <vector>
#include <algorithm>

//deklaracje funkcji
void stats_to_player();
void showstats();
int liczPunkty();

//pojedynczyk zawodnik
struct zawodnik
    {
    int nr;
    int za1_celny;
    int za1_niecelny;
    float za1_p;
    int za2_celny;
    int za2_niecelny;
    float za2_p;
    int za3_celny;
    int za3_niecelny;
    float za3_p;
    int zbiorka_atak;
    int zbiorka_obrona;
    int asysta;
    int faul_atak;
    int faul_obrona;
    int strata;
    int przechwyt;
    int eval;
    int punkty;

    public:
    void licz_eval()
    {
        int suma = ((za1_celny+za2_celny+za3_celny+zbiorka_atak+zbiorka_obrona+asysta+przechwyt)-(za1_niecelny+za2_niecelny+za3_niecelny+
                faul_atak+faul_obrona+strata));
        eval = suma;
    }

    int licz_punkty()
    {
        int suma = (za1_celny + (za2_celny*2) + (za3_celny*3));
        punkty = suma;
        return suma;
    }

    void liczp_za1()
    {
        float mianownik = (za1_celny+za1_niecelny);
        if (mianownik == 0)
           {
              za1_p = 0;
           }
        else
        {
          float suma = (za1_celny/mianownik)*100;
          za1_p = suma;
        }
    }

    void liczp_za2()
    {
         float mianownik = (za2_celny+za2_niecelny);
        if (mianownik == 0)
           {
              za2_p = 0;
           }
        else
        {
          float suma = (za2_celny/mianownik)*100;
          za2_p = suma;
        }
    }

    void liczp_za3()
    {
         float mianownik = (za3_celny+za3_niecelny);
        if (mianownik == 0)
           {
              za3_p = 0;
           }
        else
        {
          float suma = (za3_celny/mianownik)*100;
          za3_p = suma;
        }
    }

    };
//sortowanie wynikow

enum sort_value{eval=6, za1p=7, za2p=8, za3p=9};
enum sort_value actual_sort_value = za3p;

    bool operator<(const zawodnik& a, const zawodnik& b)
    {
    if (actual_sort_value == eval)
    {
        return (a.eval > b.eval);
    }
    else if (actual_sort_value == za1p)
    {
        return (a.za1_p > b.za1_p);
    }
    else if (actual_sort_value == za2p)
    {
        return (a.za2_p > b.za2_p);
    }
    else if (actual_sort_value == za3p)
    {
        return (a.za3_p > b.za3_p);
    }
    }


//zawodnicy w druzynie
struct druzyna
    {
    std::vector<zawodnik>zawodnicy;
    int suma_punktow =0;

    public:

        int licz_punkty_druzyny()
        {
            suma_punktow = 0;
            for(int p=0; p<zawodnicy.size(); p++)
                {
                suma_punktow = suma_punktow + zawodnicy[p].punkty;
                }
            return suma_punktow;

        }

          void sortuj_eval()
        {
            std::sort(zawodnicy.begin(), zawodnicy.end());
        }
    };



// Bulls to nazwa structury z nasza druzyna
druzyna Bulls;

#endif
