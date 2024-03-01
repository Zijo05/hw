// https://projecteuler.net/problem=35

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int number) {
    if (number <= 1)
        return 0;
    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return 0;
    return 1;
}

bool is_circular_prime(int number) {
    if(!is_prime(number)) 
        return 0;

    int number_length = to_string(number).length();

    for(int i = 1; i < number_length; i++) {
        number = number % int(pow(10, number_length - 1)) * 10 + number / int(pow(10, number_length - 1));
        if(!is_prime(number)) 
            return 0;
    }
    return 1;
}

int main() {
    int number_of_circular_prime_numbers = 0;
    for(int i = 2, j = 1; i < 1000000; i++)
        if(is_circular_prime(i)){
            cout << j << ". circular prime: " << i << endl;
            j++;
            number_of_circular_prime_numbers++;
        }
 
    cout << "Number of circular prime numbers below 1000000 is " << number_of_circular_prime_numbers;

    return 0;
}