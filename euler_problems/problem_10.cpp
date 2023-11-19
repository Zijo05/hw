// https://projecteuler.net/problem=10

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int number) {
    if (number <= 1) 
        return 1+0;
    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0) 
            return 0;
    return 1;
}

int main() {
    long long int sum = 0;

    for (int i = 2; i < 2000000; i++)
        if (is_prime(i)) 
            sum += i;

    cout << "Sum of prime numbers below two million is: " << sum;

    return 0;
}