/**
 * 'tiradas' en siempre un entero de 13 bits: 1 representa una tirada ya asignada, 0 lo contrario
 * maxpuntuacion[cat][tiradas] = puntuación máxima que se puede lograr teniendo asignadas
 * las 'cat' primeras categorías, habiendo usado las tiradas que indican los bits a 1 de 'tiradas'
 *   Ejemplo: maxpuntuacion[4][0000101100100] = puntuación máxima que se puede lograr habiendo usado
 *   las categorías de la 1 (unos) a la 4 (cuatros) y las tiradas 3ª, 6ª, 7ª y 9ª
 * ultima_eleccion[cat][tiradas] = indica cuál es el bit de 'tiradas' que se ha encendido al pasar de
 * 'cat-1' categorías asignadas a 'cat' categorías asignadas
 */
#include <fstream>
#include <iostream>
#include <vector>

#define int13 (1<<13)
#define shift(n) (1<<n)
#define suma(vec) (vec[0]+vec[1]+vec[2]+vec[3]+vec[4])
using namespace std;

// Devuelve la puntuación que obtiene la jugada V en la categoría Cat
// V es un vector de 5 enteros que contiene el valor de los 5 dados
int puntos( const vector<int>& V, const int& Cat ) {
	int apariciones[] = {0,0,0,0,0,0,0}; // Número de apariciones de ceros, unos, doses...
	apariciones[V[0]]++; apariciones[V[1]]++; apariciones[V[2]]++; apariciones[V[3]]++; apariciones[V[4]]++;
	switch (Cat) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		return apariciones[Cat] * Cat;
	case 7:
		return suma(V);
	case 8:
		for( int a = 1; a <= 6; ++a ) if( apariciones[a] >= 3 ) return suma(V);
		break;
	case 9:
		for( int a = 1; a <= 6; ++a ) if( apariciones[a] >= 4 ) return suma(V);
		break;
	case 10:
		for( int a = 1; a <= 6; ++a ) if( apariciones[a] == 5 ) return 50;
		break;
	case 11:
		if( (apariciones[1] > 0 && apariciones[2] > 0 && apariciones[3] > 0 && apariciones[4] > 0) ||
			(apariciones[2] > 0 && apariciones[3] > 0 && apariciones[4] > 0 && apariciones[5] > 0) ||
			(apariciones[3] > 0 && apariciones[4] > 0 && apariciones[5] > 0 && apariciones[6] > 0) )
			return 25;
		break;
	case 12:
		if( (apariciones[1] > 0 && apariciones[2] > 0 && apariciones[3] > 0 && apariciones[4] > 0 && apariciones[5] > 0) ||
			(apariciones[2] > 0 && apariciones[3] > 0 && apariciones[4] > 0 && apariciones[5] > 0 && apariciones[6] > 0) )
			return 35;
		break;
	case 13:
		for( int a = 1; a <= 6; ++a )
			for( int b = 1; b <= 6; ++b )
				if( apariciones[a] == 3 && apariciones[b] == 2 )
					return 40;
		break;
	default:
		break;
	}
	return 0;
}

// Devuelve el número de bits que tiene a 1 el entero n
int num_bits_uno( const int& n ) {
	return __builtin_popcount(n);
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int i, cat, asig, asig_anterior, puntposibles;
	vector< vector<int> > jugada(13, vector<int>(5)) ;

	while ( cin >> jugada[0][0] >> jugada[0][1] >> jugada[0][2] >> jugada[0][3] >> jugada[0][4] ) {
		for ( i = 1; i < 13; ++i )
			cin >> jugada[i][0] >> jugada[i][1] >> jugada[i][2] >> jugada[i][3] >> jugada[i][4];

		// Inicializa las tablas para la DP
		int maxpuntuacion[14][int13], ultima_eleccion[14][int13];
		for( i = 1; i < 14; ++i  )
			for ( asig = 0; asig < int13; ++asig )
				maxpuntuacion[i][asig] = -1;

		// Categoría 1 (unos)
		for ( i = 0; i < 13; ++i ) {
			maxpuntuacion[1][shift(i)] = puntos( jugada[i], 1 );
			ultima_eleccion[1][shift(i)] = i;
		}
		// Resto de categorias
		for ( cat = 2; cat < 14; ++cat ) {
			// Calcular las puntuaciones con todas las asignaciones posibles
			for ( asig = 0; asig < int13; ++asig ) {
				// Coger solo las asignaciones que cuadren con el número de categorías ya asignadas
				// Ejemplo: cat = 4, entonces valen 0011000011000 y 0001001100001, pero no 0000100010000
				if( num_bits_uno(asig) == cat ) {
					// Prueba una nueva asignación en la categoría 'cat' con cada jugada
					for ( i = 0; i < 13; ++i ) {
						asig_anterior = asig & ~(shift(i));
						puntposibles = maxpuntuacion[cat-1][asig_anterior] + puntos(jugada[i],cat);
						if( puntposibles > maxpuntuacion[cat][asig] ) {
							maxpuntuacion[cat][asig] = puntposibles;
							ultima_eleccion[cat][asig] = i;
						}
					}
					// Sumar el bonus de 35 puntos si procede
					if( cat == 6 && maxpuntuacion[cat][asig] >= 63 )
						maxpuntuacion[cat][asig] += 35;
				}
			}
		}

		// El resultado está en maxpuntuacion[13]['1111111111111']
		// Hay que ir buscando en qué orden se han asignado las jugadas mediante ultima_eleccion
		int asig = int13-1;
		vector<int> asignacion_optima(14);
		for( cat = 13; cat >= 1; --cat ) {
			asignacion_optima[cat] = ultima_eleccion[cat][asig];
			asig = asig & ~(shift(ultima_eleccion[cat][asig]));
		}

		// Imprimir el resultado
		int total = 0, bonus = 0, p;
		for ( cat = 1; cat < 14; ++cat ) {
			p = puntos(jugada[asignacion_optima[cat]],cat);
			cout << p << " ";
			total += p;
			if( cat == 6 && total >= 63 )
				total += bonus += 35;
		}
		// Aquí total == maxpuntuacion[13]['1111111111111']
		cout << bonus << " " << total << endl;
	}

	return 0;
}
