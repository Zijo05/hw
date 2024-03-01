#include<iostream>

using namespace std;

bool isPrime(int n) {
	if(n == 1)
		return false;
	else if(n == 2)
		return true;

	for(int i = 2; i < n; i++){
		if(n % i == 0)
			return false;
	}

	return true;
}

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;

    // BONUS
    for(int i = 0; i <=n; i++) {
        if(isPrime(i))
            cout << i << endl;
    }

	return 0;
}
