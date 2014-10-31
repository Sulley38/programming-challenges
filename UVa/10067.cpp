#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

#define COD(a, b, c, d) ((a) | (b << 4) | (c << 8) | (d << 12))
#define DECOD(n, i) ((n >> (4*i)) & 15)
#define PREV(n) ((n + 9) % 10)
#define NEXT(n) ((n + 1) % 10)

int main(int argc, char** argv) {
    int N, n;
    int d[4], begin, end;
    int status[10][10][10][10]; /* 0 = Unknown, 1 = Visited, 2 = Forbidden */
    int i;
    bool fin;
    scanf(" %d", &N);
    while (N--) {
        memset(status, false, sizeof status);
        scanf(" %d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
        status[d[0]][d[1]][d[2]][d[3]] = 1;
        begin = COD(d[0], d[1], d[2], d[3]);
        scanf(" %d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
        end = COD(d[0], d[1], d[2], d[3]);
        
        scanf("%d ", &n);
        for (i = 0; i < n; ++i) {
            scanf(" %d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
            status[d[0]][d[1]][d[2]][d[3]] = 2;
        }
        
        pii p;
        queue<pii> cola;
        
        fin = false;
        cola.push(pii(begin, 0));
        while (!cola.empty() && !fin) {
            p = cola.front();
            cola.pop();
            
            if (p.first == end) {
                fin = true;
                printf("%d\n", p.second);
            } else {
                d[0] = DECOD(p.first, 0), d[1] = DECOD(p.first, 1), d[2] = DECOD(p.first, 2), d[3] = DECOD(p.first, 3);
                for (i = 0; i < 4; ++i) {
                    d[i] = PREV(d[i]);
                    if (status[d[0]][d[1]][d[2]][d[3]] == 0) {
                        status[d[0]][d[1]][d[2]][d[3]] = 1;
                        cola.push(pii(COD(d[0], d[1], d[2], d[3]), p.second + 1));
                    }
                    d[i] = NEXT(d[i]);
                    d[i] = NEXT(d[i]);
                    if (status[d[0]][d[1]][d[2]][d[3]] == 0) {
                        status[d[0]][d[1]][d[2]][d[3]] = 1;
                        cola.push(pii(COD(d[0], d[1], d[2], d[3]), p.second + 1));
                    }
                    d[i] = PREV(d[i]);
                }
            }
        }
        
        if (!fin)
            puts("-1");
    }

    return 0;
}
