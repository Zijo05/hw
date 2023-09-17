#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
    long long int sum=0, n;
	cin>>n;

    for(long long int i=0;i<=n;i++){
        if(i%3==0||i%5==0)
            sum+=i;
        }

    cout<<sum;
    
    return 0;
}