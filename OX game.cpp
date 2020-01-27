#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
// test testo
char plansza[9] = { ' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ' };

void kolor(int n)
{
    HANDLE aaa;
    aaa = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(aaa, n);
}

void instrukcja()
{
    char lg = 0xC9, g = 0xCD, gs = 0xCB, pg = 0xBB;
    char lb = 0xCC, b = 0xBA, pb = 0xB9, s = 0xCE;
    char ld = 0xc8, ds = 0xCA, pd = 0xBC, x = 0xDB;
    
    
    
    cout << endl << endl << endl << "                         GRA W KOLKO I KRZYZYK" << endl << endl;
    kolor(10);
    // LOGO XO
    Sleep(500);
    Sleep(500); cout << "                         " << x << x << "          " << x << x << "          " << x << x << x << x << x << x << endl;
    Sleep(500); cout << "                           " << x << x << "      " << x << x << "          " << x << x << "      " << x << x << endl;
    Sleep(500); cout << "                             " << x << x << "  " << x << x << "          " << x << x << "          " << x << x << endl;
    Sleep(500); cout << "                               " << x << x << "            " << x << x << "          " << x << x << endl;
    Sleep(500); cout << "                             " << x << x << "  " << x << x << "          " << x << x << "          " << x << x << endl;
    Sleep(500); cout << "                           " << x << x << "      " << x << x << "          " << x << x << "      " << x << x << endl;
    Sleep(500); cout << "                         " << x << x << "          " << x << x << "          " << x << x << x << x << x << x << endl;
    cout << endl << endl << endl;
    kolor(15);
    Sleep(1000);
    cout << "                        " << lg << g << g << g << gs << g << g << g << gs << g << g << g << pg << endl;
    cout << "                        " << b << " 1 " << b << " 2 " << b << " 3 " << b << endl;
    cout << "                        " << lb << g << g << g << s << g << g << g << s << g << g << g << pb << endl;
    cout << "                        " << b << " 4 " << b << " 5 " << b << " 6 " << b << endl;
    cout << "                        " << lb << g << g << g << s << g << g << g << s << g << g << g << pb << endl;
    cout << "                        " << b << " 7 " << b << " 8 " << b << " 9 " << b << endl;
    cout << "                        " << ld << g << g << g << ds << g << g << g << ds << g << g << g << pd << endl;
    
    cout << endl << "        Pola sa ponumerowane tak jak powyzej, gra jest przeznaczona dla dwoch osob" << endl << endl << endl;
    
    kolor(10);
    Sleep(500); cout << endl << endl << "                Wcisnij dowolny przycisk, aby rozpoczac gre.";
    kolor(15);
    _getch();
    system("cls");
    
}

void rysuj_plansze()
{
    char lg = 0xC9, g = 0xCD, gs = 0xCB, pg = 0xBB;
    char lb = 0xCC, b = 0xBA, pb = 0xB9, s = 0xCE;
    char ld = 0xc8, ds = 0xCA, pd = 0xBC;
    cout << endl << endl << endl;
    cout << "                        " << lg << g << g << g << gs << g << g << g << gs << g << g << g << pg << endl;
    cout << "                        " << b << " "<<plansza[0]<<" " << b << " "<<plansza[1]<<" " << b << " "<<plansza[2]<<" " << b << endl;
    cout << "                        " << lb << g << g << g << s << g << g << g << s << g << g << g << pb << endl;
    cout << "                        " << b << " " << plansza[3] << " " << b << " " << plansza[4] << " " << b << " " << plansza[5] << " " << b << endl;
    cout << "                        " << lb << g << g << g << s << g << g << g << s << g << g << g << pb << endl;
    cout << "                        " << b << " " << plansza[6] << " " << b << " " << plansza[7] << " " << b << " " << plansza[8] << " " << b << endl;
    cout << "                        " << ld << g << g << g << ds << g << g << g << ds << g << g << g << pd << endl << endl << endl;
}

void ruch_gracza(char gracz)
{
    cout << "                    Ruch gracza " << gracz;
    int poprawny = 1;
    while (poprawny)
    {
        cout << ", prosze wybrac pole. ";
        char ruch;
        ruch = _getch();
        int Iruch = static_cast<int>(ruch) - 48; // zero ma wartosc 48
        if (Iruch >= 1 && Iruch <= 9 && plansza[Iruch - 1] == ' ')
        {
            plansza[Iruch - 1] = gracz;
            poprawny = 0;
        }
        else cout << endl << "                    Niepoprawny ruch";
    }
}

bool koniec_gry(char g)
{
    bool koniec = false;
    for (int i = 0; i < 3; i++) // sprawdza pionowo
    {
        if (plansza[i] == g && plansza[i + 3] == g && plansza[i + 6] == g) koniec = true;
    }
    for (int i = 0; i < 9; i = i + 3) // sprawdza poziomo
    {
        if (plansza[i] == g && plansza[i + 1] == g && plansza[i + 2] == g) koniec = true;
    }
    if (plansza[0] == g && plansza[4] == g && plansza[8] == g) koniec = true; // na ukos
    if (plansza[2] == g && plansza[4] == g && plansza[6] == g) koniec = true; // na ukos
    return koniec;
}

bool remis()
{
    int licznik{};
    for (int i = 0; i < 9; i++)
    {
        if (plansza[i] == ' ') return false;
        else licznik++;
    }
    if (licznik == 9) return true;
}

int main()
{
    char kolko = 'O', krzyzyk = 'X';
    bool restart = true;
    char odp;
    instrukcja();
    while (restart)
    {
        system("cls");
        for (int i = 0; i < 9; i++)
        {
            rysuj_plansze();
            if (i % 2) ruch_gracza(kolko);
            else ruch_gracza(krzyzyk);
            if (koniec_gry(krzyzyk))
            {
                system("cls");
                rysuj_plansze();
                kolor(14);
                cout << "                    Gracz X wygrywa!!! Koniec gry" << endl;
                cout << "                Czy chcesz zagrac jeszcze raz? wcisnij t" << endl;
                cout << "                Aby zakonczyc, wcisnij dowolny inny przycisk." << endl;
                odp = _getch();
                kolor(15);
                if (odp == 't' || odp == 'T') for (int j = 0; j < 9; j++) plansza[j] = ' ';
                else  exit(0);
                i = 9;
            }
            if (koniec_gry(kolko))
            {
                system("cls");
                rysuj_plansze();
                kolor(14);
                cout << "                    Gracz O wygrywa!!! Koniec gry" << endl;
                cout << "                Czy chcesz zagrac jeszcze raz? wcisnij t" << endl;
                cout << "                Aby zakonczyc, wcisnij dowolny inny przycisk." << endl;
                odp = _getch();
                kolor(15);
                if (odp == 't' || odp == 'T') for (int j = 0; j < 9; j++) plansza[j] = ' ';
                else  exit(0);
                i = 9;
            }
            if (koniec_gry(kolko) == false && koniec_gry(krzyzyk) == false && remis())
            {
                system("cls");
                rysuj_plansze();
                kolor(14);
                cout << "                    Remis!!! Koniec gry" << endl;
                cout << "                Czy chcesz zagrac jeszcze raz? wcisnij t" << endl;
                cout << "                Aby zakonczyc, wcisnij dowolny inny przycisk." << endl;
                odp = _getch();
                kolor(15);
                if (odp == 't' || odp == 'T') for (int j = 0; j < 9; j++) plansza[j] = ' ';
                else  exit(0);
                i = 9;
            }
            system("cls");
        }
    }
    system("pause");
}

