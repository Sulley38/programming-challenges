
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;
typedef map<char,char> Equivalencia;

// Variables de entrada y diccionario
int NumPalabras;
vector<string> Palabras;
vector< vector<string> > Diccionario( 16, vector<string>() );
vector<int> TamDiccionario(16);
Equivalencia Asteriscos;


// Obtiene las palabras de la línea de entrada y las guarda en el vector Palabras ordenadas por longitud decreciente
bool orden( const string& a, const string& b ) { return a.length() > b.length(); }
void ExtraerPalabras( const string& S ) {
	NumPalabras = 0;
	Palabras.clear();

	string s;
	istringstream iss(S);
	while( iss >> s ) {
		Palabras.push_back(s);
		NumPalabras++;
	}
	sort( Palabras.begin(), Palabras.end(), orden );
}

// Devuelve una clave de descodificación compuesta por asteriscos
void LlenarAsteriscos() {
	for( char c = 'a'; c <= 'z'; ++c )
		Asteriscos[c] = '*';
}

// Comprueba si es posible la descodificación de la N-ésima palabra de 'in' con la palabra I del diccionario y las claves Encriptar y Desencriptar
// En caso de serlo, devuelve la clave de descodificación
Equivalencia BuscarCoincidencia( const int N, const int I, Equivalencia Encriptar, Equivalencia Desencriptar ) {
	// Si no hay más palabras, es solución
	if( N > NumPalabras ) {
		return Desencriptar;
	} else {
		string PalEncriptada = Palabras[N-1];
		int LongitudPalabra = PalEncriptada.length();
		// Si se han agotado las opciones, no hay solución
		if( I > TamDiccionario[LongitudPalabra-1] ) {
			return Asteriscos;
		} else {
			string PalDesencriptada = Diccionario[LongitudPalabra-1][I-1];
			Equivalencia EncriptarOriginal = Encriptar, DesencriptarOriginal = Desencriptar;
			// Comprueba que cumpla los requisitos
			bool Posible = true;
			for( int i = 0; i < LongitudPalabra; ++i ) {
				if( (Desencriptar.count(PalEncriptada[i]) > 0 && Desencriptar[PalEncriptada[i]] != PalDesencriptada[i]) ||
					(Encriptar.count(PalDesencriptada[i]) > 0 && Encriptar[PalDesencriptada[i]] != PalEncriptada[i])	) {
					Posible = false;
				} else {
					Desencriptar[PalEncriptada[i]] = PalDesencriptada[i];
					Encriptar[PalDesencriptada[i]] = PalEncriptada[i];
				}
			}
			// Avanza a la siguiente palabra o prueba con otra opción del diccionario
			if( Posible ) {
				Equivalencia Res = BuscarCoincidencia( N+1, 1, Encriptar, Desencriptar );
				// Si no ha habido posibilidad, probar otra palabra
				if( I < TamDiccionario[LongitudPalabra-1] && Res['a'] == '*' ) {
					return BuscarCoincidencia( N, I+1, EncriptarOriginal, DesencriptarOriginal );;
				} else {
					return Res;
				}
			} else {
				return BuscarCoincidencia( N, I+1, EncriptarOriginal, DesencriptarOriginal );
			}
		}
	}
}

int main() {
	// Inicializar
	Equivalencia Alf1, Alf2;
	LlenarAsteriscos();
	// Lee la entrada
	int Palabras;
	cin >> Palabras;
	// Lee el diccionario
	string in;
	set<string> Leidas;
	while( Palabras-- ) {
		cin >> in;
		if( Leidas.count(in) == 0 ) {
			Diccionario[in.length()-1].push_back(in);
			Leidas.insert(in);
		}
	}
	for( int i = 0; i < 16; ++i )
		TamDiccionario[i] = Diccionario[i].size();
	cin.ignore(1);
	// Procesa las líneas codificadas
	while( getline( cin, in ) ) {
		ExtraerPalabras(in);
		Alf2 = BuscarCoincidencia( 1, 1, Alf1, Alf2 );
		// Aplica la descodificación obtenida
		for( int i = 0; i < int(in.size()); ++i )
			if( in[i] != ' ' ) in[i] = Alf2[in[i]];
		cout << in << endl;
		Alf1.clear();
		Alf2.clear();
	}

	return 0;
}
