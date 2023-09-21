/*
Neka je dat nenegativan broj n. Program treba da ispiše sumu nenegativnih brojeva koji su
djeljivi sa 3 ili sa 5. (for petlje, kondicionali)
*/

#include <iostream>

using namespace std;

int main() {
    long long int sum = 0, n;
	cin >> n;

    for(long long int i = 0; i <= n; i++){
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
        }

    cout << sum;
    
    return 0;
}