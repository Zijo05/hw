/*
Neka je dat niz brojeva 0 i 1 sa maksimalnim kapacitetom 100. Korisnik redom unosi brojeve
0 i 1 sve dok ne unese broj različito od 0 i 1. Udaljenost smatramo koliko je 1 udaljeno od druge
1 ka desnoj strani tako što prebrojimo koliko 0 se nalazi između njih. Na primjer,
10001 će imati udaljenost 3. Program treba da ispiše minimalnu i maksimalnu udaljenost.
Ukoliko nije moguće, ispisati odgovarajuću poruku. (Razumijevanje zadatka, while i for petlje)
*/

#include <iostream>

using namespace std;

int main() {
    int arr[100], num=0, index=0;
    while(num == 0 || num == 1){
        cin >> num;
        if(num == 0 || num == 1){
            arr[index]=num;
            index++;
        }
    }

    int min=99, max=0, udaljenost=0;
    bool jeJedan=false, nijeJedan=true;
    for (int i = 0; i < index; i++){
        if(arr[i] == 1 && nijeJedan){
            jeJedan=true;
            nijeJedan=false;
        }
        else if(jeJedan && arr[i] == 0)
            udaljenost++;
        else if(jeJedan && arr[i] == 1){
            if(min > udaljenost)
                min = udaljenost;
            if(max < udaljenost)
                max = udaljenost;
            udaljenost = 0;
        }
    }

    if(min == 99)
        cout << "Nije moguce naci udaljenost!";
    else
        cout << "Najmanja udaljenost je " << min << ", a najveca " << max <<".";

    return 0;
}