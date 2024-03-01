#include<iostream>

using namespace std;

// Rjesenje pomocu rekurzije
long long int fib(int n) {
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

long long int fib_fast(int n) {
    long long int previous = 0;
    long long int current = 1;
    long long int temp;

    for(int i = 0; i < n; i++) {
        temp = previous;
        previous = current;
        current += temp;
    }

    return previous;
}

int main() {
	int n;
	cout << "Enter number: ";
	cin >> n;
	cout << endl;
	cout << "Fibonacci of " << n << " is: " << fib_fast(n) << endl;
	cout << "Fibonacci of " << n << " is: " << fib(n) << endl;

	return 0;
}
