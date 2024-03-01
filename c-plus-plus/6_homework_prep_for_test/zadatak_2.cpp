#include <iostream>
#include <cmath>

using namespace std;

struct Tacka {
    double x;
    double y;
};

int main() {
    Tacka tacka_1, tacka_2;

    cout << "x1: ";
    cin >> tacka_1.x;

    cout << "y1: ";
    cin >> tacka_1.y;

    cout << "x2: ";
    cin >> tacka_2.x;

    cout << "y2: ";
    cin >> tacka_2.y;

    double absolute_difference_x = abs(tacka_1.x - tacka_2.x);
    double absolute_difference_y = abs(tacka_1.y - tacka_2.y);
    double manhattan_distance = absolute_difference_x + absolute_difference_y;

    cout << "Manhattan distanca: " << manhattan_distance;

    return 0;
}