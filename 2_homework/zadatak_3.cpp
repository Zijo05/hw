/*
Neka su dati pokazivači ptr1 i ptr2 koji pokazuju na neku vrijednost tipa int. Napraviti
program koji traži od korisnika unos 2 cijela broja. Napraviti funkciju int maksimum(int*
ptr1, int* ptr2) koja vraća cijeli broj koji je veći. Program treba da ispiše maksimum ova
dva cijela broja korištenjem ove funkcije.
*/

#include <iostream>

using namespace std;

int maksimum(int* ptr1, int* ptr2){
    if(*ptr1 > *ptr2)
        return *ptr1;
    else
        return *ptr2;
}

int main() {
    int broj1, broj2;
    int* ptr1 = &broj1;
    int* ptr2 = &broj2;

    cin >> *ptr1;
    cin >> *ptr2;

    cout << "Veci broj je: " << maksimum(ptr1, ptr2);

    return 0;
}