#define DOCTEST_CONFIG-IMPLEMENT-WITH-MAIN
#include <complex/complex.hpp>
#include "doctest.h"


void test() {
    Complex c1 = { 1,4 };
    Complex c2 = { 2,5 };
    double real = 2;
    Complex c1m = c1;
    Complex check;

    std::cout << "Complex numbers: " << c1 << "," << c2 << std::endl;
    std::cout << "real numder: " << real << std::endl;

    std::cout << "operator+: " << c1 + c2 << std::endl;
    check = c1 + c2;
    c1 += c2;
    std::cout << "operator+=: " << c1 << std::endl;
    if ((c1 == check)) std::cout << "ok" << std::endl;
    else std::cout << "no" << std::endl;
    c1 = c1m;

    std::cout << "operator+: " << c1 + real << std::endl;
    check = c1 + real;
    c1 += real;
    std::cout << "operator+=: " << c1 << std::endl;
    if ((c1 == check)) std::cout << "ok";
    else std::cout << "no";
    std::cout << std::endl;
    c1 = c1m;

    std::cout << "operator-: " << c1 - c2 << std::endl;
    check = c1 - c2;
    c1 -= c2;
    std::cout << "operator-=: " << c1 << std::endl;
    if ((c1 == check)) std::cout << "ok" << std::endl;
    else std::cout << "no" << std::endl;
    c1 = c1m;

    std::cout << "operator-: " << c1 - real << std::endl;
    check = c1 - real;
    c1 -= real;
    std::cout << "operator-=: " << c1 << std::endl;
    if ((c1 == check)) std::cout << "ok";
    else std::cout << "no";
    std::cout << std::endl;
    c1 = c1m;

    std::cout << "operator*: " << c1 * c2 << std::endl;
    check = c1 * c2;
    c1 *= c2;
    std::cout << "operator*=: " << c1 << std::endl;
    if ((c1 == check)) std::cout << "ok" << std::endl;
    else std::cout << "no" << std::endl;
    c1 = c1m;
    std::cout << "operator*: " << c1 * real << std::endl;
    check = c1 * real;
    c1 *= real;
    std::cout << "operator*=: " << c1 << std::endl;
    if ((c1 == check)) std::cout << "ok" << std::endl;
    else std::cout << "no" << std::endl;
    c1 = c1m;

    if (c2 == Complex(0)) std::cout << "no, division by zero";
    else {
        std::cout << "operator/: " << c1 / c2 << std::endl;
        check = c1 / c2;
        c1 /= c2;
        std::cout << "operator/=: " << c1 << std::endl;
        if ((c1 == check)) std::cout << "ok";
        else std::cout << "no";
        std::cout << std::endl;
        c1 = c1m;
    }
}

int main() {
    test();
    return 0;
}

