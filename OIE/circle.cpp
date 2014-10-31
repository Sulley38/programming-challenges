#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double S;
    while( cin >> S ) {
        int K = 0;
        double raiz = sqrt( S ), entero;

        for( int Y = 1; Y <= floor( raiz ); Y++ )
            if( modf( sqrt( S - Y*Y ), &entero ) == 0.0 ) K++;

        cout << K*4 << endl;
    }

    return 0;
}
