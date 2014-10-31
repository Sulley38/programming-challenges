#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int set, N, S, Q, Dest, Tiempo, Sactual, Svacias, i;
	bool end;
	stack<int> carrier;
	scanf("%d ", &set);
	while (set--) {
		scanf("%d %d %d ", &N, &S, &Q);
		vector< queue<int> > platB(N, queue<int>());
		vector<bool> Svacia(N);
		Svacias = 0;
		// Llenar las colas
		for (Sactual = 0; Sactual < N; ++Sactual) {
			scanf("%d ", &i);
			if (i == 0) {
				Svacia[Sactual] = true;
				Svacias++;
			} else {
				while (i--) {
					scanf("%d ", &Dest);
					platB[Sactual].push(Dest - 1);
				}
			}
		}
		// Procesar las cargas
		Tiempo = Sactual = 0;
		while (Svacias < N || !carrier.empty()) {
			// Descarga
			end = false;
			while (!end) {
				if (carrier.empty()) {
					end = true;
				} else if (carrier.top() == Sactual) {
					carrier.pop();
					Tiempo += 1;
				} else if (int(platB[Sactual].size()) < Q) {
					platB[Sactual].push(carrier.top());
					if (platB[Sactual].size() == 1) {
						Svacia[Sactual] = false;
						Svacias--;
					}
					carrier.pop();
					Tiempo += 1;
				} else {
					end = true;
				}
			}
			// Carga
			while (int(carrier.size()) < S && !platB[Sactual].empty()) {
				carrier.push(platB[Sactual].front());
				platB[Sactual].pop();
				Tiempo += 1;
			}
			if (platB[Sactual].empty() && !Svacia[Sactual]) {
				Svacia[Sactual] = true;
				Svacias++;
			}
			// Avanzar de plataforma
			Sactual = (Sactual + 1) % N;
			Tiempo += 2;
		}

		printf("%d\n", Tiempo - 2);
	}

	return 0;
}
