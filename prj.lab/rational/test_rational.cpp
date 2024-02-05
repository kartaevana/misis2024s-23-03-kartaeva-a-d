#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "rational.hpp"

TEST_CASE("Testing rational constructor") {
	Rational r_empty;
	CHECK(r_empty.Num() == 0);
	CHECK(r_empty.Den() == 1);

	Rational r_5(5);
	CHECK(r_5.Num() == 5);
	CHECK(r_5.Den() == 1);

	CHECK_THROWS(Rational(2, 0));

	Rational r1(3, 4);
	CHECK(r1.Num() == 3);
	CHECK(r1.Den() == 4);
}

TEST_CASE("Testing comparision operators") {
	Rational r1(3, 4), r2(4, 3);

	CHECK(r1 == Rational(3, 4));
	CHECK(r1 == Rational(178954776, 238606368));
	CHECK(!(r1 == Rational(4, 3)));
	CHECK(!(r1 == Rational(178954775, 238606368)));

	CHECK(r1 != Rational(4, 3));
	CHECK(r1 != Rational(178954775, 238606368));
	CHECK(!(r1 != Rational(3, 4)));
	CHECK(!(r1 != Rational(178954776, 238606368)));

	CHECK(r1 > Rational(178954775, 238606368));
	CHECK(r1 < Rational(178954777, 238606368));
	CHECK(r1 >= Rational(178954775, 238606368));
	CHECK(r1 <= Rational(178954777, 238606368));
	CHECK(r1 <= Rational(178954776, 238606368));
	CHECK(r1 >= Rational(178954776, 238606368));
}

TEST_CASE("Maths") {
	Rational r1(5, 2), r2(3, 2), r3(1, 2), r4(4, 1), r5(4, 3);
	CHECK(r1 == Rational(2, 1) + Rational(1, 2));
	CHECK(r1 == Rational(3, 2) + int64_t(1));
	CHECK(r1 == int64_t(2) + Rational(1, 2));

	CHECK(r2 == Rational(2, 1) - Rational(1, 2));
	CHECK(r3 == Rational(3, 2) - int64_t(1));
	CHECK(r2 == int64_t(2) - Rational(1, 2));

	CHECK(r4 == Rational(8, 1) * Rational(1, 2));
	CHECK(r2 == Rational(3, 4) * int64_t(2));
	CHECK(r4 == int64_t(8) * Rational(1, 2));

	CHECK(r4 == Rational(2, 1) / Rational(1, 2));
	CHECK(r5 == Rational(8, 3) / int64_t(2));
	CHECK(r5 == int64_t(2) / Rational(3, 2));
}

TEST_CASE("Maths with assignment") {
	Rational r1(4, 3), r2(5, 7);
	int64_t i1(2);

	r1 += r2;
	CHECK(r1 == Rational(43, 21));
	r1 += i1;
	CHECK(r1 == Rational(85, 21));

	r1 -= r2;
	CHECK(r1 == Rational(10, 3));
	r1 -= i1;
	CHECK(r1 == Rational(4, 3));

	r1 *= r2;
	CHECK(r1 == Rational(20, 21));
	r1 *= i1;
	CHECK(r1 == Rational(40, 21));

	r1 /= r2;
	CHECK(r1 == Rational(8, 3));
	r1 /= i1;
	CHECK(r1 == Rational(4, 3));
}

TEST_CASE("Input test") {
	Rational r1;
	std::cout << "Input rational in format 4/3: ";
	std::cin >> r1;
	CHECK(r1 == Rational(4, 3));

	std::cout << "Input rational in format -2/3: ";
	std::cin >> r1;
	CHECK(r1 == Rational(-2, 3));

	std::cout << "Input rational in format 0/n (n is any integer): ";
	std::cin >> r1;
	CHECK(r1 == Rational(0, 1));

	std::cout << "Input rational in format n/0 (n is any integer): ";
	CHECK_THROWS(std::cin >> r1);
}

TEST_CASE("Extra simplification test") {
	Rational r1(15823399283712, -101279287584);
	CHECK(r1 == Rational(-2656, 17));
}