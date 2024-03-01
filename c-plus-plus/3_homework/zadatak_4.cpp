/*
Školi je potreban sistem koji će moći izračunati prosjek ocjena za unešene ocjene kroz
program. Napravite sistem takav da prvo se traži unos koliko ocjena korisnik želi unijeti,
zatim za unešeni prirodan broj tražiti unos ocjena, koji mogu biti od 1 do 5. Neka je data
funkcija double mean(int* grades, int n) pri čemu prihvata dinamički alociran niz i
njegovu veličinu, zatim vraća aritmetičku sredinu ocjena. Program ispisuje prosjek u
odnosu na unešene ocjene. Ukoliko korisnik pogrešno unese ocjenu, program se
prekida i ispisuje odgovarajuću poruku.
*/

#include <iostream>

using namespace std;

double mean(int* grades, int n){
    double mean = 0;
    for(int i = 0; i < n; i++)
        mean += double(grades[i]) / n;

    return mean;
}


int main() {
    int* n = new int;

    cout << "Unesite koliko ocjena zelite unijeti: ";
    cin >> *n;

    int* grades = new int[*n];

    for (int i = 0; i < *n; i++){
        cout << "Unesite " << i + 1 <<". ocjenu: ";
        cin >> grades[i];
        if(grades[i] > 5 || grades[i] < 1){
            cout << "Pogresan unos, moguce ocjene su 1, 2, 3, 4 i 5!";
            return 0;
        }
    }
    
    cout << "Aritmeticka sredina unesenih ocjena je: " << mean(grades, *n);

    return 0;
}