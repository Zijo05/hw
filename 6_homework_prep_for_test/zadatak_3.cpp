#include <iostream>

using namespace std;

struct Flasa {
    double volumen;
    string ambalaza;
    string proizvodjac;
    bool recikliranje;
};

void ispisi_flasu(const Flasa& flasa) {
    cout << "Proizvodjac: " << flasa.proizvodjac << endl;
    cout << "Volumen: " << flasa.volumen << "L\n";
    cout << "Ambalaza: " << flasa.ambalaza << endl;
    cout << "Da li se moze reciklirati: ";
    (flasa.recikliranje) ? cout << "Da\n\n" : cout << "Ne\n\n";
}

int main() {
    Flasa flasa_1 = {2, "Plastika", "Tesanjski Kiseljak", 0};
    Flasa flasa_2 = {1, "Lim", "Kola", 1};
    Flasa flasa_3 = {5, "Plastika", "Diva", 0};

    ispisi_flasu(flasa_1);
    ispisi_flasu(flasa_2);
    ispisi_flasu(flasa_3);

    return 0;
}