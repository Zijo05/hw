/*
Slično kao i drugi zadatak, samo treba oduzeti sa sumom brojeva koji su djeljivi sa 3 i sa 5.
(for petlje, kondicionali, trik pitanje)
*/

#include <iostream>

using namespace std;

int main() {
    long long int sum=0, n;
	cin >> n;

    for(long long int i=0; i<=n; i++){
        if(i % 3 == 0 && i % 5 == 0){}
        else if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << sum;
    
    return 0;
}