#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Cuenta el número de veces que aparece el caracter c en el string s
int ocurrencias(string s, char c) {
	int o = 0;
	for (unsigned int i = 0; i < s.size(); ++i)
		if (s[i] == c)
			o++;
	return o;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int c, r, fallos, restantes;
	string s, t;
	vector<bool> dicha(26);
	while (scanf("%d ", &r) > 0 && r != -1) {
		getline(cin, s);
		getline(cin, t);

		fallos = 0;
		restantes = s.size();
		dicha.assign(26, false);
		for (unsigned int i = 0; i < t.size() && fallos < 7 && restantes > 0; ++i) {
			if (!dicha[t[i]-'a']) {
				dicha[t[i]-'a'] = true;
				c = ocurrencias(s, t[i]);
				if (c == 0)
					fallos++;
				else
					restantes -= c;
			}
		}

		printf("Round %d\n", r);
		if (fallos == 7)
			puts("You lose.");
		else if (restantes == 0)
			puts("You win.");
		else
			puts("You chickened out.");
	}

	return 0;
}
