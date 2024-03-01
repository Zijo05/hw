#include<iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    float sum = 0;

    for(int i = 0; i <= n; i = i + 1) {
        if(i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
