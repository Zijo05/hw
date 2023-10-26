#include <iostream>

using namespace std;

struct Flasa {
    double volumen;
    string ambalaza;
    string proizvodjac;
    bool recikliranje;
    double cijena;
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
    cout << "Unesi broj artikala: ";
    cin >> broj_artikala;

    Flasa flase[broj_artikala];

    for (int i = 0; i < broj_artikala; i++) {
        unesi_flasu(flase[i]);
    }

    cout << "Ukupna cijena svih artikala je: " << ukupna_cijena(flase, broj_artikala);

    return 0;
}