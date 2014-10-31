#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif

	int n, a, i, j, k;
	while( cin >> n ) {
		if( n == 0 ) break;

		vector< vector<int> > Diferencia( n, vector<int>(n));
		for( i = 0; i < n; ++i )
			cin >> Diferencia[0][i];
		cin >> k;

		// Tabla de diferencias inicial
		for( i = 1; i < n; ++i )
			for( j = 0; j < n-i; ++j )
				Diferencia[i][j] = Diferencia[i-1][j+1] - Diferencia[i-1][j];

		// Guardar la última fila
		vector<int> UltimaDiferencia(n);
		for( i = 0; i < n; ++i )
			UltimaDiferencia[i] = Diferencia[i][n-i-1];
		Diferencia.clear();

		// Computar extrapolación a-ésima
		for( a = 0; a < k; ++a )
			for( i = n-2; i >= 0; --i )
				UltimaDiferencia[i] = UltimaDiferencia[i+1] + UltimaDiferencia[i];

		// Resultado
		cout << "Term " << n+k << " of the sequence is " << UltimaDiferencia[0] << endl;

	}

	return 0;
}
