#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

long double exponentemenor(long double prefijo) {
	long double lim_menor = log2l(prefijo), lim_mayor = log2l(prefijo+1), log10 = log2l(10);
	// k -> número de digitos desconocidos
	long double k = ceill( log10l(prefijo+0.5) ) + 1;
	// Buscar la cantidad de números ocultos
	for( ; ceill(lim_menor + k*log10) != floorl(lim_mayor + k*log10); k += 1 ) {}
	return ceill(lim_menor + k*log10);
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	long double n;
	while( cin >> n )
		cout << exponentemenor(n) << endl;
	return 0;
}
