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

    for (int i = 0; i <= n; i++){
        if(isPrime(i))
            cout << i << endl;
    }

    return 0;
}