#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t, n, i, j;
	int M[8][8];
	scanf("%d ", &t);
	while (t--) {
		/* Leer la entrada */
		scanf("%d ", &n);
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				scanf("%d ", &M[i][j]);
		/* Probar todas las combinaciones */
		int Col[8] = {0,1,2,3,4,5,6,7};
		int MinSum = 1000000, Sum;
		do {
			Sum = 0;
			for (i = 0; i < n; ++i)
				Sum += M[i][Col[i]];

			if (Sum < MinSum)
				MinSum = Sum;
		} while (next_permutation(Col, Col+n));
		printf("%d\n", MinSum);
	}

	return 0;
}
