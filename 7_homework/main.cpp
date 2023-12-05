/*
Neka je dat niz od n elemenata, koji korisnik popunjava, gdje korisnik unosi koliko zeli elemenata.
Neka su elementi nenegativni brojevi, a ukoliko korisnik unese negativan element, zavrsava se unos.

Program treba da ispis element niza koji se najvise pojavljuje u njemu.

Primjer:
[1, 1, 1, 3, 4, 1, 2, 6, 7]
Treba da ispise 1
*/
#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Input n: ";
    cin >> n;

    // Unos niza
    unsigned int arr[n], arr_size = 0;
    for(arr_size; arr_size < n; arr_size++) {
        int input;
        cin >> input;
        if(input < 0)
            break;
        arr[arr_size] = input;
    }

    // Prebrojavanje broja s najvise ponavljanja
    int num;
    int num_of_repetitions = 0;
    for(int i = 0; i < arr_size; i++) {
        int num_of_repetitions_temp = 0;
        for(int j = 0; j < arr_size; j++)
            if(arr[i] == arr[j])
                num_of_repetitions_temp++;
    
        if(num_of_repetitions_temp > num_of_repetitions){
            num = arr[i];
            num_of_repetitions = num_of_repetitions_temp;
        }
    }

    cout << "Most repeated number is: " << num;
    cout << "\nNumber of repetitions is: " << num_of_repetitions;

    return 0;
}

