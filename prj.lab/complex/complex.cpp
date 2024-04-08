#include "complex.hpp"


Complex::Complex(const double real)
        : Complex(real, 0.0) {}

Complex::Complex(const double real, const double imaginary)
        : re(real),
        im(imaginary) {}

Complex Complex::operator-() const noexcept {
    return Complex{-re, -im};
}

bool Complex::operator!=(const Complex& rhs) const noexcept {
    return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept{
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) noexcept{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
    double re_c = re;
    double im_c = im;
    re = re*rhs.re - im*rhs.im;
    im = re_c*rhs.im + im_c*rhs.re;
    return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    if ((rhs.re == 0) && (rhs.im == 0)) {
        throw std::invalid_argument("division by zero");
    }
    double del = rhs.re * rhs.re + rhs.im * rhs.im;
    double re_c = re;
    double im_c = im;
    re = (re * rhs.re + im * rhs.im) / del;
    im = (rhs.re * im_c - re_c * rhs.im) / del;
    return *this;
}

Complex& Complex::operator/=(const double rhs) {
    if(rhs == 0) {
        throw std::invalid_argument("division by zero");
    }
    re = re / rhs;
    im = im / rhs;
}

Complex operator+(const Complex& lhs, const double rhs) noexcept {
    Complex sum = Complex(lhs);
    sum += rhs;
    return sum;
}

Complex operator+(const double lhs, const Complex& rhs) noexcept {
    Complex sum = Complex(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const double rhs) noexcept {
    Complex dif = Complex(lhs);
    dif -= rhs;
    return dif;
}

Complex operator-(const double lhs, const Complex& rhs) noexcept {
    Complex dif = Complex(lhs);
    dif -= rhs;
    return dif;
}

