#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
    long long int sum=0, n;
	cin>>n;

    //start timer
    auto start = high_resolution_clock::now();

    for(long long int i=0;i<=n;i++){
        if(i%3==0||i%5==0)
            sum+=i;
        }
    
    cout<<sum;


    //stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function : "<< duration.count() << " ms";

    return 0;
}