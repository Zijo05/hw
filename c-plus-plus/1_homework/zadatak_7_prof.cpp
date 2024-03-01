#include<iostream>

using namespace std;

int main() {
	int n;

	cout << "Enter n: ";
	cin >> n;

	for(int i = 0; i < n + 1; i++) {
		for(int j = i; j < n + 1; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}
