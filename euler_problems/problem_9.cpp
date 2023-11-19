// https://projecteuler.net/problem=9

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for(int a = 1; a < 1000; a++){
        for(int b = a + 1; b < 1000; b++){
            double c = sqrt( pow(a, 2) + pow(b, 2) );
            if(a + b + c == 1000) {
                cout << "Pythagorean triplet is: " << a << "^2 + " << b << "^2 = " << c << "^2" << endl;
                cout << "Product abc is: " << a * b * c;
                return 0;
            }
        }
    }

    return 0;
}