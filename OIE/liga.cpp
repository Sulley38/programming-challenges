#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore(1);
    for( int a = 0; a < N; ++a ) {
        int A = -1, B = -1, C = -1, D = -1, E = -1, Tam;
        // Lee la entrada, si no es desconocida
        string s;
        getline( cin, s );
        Tam = s.size();
        for( int i = 0; i < Tam; ++i )
            if( s[i] == '?' ) {
                s[i] = '1';
                s.insert( i, "-" );
                Tam = s.size();
            }
        stringstream ss(s);
        ss >> A >> B >> C >> D >> E;
        // Si A y D son desconocidos, D tiene que ser 0 para que haya una única solucion
        if( A == -1 && D == -1 ) D = 0;
        // Si faltan B o C, probar combinaciones que encajen
        if( B == -1 || C == -1 ) {
            for( int i = 0; i <= 100; ++i ) {
                for( int j = 0; j <= 100; ++j ) {
                    int A2 = A, B2 = B, C2 = C, D2 = D, E2 = E;
                    if( B == -1 ) B2 = i;
                    if( C == -1 ) C2 = j;

                    if( A == -1 ) A2 = B2+C2+D2;
                    if( D == -1 ) D2 = A2-B2-C2;
                    if( E == -1 ) E2 = 3*B2+C2;
                    // Si cumple las condiciones y no supera los límites
                    if( A2 == B2+C2+D2 && B2 == A2-C2-D2 && C2 == A2-B2-D2 && D2 == A2-B2-C2 && E2 == 3*B2+C2 &&
                        A2 >= 0 && A2 <= 100 && B2 >= 0 && B2 <= 100 && C2 >= 0 && C2 <= 100 && D2 >= 0 && D2 <= 100 && E2 >= 0 && E2 <= 300 ) {
                        A = A2; B = B2; C = C2; D = D2; E = E2;
                        i = 101;
                        j = 101;
                    }
                }
            }
        } else {
            if( A == -1 ) A = B+C+D;
            if( D == -1 ) D = A-B-C;
            if( E == -1 ) E = 3*B+C;
        }

        cout << A << " " << B << " " << C << " " << D << " " << E << endl;
    }
    return 0;
}
