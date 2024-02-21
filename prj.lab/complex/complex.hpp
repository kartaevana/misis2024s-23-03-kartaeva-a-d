#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <limits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iosfwd>

struct Complex {
    [[nodiscard]] Complex() = default; //умолчательный конструктор
    [[nodiscard]] Complex(const Complex& rhs) = default; //копирующий конструктор
    [[nodiscard]] explicit Complex(const double real) : re(real), im(0) {}
    [[nodiscard]] Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
    ~Complex() = default; // деструктор

    Complex& operator=(const Complex& rhs);// присваивание
    Complex& operator=(double rhs);

    Complex operator-() const noexcept { return Complex(-re, -im); } // унарный минус

    // сравнение комплексных чисел на равенство

    bool operator== (const Complex& rhs) const;
    bool operator== (const double rhs) const;

    bool operator!= (const Complex& rhs) const;
    bool operator!= (const double rhs) const;

    Complex& operator+= (const Complex& rhs);
    Complex& operator+= (const double rhs);

    Complex& operator-= (const Complex& rhs);
    Complex& operator-= (const double rhs);

    Complex& operator*= (const Complex& rhs);
    Complex& operator*= (const double rhs);

    Complex& operator/= (const Complex& rhs);
    Complex& operator/= (const double rhs);


    std::ostream& WriteTo(std::ostream& stream) const;
    std::istream& ReadFrom(std::istream& srteam) noexcept;

    void conjugate();

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
    const double minDiff = 2 * std::numeric_limits<double>::epsilon();
};

Complex operator+ (const Complex& lhs, const Complex& rhs);
Complex operator+ (double lhs, const Complex& rhs);
Complex operator+ (const Complex& lhs, const double rhs);

Complex operator- (const Complex& lhs, const Complex& rhs);
Complex operator- (double lhs, const Complex& rhs);
Complex operator- (const Complex& lhs, const double rhs);

Complex operator* (const Complex& lhs, const Complex& rhs);
Complex operator* (double lhs, const Complex& rhs);
Complex operator* (Complex& lhs, const double rhs);

Complex operator/ (const Complex& lhs, const Complex& rhs);
Complex operator/ (double lhs, const Complex& rhs);
Complex operator/ (Complex& lhs, const double rhs);


std::istream& operator>>(std::istream& stream, Complex& val);
std::ostream& operator<<(std::ostream& stream, const Complex& val);

#endif
