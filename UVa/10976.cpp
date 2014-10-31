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
	int k, x;
	while (scanf("%d ", &k) > 0) {
		x = k + 1;
		vector<int> soluciones1, soluciones2;
		while ((float(k*x) / float(x - k)) >= 2*k) {
			// Solución válida?
			if (k*x % (x - k) == 0) {
				soluciones1.push_back(x);
				soluciones2.push_back(k*x / (x - k));
			}
			x++;
		}
		printf("%d\n", soluciones1.size());
		for (unsigned int i = 0; i < soluciones1.size(); ++i)
			printf("1/%d = 1/%d + 1/%d\n", k, soluciones2[i], soluciones1[i]);
	}

	return 0;
}
