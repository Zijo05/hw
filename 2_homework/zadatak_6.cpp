/*
Neka su nam dati nizovi arr_1 i arr_2 koji sadržavaju cijele brojeve.
Definisati funkciju int* union_arr(int* arr_1, int size_1, int* arr_2, int size_2) i int
union_arr_size(int* arr_1, int size_1, int* arr_2, int size_2) koja vraća novi niz koja sadrži
uniju ova dva niza i veličinu unije respektivno. Testirati ovaj program tako što korisnik
unosi prirodne brojeve n i m, pri čemu onda unosi n cijelih brojeva za arr_1, zatim m
brojeva za arr_2, te ispisuje uniju ova dva niza i ispisuje srednji element nađene unije (to
jeste, ako ste spasili rezultat unije u union_array, onda ispišite samo
union_array[union_size/2]).
*/

#include <iostream>
#include <cmath>

using namespace std;

int* union_arr(int* arr_1, int size_1, int* arr_2, int size_2){

}

int union_arr_size(int* arr_1, int size_1, int* arr_2, int size_2){

}

int main() {
    int n, m;
    cin >> n >> m;
    int arr_1[n], arr_2[m];
    for(int i=0; i < n; i++){
        cin>>arr_1[i];
    }
    for(int i=0; i < m; i++){
        cin>>arr_2[i];
    }

    return 0;
}