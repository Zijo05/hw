/*
S obzirom da smo uspjeli napraviti program za računanje volumena za cilindar, sada je
potrebno da napravimo i za površinu cilindra. Iskoristiti rješenje iz 2. zadatka i napraviti
funkciju double* cylinder_volume(double* radius, double* height) i double*
cylinder_area(double* radius, double* height) koji računaju i vraćaju volumen i površinu
cilindra, respektivno. Sada kada korisnik unese poluprečnik i visinu u realnim
vrijednostima, program ispisuje volumen i površinu cilindra. NAPOMENA: Površina
cilindra je A = 2*pi*r*h + 2*pi*r^2, pri čemu r je poluprečnik i h visina cilindra
*/

double const PI = 3.14;

#include <iostream>

using namespace std;

double* cylinder_volume(double* radius, double* height){
    double* volume = new double;
    *volume = PI * *radius * *radius * *height;

    return volume;
}

double* cylinder_area(double* radius, double* height){
    double* area = new double;
    *area = 2 * PI * *radius * *height + 2 * PI * *radius * *radius;

    return area;
}


int main() {
    double* height = new double;
    double* radius = new double;

    cout << "Enter height of cylinder (cm): ";
    cin >> *height;
    cout << "Enter radius of cylinder (cm): ";
    cin >> *radius;
    
    double* volume = cylinder_volume(radius, height);
    double* area = cylinder_area(radius, height);

    cout << "Volume of cylinder is " << *volume << " cm^3" << endl;
    cout << "Area of cylinder is " << *area << " cm^2";

    delete height;
    delete radius;
    delete volume;
    delete area;

    return 0;
}