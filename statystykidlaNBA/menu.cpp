#include "sort.hpp"
#include "menu.hpp"
#include "stoper.hpp"

//Dodawanie wydarzenia na boisku
void Dodaj(enum wydarzenie akcje)
{
  system("cls");
  cout <<"\n\n\t\tZawodnik : ";
  cin >>akcja[i].zawodnik;
  akcja[i].czas = pobierz_czas(clock());
  akcja[i].zmeczu = akcje;
  i++;
}

//Zapisywanie do pliku
void Zapisz()
{
  ofstream plik("staty.txt",ios::trunc);
  plik <<i<<"\n";

  for (int j = 0; j < i; j++)
  {
    plik <<akcja[j].zawodnik<<"\n";
    plik <<akcja[j].czas<<"\n";
    plik <<akcja[j].zmeczu<<"\n";
  }
  system("cls");
  cout <<"\n\n\t\tDane zostaly zapisane! \n\n\t\t";

}

int menu()
{
char wybor;
for(;;){

    stats_to_player();

    cout<<endl;
    cout << "--------------------------" << endl;
    cout << ". - Start/Pauza czasu" << endl;
    cout << "--------------------------" << endl;
    cout << "1 - Rzut wolny (za 1 punkt)" << endl;
    cout << "2 - Rzut za 2 punkty" << endl;
    cout << "3 - Rzut za 3 punkty" << endl;
    cout << "a - Asysta" << endl;
    cout << "p - Przechwyt" << endl;
    cout << "z - Zbiorka" << endl;
    cout << "f - Faul" << endl;
    cout << "s - Strata" << endl;
    cout << "--------------------------" << endl;
    cout << "q - Koniec" << endl;
    cout << endl;
    cout << endl;
    showstats();
    cout << endl;
    wybor=getch();
    switch(wybor)
    {
    case '1':
        cout << "1 - celny/niecelny - 2" << endl;
        char wybor_za1;
        wybor_za1=getch();
            switch (wybor_za1){
            case '1':
                Dodaj(za1_celny);
            break;
            case '2':
                Dodaj(za1_niecelny);
            break;}
    break;
    case '2':
        cout << "1 - celny/niecelny - 2" << endl;
        char wybor_za2;
        wybor_za2=getch();
            switch (wybor_za2){
            case '1':
                Dodaj(za2_celny);
            break;
            case '2':
                Dodaj(za2_niecelny);
            break;}
    break;
    case '3':
       cout << "1 - celny/niecelny - 2" << endl;
        char wybor_za3;
        wybor_za3=getch();
            switch (wybor_za3){
            case '1':
                Dodaj(za3_celny);
            break;
            case '2':
                Dodaj(za3_niecelny);
            break;}
    break;
    case 'z':
       cout << "1 - atak/obrona - 2" << endl;
        char wybor_zbiorka;
        wybor_zbiorka=getch();
            switch (wybor_zbiorka){
            case '1':
                Dodaj(zbiorka_atak);
            break;
            case '2':
                Dodaj(zbiorka_obrona);
            break;}
    break;
    case 'a':
            Dodaj(asysta);
    break;
     case 'p':
            Dodaj(przechwyt);
    break;
    case 'f':
       cout << "1 - atak/obrona - 2" << endl;
        char wybor_faul;
        wybor_faul=getch();
            switch (wybor_faul){
            case '1':
                Dodaj(faul_atak);
            break;
            case '2':
                Dodaj(faul_obrona);
            break;}
    break;
    case '.':
        stoper();
    break;
    case 'q':
            Zapisz();
            exit(0);
    break;
    case 's':
            Dodaj(strata);
    break;
    case '6':
       actual_sort_value = eval;
    break;
    case '7':
       actual_sort_value = za1p;
    break;
    case '8':
       actual_sort_value = za2p;
    break;
    case '9':
       actual_sort_value = za3p;
    break;

    default: cout<<"Nie ma takiej akcji";
    }
    getchar();
    system("cls");
}
    return 0;
}
