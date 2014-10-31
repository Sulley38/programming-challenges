#include <bitset>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, m, i, cuenta;
	static bitset<1000000001> tiene;
	while (scanf("%d %d ", &n, &m) > 0 && (m != 0 || n != 0)) {
		tiene.reset();
		cuenta = 0;

		while (m--) {
			scanf("%d ", &i);
			tiene.set(i, 1);
		}
		while (n--) {
			scanf("%d ", &i);
			if (tiene.test(i))
				cuenta++;
		}

		printf("%d\n", cuenta);
	}

	return 0;
}
