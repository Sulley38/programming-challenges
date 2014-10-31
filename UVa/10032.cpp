#include <algorithm>
#include <bitset>
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

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, N, W, Sum;
	scanf("%d ", &T);

	long long weights[45001]; // El bit j-ésimo de weights[i] indica si el peso i es alcanzable con j personas
	while (T--) {
		weights[0] = 1;
		for (int i = 1; i < 45001; ++i)
			weights[i] = 0;
		Sum = 0;

		scanf("%d ", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d ", &W);
			for (int j = Sum; j >= 0; --j) {
				// El peso j + W es alcanzable con una persona más que el peso j
				weights[j + W] |= weights[j] << 1;
			}
			Sum += W;
		}

		// Busco el mejor peso que sea alcanzable con N / 2 personas
		int mitad = N / 2, bestA = 0, bestB = 10000000;
		for (int i = 0; i <= Sum; ++i) {
			if ((weights[i] & (1LL << mitad)) && bestB - bestA > abs((Sum - i) - i)) {
				bestA = min(Sum - i, i);
				bestB = max(Sum - i, i);
			}
		}

		printf("%d %d\n", bestA, bestB);
		if (T > 0) puts("");
	}

	return 0;
}
