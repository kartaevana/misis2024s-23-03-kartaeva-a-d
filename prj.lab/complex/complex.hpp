#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <sstream>
#include <iosfwd>

struct Complex {
    Complex() = default; //умолчательный конструктор

    Complex(const Complex&) = default; //копирующий конструктор

    explicit Complex(const double real) : re(real) { }

    Complex(const double real, const double imaginary) : re(real), im(imaginary) { }

    Complex& operator=(const Complex&) = default; // присваивание

    ~Complex() = default; // деструктор

    Complex operator-() const noexcept; // унарный минус

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


    std::ostream& WriteTo(std::ostream& ostrm) const;
    std::istream& ReadFrom(std::istream& istrm) noexcept;

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

Complex operator+ (const Complex& lhs, const Complex& rhs) noexcept;
inline Complex operator+ (double& lhs, const Complex& rhs) noexcept;
inline Complex operator+ (Complex& lhs, const double& rhs) noexcept;

Complex operator- (const Complex& lhs, const Complex& rhs) noexcept;
inline Complex operator- (double& lhs, const Complex& rhs) noexcept;
inline Complex operator- (Complex& lhs, const double& rhs) noexcept;

Complex operator* (const Complex& lhs, const Complex& rhs) noexcept;
inline Complex operator* (double& lhs, const Complex& rhs) noexcept;
inline Complex operator* (Complex& lhs, const double& rhs) noexcept;

Complex operator/ (const Complex& lhs, const Complex& rhs);
inline Complex operator/ (double& lhs, const Complex& rhs);
inline Complex operator/ (Complex& lhs, const double& rhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
    return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
    return rhs.ReadFrom(istrm);
}

#endif
