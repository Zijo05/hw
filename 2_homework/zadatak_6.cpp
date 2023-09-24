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

// int arrSize = sizeof(arr)/sizeof(arr[0]);

#include <iostream>
#include <vector>

using namespace std;

int* union_arr(int* arr_1, int size_1, int* arr_2, int size_2){
    vector<int> vectorUnion;
    bool postoji = false;
    for(int i=0; i < size_1; i++){
        vectorUnion.push_back(arr_1[i]);
    }

    for(int i = 0; i < size_2; i++){
        for(int j = 0; j < size_1; j++){
            if(arr_2[i] == arr_1[j])
                postoji = true;
        }

        if(!postoji)
            vectorUnion.push_back(arr_2[i]);
        
        postoji = false;
    }

    int arrUnion[size(vectorUnion)];
    for(int i = 0; i < size(vectorUnion); i++){
        arrUnion[i] = vectorUnion.at(i);
    }

    int* ptr = arrUnion;

    return ptr;
}

int union_arr_size(int* arr_1, int size_1, int* arr_2, int size_2){
    int* ptr = union_arr(arr_1, size_1, arr_2, size_2);
    int size = sizeof(ptr)/sizeof(ptr[0]);
    return size;
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

    int* ptr = union_arr(arr_1, n, arr_2, m);
    int union_size = union_arr_size(arr_1, n, arr_2, m);

    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << ptr[i] << endl;
    }
    
    cout << endl << "Velicina unije je " << union_size;
    

    return 0;
}
