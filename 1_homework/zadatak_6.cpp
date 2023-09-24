/*
Fibonaccijev niz je niz definisan sa prva dva člana i rekurentnom jednačinom fib(0) = 0, fib(1)
= 1, fib(n) = fib(n – 1) + fib(n – 2). Napisati program koji će dati za dati nenegativan broj n fib(n) ,
to jeste n-ti Fibonaccijev broj. (Nije potrebna rekurzija za izradu ovog zadatka)

*/

#include <iostream>

using namespace std;

long long int fib(int n) {
    long long int previous = 0;
    long long int current = 1;
    long long int temp;

    for(int i = 0; i < n; i++) {
        temp = previous;
        cout << temp << " = " << previous << endl;
        previous = current;
        cout << previous << " = " << current << endl;
        cout << current << " = " << current << " + " << temp << endl;
        current += temp;
        cout << "________" << endl;
    }

    return previous;
}

int main() {
	int n;
	cout << "Enter number: ";
	cin >> n;
	cout << endl;
	cout << "Fibonacci of " << n << " is: " << fib(n) << endl;

	return 0;
}
