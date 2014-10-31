#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Devuelve la posición de S en V, o -1 si no se encuentra
int buscar( const vector<string>& V, const string& S ) {
	for( unsigned int i = 0; i < V.size(); ++i )
		if( V[i] == S ) return i;
	return -1;
}

// Devuelve true si a y b forman un doblete (se diferencian en una sola letra)
bool esDoblete( const string& a, const string& b ) {
	bool dif = false;
	for( unsigned int i = 0; i < a.length(); ++i ) {
		if( a[i] != b[i] && !dif ) dif = true;
		else if( a[i] != b[i] && dif ) return false;
	}
	return dif;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s, a, b;
	vector< vector<string> > palabras(17,vector<string>());
	// Leer diccionario
	while( getline(cin,s) && !s.empty() )
		palabras[s.size()].push_back(s);

	// Parejas de palabras
	int tamA = -1, tamB, posA, posB, posT, i;
	while( cin >> a >> b ) {
		if( tamA > 0 ) cout << endl;
		// Comprobar requisitos de longitud y existencia
		tamA = a.length();
		tamB = b.length();
		if( tamA == tamB ) {
			posA = buscar(palabras[tamA],a);
			posB = buscar(palabras[tamB],b);
			if( posA != -1 && posB != -1 ) {
				// BFS para ver si hay camino
				// Los pasos se guardan en 'anterior'
				vector<int> anterior( palabras[tamA].size(), -1 );
				anterior[posA] = posA;
				queue<int> cola;
				cola.push(posA);
				while( !cola.empty() ) {
					posT = cola.front();
					cola.pop();
					for( i = 0; i < int(palabras[tamA].size()); ++i ) {
						if( anterior[i] == -1 && esDoblete(palabras[tamA][posT],palabras[tamA][i]) ) {
							// Posible camino, insertar en la cola
							anterior[i] = posT;
							cola.push(i);
						}
					}
				}

				if( anterior[posB] != -1 ) {
					// Desde anterior[posB] hasta anterior[posA] es la solución
					vector<int> solucion;
					i = posB;
					while( i != posA ) {
						solucion.push_back(i);
						i = anterior[i];
					}
					// Imprimir el resultado
					cout << a << endl;
					for( vector<int>::reverse_iterator it = solucion.rbegin(); it != solucion.rend(); ++it )
						cout << palabras[tamA][*it] << endl;

				} else {
					cout << "No solution." << endl;
				}
			} else {
				cout << "No solution." << endl;
			}
		} else {
			cout << "No solution." << endl;
		}

	}

	return 0;
}
