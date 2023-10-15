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

using namespace std;

int* union_arr(int* arr_1, int size_1, int* arr_2, int size_2){
    int* arr_union = new int[size_1 + size_2];

    int count = 1;
    bool postoji = false;

    arr_union[0] = arr_1[0];

    for(int i = 1; i < size_1; i++){
        for (int j = 0; j < count; j++)
        {
            if(arr_1[i] == arr_union[j]){
                postoji = true;
                break;
            }
        }
        if(!postoji){
            arr_union[count] = arr_1[i];
            count++;
        }
        postoji = false;
    }

    for(int i = 0; i < size_2; i++){
        for (int j = 0; j < count; j++)
        {
            if(arr_2[i] == arr_union[j]){
                postoji = true;
                break;
            }
        }
        if(!postoji){
            arr_union[count] = arr_2[i];
            count++;
        }
        postoji = false;
    }

    return arr_union;
}

int union_arr_size(int* arr_1, int size_1, int* arr_2, int size_2){    // izračun veličine unije dva skupa
    int count = 0;
    int arr[size_1 + size_2];
    bool postoji = false;

    for(int i = 0; i < size_1; i++){
        arr[i] = arr_1[i];
        count++;
    }
    
    for(int i = 0; i < size_2; i++){
        for (int j = 0; j < count; j++)
        {
            if(arr_2[i] == arr[j]){
                postoji = true;
                break;
            }
        }
        if(!postoji){
            arr[count] = arr_2[i];
            count++;
        }
        postoji = false;
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    int arr_1[n], arr_2[m];

    for(int i = 0; i < n; i++){    // unos prvog skupa
        cout << "Prvi skup - element [" << i + 1 << "] = ";
        cin >> arr_1[i];
    }
    for(int i = 0; i < m; i++){    // unos drugog skupa
        cout << "Drugi skup - element [" << i + 1 << "] = ";
        cin >> arr_2[i];
    }

    int* arrU = union_arr(arr_1, n, arr_2, m);    // pohranjivanje pointera za dinamički niz unije
    int union_size = union_arr_size(arr_1, n, arr_2, m);    // pohranjivanje veličine niza unije

    cout << "Unija dva unesena skupa: " << endl;    // ispis unije
    for (int i = 0; i < union_size; i++){
        cout << arrU[i] << endl;
    }

    cout << "Srednji element unije skupova je: " << arrU[union_size/2];    // ispis srednje elementa niza unije

    delete [] arrU;

    return 0;
}
