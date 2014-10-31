#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Redondear( float& F ) { F = (int)((float)(F*10.0)+0.5)/10.0; }

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int N, S, T, i, j;
	cin >> N;

	cout << "MAKING THE GRADE OUTPUT" << endl;
	while( N-- ) {
		cin >> S >> T;
		vector< vector<int> > Estudiantes( S, vector<int>(T+2) );
		for( i = 0; i < S; ++i )
			for( j = 0; j < T+2; ++j )
				cin >> Estudiantes[i][j];

		// Eliminar el test de menor puntuación si T > 2
		if( T > 2 ) {
			for( i = 0; i < S; ++i ) {
				int menor = 0;
				for( j = 1; j < T; ++j ) {
					if( Estudiantes[i][j] < Estudiantes[i][menor] )
						menor = j;
				}
				Estudiantes[i][menor] = 0;
			}
		}

		// Media de cada estudiante
		vector<float> Medias(S,0.0);
		for( i = 0; i < S; ++i ) {
			for( j = 0; j < T; ++j )
				Medias[i] += Estudiantes[i][j];
			if( T > 2 ) Medias[i] /= T-1;
			else Medias[i] /= T;
			Redondear(Medias[i]);
		}

		// Media de la clase
		float MediaClase = 0.0;
		for( i = 0; i < S; ++i )
			MediaClase += Medias[i];
		MediaClase /= S;
		Redondear( MediaClase );

		// Desviación estándar de la claaaclaclaclasdgmf (Jiménez)
		float DEClase, suma = 0.0;
		for( i = 0; i < S; ++i )
			suma += (Medias[i] - MediaClase)*(Medias[i] - MediaClase);
		DEClase = sqrt( suma / S );
		Redondear(DEClase);
		if( DEClase < 1.0 ) DEClase = 1.0;

		// Bonus points
		for( i = 0; i < S; ++i )
			Medias[i] += (Estudiantes[i][T] / 2)*3.0;

		// Nota de cada alumno
		vector<int> Nota(S);
		for( i = 0; i < S; ++i ) {
			if( Medias[i] >= MediaClase + DEClase ) Nota[i] = 0;
			else if( Medias[i] >= MediaClase ) Nota[i] = 1;
			else if( Medias[i] >= MediaClase - DEClase ) Nota[i] = 2;
			else Nota[i] = 3;
		}

		// Ausencias
		for( i = 0; i < S; ++i ) {
			Nota[i] += Estudiantes[i][T+1] / 4;
			if( Estudiantes[i][T+1] == 0 )
				Nota[i]--;
			if( Nota[i] < 0 ) Nota[i] = 0;
			else if( Nota[i] > 4 ) Nota[i] = 4;
		}

		// Puntuación media de la clase
		float PuntuacionFinal = 0.0;
		for( i = 0; i < S; ++i )
			PuntuacionFinal += 4 - Nota[i];
		PuntuacionFinal /= S;
		Redondear(PuntuacionFinal);

		if( (int)(PuntuacionFinal*10) % 10 == 0 )
			cout << PuntuacionFinal << ".0" << endl;
		else
			cout << PuntuacionFinal << endl;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}
