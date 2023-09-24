#include <iostream>

using namespace std;

int* kvadriraj(int* niz, int n){
    int arr2[n];
    
    for(int i=0; i < n; i++){
        arr2[i] = niz[i] * niz[i];
    }
    return arr2;
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