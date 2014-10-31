#include <algorithm>
#include <bitset>
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

/************ COMIENZO DE DEFINICIÓN DE CLASE BIGINTEGER ************/

#define MAX_DIGITS 620

/*
 * Clase para trabajar con números muy grandes
 * Requiere <iostream>
 */
class BigInteger {
private:
	char data[MAX_DIGITS]; // Dígitos, data[0] es el menos significativo
	int longitud;
	bool signo; // True = Positivo, False = Negativo
	// Funciones de uso interno
	bool Mayor(const char* a, const int &m, const char* b, const int &n) const;
	void Sumar(const char* a, const char* b, const int &n, char* suma, int &lsuma) const;
	void Restar(const char* a, const char* b, const int &n, char* resta, int &lresta) const;
	void Multiplicar(const char* a, const int &m, const char* b, const int& n, char* mult, int &lmult) const;
	void Dividir(const char* a, const int &m, const char* b, const int &n, char* q, int &lq, char* r, int &lr) const;
	void DividirLongitudUno(const char* a, const int &m, const char &b, char* q, int &lq, char &r) const;
	void QuitarCeros(char* a, int &m) const;
	void Equilibrar(char* a, int &m, char* b, int &n) const;
public:
	// Métodos constructores
	BigInteger();
	BigInteger(const int numero);
	BigInteger(const char* numero);
	// Operadores combinados aritméticos-asignación
	const BigInteger& operator=(const BigInteger &num);
	const BigInteger& operator+=(const BigInteger &num);
	const BigInteger& operator-=(const BigInteger &num);
	const BigInteger& operator*=(const BigInteger &num);
	const BigInteger& operator/=(const BigInteger &num);
	const BigInteger& operator%=(const BigInteger &num);
	// Operadores aritméticos unarios
	BigInteger operator+() const;
	BigInteger operator-() const;
	BigInteger& operator++();
	BigInteger operator++(int);
	BigInteger& operator--();
	BigInteger operator--(int);
	// Operadores aritméticos binarios
	friend const BigInteger operator+(const BigInteger &num1, const BigInteger &num2);
	friend const BigInteger operator+(const BigInteger &num1, const int &num2);
	friend const BigInteger operator-(const BigInteger &num1, const BigInteger &num2);
	friend const BigInteger operator-(const BigInteger &num1, const int &num2);
	friend const BigInteger operator*(const BigInteger &num1, const BigInteger &num2);
	friend const BigInteger operator*(const BigInteger &num1, const int &num2);
	friend const BigInteger operator/(const BigInteger &num1, const BigInteger &num2);
	friend const BigInteger operator/(const BigInteger &num1, const int &num2);
	friend const BigInteger operator%(const BigInteger &num1, const BigInteger &num2);
	friend const BigInteger operator%(const BigInteger &num1, const int &num2);
	// Operadores de inserción-extracción
	friend istream& operator>>(istream &in, BigInteger &num);
	friend ostream& operator<<(ostream &out, const BigInteger &num);
	// Operadores lógicos
	const bool operator!() const;
	// Operadores de comparación
	bool operator==(const BigInteger &num) const;
	bool operator!=(const BigInteger &num) const;
	bool operator<(const BigInteger &num) const;
	bool operator>(const BigInteger &num) const;
	bool operator<=(const BigInteger &num) const;
	bool operator>=(const BigInteger &num) const;
};

