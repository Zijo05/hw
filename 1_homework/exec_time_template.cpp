#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
    //start timer
    auto start = high_resolution_clock::now();

    //stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nExecution time: "<< duration.count() << " microseconds";

    return 0;
}