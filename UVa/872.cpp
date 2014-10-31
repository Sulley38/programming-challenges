#include <algorithm>
#include <bitset>
#include <cmath>
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

int N;
int nodes[20];
int adj[26][20];
int nadj[26];

char seq[20];
bool visited[26];
bool hassolution;
int nvisited;

/* true if all the dependencies for the node n are already in the sequence */
bool satisfied(int n) {
	for (int i = 0; i < nadj[n]; ++i) {
		if (!visited[adj[n][i]])
			return false;
	}
	return true;
}

void dfs(int from) {
	if (!satisfied(from)) return; /* from can't be inserted if conditions aren't satisfied */
	/* insert the node in the result sequence */
	seq[nvisited++] = from;
	visited[from] = 1;
	if (nvisited == N) {
		/* sequence completed */
		for (int i = 0; i < N - 1; ++i)
			printf("%c ", seq[i] + 'A');
		printf("%c\n", seq[N - 1] + 'A');
		hassolution = true;
	} else {
		/* try to expand the sequence */
		for (int i = 0; i < N; ++i)
			if (!visited[nodes[i]])
				dfs(nodes[i]);
	}
	/* remove the node from the sequence */
	visited[from] = 0;
	nvisited--;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int caso;
	int count, i;
	char line[256], node1, node2, sep;
	scanf("%d ", &caso);
	while (caso--) {
		N = nvisited = 0;
		hassolution = false;
		memset(nadj, 0, sizeof nadj);
		memset(visited, false, sizeof visited);
		/* read nodes */
		i = 0;
		fgets(line, 256, stdin);
		while (sscanf(line + i, "%c %n", &node1, &count) > 0) {
			nodes[N++] = node1 - 'A';
			i += count;
		}
		/* ensure the search is done in alphabetical order */
		sort(nodes, nodes + N);
		/* read conditions */
		i = 0;
		fgets(line, 256, stdin);
		while (sscanf(line + i, "%c%c%c %n", &node1, &sep, &node2, &count) > 0) {
			adj[node2 - 'A'][nadj[node2 - 'A']++] = node1 - 'A';
			i += count;
		}
		/* launch the search */
		for (i = 0; i < N; ++i)
			dfs(nodes[i]);
		/* print if no solution is found */
		if (!hassolution)
			puts("NO");

		if (caso > 0) {
			puts("");
			scanf(" ");
		}
	}

	return 0;
}
