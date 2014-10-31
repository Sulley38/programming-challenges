#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

#define MAX 1000000

char S[MAX + 2];

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int index;
	set<int> aparicion[52];
	fgets(S, MAX + 2, stdin);
	/* Guardar las apariciones de cada letra en un set ordenado por cada */
	for (int i = 0; S[i] != '\n'; ++i) {
		index = S[i] >= 'A' && S[i] <= 'Z' ? S[i] - 'A' : S[i] - 'G';
		aparicion[index].insert(i);
	}

	int Q, begin, last = -1;
	scanf("%d ", &Q);
	char SS[102];
	set<int>::iterator it;
	while (Q--) {
		fgets(SS, 102, stdin);
		index = SS[0] >= 'A' && SS[0] <= 'Z' ? SS[0] - 'A' : SS[0] - 'G';
		it = aparicion[index].begin();
		if (it == aparicion[index].end()) {
			puts("Not matched");
		} else {
			begin = last = *it;
			for (int i = 1; SS[i] != '\n' && SS[i] != 0; ++i) {
				/* Buscar en la lista de apariciones de la letra correspondiente,
				 * la primera aparición posterior a 'last' */
				index = SS[i] >= 'A' && SS[i] <= 'Z' ? SS[i] - 'A' : SS[i] - 'G';
				it = aparicion[index].upper_bound(last);
				if (it == aparicion[index].end()) {
					puts("Not matched");
					SS[i + 1] = 0;
				} else {
					last = *it;
				}
			}
			if (it != aparicion[index].end()) {
				printf("Matched %d %d\n", begin, *it);
			}
		}
	}

	return 0;
}
