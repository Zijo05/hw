/*
Kvadriranjem broja 2 (2, 4, 8, 16, 32, 64, ...) dobijamo broj koji ima barem jednu cifru djeljivu
sa 2. Potrebno je pronaći stepen koji je rezultat kvadriranjem broja 2 koja nema niti jednu cifru
djeljivu sa 2.
*/

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int CharToInt(char character) {
    return character - '0';
}


int main() {
    int tajBroj = 0;
    string broj;
    bool isTajBroj = false;
    for(int i = 0; tajBroj == 0; i++){
        broj = to_string(int(pow(2, i)));
        
        for(int j = 0; j < size(broj); j++){
            if(broj[j] == '1' || broj[j] == '2' || broj[j] == '4' || broj[j] == '8'){
                isTajBroj = false;
                break;
            }
            else
                isTajBroj = true;
        }

        if(isTajBroj){
            break;
        }
    }

    cout << "Taj broj je: " << broj;

    return 0;
}