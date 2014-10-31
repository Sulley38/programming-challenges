#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Direcciones: +x = 4, -x = 5, +y = 0, -y = 1, +z = 2, -z = 3
int valor(string direccion) {
	if (direccion == "+y")
		return 0;
	if (direccion == "-y")
		return 1;
	if (direccion == "+z")
		return 2;
	if (direccion == "-z")
		return 3;
	return -1;
}

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	// Representaciones numéricas de las direcciones
	vector<string> texto(6);
	texto[0] = "+y"; texto[1] = "-y"; texto[2] = "+z";
	texto[3] = "-z"; texto[4] = "+x"; texto[5] = "-x";
	// Tabla de conversiones
	vector< vector<int> > cambio(6, vector<int>(4));
	cambio[0][0] = 5; cambio[0][1] = 4; cambio[0][2] = 0; cambio[0][3] = 0;
	cambio[1][0] = 4; cambio[1][1] = 5; cambio[1][2] = 1; cambio[1][3] = 1;
	cambio[2][0] = 2; cambio[2][1] = 2; cambio[2][2] = 5; cambio[2][3] = 4;
	cambio[3][0] = 3; cambio[3][1] = 3; cambio[3][2] = 4; cambio[3][3] = 5;
	cambio[4][0] = 0; cambio[4][1] = 1; cambio[4][2] = 2; cambio[4][3] = 3;
	cambio[5][0] = 1; cambio[5][1] = 0; cambio[5][2] = 3; cambio[5][3] = 2;

	int i, l;
	string s;
	while (cin >> l && l != 0) {
		int dir = 4; // Dirección inicial: +x
		for (i = 0; i < l-1; ++i) {
			cin >> s;
			if (s != "No")
				dir = cambio[dir][valor(s)];
		}
		cout << texto[dir] << endl;
	}

	return 0;
}
