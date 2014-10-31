#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Posicion( const string& C, const vector<string>& T ) {
	int pos = 0;
	while( T[pos] != C ) pos++;
	return pos;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int Casos, N, i, j, mayor;
	cin >> Casos;
	while( Casos-- ) {
		cin >> N;
		cin.ignore();
		vector<string> Tortuga(N), TortugaOrdenada(N), Resultado;
		for( i = 0; i < N; ++i )
			getline( cin, Tortuga[i] );
		for( i = 0; i < N; ++i )
			getline( cin, TortugaOrdenada[i] );

		// Buscar las que no están en posición
		i = N-1;
		j = N-1;
		while( i >= 0 ) {
			if( Tortuga[i] == TortugaOrdenada[j] ) {
				i--; j--;
			} else {
				Resultado.push_back( Tortuga[i] );
				i--;
			}
		}

		// Hallar la que está más abajo
		mayor = -1;
		for( i = 0; i < int(Resultado.size()); ++i )
			mayor = max( mayor, Posicion(Resultado[i], TortugaOrdenada) );

		// Imprimir todas desde esa para arriba
		for( i = 0; i <= mayor; ++i )
			cout << TortugaOrdenada[mayor-i] << endl;

		cout << endl;
	}

	return 0;
}
