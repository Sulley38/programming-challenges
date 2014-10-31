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
	int m, n, i, j, r, col, val;
	while (scanf("%d %d ", &m, &n) > 0) {
		vector< vector<int> > index(n, vector<int>()), value(n, vector<int>());
		vector<int> read_columns;
		for (i = 0; i < m; ++i) {
			scanf("%d ", &r);
			read_columns.clear();
			// Leer posiciones
			for (j = 0; j < r; ++j) {
				scanf("%d ", &col);
				index[col - 1].push_back(i + 1);
				read_columns.push_back(col - 1);
			}
			// Leer valores
			for (j = 0; j < r; ++j) {
				scanf("%d ", &val);
				value[read_columns[j]].push_back(val);
			}
		}

		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i) {
			printf("%d", index[i].size());
			for (j = 0; j < int(index[i].size()); ++j)
				printf(" %d", index[i][j]);
			printf("\n");
			if (!value[i].empty())
				printf("%d", value[i][0]);
			for (j = 1; j < int(value[i].size()); ++j)
				printf(" %d", value[i][j]);
			printf("\n");
		}
	}

	return 0;
}
