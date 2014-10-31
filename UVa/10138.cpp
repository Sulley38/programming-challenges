#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

struct Foto {
	int Mes, Dia, Hora, Min, Punto;
	string Accion;
	Foto( int M, int D, int H, int Mi, int P, string A) { Mes = M; Dia = D; Hora = H; Min = Mi; Punto = P; Accion = A; }
};

typedef map< string, vector<Foto> > Lista;

bool CriterioOrden( const Foto& a, const Foto& b ) {
	if( a.Mes == b.Mes ) {
		if( a.Dia == b.Dia ) {
			if( a.Hora == b.Hora ) {
				return a.Min < b.Min;
			}
			return a.Hora < b.Hora;
		}
		return a.Dia < b.Dia;
	}
	return a.Mes < b.Mes;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	unsigned int casos, mes, dia, hora, minuto, posicion, i, Precio;
	string s, matricula, accion;

	cin >> casos;
	while(casos--) {
		Lista L;
		// Leer los datos
		vector<int> Tarifas(24);
		for( i = 0; i < 24; ++i )
				cin >> Tarifas[i];

		cin.ignore();
		while( getline(cin,s) ) {
			if( s == "" ) break;

			stringstream ss(s);
			ss >> matricula;
			ss >> mes; ss.ignore();
			ss >> dia; ss.ignore();
			ss >> hora; ss.ignore();
			ss >> minuto;
			ss >> accion;
			ss >> posicion;
			L[matricula].push_back( Foto(mes,dia,hora,minuto,posicion,accion) );
		}

		// Procesar eventos
		for( Lista::iterator it = L.begin(); it != L.end(); it++ ) {
			// Ordenar por fecha
			sort( it->second.begin(), it->second.end(), CriterioOrden );

			// Calcular precios de los viajes
			Precio = 0;
			for( i = 1; i < it->second.size(); ++i ) {
				if( it->second[i].Accion == "exit" && it->second[i-1].Accion == "enter" ) {
					Precio += abs(it->second[i].Punto - it->second[i-1].Punto) * Tarifas[it->second[i-1].Hora];
					Precio += 100; // Dólar extra por viaje
				}
			}

			if( Precio > 0 ) {
				Precio += 200; // Gastos de gestión
				cout << it->first << " $" << Precio / 100 << ".";
				if( Precio % 100 < 10 ) cout << "0";
				cout << Precio % 100 << endl;
			}
		}



		if(casos > 0)
			cout << endl;
	}

	return 0;
}
