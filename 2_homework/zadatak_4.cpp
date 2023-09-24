/*Program traži od korisnika da unese prirodan broj n. Zatim traži n unos cijelih brojeva.
Program treba da ispiše sumu prvih k cijelih brojeva, pri čemu k je jedna trećina n
zaokružena na veći cijeli broj (npr. ako je 0.3, tada je 1)
*/

#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++){
        cin>>arr[i];
    }

    int k = (n+3-1)/3;

    for(int i=0; i < k; i++){
        cout << arr[i];
    }

    return 0;
}