/************* CONSTRUCCIÓN *************/
BigInteger::BigInteger() {
	data[0] = 0;
	longitud = 1;
	signo = true;
}
BigInteger::BigInteger(const int numero) {
	int n = max(numero, -numero);
	if (n == 0) {
		data[0] = 0;
		longitud = 1;
	} else {
		longitud = 0;
		while (n > 0) {
			data[longitud] = n % 10;
			longitud++;
			n /= 10;
		}
	}
	signo = (numero >= 0);
}
BigInteger::BigInteger(const char* numero) {
	longitud = 0;
	while (numero[longitud] != '\0')
		longitud++;
	int ajuste = 0;
	if (numero[0] == '-') {
		signo = false;
		ajuste = 1;
	} else {
		signo = true;
		data[longitud-1] = numero[0] - '0';
	}
	for (int i = 1; i < longitud; ++i)
		data[longitud-1-i] = numero[i] - '0';
	longitud -= ajuste;
	QuitarCeros(data, longitud);
}
/************* ASIGNACIÓN *************/
const BigInteger& BigInteger::operator=(const BigInteger &num) {
	if (this != &num) {
		copy(num.data, num.data + num.longitud, this->data);
		this->longitud = num.longitud;
		this->signo = num.signo;
	}
	return *this;
}
/************* SUMA-ASIGNACIÓN *************/
const BigInteger& BigInteger::operator+=(const BigInteger &num) {
	BigInteger tempA = *this, tempB = num;
	Equilibrar(tempA.data, tempA.longitud, tempB.data, tempB.longitud);
	if (this->signo == num.signo) {
		Sumar(tempA.data, tempB.data, tempA.longitud, this->data, this->longitud);
	} else if (this->signo == true && num.signo == false) {
		if (Mayor(num.data, num.longitud, this->data, this->longitud)) {
			Restar(tempB.data, tempA.data, tempA.longitud, this->data, this->longitud);
			this->signo = false;
		} else {
			Restar(tempA.data, tempB.data, tempA.longitud, this->data, this->longitud);
		}
	} else {
		if (Mayor(this->data, this->longitud, num.data, num.longitud)) {
			Restar(tempA.data, tempB.data, tempA.longitud, this->data, this->longitud);
		} else {
			Restar(tempB.data, tempA.data, tempA.longitud, this->data, this->longitud);
			this->signo = true;
		}
	}
	return *this;
}
/************* RESTA-ASIGNACIÓN *************/
const BigInteger& BigInteger::operator-=(const BigInteger &num) {
	this->operator+=(-num);
	return *this;
}
/************* PRODUCTO-ASIGNACIÓN *************/
const BigInteger& BigInteger::operator*=(const BigInteger &num) {
	BigInteger temp;
	temp.signo = (this->signo == num.signo);
	Multiplicar(this->data, this->longitud, num.data, num.longitud, temp.data, temp.longitud);
	*this = temp;
	return *this;
}
/************* DIVISIÓN-ASIGNACIÓN *************/
const BigInteger& BigInteger::operator/=(const BigInteger &num) {
	if (num.longitud == 1 && num.data[0] == 0) {
		throw "DivisionByZero";
	} else if (Mayor(num.data, num.longitud, this->data, this->longitud)) {
		this->data[0] = 0;
		this->longitud = 1;
	} else if (num.longitud == 1) {
		char resto;
		this->signo = (this->signo == num.signo);
		DividirLongitudUno(this->data, this->longitud, num.data[0], this->data, this->longitud, resto);
	} else {
		BigInteger tempR;
		this->signo = (this->signo == num.signo);
		Dividir(this->data, this->longitud, num.data, num.longitud, this->data, this->longitud, tempR.data, tempR.longitud);
	}
	return *this;
}
/************* MÓDULO-ASIGNACIÓN *************/
const BigInteger& BigInteger::operator%=(const BigInteger &num) {
	if (num.longitud == 1 && num.data[0] == 0) {
		throw "DivisionByZero";
	} else if (!Mayor(num.data, num.longitud, this->data, this->longitud)) {
		if (num.longitud == 1) {
			char resto;
			DividirLongitudUno(this->data, this->longitud, num.data[0], this->data, this->longitud, resto);
			this->data[0] = resto;
			this->longitud = 1;
		} else {
			BigInteger tempC;
			this->signo = (this->signo == num.signo);
			Dividir(this->data, this->longitud, num.data, num.longitud, tempC.data, tempC.longitud, this->data, this->longitud);
		}
	}
	return *this;
}
/************* PROMOCIÓN A ENTERO *************/
BigInteger BigInteger::operator+() const {
	return *this;
}
/************* NEGACIÓN *************/
BigInteger BigInteger::operator-() const {
	BigInteger temp = *this;
	temp.signo = !temp.signo;
	return temp;
}
/************* INCREMENTO *************/
BigInteger& BigInteger::operator++() {
	this->operator+=(1);
	return *this;
}
BigInteger BigInteger::operator++(int) {
	BigInteger resultado = *this;
	this->operator+=(1);
	return resultado;
}
/************* DECREMENTO *************/
BigInteger& BigInteger::operator--() {
	this->operator-=(1);
	return *this;
}
BigInteger BigInteger::operator--(int) {
	BigInteger resultado = *this;
	this->operator-=(1);
	return resultado;
}
/************* SUMA *************/
const BigInteger operator+(const BigInteger &num1, const BigInteger &num2) {
	return BigInteger(num1) += num2;
}
const BigInteger operator+(const BigInteger &num1, const int &num2) {
	return BigInteger(num1) += BigInteger(num2);
}
/************* RESTA *************/
const BigInteger operator-(const BigInteger &num1, const BigInteger &num2) {
	return BigInteger(num1) -= num2;
}
const BigInteger operator-(const BigInteger &num1, const int &num2) {
	return BigInteger(num1) -= BigInteger(num2);
}
/************* PRODUCTO *************/
const BigInteger operator*(const BigInteger &num1, const BigInteger &num2) {
	return BigInteger(num1) *= num2;
}
const BigInteger operator*(const BigInteger &num1, const int &num2) {
	return BigInteger(num1) *= BigInteger(num2);
}
/************* DIVISIÓN *************/
const BigInteger operator/(const BigInteger &num1, const BigInteger &num2) {
	return BigInteger(num1) /= num2;
}
const BigInteger operator/(const BigInteger &num1, const int &num2) {
	return BigInteger(num1) /= BigInteger(num2);
}
/************* MÓDULO *************/
const BigInteger operator%(const BigInteger &num1, const BigInteger &num2) {
	return BigInteger(num1) %= num2;
}
const BigInteger operator%(const BigInteger &num1, const int &num2) {
	return BigInteger(num1) %= BigInteger(num2);
}
/************* INSERCIÓN-EXTRACCIÓN *************/
istream& operator>>(istream &in, BigInteger &num) {
	char temp[MAX_DIGITS];
	in >> temp;
	num = BigInteger(temp);
	return in;
}
ostream& operator<<(ostream &out, const BigInteger &num) {
	if (num.signo == false && (num.longitud > 1 || num.data[0] != 0))
		out.put('-');
	for (int i = num.longitud - 1; i >= 0; --i)
		out.put(num.data[i] + '0');
	return out;
}
/************* NEGACIÓN LÓGICA *************/
const bool BigInteger::operator!() const {
	return (this->longitud == 1 && this->data[0] == 0);
}
/************* COMPARACIÓN *************/
bool BigInteger::operator==(const BigInteger &num) const {
	if ((this->signo != num.signo) || (this->longitud != num.longitud))
		return false;
	for (int i = 0; i < this->longitud; ++i)
		if (this->data[i] != num.data[i])
			return false;
	return true;
}
inline bool BigInteger::operator!=(const BigInteger &num) const {
	return !operator==(num);
}
bool BigInteger::operator<(const BigInteger &num) const {
	if (this->signo == true && num.signo == true)
		return Mayor(num.data, num.longitud, this->data, this->longitud);
	else if (this->signo == false && num.signo == false)
		return Mayor(this->data, this->longitud, num.data, num.longitud);
	else
		return (this->signo == false);
}
inline bool BigInteger::operator>(const BigInteger &num) const {
	return num.operator<(*this);
}
inline bool BigInteger::operator<=(const BigInteger &num) const {
	return !operator>(num);
}
inline bool BigInteger::operator>=(const BigInteger &num) const {
	return !operator<(num);
}
/************* OPERACIONES INTERNAS *************/
// True si a es mayor que b
bool BigInteger::Mayor(const char* a, const int &m, const char* b, const int &n) const {
	if (m != n)
		return (m > n);
	for (int i = m - 1; i >= 0; --i) {
		if (a[i] > b[i])
			return true;
		else if (a[i] < b[i])
			return false;
	}
	return false;
}
// Algoritmos de operaciones extraídos del libro: The Art of Computer Programming, Vol. 2. Donald Knuth.
// Suma dos números positivos de la misma longitud: a + b
void BigInteger::Sumar(const char* a, const char* b, const int &n, char* suma, int &lsuma) const {
	int j = 0, k = 0, t;
	while (j < n) {
		t = a[j] + b[j] + k, suma[j] = t % 10, k = t / 10;
		j++;
	}
	suma[j] = k;
	lsuma = n + 1;
	QuitarCeros(suma, lsuma);
}
// Suma un número positivo y otro negativo igual o más pequeño pero de misma longitud: a - b, a >= b
void BigInteger::Restar(const char* a, const char* b, const int &n, char* resta, int &lresta) const {
	int j = 0, k = 0, t;
	while (j < n) {
		t = a[j] - b[j] + k + 10, resta[j] = t % 10, k = (t / 10) - 1;
		j++;
	}
	lresta = n;
	QuitarCeros(resta, lresta);
}
// Multiplica dos números: a * b
void BigInteger::Multiplicar(const char* a, const int &m, const char* b, const int& n, char* mult, int &lmult) const {
	int j = 0, i, k, t;
	for (i = 0; i < m; ++i)
		mult[i] = 0;
	while (j < n) {
		if (b[j] == 0) {
			mult[j+m] = 0;
		} else {
			i = 0, k = 0;
			while (i < m) {
				t = a[i] * b[j] + mult[i+j] + k, mult[i+j] = t % 10, k = t / 10;
				i++;
			}
			mult[j+m] = k;
		}
		j++;
	}
	lmult = m + n;
	QuitarCeros(mult, lmult);
}
// División entera de dos números, divisor positivo: a / b, b > 0, a >= b
// http://www.loria.fr/~zimmerma/mca/mca-0.2.pdf Pág. 22
void BigInteger::Dividir(const char* a, const int &m, const char* b, const int &n, char* q, int &lq, char* r, int &lr) const {
	// Normalizar
	char u[MAX_DIGITS], v[MAX_DIGITS], t[MAX_DIGITS], d = 10 / (b[n-1] + 1);
	int x = m, y = n, lt, ceros, j;
	if (d == 1) {
		ceros = m - n;
		copy(a, a + m, u);
		copy(b, b + n, v + ceros);
	} else {
		Multiplicar(a, m, &d, 1, u, x);
		Multiplicar(b, n, &d, 1, q, y);
		ceros = x - y;
		copy(q, q + y, v + ceros);
	}
	y = x;
	for (j = 0; j < ceros; ++j)
		v[j] = 0;
	// Primer dígito del cociente
	if (!Mayor(v, y, u, x)) {
		q[ceros] = 1;
		Restar(u, v, x, u, x);
	} else {
		q[ceros] = 0;
	}
	// Resto de dígitos
	char *B = v;
	for (j = ceros - 1; j >= 0; --j) {
		B++; // Dividir v entre 10
		y--;
		q[j] = (u[n+j]*10 + u[n+j-1]) / B[y-1];
		if (q[j] > 9)
			q[j] = 9;
		Multiplicar(B, y, &q[j], 1, t, lt); // t = cociente * divisor
		while (Mayor(t, lt, u, x)) {
			q[j]--;
			Equilibrar(t, lt, B, y);
			Restar(t, B, y, t, lt); // t -= divisor
		}
		Equilibrar(t, lt, u, x);
		Restar(u, t, lt, u, x); // x -= t
		QuitarCeros(B, y);
	}
	// Denormalizar: dividir el resto entre d
	lq = ceros + 1;
	if (d == 1) {
		copy(u, u + x, r);
		lr = x;
	} else {
		char resto;
		DividirLongitudUno(u, x, d, r, lr, resto); // r = a / d
	}
	QuitarCeros(q, lq), QuitarCeros(r, lr);
}
// División entera de un número entre un dígito positivo: a / b, 0 < b <= 9
void BigInteger::DividirLongitudUno(const char* a, const int &m, const char &b, char* q, int &lq, char &r) const {
	int j = m - 1, t;
	lq = m, r = 0;
	while (j >= 0) {
		t = r*10 + a[j], q[j] = t / b, r = t % b;
		j--;
	}
	QuitarCeros(q, lq);
}
// Quita ceros a la izquierda del número
void BigInteger::QuitarCeros(char* a, int &m) const {
	while (m > 1 && a[m-1] == 0)
		m--;
}
// Iguala las longitudes de dos números añadiendo ceros a la izquierda del menor
void BigInteger::Equilibrar(char* a, int &m, char* b, int &n) const {
	while (m > n) {
		b[n] = 0;
		n++;
	}
	while (n > m) {
		a[m] = 0;
		m++;
	}
}

/************ FIN DE DEFINICIÓN DE CLASE BIGINTEGER ************/

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	BigInteger C[1001];
	int i, a, b;
	C[0] = C[1] = 1;
	for (i = 1; i < 1000; ++i) {
		a = 4 * i + 2;
		b = i + 2;
		C[i + 1] = a * C[i] / b;
	}

	while (cin >> i) {
		cout << C[i] << endl;
	}

	return 0;
}
