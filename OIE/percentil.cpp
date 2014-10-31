#include <iostream>
#include <vector>

using namespace std;

int main()
{
    float fNumeros, fPreguntas, fPercentil;
    cin >> fNumeros;

    vector<float> vNumeros( fNumeros );
    for( int i = 0; i < fNumeros; i++ )
        cin >> vNumeros[i];

    cin >> fPreguntas;
    while( fPreguntas-- ) {
        cin >> fPercentil;

        if( fPercentil == 0.0 ) {
            cout << vNumeros[0] << endl;
        } else if( fPercentil == 100.0 ) {
            cout << vNumeros[fNumeros-1] << endl;
        } else {
            fPercentil = fPercentil * fNumeros / 100;
            for( float j = 0.0; j < fNumeros; j++ ) {
                if( fPercentil == j ) {
                    cout << ( vNumeros[j-1] + vNumeros[j] )/2 << endl;
                    j = fNumeros;
                } else if( fPercentil > j && fPercentil < j+1 ) {
                    cout << vNumeros[j] << endl;
                    j = fNumeros;
                }
            }
        }
    }

    return 0;
}
