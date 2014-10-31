#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;
typedef map<int,int>::iterator Iterador;

void DarFormato( ostringstream& o1, ostringstream& o2, const Iterador& it, const bool& Mas )
{
    o2 << it->first;
    for( int i = o1.str().size(); i < int(o2.str().size()); i++ ) o1 << " ";
    if( it->second != 1 ) o1 << it->second;
    for( int i = o2.str().size(); i < int(o1.str().size()); i++ ) o2 << " ";
    if( Mas ) o2 << " x ";
}

int main()
{
    // Lee la entrada
    int iCasos;
    string s;
    cin >> iCasos >> s;

    vector<int> Divisores;
    while( iCasos-- ) {
        int n, Numero, Prueba = 2;
        cin >> n;
        Numero = n;
        // Obtiene los divisores primos
        while( Prueba*Prueba <= n && n != 1 ){
            if( n % Prueba == 0 ) {
                Divisores.push_back(Prueba);
                n /= Prueba;
            } else {
                Prueba++;
            }
        }
        if( n != 1 ) Divisores.push_back(n); // Queda el ultimo factor
        // Formatea
        int Tam = Divisores.size();
        if( s == "NORMAL" ) {
            for( int i = 0; i < Tam-1; i++ ) cout <<  Divisores[i] << ",";
            cout << Divisores[Tam-1] << "." << endl;
        } else {
            map<int,int> Apariciones;
            for( int i = 0; i < Tam; i++ ) Apariciones[Divisores[i]]++;

            ostringstream oss, oss2;
            oss2 << Numero << " = ";
            Iterador it = Apariciones.end();
            it--;
            while( it != Apariciones.begin() ) {
                DarFormato( oss, oss2, it, true );
                it--;
            }
            DarFormato( oss, oss2, it, false );
            cout << oss.str() << "|" << endl;
            cout << oss2.str() << "|" << endl;
        }


        Divisores.clear();
    }

    return 0;
}
