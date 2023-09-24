/*
Neka je data varijabla tipa int. Napraviti pokazivač koji pokazuje na vrijednost te
varijable, te putem pokazivača ispisati adresu i vrijednost varijable, a vrijednost se dobija
unosom od strane korisnika.
*/

#include <iostream>

using namespace std;



int main() {
    int broj;
    cin >> broj;
    cout << "Unesena varijabla vrijednost: " << broj << endl;

    int* ptr = &broj;

    cout << "Adresa: " << ptr << endl;
    cout << "Vrijednost varijable preko pointera: " << *ptr;
    
    
    return 0;
}