#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

vector< stack<int> > S(24); // Contenido de la pila i
int B[24]; // Pila en la que se encuentra el bloque i

void move(int a, int b, bool onto) {
	int p1 = B[a], p2 = B[b], aux;
	// Quitar lo que haya encima de a
	while (!S[p1].empty() && (aux = S[p1].top()) != a) {
		S[aux].push(aux);
		B[aux] = aux;
		S[p1].pop();
	}
	S[p1].pop();
	if (onto) {
		// Quitar lo que haya encima de b
		while (!S[p2].empty() && (aux = S[p2].top()) != b) {
			S[aux].push(aux);
			B[aux] = aux;
			S[p2].pop();
		}
	}
	// Poner a sobre la pila de b
	S[p2].push(a);
	B[a] = p2;
}

void pile(int a, int b, bool onto) {
	int p1 = B[a], p2 = B[b], aux;
	if (onto) {
		// Quitar lo que haya encima de b
		while (!S[p2].empty() && (aux = S[p2].top()) != b) {
			S[aux].push(aux);
			B[aux] = aux;
			S[p2].pop();
		}
	}
	// Guardar lo que hay encima de a
	stack<int> temp;
	while (!S[p1].empty() && (aux = S[p1].top()) != a) {
		temp.push(aux);
		S[p1].pop();
	}
	S[p1].pop();
	// Poner a sobre la pila de b
	S[p2].push(a);
	B[a] = p2;
	// Vaciar la pila temporal en la pila de b
	while (!temp.empty()) {
		aux = temp.top();
		S[p2].push(aux);
		B[aux] = p2;
		temp.pop();
	}
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, a, b, i;
	scanf("%d ", &n);
	for (i = 0; i < n; ++i) {
		S[i].push(i);
		B[i] = i;
	}

	char command[5], type[5];
	scanf("%s ", command);
	while (command[0] != 'q') {
		scanf("%d %s %d ", &a, type, &b);
		if (a != b && B[a] != B[b]) {
			if (command[0] == 'm')
				move(a, b, type[1] == 'n');
			else
				pile(a, b, type[1] == 'n');
		}
		scanf("%s ", command);
	}

	int aux[24], num;
	for (i = 0; i < n; ++i) {
		printf("%d:", i);
		num = 0;
		while (!S[i].empty()) {
			aux[num] = S[i].top();
			S[i].pop();
			num++;
		}
		while (num > 0) {
			num--;
			printf(" %d", aux[num]);
		}
		printf("\n");
	}

	return 0;
}
