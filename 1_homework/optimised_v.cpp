#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
    long long int sum=0, n;
	cin>>n;

	for(long long int byFive=5;byFive<=n;byFive+=5){
		sum+=byFive;
	}
	for(long long int byThree=3;byThree<=n;byThree+=3){
		sum+=byThree;
	}

	cout<<"Suma prvih "<<n<<" prirodnih brojeva dijeljivih sa 3 i 5 je: "<<sum;

    return 0;
}