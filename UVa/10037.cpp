#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int casos, n;
	cin >> casos;
	while( casos-- ) {

		cin >> n;
		// Leer entrada
		vector<int> Tiempos(n);
		for( int i = 0; i < n; ++i )
			cin >> Tiempos[i];
		// Ordenar los tiempos
		sort( Tiempos.begin(), Tiempos.end() );
		// Calcular el resultado
		if( n == 1 ) {
			// Caso especial: solo 1 persona
			cout << Tiempos[0] << endl << Tiempos[0] << endl;
		} else {
			vector<int> Resultado;
			int TiempoTotal = 0, aCruzar = n-1;
			bool TodosHanCruzado = false;
			while( !TodosHanCruzado ) {
				if( Tiempos[aCruzar-1] + Tiempos[0] < 2*Tiempos[1] ) {
					// MÉTODO UNO

					// Cruzan el más y el menos rápido
					Resultado.push_back(Tiempos[0]);
					Resultado.push_back(Tiempos[aCruzar]);
					TiempoTotal += Tiempos[aCruzar];
					// Si no se ha terminado
					if( aCruzar > 1 ) {
						// Vuelve el más rápido
						Resultado.push_back(Tiempos[0]);
						TiempoTotal += Tiempos[0];
						// Se lleva al segundo menos rápido
						Resultado.push_back(Tiempos[0]);
						Resultado.push_back(Tiempos[aCruzar-1]);
						TiempoTotal += Tiempos[aCruzar-1];
						aCruzar -= 2;
						// Si no ha terminado, vuelve el más rápido otra vez
						if( aCruzar > 0 ) {
							Resultado.push_back(Tiempos[0]);
							TiempoTotal += Tiempos[0];
						} else {
							TodosHanCruzado = true;
						}

					} else {
						TodosHanCruzado = true;
					}

				} else {
					// MÉTODO DOS

					// Cruzan los dos más rápidos
					Resultado.push_back(Tiempos[0]);
					Resultado.push_back(Tiempos[1]);
					TiempoTotal += Tiempos[1];
					// Si no se ha terminado
					if( aCruzar > 1 ) {
						// Vuelve el más rápido
						Resultado.push_back(Tiempos[0]);
						TiempoTotal += Tiempos[0];
						// Lleva a los dos más lentos, o el que queda y el rápido
						if( aCruzar > 2 ) {
							Resultado.push_back(Tiempos[aCruzar-1]);
							Resultado.push_back(Tiempos[aCruzar]);
							TiempoTotal += Tiempos[aCruzar];
							aCruzar -= 2;
							// Vuelve el segundo más rápido, y repetir el proceso
							Resultado.push_back(Tiempos[1]);
							TiempoTotal += Tiempos[1];
						} else {
							Resultado.push_back(Tiempos[0]);
							Resultado.push_back(Tiempos[aCruzar]); // aCruzar == 2
							TiempoTotal += Tiempos[aCruzar]; // aCruzar == 2
							TodosHanCruzado = true;
						}
					} else {
						TodosHanCruzado = true;
					}

				}
			}
			// Imprime el resultado
			cout << TiempoTotal << endl;
			for( int i = 0; i < int(Resultado.size()); ++i ) {
				if( i % 3 == 0 ) cout << Resultado[i] << " ";
				else cout << Resultado[i] << endl;
			}
		}

		// Línea en blanco para separar casos
		if( casos > 0 )
			cout << endl;

	}

	return 0;
}
