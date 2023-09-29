/*
(CRNA POGIBIJA) U statistici prosjek je relativan pojam. Često koristimo aritmetičku
sredinu da bismo dobili prosjek, međutim ako bismo imali niz od recimo 1, 2, 3, 3, 1000;
tada aritmetička sredina je 201.8, što nije često reprezentacija prosjeka niza zbog toga
što imamo 1000 koje zovemo outlier. Stoga, koristimo drugu interpretaciju prosjeka koju
zovemo medijana. Medijana je srednji broj monotono opadajućeg ili monotono rastućeg
niza (drugim riječima, sortiranog niza). Često medijanu koristimo zajedno sa
aritmetičkom sredinom, standardnom devijacijom i modom da bismo dobili više
informacija o podacima s kojim radimo.
Cilj ovog zadatka jeste da izračunamo medijanu. Definisati funkciju double
median(double* arr, int n) koja vraća medijanu niza i double mean(double* arr, int n) koja
vraća aritmetičku sredinu. Program traži od korisnika unos n, zatim n unosa realnih
brojeva i ispisuje aritmetičku sredinu i medijanu. NAPOMENA: Ukoliko je niz parne
veličine, npr. 1, 2, 3, 4, 5, 6, tada medijana se računa tako što se uzme dva srednja
elementa 3 i 4 i izračunamo njihovu aritmetičku sredinu, to jeste (3 + 4) / 2 = 3.5. Ukoliko
je niz neparne veličine, srednji element sortiranog niza se uzme za medijanu.
Primjeri medijana
1, 2, 3, 4, 5 -> 3
1, 2, 3, 4, 5, 6 -> 3.5
1, 2, 3, 4, 5, 6, 100 -> 4
*/

#include <iostream>

using namespace std;

double median(double* arr, int n){
    double median;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j + 1]){
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    if (n % 2 == 0)
        median = ( arr[n / 2] + arr[n / 2 - 1] ) / 2;
    else
        median = arr[n / 2];

    return median;
}

double mean(double* arr, int n){
    double mean = 0;
    for(int i = 0; i < n; i++)
        mean += arr[i] / n;

    return mean;
}


int main() {
    int* n = new int;
    cin >> *n;
    double* arr = new double[*n];

    for (int i = 0; i < *n; i++){
        cout << "Unesite " << i + 1 << ". clan niza: ";
        cin >> arr[i];
    }

    cout << "Aritmeticka sredina: " << mean(arr, *n) << endl;
    cout << "Median: " << median(arr, *n);

    delete [] arr;
    delete n;

    return 0;
}