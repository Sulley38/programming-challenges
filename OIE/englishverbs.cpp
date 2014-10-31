#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int Verbos, Preguntas, Semilla, Index;
    cin >> Verbos >> Preguntas >> Semilla;

    vector<string> V1(Verbos), V2(Verbos), V3(Verbos);
    for( int i = 0; i < Verbos; i++ ) cin >> V1[i] >> V2[i] >> V3[i];

    string a, b;
    while( Preguntas-- ) {
        // Plantea la pregunta
        Semilla = ( 13821*Semilla ) % 32768;
        Index = Semilla % Verbos;
        cout << V1[Index] << "?" << endl;
        // Comprueba si la entrada es correcta
        cin >> a >> b;
        if( a == V2[Index] && b == V3[Index] ) cout << "Ok" << endl;
        else cout << "Wrong: " << V2[Index] << " " << V3[Index] << endl;
    }

    return 0;
}
