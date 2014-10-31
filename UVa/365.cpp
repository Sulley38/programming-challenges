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
typedef pair<int,int> pii;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int N;
    char name;
    string nei;
    double g;
    while (cin >> N) {
        vector< vector<bool> > adj(27, vector<bool>(27));
        vector<bool> visited(27);
        vector<double> good(27);
        double val, bestval = -1.0;
        char bestplan;

        for (int i = 0; i < N; ++i) {
            cin >> name >> g >> nei;
            good[name-'A'+1] = g;
            for (unsigned int j = 0; j < nei.size(); ++j) {
                if (nei[j] == '*') {
                    adj[name-'A'+1][0] = true;
                    adj[0][name-'A'+1] = true;
                } else {
                    adj[name-'A'+1][nei[j]-'A'+1] = true;
                    adj[nei[j]-'A'+1][name-'A'+1] = true;
                }
            }
        }

        pii p;
        queue<pii> cola;
        cola.push(pii(0, 0));
        visited[0] = true;
        while (!cola.empty()) {
            p = cola.front();
            cola.pop();
            for (int i = 1; i < 27; ++i) {
                if (adj[p.first][i] && !visited[i]) {
                    val = good[i];
                    for (int j = 0; j < p.second; ++j)
                        val = val * 0.95;
                    if (val > bestval) {
                        bestval = val;
                        bestplan = i + 'A' - 1;
                    }
                    cola.push(pii(i, p.second + 1));
                    visited[i] = true;
                }
            }
        }

        printf("Import from %c\n", bestplan);
    }

	return 0;
}
