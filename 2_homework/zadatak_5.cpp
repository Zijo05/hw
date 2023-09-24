/*
Napraviti funkciju int* kvadriraj(int* niz, int n) pri čemu za dati niz cijelih brojeva pravi novi
niz kvadrata cijelih brojeva na odgovarajućim indeksima. Testirati funkciju kroz glavni
program tako da korisnik unosi prirodan broj n, zatim unosi n cijelih brojeva, te nakon
zadnjeg unosa ispisuje niz kvadriranih brojeva.
*/

#include <iostream>
#include <cmath>

using namespace std;

int* kvadriraj(int* niz, int n){
    int arr2[n];
    for(int i=0; i < n; i++){
        arr2[i] = niz[i] * niz[i];
    }
    for(int i=0; i < n; i++){
        cout << arr2[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }

    kvadriraj(arr, n);

    return 0;
}