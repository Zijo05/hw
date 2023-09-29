/*
Korisnik unosi dva cijela broja a i b. Primjenom pokazivača zamijeniti vrijednosti varijabli
a i b.
*/

#include <iostream>

using namespace std;

int main() {
    int* a = new int;
    int* b = new int;

    cout << "Unesi a: ";
    cin >> *a;
    cout << "Unesi b: ";
    cin >> *b;
    
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    cout << "Zamjenjene vrijednosti su: " << endl;
    cout << "a: " << *a << endl;
    cout << "b: " << *b;

    return 0;
}