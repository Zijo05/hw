#include<iostream>
#include<cmath>
 
using namespace std;
 
struct Kruznica {
    double x;
    double y;
    double r;
};
 
 
double udaljenost_kruznica(Kruznica kruznica_1, Kruznica kruznica_2) {
    double x_razlika = pow(kruznica_1.x - kruznica_2.x, 2);
    double y_razlika = pow(kruznica_1.y - kruznica_2.y, 2);
 
    return sqrt(x_razlika + y_razlika);
}
 
double udaljenost_tacaka(double x1, double y1, double x2, double y2) {
    double x_razlika = pow(x1 - x2, 2);
    double y_razlika = pow(y1 - y2, 2);
 
    return sqrt(x_razlika + y_razlika);
}


//2. dodatni zadatak
double zbir_radijusa(Kruznica kruznica_1, Kruznica kruznica_2) {
    return kruznica_1.r + kruznica_2.r;
}

bool se_sijeku(Kruznica kruznica_1, Kruznica kruznica_2) {
    return udaljenost_kruznica(kruznica_1, kruznica_2) <= zbir_radijusa(kruznica_1, kruznica_2);
}


//1. dodatni zadatak
void ispisi_jednacinu_kruznice(Kruznica kruznica) {
    cout << " (x" << -kruznica.x << ")^2 + (y" << -kruznica.y << ")^2 = " << pow(kruznica.r, 2);
}


//3. dodatni zadatak
bool kruznica_sijece_koordinatnu_osu(Kruznica kruznica) {
    if (pow(kruznica.r, 2) >= pow(kruznica.x, 2) && pow(kruznica.r, 2) >= pow(kruznica.y, 2)){
        cout << "Kruznica sijece obje koordinatne ose.";
        return true;
    }
    else if (pow(kruznica.r, 2) >= pow(kruznica.x, 2)){
        cout << "Kruznica sijece x osu.";
        return true;
    }
    else if (pow(kruznica.r, 2) >= pow(kruznica.y, 2)){
        cout << "Kruznica sijece y osu.";
        return true;
    }

    return false;
}


//4. dodatni zadatak 
bool tacka_je_u_kruznici(double x, double y, Kruznica kruznica) {
    if (udaljenost_tacaka(x, y, kruznica.x, kruznica.y) > kruznica.r)
        return false;
    return true;
}


//5. dodatni zadatak
void ispisi_tacke_dodira(double x, double y, Kruznica kruznica) {
    double d = udaljenost_tacaka(x, y, kruznica.x, kruznica.y);

    if (d > kruznica.r) {
        double theta = atan2(y - kruznica.y, x - kruznica.x); // Ugao između (x, y) i centra kruga

        double alpha = acos(kruznica.r / d); // Polu-ugao između radijusa i tangente

        double beta1 = theta + alpha;
        double beta2 = theta - alpha;

        double x_p1 = kruznica.x + kruznica.r * cos(beta1);
        double y_p1 = kruznica.y + kruznica.r * sin(beta1);

        double x_p2 = kruznica.x + kruznica.r * cos(beta2);
        double y_p2 = kruznica.y + kruznica.r * sin(beta2);

        cout << "Tangenta Tacka 1: (" << x_p1 << ", " << y_p1 << ")" << endl;
        cout << "Tangenta Tacka 2: (" << x_p2 << ", " << y_p2 << ")" << endl;
    } else {
        cout << "Tacka je unutar ili na krugu. Nema tacaka dodira." << endl;
    }
}


int main() {
    const int N = 5;
    Kruznica kruznice[N] = {
        {1, 2, 5},
        {3, 6, 10},
        {-2, 3, 7},
        {10, 20, 4},
        {11, 20, 3}
    };
    

    return 0;
}