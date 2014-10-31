#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// Estructuras de identificación de autores
int UltimoID;
map<string,int> Identificador;

// Lee un artículo de la entrada estándar
vector<int> LeerArticulo() {
	bool fin = false;
	vector<int> leidos;
	string linea, nombre, ap;
	while( !fin ) {
		// Lectura de un pareja apellido + nombre
		cin >> ap >> nombre;
		if( ap.at(ap.size()-1) == ':' ) {
			fin = true;
		} else {
			if( nombre.at(nombre.size()-1) == ':' )
				fin = true;
			// Elimina el caracter delimitador ',' ó ':'
			nombre.erase( nombre.size()-1, 1 );
			// Añade el nombre a la lista
			if( Identificador.count(ap + " " + nombre) == 0 ) {
				Identificador[ap + " " + nombre] = UltimoID;
				UltimoID++;
			}
			leidos.push_back(Identificador[ap + " " + nombre]);
		}
	}
	getline( cin, linea );
	return leidos;
}

int main() {
	int Casos, NumArticulos, NumAutores;
	cin >> Casos;
	// Casos de prueba
	for( int a = 1; a <= Casos; ++a ) {
		cin >> NumArticulos >> NumAutores;
		cin.ignore(1);

		vector< vector<int> > Articulos;
		Identificador.clear();
		UltimoID = 0;

		// Leer artículos
		for( int i = 0; i < NumArticulos; ++i )
			Articulos.push_back( LeerArticulo() );

		vector< vector<bool> > Colaboracion( UltimoID, vector<bool>(UltimoID,false) );
		// Actualiza las listas de colaboradores
		for( int i = 0; i < NumArticulos; ++i ) {
			for( int j = 0; j < int(Articulos[i].size()); ++j ) {
				for( int k = 0; k < int(Articulos[i].size()); ++k ) {
					if( j != k )
						Colaboracion[Articulos[i][j]][Articulos[i][k]] = true;
				}
			}
		}

		// Calcular números de Erdos por BFS
		int curid = Identificador["Erdos, P."];
		vector<int> NumErdos(UltimoID,-1);
		NumErdos[curid] = 0;
		queue<int> Cola;
		Cola.push(curid);
		while( !Cola.empty() ) {
			curid = Cola.front();
			Cola.pop();
			for( int i = 0; i < UltimoID; ++i ) {
				if( Colaboracion[curid][i] && (NumErdos[i] == -1 || NumErdos[i] > NumErdos[curid] + 1) ) {
					NumErdos[i] = NumErdos[curid] + 1;
					Cola.push(i);
				}
			}
		}

		// Imprimir resultado
		cout << "Scenario " << a << endl;
		string nombre, ap;
		int n;
		while( NumAutores-- ) {
			cin >> ap >> nombre;
			// Calcular número
			if( Identificador.count(ap + " " + nombre) ) n = NumErdos[Identificador[ap + " " + nombre]];
			else n = -1;
			if( n < 0 )
				cout << ap << " " << nombre << " infinity" << endl;
			else
				cout << ap << " " << nombre << " " << n << endl;
		}
	}

	return 0;
}
