#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> Par;

// Representación del grafo y del minimum spanning tree
VVI hasta, peso, mst_hasta, mst_peso;
int num_nodos, num_aristas;
struct comparacion {
	bool operator() ( const Par& a, const Par& b ) { return peso[a.first][a.second] > peso[b.first][b.second]; }
};

// Rellena mst_hasta y mst_peso con datos del árbol en forma de lista de adyacencia
void Prim() {
	int i, objetivo;
	mst_hasta = VVI( num_nodos, VI() );
	mst_peso = VVI( num_nodos, VI() );
	priority_queue<Par,vector<Par>,comparacion> cola;
	// Insertar las aristas adyacentes al nodo 0 en la cola
	for( i = 0; i < int(hasta[0].size()); ++i )
		cola.push( Par(0,i) );

	Par p;
	int nodos_incluidos = 1;
	while( nodos_incluidos < num_nodos ) {
		// Analiza la arista de menor peso en la cola, y si el nodo al que apunta
		// no pertenece al árbol, inserta la arista en el árbol (y por lo tanto, el nodo)
		p = cola.top();
		cola.pop();
		objetivo = hasta[p.first][p.second];
		if( mst_hasta[objetivo].empty() ) {
			// Incluir el nodo y la arista en el árbol
			mst_hasta[p.first].push_back( objetivo );
			mst_hasta[objetivo].push_back( p.first );
			mst_peso[p.first].push_back( peso[p.first][p.second] );
			mst_peso[objetivo].push_back( peso[p.first][p.second] );
			nodos_incluidos++;
			// Meter en la cola las aristas del último nodo visitado y que no van a uno ya en el árbol
			for( i = 0; i < int(hasta[objetivo].size()); ++i )
				if( mst_hasta[hasta[objetivo][i]].empty() )
					cola.push( Par(objetivo,i) );
		}
	}
}

// Devuelve la arista de mayor peso del árbol mst en el camino entre From y To, viniendo desde Parent
int dfs( const int From, const int To, const int Parent ) {
	if( From == To ) return 0;
	for( int i = 0; i < int(mst_hasta[From].size()); ++i ) {
		if( mst_hasta[From][i] != Parent ) {
			int maximo = dfs( mst_hasta[From][i], To, From );
			if( maximo >= 0 )
				return max( mst_peso[From][i], maximo );
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int casos, z;
	cin >> casos;
	for( z = 1; z <= casos; ++z ) {
		int a, b, q, from, to, weight;
		// Leer el grafo
		cin >> num_nodos >> num_aristas;
		hasta = VVI( num_nodos, VI() );
		peso = VVI( num_nodos, VI() );
		for( int i = 0; i < num_aristas; ++i ) {
			cin >> from >> to >> weight;
			// Introduce la arista en ambos sentidos
			hasta[--from].push_back(--to);
			peso[from].push_back(weight);
			hasta[to].push_back(from);
			peso[to].push_back(weight);
		}

		// Minimum spanning tree (algoritmo de Prim)
		Prim();

		// Queries
		cin >> q;
		cout << "Case " << z << endl;
		while( q-- ) {
			cin >> a >> b;
			cout << dfs( a-1, b-1, -1 ) << endl;
		}
		cout << endl;

	}

	return 0;
}
