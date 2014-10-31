#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, c[5], top, suma;
	map<string, int> voto;
	ostringstream oss;
	while (scanf("%d ", &n) > 0 && n != 0) {
		top = suma = 0;
		voto.clear();
		while (n--) {
			scanf("%d %d %d %d %d ", &c[0], &c[1], &c[2], &c[3], &c[4]);
			sort(c, c + 5);
			oss.str(string());
			oss << c[0] << c[1] << c[2] << c[3] << c[4];
			voto[oss.str()]++;
			if (voto[oss.str()] > top) {
				top = voto[oss.str()];
				suma = top;
			} else if (voto[oss.str()] == top) {
				suma += top;
			}
		}
		printf("%d\n", suma);
	}

	return 0;
}
