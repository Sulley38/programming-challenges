#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> primo;

// Devuelve en res la factorización de n, donde res[i] es el exponente del primo i
void factorizar(int n, map<int,int> &res) {
	int i = 0;
	while (n > 1 && i < int(primo.size())) {
		if (n % primo[i] == 0) {
			res[primo[i]]++;
			n /= primo[i];
		} else {
			i++;
		}
	}
	if (n > 1)
		res[n]++;
}

// Guarda en 'primo' los números primos hasta n (criba de eratóstenes)
void getPrimosHasta(const int n) {
	int i, j;
	primo = vector<int>();
	vector<bool> criba(n+1, true);
	for (i = 2; i <= n; ++i) {
		if (criba[i]) {
			primo.push_back(i);
			for (j = 2; i*j <= n; ++j)
				criba[i*j] = false;
		}
	}
}

// Exponente de p en la descomposición en factores de n!
int exponenteFact(const long long int n, const long long int p) {
	long long int res = 0;
	for (long long int i = p; i <= n; i *= p)
		res += n / i;
	return res;
}

// true si m es divisor de n!
bool esDivisor(const int n, const int m) {
	map<int,int> factores;
	factorizar(m, factores);
	map<int,int>::iterator it;
	for (it = factores.begin(); it != factores.end(); ++it) {
		// Para cada factor primo de m, comparar con su exponente en n!
		if (exponenteFact(n, it->first) < it->second)
			return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	getPrimosHasta(46341);

	int n, m;
	while (cin >> n >> m) {
		if ((m <= n || esDivisor(n, m)) && m != 0)
			cout << m << " divides " << n << "!" << endl;
		else
			cout << m << " does not divide " << n << "!" << endl;
	}

	return 0;
}
