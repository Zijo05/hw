/*
Napraviti funkciju int* kvadriraj(int* niz, int n) pri čemu za dati niz cijelih brojeva pravi novi
niz kvadrata cijelih brojeva na odgovarajućim indeksima. Testirati funkciju kroz glavni
program tako da korisnik unosi prirodan broj n, zatim unosi n cijelih brojeva, te nakon
zadnjeg unosa ispisuje niz kvadriranih brojeva.
*/

#include <iostream>

using namespace std;

int* kvadriraj(int* niz, int n){
    int* ptr = niz;
    
    for(int i=0; i < n; i++){
        niz[i] = niz[i] * niz[i];
    }
    return ptr;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }

    int* ptr = kvadriraj(arr, n);

    cout << "Niz kvadriran: " << endl;
    for(int i=0; i < n; i++){
        cout << ptr[i] << endl;
    }
    

    return 0;
}