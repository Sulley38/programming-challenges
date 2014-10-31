#include <iostream>
#include <fstream>

using namespace std;

#define MAX_DIGITS 512

/*
 * Clase para trabajar con números muy grandes
 * Requiere <iostream>
 */
class BigInt {
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
	BigInt();
	BigInt(const int numero);
	BigInt(const char* numero);
	// Operadores combinados aritméticos-asignación
	const BigInt& operator=(const BigInt &num);
	const BigInt& operator+=(const BigInt &num);
	const BigInt& operator-=(const BigInt &num);
	const BigInt& operator*=(const BigInt &num);
	const BigInt& operator/=(const BigInt &num);
	const BigInt& operator%=(const BigInt &num);
	// Operadores aritméticos unarios
	BigInt operator+() const;
	BigInt operator-() const;
	BigInt& operator++();
	BigInt operator++(int);
	BigInt& operator--();
	BigInt operator--(int);
	// Operadores aritméticos binarios
	friend const BigInt operator+(const BigInt &num1, const BigInt &num2);
	friend const BigInt operator+(const BigInt &num1, const int &num2);
	friend const BigInt operator-(const BigInt &num1, const BigInt &num2);
	friend const BigInt operator-(const BigInt &num1, const int &num2);
	friend const BigInt operator*(const BigInt &num1, const BigInt &num2);
	friend const BigInt operator*(const BigInt &num1, const int &num2);
	friend const BigInt operator/(const BigInt &num1, const BigInt &num2);
	friend const BigInt operator/(const BigInt &num1, const int &num2);
	friend const BigInt operator%(const BigInt &num1, const BigInt &num2);
	friend const BigInt operator%(const BigInt &num1, const int &num2);
	// Operadores de inserción-extracción
	friend istream& operator>>(istream &in, BigInt &num);
	friend ostream& operator<<(ostream &out, const BigInt &num);
	// Operadores lógicos
	const bool operator!() const;
	// Operadores de comparación
	bool operator==(const BigInt &num) const;
	bool operator!=(const BigInt &num) const;
	bool operator<(const BigInt &num) const;
	bool operator>(const BigInt &num) const;
	bool operator<=(const BigInt &num) const;
	bool operator>=(const BigInt &num) const;
};

