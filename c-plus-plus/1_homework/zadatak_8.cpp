/*
Napraviti klasu ComplexNumber, koja će čuvati informaciju o realnoj i imaginarnoj
komponenti broja. Definisati operacije sabiranja, oduzimanja i množenja dva kompleksna broja.
Zatim, u glavnom programu potrebno je omogućiti unos korisnika u obliku a + bi i u sljedećoj linij
c + di, pri čemu pravi dvije varijable tipa ComplexNumber i zatim ispisuje rezultate zbira, razlike i
proizvoda dva kompleksna broja.

Primjer:
3 + 4i
-2 - 5i

Zbir: 1 - 1i
Razlika: 5 + 9i
Proizvod: 4 - 19i

BONUS: Napraviti funkciju conjugate koja će vratiti konjugovani kompleksni broj
BONUS: Napraviti funkciju koja će izračunati njihov količnik, te ispisati u glavnom programu
BONUS: Napraviti funkciju koja računa (a + bi)^n
BONUS: Napraviti funkciju koja računa modul kompleksnog broja
BONUS: Napraviti funkciju polar koja vraća string oblik kompleksnog broja u polarnom formatu
*/

#include <iostream>
#include <vector>

using namespace std;


class ComplexNumber{
    private:
        int real;
        char prefix;
        string imag;
    
    public:
        ComplexNumber(int realPart, char pref, string imagPart){
            real = realPart;
            prefix = pref;
            imag = imagPart;
        }

        int getReal(){
            return real;
        }

        int getImag(){
            if(prefix == '+')
                return stoi(imag);
            else
                return -stoi(imag);
        }
};

//(a + ib) (c + id) = (ac - bd) + i(ad + bc)
void multiplyComplexNumbers(ComplexNumber broj, ComplexNumber broj2){
    int realResult = broj.getReal()*broj2.getReal() - broj.getImag()*broj2.getImag();

    int imagResult = broj.getReal()*broj2.getImag() + broj.getImag()*broj2.getReal();
    
    cout << realResult << imagResult << "i";
}

void addComplexNumbers(ComplexNumber broj, ComplexNumber broj2){
    int realResult = broj.getReal() + broj2.getReal();

    int imagResult = broj2.getImag() + broj2.getImag();

    cout << realResult << imagResult << "i";
}

void subtractComplexNumbers(ComplexNumber broj, ComplexNumber broj2){
    int realResult = broj.getReal() - broj2.getReal();

    int imagResult = broj2.getImag() - broj2.getImag();
    
    cout << realResult << imagResult << "i";
}

int main() {
    vector<ComplexNumber> brojevi, rjesenja;
    int realniDio[2];
    char prefixDio[2];
    string imaginardniDio[2];

    cout << "Prvi kompleksni broj: ";
    cin >> realniDio[1] >> prefixDio[1] >> imaginardniDio[1];
    brojevi.push_back(ComplexNumber(realniDio[1], prefixDio[1], imaginardniDio[1]));

    cout << "Drugi kompleksni broj: ";
    cin >> realniDio[2] >> prefixDio[2] >> imaginardniDio[2];
    brojevi.push_back(ComplexNumber(realniDio[2], prefixDio[2], imaginardniDio[2]));

    cout << "Zbir: ";
    addComplexNumbers(brojevi.at(0), brojevi.at(1));

    return 0;
}