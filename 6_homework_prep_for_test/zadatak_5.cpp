#include <iostream>

using namespace std;

struct Flasa {
    double volumen;
    string ambalaza;
    string proizvodjac;
    bool recikliranje;
    double cijena;
    int barkod;
};

double ukupna_cijena(Flasa* artikli, int broj_artikala) {
    double sum = 0;
    for (int i = 0; i < broj_artikala; i++)
        sum += artikli[i].cijena;

    return sum;
}

void unesi_flasu(Flasa& flasa) {
    cout << "Unesi proizvodjaca: ";
    cin.ignore();
    getline(cin, flasa.proizvodjac);

    cout << "Unesi volumen: ";
    cin >> flasa.volumen;

    cout << "Unesi Ambalazu: ";
    cin.ignore();
    getline(cin, flasa.ambalaza);

    cout << "Moze li se reciklirati (0/1): ";
    cin >> flasa.recikliranje;

    cout << "Unesi cijenu: ";
    cin >> flasa.cijena;

}


int main() {
    int broj_artikala;
    cout << "Koliko vrsta flasa zelite napraviti: ";
    cin >> broj_artikala;

    Flasa flase[broj_artikala];

    for (int i = 0; i < broj_artikala; i++) {
        cout << "Unesi " << i + 1 << ". flasu: ";
        unesi_flasu(flase[i]);
    }

    

    return 0;
}