/************* CONSTRUCCIÓN *************/
BigInt::BigInt() {
	data[0] = 0;
	longitud = 1;
	signo = true;
}
BigInt::BigInt(const int numero) {
	int n = numero;
	longitud = 0;
	while (n > 0) {
		data[longitud] = n % 10;
		longitud++;
		n /= 10;
	}
	signo = (numero >= 0);
}
BigInt::BigInt(const char* numero) {
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
const BigInt& BigInt::operator=(const BigInt &num) {
	if (this != &num) {
		copy(num.data, num.data + num.longitud, this->data);
		this->longitud = num.longitud;
		this->signo = num.signo;
	}
	return *this;
}
/************* SUMA-ASIGNACIÓN *************/
const BigInt& BigInt::operator+=(const BigInt &num) {
	BigInt tempA = *this, tempB = num;
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
const BigInt& BigInt::operator-=(const BigInt &num) {
	this->operator+=(-num);
	return *this;
}
/************* PRODUCTO-ASIGNACIÓN *************/
const BigInt& BigInt::operator*=(const BigInt &num) {
	BigInt temp;
	temp.signo = (this->signo == num.signo);
	Multiplicar(this->data, this->longitud, num.data, num.longitud, temp.data, temp.longitud);
	*this = temp;
	return *this;
}
/************* DIVISIÓN-ASIGNACIÓN *************/
const BigInt& BigInt::operator/=(const BigInt &num) {
	if (num.longitud == 1 && num.data[0] == 0) {
		throw "DivisionByZero";
	} else if (Mayor(num.data, num.longitud, this->data, this->longitud)) {
		this->data[0] = 0;
		this->longitud = 1;
	} else if (num.longitud == 1) {
		char resto;
		DividirLongitudUno(this->data, this->longitud, num.data[0], this->data, this->longitud, resto);
	} else {
		BigInt tempR;
		this->signo = (this->signo == num.signo);
		Dividir(this->data, this->longitud, num.data, num.longitud, this->data, this->longitud, tempR.data, tempR.longitud);
	}
	return *this;
}
/************* MÓDULO-ASIGNACIÓN *************/
const BigInt& BigInt::operator%=(const BigInt &num) {
	if (num.longitud == 1 && num.data[0] == 0) {
		throw "DivisionByZero";
	} else if (!Mayor(num.data, num.longitud, this->data, this->longitud)) {
		if (num.longitud == 1) {
			char resto;
			DividirLongitudUno(this->data, this->longitud, num.data[0], this->data, this->longitud, resto);
			this->data[0] = resto;
			this->longitud = 1;
		} else {
			BigInt tempC;
			this->signo = (this->signo == num.signo);
			Dividir(this->data, this->longitud, num.data, num.longitud, tempC.data, tempC.longitud, this->data, this->longitud);
		}
	}
	return *this;
}
/************* PROMOCIÓN A ENTERO *************/
BigInt BigInt::operator+() const {
	return *this;
}
/************* NEGACIÓN *************/
BigInt BigInt::operator-() const {
	BigInt temp = *this;
	temp.signo = !temp.signo;
	return temp;
}
/************* INCREMENTO *************/
BigInt& BigInt::operator++() {
	this->operator+=(1);
	return *this;
}
BigInt BigInt::operator++(int) {
	BigInt resultado = *this;
	this->operator+=(1);
	return resultado;
}
/************* DECREMENTO *************/
BigInt& BigInt::operator--() {
	this->operator-=(1);
	return *this;
}
BigInt BigInt::operator--(int) {
	BigInt resultado = *this;
	this->operator-=(1);
	return resultado;
}
/************* SUMA *************/
const BigInt operator+(const BigInt &num1, const BigInt &num2) {
	return BigInt(num1) += num2;
}
const BigInt operator+(const BigInt &num1, const int &num2) {
	return BigInt(num1) += BigInt(num2);
}
/************* RESTA *************/
const BigInt operator-(const BigInt &num1, const BigInt &num2) {
	return BigInt(num1) -= num2;
}
const BigInt operator-(const BigInt &num1, const int &num2) {
	return BigInt(num1) -= BigInt(num2);
}
/************* PRODUCTO *************/
const BigInt operator*(const BigInt &num1, const BigInt &num2) {
	return BigInt(num1) *= num2;
}
const BigInt operator*(const BigInt &num1, const int &num2) {
	return BigInt(num1) *= BigInt(num2);
}
/************* DIVISIÓN *************/
const BigInt operator/(const BigInt &num1, const BigInt &num2) {
	return BigInt(num1) /= num2;
}
const BigInt operator/(const BigInt &num1, const int &num2) {
	return BigInt(num1) /= BigInt(num2);
}
/************* MÓDULO *************/
const BigInt operator%(const BigInt &num1, const BigInt &num2) {
	return BigInt(num1) %= num2;
}
const BigInt operator%(const BigInt &num1, const int &num2) {
	return BigInt(num1) %= BigInt(num2);
}
/************* INSERCIÓN-EXTRACCIÓN *************/
istream& operator>>(istream &in, BigInt &num) {
	char temp[MAX_DIGITS];
	in >> temp;
	num = BigInt(temp);
	return in;
}
ostream& operator<<(ostream &out, const BigInt &num) {
	if (num.signo == false)
		out.put('-');
	for (int i = num.longitud - 1; i >= 0; --i)
		out.put(num.data[i] + '0');
	return out;
}
/************* NEGACIÓN LÓGICA *************/
const bool BigInt::operator!() const {
	return (this->longitud == 1 && this->data[0] == 0);
}
/************* COMPARACIÓN *************/
inline bool BigInt::operator==(const BigInt &num) const {
	return (this->data == num.data) && (this->signo == num.signo);
}
inline bool BigInt::operator!=(const BigInt &num) const {
	return !operator==(num);
}
bool BigInt::operator<(const BigInt &num) const {
	if (this->signo == true && num.signo == true)
		return Mayor(num.data, num.longitud, this->data, this->longitud);
	else if (this->signo == false && num.signo == false)
		return Mayor(this->data, this->longitud, num.data, num.longitud);
	else
		return (this->signo == false);
}
inline bool BigInt::operator>(const BigInt &num) const {
	return num.operator<(*this);
}
inline bool BigInt::operator<=(const BigInt &num) const {
	return !operator>(num);
}
inline bool BigInt::operator>=(const BigInt &num) const {
	return !operator<(num);
}
/************* OPERACIONES INTERNAS *************/
// True si a es mayor que b
bool BigInt::Mayor(const char* a, const int &m, const char* b, const int &n) const {
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
void BigInt::Sumar(const char* a, const char* b, const int &n, char* suma, int &lsuma) const {
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
void BigInt::Restar(const char* a, const char* b, const int &n, char* resta, int &lresta) const {
	int j = 0, k = 0, t;
	while (j < n) {
		t = a[j] - b[j] + k + 10, resta[j] = t % 10, k = (t / 10) - 1;
		j++;
	}
	lresta = n;
	QuitarCeros(resta, lresta);
}
// Multiplica dos números: a * b
void BigInt::Multiplicar(const char* a, const int &m, const char* b, const int& n, char* mult, int &lmult) const {
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
void BigInt::Dividir(const char* a, const int &m, const char* b, const int &n, char* q, int &lq, char* r, int &lr) const {
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
void BigInt::DividirLongitudUno(const char* a, const int &m, const char &b, char* q, int &lq, char &r) const {
	int j = m - 1, t;
	lq = m, r = 0;
	while (j >= 0) {
		t = r*10 + a[j], q[j] = t / b, r = t % b;
		j--;
	}
	QuitarCeros(q, lq);
}
// Quita ceros a la izquierda del número
void BigInt::QuitarCeros(char* a, int &m) const {
	while (m > 1 && a[m-1] == 0)
		m--;
}
// Iguala las longitudes de dos números añadiendo ceros a la izquierda del menor
void BigInt::Equilibrar(char* a, int &m, char* b, int &n) const {
	while (m > n) {
		b[n] = 0;
		n++;
	}
	while (n > m) {
		a[m] = 0;
		m++;
	}
}


int main(int argc, char** argv) {
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	int n;
	BigInt valores[1000];
	valores[0] = 2, valores[1] = 5, valores[2] = 13, valores[3] = 33;
	for (n = 4; n < 1000; ++n)
		valores[n] = valores[n-1] + valores[n-1] + valores[n-2] + valores[n-3];
	while (cin >> n)
		cout << valores[n-1] << endl;
	return 0;
}
