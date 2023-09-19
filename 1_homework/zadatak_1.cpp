/*
Definisati funkciju koja provjerava da li je dati prirodan broj prost. U glavnom programu
korisnik unosi prirodan broj n i program ispisuje da li je broj prost ili ne. (kondicionali, funkcije).
BONUS: Ispisati za broj n sve proste brojeve do n.
*/

#include <iostream>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++){
        if (n % i == 0)
            return false;
    }
 
    return true;
}

int main() {
    
    int n;
    cout << "Unesi cijeli broj: ";
    cin >> n;

    if (n <= 1 )
        cout << "Uneseni broj nije prost i prije njega nema prostih brojeva.";
    else if (n == 2)
        cout << "Uneseni broj je prost, a od 0 do unesenog broja nema prostih brojeva.";
    else if (n == 3)
        cout << "Uneseni broj je prost, a od 0 do unesenog broja ima prost broj. Taj broj je: 2";
    else if(isPrime(n)){
        cout << "Uneseni broj je prost, a od 0 do unesenog broja ima prostih brojeva. Ti brojevi su: ";
        for (int j = 2; j<n; j++){
            if(isPrime(j))
                cout << j << " || ";
        }
    }
    else
        cout << "Uneseni broj nije prost i prije njega nema prostih brojeva.";

    return 0;
}