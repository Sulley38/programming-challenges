
#include <iostream>
#include <vector>

#define MAX_LENGTH 2048

using namespace std;

bool Emparejables( const string& Solucion, const vector<string>& F, vector<bool> Emparejado  ) {
	for( int i = 1; i < int(F.size()); ++i ) {
		if( !Emparejado[i] ) {
			Emparejado[i] = true;
			for( int j = i+1; j < int(F.size()); ++j ) {
				if( !Emparejado[j] && (F[i] + F[j] == Solucion || F[j] + F[i] == Solucion ) ) {
					Emparejado[j] = true;
					return Emparejables( Solucion, F, Emparejado );
				}
			}
			return false;
		}
	}
	return true;
}

int main() {
	int Casos;
	cin >> Casos;
	cin.ignore(1);

	string in;
	getline( cin, in ); // Línea en blanco
	while( Casos-- ) {
		vector<string> Fragmento;
		int NumFragmentos = 0, begin, end, min = MAX_LENGTH, max = 0;

		// Leer los fragmentos
		bool Continuar = true;
		getline( cin, in );
		while( !in.empty() && Continuar ) {
			begin = 0;
			end = in.size()-1;
			// 'Trim' fragmento
			while( in[begin] == ' ' ) begin++;
			while( in[end] == ' ' ) end--;
			Fragmento.push_back( in.substr(begin,end-begin+1) );
			NumFragmentos++;

			// Longitud objetivo
			if( end-begin+1 > max ) max = end-begin+1;
			if( end-begin+1 < min ) min = end-begin+1;

			if( cin.eof() ) Continuar = false;
			getline( cin, in );
		}

		// Buscar la pareja del primero y comprobar que el resto se cumple
		string solucion;
		vector<bool> Usado(NumFragmentos,false);
		Usado[0] = true;
		int longitud = min + max, i = 1;
		while( solucion.empty() ) {
			if( Fragmento[0].size() + Fragmento[i].size() == longitud ) {
				// Comprobar si el resto se pueden emparejar igual
				Usado[i] = true;
				if( Emparejables(Fragmento[0]+Fragmento[i],Fragmento,Usado) )
					solucion = Fragmento[0] + Fragmento[i];
				else if( Emparejables(Fragmento[i]+Fragmento[0],Fragmento,Usado) )
					solucion = Fragmento[i] + Fragmento[0];
				Usado[i] = false;
			}
			i++;
		}

		// Imprimir el resultado
		cout << solucion << endl;
		if( Casos > 0 ) cout << endl;
	}
	return 0;
}
