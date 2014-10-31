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

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

struct edge {
    edge() {c1 = 0, c2 = 0, p = 0;}
    int c1, c2, p;
};

bool cmp(const edge &a, const edge &b) {
    return a.p > b.p;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int N, R, S, D, T, caso = 1, i;
    while (scanf("%d %d ", &N, &R) && N > 0) {
        vector<edge> E(R);
        for (i = 0; i < R; ++i)
            scanf("%d %d %d ", &E[i].c1, &E[i].c2, &E[i].p);
        scanf("%d %d %d ", &S, &D, &T);
        sort(E.begin(), E.end(), cmp);

        i = 0;
        UnionFind uf = UnionFind(N+1);
        while (!uf.isSameSet(S, D)) {
            uf.unionSet(E[i].c1, E[i].c2);
            i++;
        }
        printf("Scenario #%d\n", caso++);
        printf("Minimum Number of Trips = %d\n\n", int(ceil(double(T) / (E[i-1].p - 1))));
    }

	return 0;
}
