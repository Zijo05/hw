// https://projecteuler.net/problem=2

#include <iostream>

using namespace std;

int main() {
    int sum = 2;
    int fib = 3;
    int n_1 = 2;
    int n_2 = 1;

    while(fib < 4000000) {
        fib = n_1 + n_2;
        if(fib % 2 == 0)
            sum += fib;
        n_2 = n_1;
        n_1 = fib;
    }

    cout << "Sum of even terms in Fibonacci sequence whose values don't exceed four million: " << sum;

    return 0;
}