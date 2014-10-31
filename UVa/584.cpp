#ifdef TESTING
#include <fstream>
#endif
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s;
	getline(cin, s);
	while (s != "Game Over") {
		int i = 0, score = 0, frames = 0, frameActual = -1;
		while (frames < 10) {
			if (s[i] == 'X') {
				score += 10;
				/* Sumar siguiente */
				if (s[i+2] == 'X')
					score += 10;
				else
					frameActual = s[i+2] - '0';
				/* Sumar otra más */
				if (s[i+4] == 'X')
					score += 10;
				else if (s[i+4] == '/')
					score += 10;
				else if (frameActual == -1)
					score += s[i+4] - '0';
				else
					score += frameActual + s[i+4] - '0';
				frames++;
				frameActual = -1;
			} else if (s[i] == '/') {
				score += 10;
				/* Sumar siguiente */
				if (s[i+2] == 'X')
					score += 10;
				else
					score += s[i+2] - '0';
				frames++;
				frameActual = -1;
			} else {
				if (frameActual == -1) {
					frameActual = s[i] - '0';
				} else {
					score += frameActual + s[i] - '0';
					frames++;
					frameActual = -1;
				}
			}
			i += 2;
		}

		cout << score << endl;

		getline(cin, s);
	}

	return 0;
}
