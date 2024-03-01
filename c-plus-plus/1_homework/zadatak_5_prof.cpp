#include<iostream>

using namespace std;

bool containsDigitPowerOfTwo(int num) {
    while(num != 0) {
        int digit = num % 10;

        if (digit == 1 || digit == 2 || digit == 4 || digit == 8)
            return true;

        num /= 10;
    }

    return false;
}

int main() {
    int n = 1;
    while(containsDigitPowerOfTwo(n))
          n *= 2;

    cout << n << endl;

    return 0;
}
