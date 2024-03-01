/*
Neka su date dvije varijable tipa int. Napraviti pokazivače na te dvije varijable, te unosom
od korisnika spremiti vrijednosti u te varijablje putem pokazivača, te putem pokazivača
ispisati njihov zbir, razliku, proizvod i količnik.
*/

#include <iostream>

using namespace std;



int main() {
    int broj1, broj2;
    int* ptr1 = &broj1;
    int* ptr2 = &broj2;

    cin >> *ptr1;
    cin >> *ptr2;

    cout << "Zbir: " << *ptr1 + *ptr2 << endl;
    cout << "Razlika: " << *ptr1 - *ptr2 << endl;
    cout << "Proizvod: " << *ptr1 * *ptr2 << endl;
    cout << "Kolicnik: " << *ptr1 / *ptr2;
    
    return 0;
}