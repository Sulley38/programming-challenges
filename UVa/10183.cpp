#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 * Clase para trabajar con números muy grandes
 */
class BigNum {
private:
	string data;
public:
	BigNum() { this->data = "0"; }
	BigNum(const int numero) { stringstream ss; ss << numero; this->data = ss.str(); }
	BigNum(const char* numero) { this->data = string(numero); }
	BigNum(const string numero) { this->data = numero; }
	/************* ASIGNACIÓN *************/
	BigNum& operator=(const BigNum &num) {
		if (this != &num)
			this->data = num.data;
		return *this;
	}
	/************* SUMA-ASIGNACIÓN *************/
	BigNum& operator+=(const BigNum &num) {
		string suma;
		int carry = 0, add;
		for (int i = this->data.length() - 1, j = num.data.length() - 1; i >= 0 || j >= 0; --i, --j) {
			if (i >= 0 && j >= 0)
				add = (this->data[i] - '0') + (num.data[j] - '0') + carry;
			else if (i >= 0)
				add = (this->data[i] - '0') + carry;
			else
				add = (num.data[j] - '0') + carry;
			// Ajustar la llevada
			if (add > 9) {
				carry = 1;
				suma.push_back((add - 10) + '0');
			} else {
				carry = 0;
				suma.push_back(add + '0');
			}
		}
		if (carry == 1)
			suma.push_back('1');
		this->data = string(suma.rbegin(), suma.rend());
		return *this;
	}
	/************* SUMA *************/
	const BigNum operator+(const BigNum &num) const {
		return BigNum(*this) += num;
	}
	/************* INSERCIÓN-EXTRACCIÓN *************/
	friend istream& operator>>(istream &in, BigNum &num) {
		in >> num.data;
		return in;
	}
	friend ostream& operator<<(ostream &out, const BigNum &num) {
		out << num.data;
		return out;
	}
	/************* COMPARACIÓN *************/
	inline bool operator==(const BigNum &num) const {
		return (this->data == num.data);
	}
	inline bool operator!=(const BigNum &num) const {
		return !operator==(num);
	}
	inline bool operator<(const BigNum &num) const {
		if (this->data.length() == num.data.length())
			return (this->data < num.data);
		return (this->data.length() < num.data.length());
	}
	inline bool operator>(const BigNum &num) const {
		return num.operator<(*this);
	}
	inline bool operator<=(const BigNum &num) const {
		return !operator>(num);
	}
	inline bool operator>=(const BigNum &num) const {
		return !operator<(num);
	}
};


int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	vector<BigNum> Fibo;
	Fibo.push_back("1");
	Fibo.push_back("2");

	int numFibos = 2;
	BigNum a, b;
	cin >> a >> b;
	while (a != "0" || b != "0") {
		while (Fibo[numFibos-1] < b) {
			// Buscar más números de Fibonacci
			Fibo.push_back( Fibo[numFibos-2] + Fibo[numFibos-1] );
			numFibos++;
		}

		// Contar cuántos números de Fibonacci hay entre a y b
		int cont = 0, i = 0;
		while (Fibo[i] < a) ++i;
		while (Fibo[i] <= b) {
			++cont;
			++i;
		}
		cout << cont << endl;

		cin >> a >> b;
	}

	return 0;
}
