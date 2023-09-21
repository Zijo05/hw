#include<iostream>

using namespace std;

int main() {
    int arr[100];

    int num;
    int length = 0;

    // Upis pomocu do while
    do {
        cout << "Insert number: ";
        cin >> num;

        arr[length++] = num;
    } while(num == 0 || num == 1);

    // Ispis radi manuelne verifikacije unosa
    for(int i = 0; i < length; i++)
        cout << arr[i];

    cout << endl;

    // Kalkulacija udaljenosti
    int min_distance = -1;
    int max_distance = -1;
    int current_distance = 0;
    bool hasOne = false;

    for(int i = 0; i < length; i++) {
        if(hasOne && arr[i] != 1) {
          current_distance++;
        }
        else if(hasOne) {
            if(current_distance <= min_distance || min_distance < 0)
                min_distance = current_distance;
            if(current_distance >= max_distance || max_distance < 0)
                max_distance = current_distance;

            current_distance = 0;
        }

        else if(!hasOne && arr[i] == 1) {
            hasOne = true;
        }
        else
            continue;
    }

    cout << "Min distance: " << min_distance << endl;
    cout << "Max distance: " << max_distance << endl;

    return 0;
}
