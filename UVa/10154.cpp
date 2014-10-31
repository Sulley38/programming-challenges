#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
#define INF 2147483647

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
	return (a.second < b.second);
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	vector< pair<int,int> > tortuga;
	int w, s;
	while (scanf("%d %d ", &w, &s) > 0)
		tortuga.push_back(make_pair(w,s));
	// Ordenar tortugas por fuerza
	sort(tortuga.begin(), tortuga.end(), comp);
	// DP por cada tortuga sobre cada altura: intentar minimizar el peso de las torres formadas
	int torreMasAlta = 0;
	vector<int> pesoMin(2, 0); // Torre de altura 0 = peso 0
	pesoMin[1] = INF; // Torre de altura 1 = peso INF (aún no descubierto)
	for (unsigned int i = 0; i < tortuga.size(); ++i) {
		// Para cada altura desde torreMasAlta+1 hasta 1, minimizar el peso de la torre actual
		for (int j = torreMasAlta+1; j > 0; --j) {
			// Si la tortuga soporta la torre de altura j-1 y mejora el peso de la actual, tenemos nueva torre de altura j
			if (tortuga[i].second - tortuga[i].first >= pesoMin[j-1] && pesoMin[j-1] + tortuga[i].first < pesoMin[j]) {
				pesoMin[j] = pesoMin[j-1] + tortuga[i].first;
				if (j > torreMasAlta) {
					torreMasAlta++;
					pesoMin.push_back(INF);
				}
			}
		}
	}

	printf("%d\n", torreMasAlta);

	return 0;
}
