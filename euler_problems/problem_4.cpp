// https://projecteuler.net/problem=4

#include <iostream>

using namespace std;

bool is_palindrome(int number) {
    int palindrome = 0;
    int temp = number;
    while(temp != 0) {
        palindrome = palindrome * 10 + temp % 10;
        temp /= 10;
    }

    return palindrome == number;
}

int main() {
    int largest_six_digit_palindrome = 0;
    for(int multiplicand = 100; multiplicand < 1000; multiplicand++) {
        for(int multiplier = multiplicand; multiplier < 1000; multiplier++) {
            int product = multiplicand * multiplier;
            if(is_palindrome(product)) {
                cout << multiplicand << " * " << multiplier << " = " << product << endl;
                if(largest_six_digit_palindrome < product)
                    largest_six_digit_palindrome = product;
            }
        }
    }

    cout << "Largest six digit palindrome is: " << largest_six_digit_palindrome;

    return 0;
}