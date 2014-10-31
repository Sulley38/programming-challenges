#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void Voltear( vector<int>& Pila, int Posicion ) {
	int aux;
	for( unsigned int i = 0; i < (Pila.size() - Posicion + 1)/2; ++i  ) {
		aux = Pila[i];
		Pila[i] = Pila[Pila.size()-Posicion-i];
		Pila[Pila.size()-Posicion-i] = aux;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	string s;
	while( getline(cin,s) ) {
		// Leer la entrada
		stringstream ss(s);
		vector<int> Tortitas, Resultado;
		unsigned int diametro, i;
		while( ss >> diametro ) Tortitas.push_back(diametro);
		// Imprime la situación inicial
		for( i = 0; i < Tortitas.size()-1; ++i )
			cout << Tortitas[i] << " ";
		cout << Tortitas[i] << endl;
		// Ordenar las tortitas
		vector<int> TortitasOrdenadas = Tortitas;
		sort( TortitasOrdenadas.begin(), TortitasOrdenadas.end() );
		// Procesa la pila de tortitas
		for( int j = TortitasOrdenadas.size()-1; j >= 0; --j ) {
			// Poner en su sitio las tortitas, empezando por la mayor: llevar arriba, y voltear la pila
			if( Tortitas[j] != TortitasOrdenadas[j] ) {
				int index = 0;
				while( Tortitas[index] != TortitasOrdenadas[j] )
					index++;

				if( index > 0 ) {
					// Llevarlo arriba
					Voltear(Tortitas,Tortitas.size()-index);
					Resultado.push_back(Tortitas.size()-index);
				}
				// Voltear la parte no ordenada de la pila
				Voltear(Tortitas,Tortitas.size()-j);
				Resultado.push_back(Tortitas.size()-j);
			}
		}

		for( i = 0; i < Resultado.size(); ++i )
			cout << Resultado[i] << " ";
		cout << "0" << endl;
	}


	return 0;
}
