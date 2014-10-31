#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iCasos;
    cin >> iCasos;
    while( iCasos-- ){
        // Leer la entrada
        int G1, G2;
        cin >> G1;
        vector<int> P1( G1+1 );
        for( int i = 0; i < G1+1; i++ ) cin >> P1[i];
        cin >> G2;
        vector<int> P2( G2+1 );
        for( int i = 0; i < G2+1; i++ ) cin >> P2[i];
        // Calcular el resultado
        vector<int> Res( G1+G2+1 );
        for( int i = G1; i >= 0; i-- ) {
            for( int j = G2; j >= 0; j-- ) {
                Res[i+j] += P1[i]*P2[j];
            }
        }
        // Mostrar en pantalla
        cout << G1+G2 << " ";
        for( int i = 0; i < G1+G2 ; i++ ) cout << Res[i] << " ";
        cout << Res[G1+G2] << endl;
    }
    return 0;
}
