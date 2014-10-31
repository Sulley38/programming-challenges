#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int N; // Número de ciudades
int minEstaciones; // Número mínimo de estaciones necesarias
vector< vector<int> > cubiertoPor; // Por cada ciudad, listado de ciudades que al poner una estación la cubrirían (ella misma y sus adyacentes)

// Función de comparación para ordenar las ciudades según su número de adyacentes (de mayor a menor)
bool comp(const int a, const int b) {
	return cubiertoPor[a].size() > cubiertoPor[b].size();
}

// Marca las ciudades que quedarían cubiertas al poner una estación en la ciudad I
long long int marcar_cubiertas(const int I, const long long int C) {
	long long int NC = C;
	NC |= 1LL << I;
	for (unsigned int i = 0; i < cubiertoPor[I].size(); i++)
		NC |= 1LL << cubiertoPor[I][i];
	return NC;
}

// Habiendo puesto 'numEstaciones' estaciones de servicio en las ciudades 'estaciones' (máscara de bits),
// que cubren las ciudades 'cubiertas' (máscara de bits), poner las estaciones necesarias hasta cubrir todas las ciudades.
void poner_estacion(const long long int estaciones, const int numEstaciones, const long long int cubiertas) {
	if (cubiertas == (1LL << (N+1)) - 2) {
		// Si es solucion, considerar si es mínima
		minEstaciones = min(minEstaciones, numEstaciones);
	} else if (numEstaciones + 1 < minEstaciones) {
		// Intentar expandir la búsqueda si se puede optar a una mejor solución
		// Buscar la primera ciudad que falta por cubrir
		long long int primerHueco = 2;
		int posicion = 1;
		while (cubiertas & primerHueco) {
			primerHueco <<= 1;
			posicion++;
		}
		// Poner una estación en ella o en alguna de sus adyacentes
		for (unsigned int i = 0; i < cubiertoPor[posicion].size(); ++i) {
			poner_estacion(estaciones | (1LL << cubiertoPor[posicion][i]),
						numEstaciones + 1,
						marcar_cubiertas(cubiertoPor[posicion][i], cubiertas));
		}
	}
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int M, a, b, i;
	scanf("%d %d ", &N, &M);
	while (N != 0 || M != 0) {
		minEstaciones = INT_MAX;
		cubiertoPor = vector< vector<int> >(N+1, vector<int>());
		// Leer datos de la entrada
		for (i = 0; i < M; ++i) {
			scanf("%d %d ", &a, &b);
			cubiertoPor[a].push_back(b);
			cubiertoPor[b].push_back(a);
		}
		// Ordenar de mayor número de adyacentes a menor
		for (i = 1; i <= N; ++i) {
			cubiertoPor[i].push_back(i);
			sort(cubiertoPor[i].begin(), cubiertoPor[i].end(), comp);
		}
		// Comenzar la búsqueda
		poner_estacion(0, 0, 0);
		// Imprimir el resultado
		printf("%d\n", minEstaciones);
		scanf("%d %d ", &N, &M);
	}

	return 0;
}
