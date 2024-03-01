/*Program traži od korisnika da unese prirodan broj n. Zatim traži n unos cijelih brojeva.
Program treba da ispiše sumu prvih k cijelih brojeva, pri čemu k je jedna trećina n
zaokružena na veći cijeli broj (npr. ako je 0.3, tada je 1)
*/

#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }

    int k = (n+3-1)/3;

    int sum = 0;

    for(int i=0; i < k; i++){
        sum += arr[i];
    }

    cout << "Suma prvih k brojeva: " << sum;

    return 0;
}