#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	string s;
	getline(cin, s);
	while (s != "DONE") {
		bool posible = true;
		for (int i = 0, j = s.size() - 1; i < j && posible; ) {
			if (s[i] == '.' || s[i] == ',' || s[i] == '?' || s[i] == '!' || s[i] == ' ') {
				i++;
			} else if (s[j] == '.' || s[j] == ',' || s[j] == '?' || s[j] == '!' || s[j] == ' ') {
				j--;
			} else if (tolower(s[i]) == tolower(s[j])) {
				i++; j--;
			} else {
				posible = false;
			}
		}

		if (posible)
			puts("You won't be eaten!");
		else
			puts("Uh oh..");

		getline(cin, s);
	}

	return 0;
}
