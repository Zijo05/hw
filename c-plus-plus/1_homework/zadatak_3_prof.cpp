
#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    int sum = 0;
    int other_sum = 0;

    for(int i = 0; i <= n; i++) {
        if(i % 3 == 0 && i % 5 == 0)
            other_sum += i;
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    cout << "Result of sum - other_sum: " << sum - other_sum << endl;
    
    return 0;
}