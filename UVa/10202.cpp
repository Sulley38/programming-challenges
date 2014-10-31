#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Elimina la primera aparición de Valor en S, o devuelve false si no se ha encontrado
bool eliminar( vector<int>& S, const int& Valor ) {
	vector<int>::iterator it = S.begin();
	while (it != S.end()) {
		if (*it == Valor) {
			S.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

// El vector A son los números que se piden (se conoce A[0]), Suma son las sumas
bool rellenar( vector<int>& A, vector<int> Suma ) {
	int numElementosDeA = 1;
	while (!Suma.empty()) {
		int elementoDeA = *Suma.begin() - A[0];
		for (int i = 0; i < numElementosDeA; ++i)
			if (!eliminar(Suma, A[i] + elementoDeA))
				return false;

		A[numElementosDeA] = elementoDeA;
		numElementosDeA++;
	}
	return true;
}

int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int i, N;
	while (cin >> N) {
		int numElem = N*(N-1)/2;
		vector<int> A(N), Sumas(numElem);
		// Leer
		for (i = 0; i < numElem; ++i)
			cin >> Sumas[i];
		sort( Sumas.begin(), Sumas.end() );
		// Calcular
		bool found = false;
		for (i = 2; i < numElem && !found; i++) {
			if ((Sumas[0] + Sumas[1] - Sumas[i]) % 2 == 0) {
				A[0] = (Sumas[0] + Sumas[1] - Sumas[i])/2;
				if (rellenar(A, Sumas))
					found = true;
			}
		}
		// Escribir
		if (found) {
			cout << A[0];
			for (i = 1; i < N; ++i)
				cout << " " << A[i];
			cout << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
