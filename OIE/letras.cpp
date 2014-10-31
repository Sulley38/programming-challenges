#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int iLongDiccionario = 0;
    cin >> iLongDiccionario;

    vector<string> vDiccionario;
    string Palabra;
    for( int i = 0; i < iLongDiccionario; i++ ) {
        cin >> Palabra;
        for( int j = 0; j < int(Palabra.length()); j++ )
            Palabra[j] = toupper( Palabra[j] );
        vDiccionario.push_back( Palabra );
    }

    int iCasos = 0;
    cin >> iCasos;
    for( int i = 0; i < iCasos; i++ ) {
        string LetrasOrg, Mayor;
        cin >> LetrasOrg;

        for( int j = 0; j < iLongDiccionario; j++ ) {
            int iLength = vDiccionario[j].size();
            string Letras = LetrasOrg;
            for( int k = 0; k < iLength; k++ ) {
                size_t stPos = Letras.find( vDiccionario[j][k] );
                if( stPos == string::npos ) {
                    k = iLength;
                } else {
                    Letras[stPos] = '0';
                }
                if( k == iLength-1 && iLength > int(Mayor.size()) ) {
                    Mayor = vDiccionario[j];
                }
            }
        }

        cout << Mayor << endl;
    }

    return 0;
}
