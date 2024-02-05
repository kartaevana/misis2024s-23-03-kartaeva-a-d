#include "rational.hpp"

Rational::Rational(const int64_t num) : num(num), den(1) {}
Rational::Rational(const int64_t lhs, const int64_t rhs) : num(lhs), den(rhs) {
	if (rhs == 0) {
		throw std::invalid_argument("Zero denumenator in Rational");
		den = 1;
	}
}

Rational& Rational::operator=(const Rational& rhs) {
	num = rhs.num;
	den = rhs.den;
	(*this).simplify();
	return *this;
}
Rational& Rational::operator=(const int64_t& rhs) {
	num = rhs;
	den = 1;
	return *this;
}

bool Rational::operator==(Rational rhs) {
	rhs.simplify();
	(*this).simplify();
	return (num == rhs.num) && (den == rhs.den);
}
bool Rational::operator==(int64_t rhs) {
	return (*this) == Rational(rhs);
}

bool Rational::operator!=(Rational rhs) {
	return !((*this) == rhs);
}
bool Rational::operator!=(int64_t rhs) {
	return (*this) != Rational(rhs);
}

bool Rational::operator>(Rational rhs) {
	if (num * rhs.den - den * rhs.num > 0) {
		return 1;
	}
	return 0;
}
bool Rational::operator>(int64_t rhs) {
	return (*this) > Rational(rhs);
}

bool Rational::operator<(Rational rhs) {
	return !((*this) > rhs);
}
bool Rational::operator<(int64_t rhs) {
	return (*this) < Rational(rhs);
}

bool Rational::operator>=(Rational rhs) {
	return ((*this) > rhs) || (*this) == rhs;
}
bool Rational::operator>=(int64_t rhs) {
	return (*this) >= Rational(rhs);
}

bool Rational::operator<=(Rational rhs) {
	return ((*this) < rhs) || (*this) == rhs;
}
bool Rational::operator<=(int64_t rhs) {
	return (*this) <= Rational(rhs);
}



Rational& Rational::operator+=(const Rational& rhs) {
	num = num * rhs.den + rhs.num * den;
	den = den * rhs.den;
	return *this;
}
Rational& Rational::operator+=(const int64_t& rhs) {
	return *this += Rational(rhs);
}

Rational& Rational::operator-=(const Rational& rhs) {
	num = num * rhs.den - rhs.num * den;
	den = den * rhs.den;
	return *this;
}
Rational& Rational::operator-=(const int64_t& rhs) {
	return *this -= Rational(rhs);
}

Rational& Rational::operator*=(const Rational& rhs) {
	num *= rhs.num;
	den *= rhs.den;
	return *this;
}
Rational& Rational::operator*=(const int64_t& rhs) {
	return *this *= Rational(rhs);
}

Rational& Rational::operator/=(const Rational& rhs) {
	return *this *= Rational(rhs.den, rhs.num);
}
Rational& Rational::operator/=(const int64_t& rhs) {
	if (rhs == 0) {
		throw std::invalid_argument("Zero denumenator in Rational");
		return *this;
	}
	return *this *= Rational(1, rhs);
}

Rational& Rational::simplify() {
	int64_t a = num;
	int64_t b = den;
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	num /= (a + b);
	den /= (a + b);
	if (den < 0) {
		num = -num;
		den = -den;
	}
	return *this;
}

int64_t Rational::Num() const {
	return (*this).num;
}
int64_t Rational::Den() const {
	return (*this).den;
}
void Rational::setNum(const int64_t& rhs) {
	num = rhs;
	(*this).simplify();
}
void Rational::setDen(const int64_t& rhs) {
	den = rhs;
	(*this).simplify();
}

std::ostream& operator<<(std::ostream& ostr, Rational num) {
	num.simplify();
	return ostr << num.Num() << num.slash << num.Den();
}
std::istream& operator>>(std::istream& istr, Rational& num) {
	int64_t up(0);
	char slash(0);
	int64_t down(0);
	istr >> up >> slash >> down;
	if (down == 0) {
		throw std::invalid_argument("Zero denumenator in Rational");
		down = 1;
	}
	if ((istr.good()) && (slash == '/')) {
		num.setNum(up);
		num.setDen(down);
	}
	else {
		istr.setstate(std::ios_base::failbit);
	}
	return istr;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	int64_t num1 = lhs.Num() * rhs.Den() + lhs.Den() * rhs.Num();
	int64_t num2 = lhs.Den() * rhs.Den();
	return Rational(num1, num2);
}
Rational operator+(const Rational& lhs, const int64_t& rhs) {
	return lhs + Rational(rhs);
}
Rational operator+(const int64_t& lhs, const Rational& rhs) {
	return Rational(lhs) + rhs;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int64_t num1 = lhs.Num() * rhs.Den() - lhs.Den() * rhs.Num();
	int64_t num2 = lhs.Den() * rhs.Den();
	return Rational(num1, num2);
}
Rational operator-(const Rational& lhs, const int64_t& rhs) {
	return lhs - Rational(rhs);
}
Rational operator-(const int64_t& lhs, const Rational& rhs) {
	return Rational(lhs) - rhs;
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
	int64_t num1 = lhs.Num() * rhs.Num();
	int64_t num2 = lhs.Den() * rhs.Den();
	return Rational(num1, num2);
}
Rational operator*(const Rational& lhs, const int64_t& rhs) {
	return lhs * Rational(rhs);
}
Rational operator*(const int64_t& lhs, const Rational& rhs) {
	return Rational(lhs) * rhs;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	int64_t num1 = lhs.Num() * rhs.Den();
	int64_t num2 = lhs.Den() * rhs.Num();
	return Rational(num1, num2);
}
Rational operator/(const Rational& lhs, const int64_t& rhs) {
	return lhs / Rational(rhs);
}
Rational operator/(const int64_t& lhs, const Rational& rhs) {
	return Rational(lhs) / rhs;
}
