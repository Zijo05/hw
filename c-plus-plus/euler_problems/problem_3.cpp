// https://projecteuler.net/problem=3

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
    int largest_prime_factor = 0;
    unsigned long long int number = 600851475143;

    for(unsigned long long int i = 2; i < 600851475143 / 2 && number != 1; i++) {
        if(is_prime(i)){
            while(number % i == 0) {
                largest_prime_factor = i;
                number /= i;
            }
        }
    }

    cout << "Largest prime factor of 600851475143 is: " << largest_prime_factor;

    return 0;
}