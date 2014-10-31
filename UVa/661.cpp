#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	fstream cin("input.txt");
#endif
	int n, m, c, test = 1, i;
	cin >> n >> m >> c;
	while( n != 0 || m != 0 || c != 0 ) {
		vector<int> consumo(n);
		vector<bool> estado(n,false);
		bool revienta = false;
		int consumoactual = 0, consumomaximo = 0, accion;
		for( i = 0; i < n; ++i )
			cin >> consumo[i];
		for( i = 0; i < m; ++i ) {
			cin >> accion;
			accion--;
			if( estado[accion] ) {
				consumoactual -= consumo[accion];
				estado[accion] = false;
			} else {
				consumoactual += consumo[accion];
				estado[accion] = true;
				consumomaximo = max( consumoactual, consumomaximo );
				if( consumoactual > c )
					revienta = true;
			}
		}
		cout << "Sequence " << test << endl;
		if( revienta ) {
			cout << "Fuse was blown." << endl;
		} else {
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << consumomaximo << " amperes." << endl;
		}
		cout << endl;
		test++;
		cin >> n >> m >> c;
	}
	return 0;
}
