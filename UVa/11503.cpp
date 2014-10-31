#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> id, sz;

int root(int i) {
	while (i != id[i]) {
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n, f, count, p, q, r1, r2;
	char name1[20], name2[20];
	map<string, int> num;
	map<string, int>::iterator it;

	scanf("%d ", &n);
	while (n--) {
		id = vector<int>();
		sz = vector<int>();
		num.clear();
		count = 0;

		scanf("%d ", &f);
		while (f--) {
			scanf("%s %s ", name1, name2);
			// Buscar name1
			if ((it = num.find(name1)) == num.end()) {
				num.insert( pair<string, int>(name1, count) );
				id.push_back(count);
				sz.push_back(1);
				p = count++;
			} else {
				p = it->second;
			}
			// Buscar name2
			if ((it = num.find(name2)) == num.end()) {
				num.insert( pair<string, int>(name2, count) );
				id.push_back(count);
				sz.push_back(1);
				q = count++;
			} else {
				q = it->second;
			}
			// Comprobar su grupo
			r1 = root(p), r2 = root(q);
			if (r1 != r2) {
				// Union
				if (sz[r1] < sz[r2]) {
					id[r1] = r2;
					sz[r2] += sz[r1];
					printf("%d\n", sz[r2]);
				} else {
					id[r2] = r1;
					sz[r1] += sz[r2];
					printf("%d\n", sz[r1]);
				}
			} else {
				// Print size
				printf("%d\n", sz[r1]);
			}
		}
	}

	return 0;
}
