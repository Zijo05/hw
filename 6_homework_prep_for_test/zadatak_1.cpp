#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float num1;
    float num2;

    cout << "Enter num1: ";
    cin >> num1;

    cout << "Enter num2: ";
    cin >> num2;

    float* ptr1 = &num1;
    float* ptr2 = &num2;
    
    float sum_of_squares = pow(*ptr1, 2) + pow(*ptr2, 2);

    cout << "Diagonal of a rectangle: " << sqrt(sum_of_squares);

    return 0;
}