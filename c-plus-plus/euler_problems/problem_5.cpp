// https://projecteuler.net/problem=5

#include <iostream>

using namespace std;

int main() {
    bool evenly_divisible = 0;
    for(int i = 20; i > 0; i++) {
        for(int j = 1; j <= 20; j++){
            if (i % j != 0) {
                evenly_divisible = 0;
                break;
            }
        }

        if(evenly_divisible) {
            cout << i << " is the smallest evenly divisible number by all of the numbers from 1 to 20";
            return 0;
        }

        evenly_divisible = 1;
    }

    return 0;
}