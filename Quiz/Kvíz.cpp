#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Otazka
{
    string otazka;
    string a;
    string b;
    string c;
    char reseni;
};

int main()
{
    fstream myFile;
    char odpoved;
    int skore = 0;
    int pocet_otazek = 0;
    vector<Otazka> otazky;

    myFile.open("otazky.txt", ios::in);
    if (myFile.is_open())
    {
        string radek;
        while (getline(myFile, radek))
        {
            Otazka otazka;
            stringstream ss(radek);
            getline(ss, otazka.otazka, ';');
            getline(ss, otazka.a, ';');
            getline(ss, otazka.b, ';');
            getline(ss, otazka.c, ';');
            ss >> otazka.reseni;
            otazky.push_back(otazka);
        }
        myFile.close();

        for (const auto& otazka : otazky)
        {
            cout << otazka.otazka << " " << otazka.a << " " << otazka.b << " " << otazka.c << " (a, b, c): ";
            cin >> odpoved;
            pocet_otazek++;
            if (odpoved == otazka.reseni)
            {
                cout << "Správně!" << endl;
                skore++;
            }
            else
            {
                cout << "Špatně!" << endl;
            }
        }

        cout << endl << "Gratulujeme, vaše skóre je " << skore << "/" << pocet_otazek << "." << endl;
    }
    else
    {
        cout << "Chyba při otevírání souboru." << endl;
    }

    return 0;
}