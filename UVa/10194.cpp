#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

struct DatosEquipo {
	string Nombre;
	int Puntos, Victorias, Empates, Derrotas, GMarcados, GEncajados;
	// Partidos jugados = Victorias + Empates + Derrotas
	// Diferencia de goles = GMarcados - GEncajados
};

bool Menor( const string& a, const string& b ) {
	unsigned int k;
	string A = a, B = b;
	for( k = 0; k < A.length(); ++k )
		if( A[k] >= 65 && A[k] <= 90 )
			A[k] +=32;
	for( k = 0; k < B.length(); ++k )
		if( B[k] >= 65 && B[k] <= 90 )
			B[k] +=32;
	return A < B;
}

bool Criterio( const DatosEquipo& a, const DatosEquipo& b) {
	if( a.Puntos == b.Puntos ) {
		if( a.Victorias == b.Victorias ) {
			if( a.GMarcados - a.GEncajados == b.GMarcados - b.GEncajados ) {
				if( a.GMarcados == b.GMarcados ) {
					if( a.Victorias + a.Empates + a.Derrotas == b.Victorias + b.Empates + b.Derrotas )
						return Menor( a.Nombre, b.Nombre );
					return a.Victorias + a.Empates + a.Derrotas < b.Victorias + b.Empates + b.Derrotas;
				}
				return a.GMarcados > b.GMarcados;
			}
			return a.GMarcados - a.GEncajados > b.GMarcados - b.GEncajados;
		}
		return a.Victorias > b.Victorias;
	}
	return a.Puntos > b.Puntos;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif

	int N, T, G, i, pos, g1, g2, id1, id2;
	string Torneo, s, e1, e2;

	cin >> N;
	cin.ignore();
	while( N-- ) {
		getline(cin,Torneo);

		cin >> T;
		cin.ignore();

		// Leer nombres de equipos e inicializar datos
		map<string,int> IDEquipo;
		vector<DatosEquipo> Equipos(T);
		for( i = 0; i < T; ++i ) {
			getline(cin,s);
			IDEquipo[s] = i;
			Equipos[i].Nombre = s;
			Equipos[i].Puntos = 0;
			Equipos[i].Victorias = 0;
			Equipos[i].Empates = 0;
			Equipos[i].Derrotas = 0;
			Equipos[i].GMarcados = 0;
			Equipos[i].GEncajados = 0;
		}

		cin >> G;
		cin.ignore();

		for( i = 0; i < G; ++i ) {
			// Leer resultados de partidos
			getline(cin,s);
			pos = s.find('#');
			e1 = s.substr(0,pos); // Equipo A
			id1 = IDEquipo[e1];
			pos++; // #
			g1 = s[pos]-'0';
			pos++;
			if( s[pos] != '@' ) {
				g1 = 10*g1 + s[pos]-'0';
				pos++;
			}
			pos++; // @
			g2 = s[pos]-'0';
			pos++;
			if( s[pos] != '#' ) {
				g2 = 10*g2 + s[pos]-'0';
				pos++;
			}
			pos++; // #
			e2 = s.substr(pos); // Equipo B
			id2 = IDEquipo[e2];

			// Actualizar los datos
			if( g1 > g2 ) { // Victoria Equipo A
				Equipos[id1].Puntos += 3;
				Equipos[id1].Victorias++;
				Equipos[id2].Derrotas++;
			} else if( g2 > g1) { // Victoria Equipo B
				Equipos[id2].Puntos += 3;
				Equipos[id2].Victorias++;
				Equipos[id1].Derrotas++;
			} else { // Empate
				Equipos[id1].Puntos += 1;
				Equipos[id2].Puntos += 1;
				Equipos[id1].Empates++;
				Equipos[id2].Empates++;
			}
			Equipos[id1].GMarcados += g1;
			Equipos[id2].GMarcados += g2;
			Equipos[id1].GEncajados += g2;
			Equipos[id2].GEncajados += g1;
		}

		// Ordenar por los criterios indicados
		sort( Equipos.begin(), Equipos.end(), Criterio );

		// Imprimir el resultado
		cout << Torneo << endl;
		for( i = 0; i < T; ++i ) {
			cout << i+1 << ") " << Equipos[i].Nombre << " " << Equipos[i].Puntos << "p, ";
			cout << Equipos[i].Victorias + Equipos[i].Empates + Equipos[i].Derrotas << "g (";
			cout << Equipos[i].Victorias << "-" << Equipos[i].Empates << "-" << Equipos[i].Derrotas << "), ";
			cout << Equipos[i].GMarcados - Equipos[i].GEncajados << "gd (" << Equipos[i].GMarcados << "-" << Equipos[i].GEncajados << ")" << endl;
		}

		if( N > 0 ) cout << endl;
	}

	return 0;
}
