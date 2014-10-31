#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vll;

struct edge {
	int to, depart, arrive;
	edge(int a, int b, int c) {to = a, depart = b, arrive = c;}
};

struct node {
	int city, blood, arrival;
	node(int a, int b, int c) {city = a, blood = b, arrival = c;}
};

// Comprueba si la hora h1 es anterior o igual a la hora h2
// Las 6pm es lo primero
bool isBefore(int h1, int h2) {
	if (h1 < 18) h1 += 24;
	if (h2 < 18) h2 += 24;
	return h1 <= h2;
}

// Una ruta es válida si sale y llega entre las 18 y las 6 y dura 12 horas o menos
bool isValidEdge(int depart, int arrive, int duration) {
	if (duration > 12) return false;
	return (depart >= 18 || depart < 6) && (arrive > 18 || arrive <= 6);
}

class comp {
public:
	bool operator() (const node& a, const node& b) const {
		if (a.blood == b.blood)
			return !isBefore(a.arrival, b.arrival);
		return a.blood > b.blood;
	}
};

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int C;
	cin >> C;
	for (int caso = 1; caso <= C; ++caso) {
		int routes;
		cin >> routes;
		int citycount = 0;
		string a, b;
		map<string,int> cities;
		map<string,int>::iterator it;
		vector< vector<edge> > adj;
		while (routes--) {
			int depart, duration, from, to;
			cin >> a >> b >> depart >> duration;
			if ((it = cities.find(a)) == cities.end()) {
				from = cities[a] = citycount++;
				adj.push_back(vector<edge>());
			} else {
				from = it->second;
			}
			if ((it = cities.find(b)) == cities.end()) {
				to = cities[b] = citycount++;
				adj.push_back(vector<edge>());
			} else {
				to = it->second;
			}

			if (depart == 24) depart = 0;
			int arrive = (depart + duration) % 24;
			if (isValidEdge(depart, arrive, duration))
				adj[from].push_back(edge(to, depart, arrive));
		}

		cin >> a >> b;
		int origin = cities[a], destination = cities[b];

		vb visited(citycount);
		vector<pii> dist(citycount, pii(1 << 30, 50));
		priority_queue<node, vector<node>, comp> cola;
		node u(origin, 0, 18);
		cola.push(u);
		while (!cola.empty()) {
			u = cola.top();
			cola.pop();
			if (visited[u.city]) continue;
			visited[u.city] = true;
			if (u.city == destination) break;

			for (unsigned int i = 0; i < adj[u.city].size(); ++i) {
				edge e = adj[u.city][i];
				if (!visited[e.to]) {
					// A qué hora llego a e.to cogiendo esta ruta, y cuánta sangre necesito
					int extraBlood = 0;
					if (!isBefore(u.arrival, e.depart)) // Pasar el día en la estación
						extraBlood = 1;
					if (u.blood + extraBlood < dist[e.to].first) { // Actualizar camino mínimo
						dist[e.to].first = u.blood + extraBlood;
						dist[e.to].second = e.arrive;
						cola.push(node(e.to, dist[e.to].first, dist[e.to].second));
					} else if (u.blood + extraBlood == dist[e.to].first && isBefore(e.arrive, dist[e.to].second)) {
						dist[e.to].second = e.arrive;
						cola.push(node(e.to, dist[e.to].first, dist[e.to].second));
					}
				}
			}
		}

		cout << "Test Case " << caso << "." << endl;
		if (!visited[destination])
			cout << "There is no route Vladimir can take." << endl;
		else
			cout << "Vladimir needs " << u.blood << " litre(s) of blood." << endl;
	}
}
