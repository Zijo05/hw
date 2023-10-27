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

void ispisi_flasu(const Flasa& flasa) {
    cout << "Proizvodjac: " << flasa.proizvodjac << endl;
    cout << "Da li se moze reciklirati: ";
    (flasa.recikliranje) ? cout << "Da\nPovratna cijena: " << flasa.cijena * 0.1 << " KM\n" : cout << "Ne\nPovratna cijena: 0 KM\n";
}

int main() {
    int broj_artikala;
    cout << "Unesi broj mogucih flasa: ";
    cin >> broj_artikala;
    system("cls");

    Flasa* flase = new Flasa[broj_artikala];

    for (int i = 0; i < broj_artikala; i++) {
        cout << "Unesi " << i + 1 << ". flasu: \n";
        unesi_flasu(flase[i]);
        flase[i].barkod = i;
        system("cls");  
    }

    
    while(1){
        system("cls");
        cout << "Unesi barkodove: " << endl;
        int barkod = 0;
        int broj_barkodova = 8;
        int broj_unesenih_artikala;
        int* barkodovi = new int[broj_barkodova];
        double novac_za_vratiti = 0;
        for (int i = 0; barkod >= 0;) {
            if (barkod < broj_artikala) {
                cin >> barkod;

                if (barkod >= 0 && flase[barkod].recikliranje)
                    novac_za_vratiti += flase[barkod].cijena * 0.1;

                if (barkod >= 0 && barkod < broj_artikala) {
                    barkodovi[i] = barkod;
                    barkod = 0;
                    i++;
                }
            }

            else {
                cout << "Neispravan unos!\n";
                barkod = 0;
            }

            if (i == broj_barkodova) {
                int* temp = barkodovi;
                broj_barkodova *= 2;
                barkodovi = new int [broj_barkodova];
                barkodovi = temp;
            }
            broj_unesenih_artikala = i;
        }

        system("cls");
        cout << "Ubacene flase: \n";
        for (int i = 0; i < broj_unesenih_artikala; i++) {
            cout << "\nFlasa " << i + 1 << ":\n";
            ispisi_flasu(flase[barkodovi[i]]);
        }
        
        delete[] barkodovi;

        cout << "\nDobili ste " << novac_za_vratiti << " KM\n";
        system("pause");  
    }
    

    return 0;
}