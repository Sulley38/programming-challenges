#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed); cout.precision(2);
    double X1, Y1, X2, Y2, X3, Y3;
    while( cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 ) {
        // Resolviendo un sistema con los tres puntos se halla la ecuacion de la parabola
        double M1 = X1*X1, M2 = X2*X2, M3 = X3*X3;
        double DetM = M1*X2 + M2*X3 + M3*X1 - M3*X2 - M2*X1 - M1*X3,
               DetA = Y1*X2 + Y2*X3 + Y3*X1 - Y3*X2 - Y2*X1 - Y1*X3,
               DetB = M1*Y2 + M2*Y3 + M3*Y1 - M3*Y2 - M2*Y1 - M1*Y3,
               DetC = M1*X2*Y3 + M2*X3*Y1 + M3*X1*Y2 - M3*X2*Y1 - M2*X1*Y3 - M1*X3*Y2;
        double A = DetA/DetM, B = DetB/DetM, C = DetC/DetM;
        // Resolver X para AX^2 + BX + C = 0
        double Disc = B*B - 4*A*C;
        if( Disc > 0 ) {
            double R = sqrt(Disc);
            double Sol1 = (-B+R)/(2*A), Sol2 = (-B-R)/(2*A);
            cout << abs(Sol2 - Sol1) << endl;
        } else if( Disc == 0 ) {
            double Sol = (-B+sqrt(Disc))/(2*A);
            cout << Sol << endl;
        } else {
            cout << "Error!" << endl; // Nunca deberia ejecutarse
        }
    }
    return 0;
}
