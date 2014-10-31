
#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

// Estructuras de datos
vector<int> NumResueltos(100);
vector<int> TiempoTotal(100);

bool orden( const int& a, const int& b ) {
	if( NumResueltos[a] == NumResueltos[b] ) {
		if( TiempoTotal[a] == TiempoTotal[b] )
			return a < b;
		else
			return TiempoTotal[a] < TiempoTotal[b];
	} else {
		return NumResueltos[a] > NumResueltos[b];
	}
}

int main() {
	vector< vector<bool> > Resueltos(100, vector<bool>(9) );
	vector< vector<int> > Penalizacion(100, vector<int>(9));
	list<int> Participantes;

	string in;
	istringstream iss;
	char L;
	int Casos, Concursante, Problema, Tiempo;
	cin >> Casos;
	cin.ignore(1);

	getline( cin, in );
	while( Casos-- ) {
		// Inicializar valores
		for( int i = 0; i < 100; ++i ) {
			for( int j = 0; j < 9; ++j ) {
				Resueltos[i][j] = false;
				Penalizacion[i][j] = 0;
			}
			NumResueltos[i] = 0;
			TiempoTotal[i] = 0;
		}
		Participantes.clear();

		bool Continuar = true;
		getline( cin, in );
		while( !in.empty() && Continuar ) {
			// Acumular los datos
			iss.str(in);
			iss >> Concursante >> Problema >> Tiempo >> L;

			Participantes.push_front(Concursante-1); // Ha hecho algún envío
			if( !Resueltos[Concursante-1][Problema-1] ) {
				if( L == 'C' ) {
					Resueltos[Concursante-1][Problema-1] = true;
					NumResueltos[Concursante-1]++;
					TiempoTotal[Concursante-1] += Penalizacion[Concursante-1][Problema-1] + Tiempo;
				} else if( L == 'I' ) {
					Penalizacion[Concursante-1][Problema-1] += 20;
				}
			}

			if( cin.eof() ) Continuar = false;
			getline( cin, in );
		}

		// Ordenar y mostrar los resultados
		Participantes.sort();
		Participantes.unique();
		Participantes.sort(orden);
		for( list<int>::iterator it = Participantes.begin(); it != Participantes.end(); it++ )
			cout << (*it)+1 << " " << NumResueltos[(*it)] << " " << TiempoTotal[(*it)] << endl;
		if( Casos > 0 ) cout << endl;
	}

	return 0;
}
