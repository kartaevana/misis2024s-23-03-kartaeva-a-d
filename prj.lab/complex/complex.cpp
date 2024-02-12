#include <complex/complex.hpp>


Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real), im(imaginary)
{
}

Complex& Complex::operator+= (const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}
Complex operator+ (const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex& Complex::operator-= (const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex operator- (const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*= (const Complex& rhs) {
    double per = re * rhs.re - im * rhs.im;
    im = re * rhs.im + im * rhs.re;
    re = per;
    return *this;
}
Complex operator* (const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + lhs.im * rhs.re);
}

Complex& Complex::operator/= (const Complex& rhs) {
    double per = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    im = (rhs.re * im - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    re = per;
    return *this;
}
Complex operator/ (const Complex& lhs, const Complex& rhs) {
    return Complex((lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im), (rhs.re * lhs.im - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im));
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good())
    {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
        {
            re = real;
            im = imaganary;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}