// https://projecteuler.net/problem=9

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 1000;
    int a, b;
    double c = 0;

    for(a = 1; a < n; a++){
        for(b = a+1; b < n; b++){
            c = sqrt( pow(a, 2) + pow(b, 2) );
            if(a + b + c == 1000){
                break;
            }
        }
        if(a + b + c == 1000)
                break;
    }

    cout << "Pythagorean triplet is: " << a << "^2 + " << b << "^2 = " << c << "^2" << endl;
    cout << "Product abc is: " << a * b * c;

    return 0;
}