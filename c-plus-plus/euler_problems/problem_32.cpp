// https://projecteuler.net/problem=32

#include <iostream>
#include <algorithm>

using namespace std;

bool is_pandigital(int a, int b, int product) {
    string all_numbers = to_string(a) + to_string(b) + to_string(product);
    sort(all_numbers.begin(), all_numbers.end());
    return all_numbers == "123456789";
}

int main() {
    unsigned int sum = 0;

    cout << "Multiplicand/multiplier/product identities that can be written as a 1 through 9 pandigital: " << endl;
    for(int multiplicand = 10; multiplicand < 100; multiplicand++) {
        for(int multiplier = 100; multiplier < 1000; multiplier++) {
            int product = multiplicand * multiplier;
            if(is_pandigital(multiplicand, multiplier, product)) {
                cout << multiplicand << " * " << multiplier << " = " << product << endl;
                sum += product;
            }
        }
    }

    cout << "\nSum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital is: " << sum;

    return 0;
}