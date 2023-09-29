/*
Neka nam je data formula za računanje volumen cilindra
V = pi * r^2 *  h
pri čemu je h visina, a r poluprečnik baze. Napisati program koji će korisnik unijeti realne
dimenzije cilindra kroz pokazivače, spasiti rezultat kroz pokazivač, te ispisati volumen
cilindra.
*/

#include <iostream>

using namespace std;

double const PI = 3.14;

int main() {
    double* height = new double;
    double* radius = new double;

    cout << "Enter height of cylinder (cm): ";
    cin >> *height;
    cout << "Enter radius of cylinder (cm): ";
    cin >> *radius;
    
    double* volume = new double;

    *volume = PI * *radius * *radius * *height;

    cout << "Volume of cylinder is " << volume << " cm^3";

    delete height;
    delete radius;
    delete volume;

    return 0;
}