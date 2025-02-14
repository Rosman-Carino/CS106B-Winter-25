#include "Fraction.h"
#include "error.h"
#include <cmath>
using namespace std;

/* Constructs a new fraction. */
Fraction::Fraction(int numerator, int denominator) {
    /* Error-handling. */
    if (denominator == 0) {
        error("Division by zero.");
    }

    /* Stash the numerator and denominator. */
    num = numerator;
    den = denominator;

    /* Reduce to simplest form. */
    reduce();
}

int Fraction::numerator() const {
    return num;
}

int Fraction::denominator() const {
    return den;
}

void Fraction::add(const Fraction& f) {
    /* a/b + c/d = ad/bd + bc/bd = (ad + bc)/db */
    int nextNum = (numerator() * f.denominator()) + (denominator() * f.numerator());
    int nextDen = denominator() * f.denominator();

    /* Set these as the new numerator/denominator, then simplify. */
    num = nextNum;
    den = nextDen;
    reduce();
}

void Fraction::multiply(const Fraction& f) {
    /* A breath of fresh air compared to the ones above. >_< */
    num *= f.numerator();
    den *= f.denominator();
    reduce();
}

double Fraction::asDecimal() const {
    return double(numerator()) / denominator();
}

/* Reduces the fraction to its simplest form. This uses Euclid's algorithm to
 * compute the greatest common divisor (gcd) of the numerator and denominator,
 * then divides through by it.
 */
void Fraction::reduce() {
    int a = abs(numerator());
    int b = abs(denominator());

    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }

    /* a is now the gcd of the numerator and denominator. */
    num /= a;
    den /= a;

    /* Transfer sign to the numerator. */
    if (den < 0) {
        den *= -1;
        num *= -1;
    }
}



/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/ConditionalTest.h"

PROVIDED_TEST("Basic checks on Fraction.") {
    Fraction f0;
    Fraction f1 = 1;
    Fraction f3_2(6, 4);
    Fraction f4_3(-12, -9);

    EXPECT_EQUAL(f0.numerator(), 0);
    EXPECT_EQUAL(f0.denominator(), 1);
    EXPECT_EQUAL(f1.numerator(), 1);
    EXPECT_EQUAL(f1.denominator(), 1);
    EXPECT_EQUAL(f3_2.numerator(), 3);
    EXPECT_EQUAL(f3_2.denominator(), 2);
    EXPECT_EQUAL(f4_3.numerator(), 4);
    EXPECT_EQUAL(f4_3.denominator(), 3);

    Fraction f17_6 = f3_2;
    f17_6.add(f4_3);

    EXPECT_EQUAL(f17_6.numerator(), 17);
    EXPECT_EQUAL(f17_6.denominator(), 6);

    Fraction f17_3 = f17_6;
    f17_3.add(f17_3);

    EXPECT_EQUAL(f17_3.numerator(), 17);
    EXPECT_EQUAL(f17_3.denominator(), 3);

    Fraction f17_2 = f17_3;
    f17_2.multiply(f3_2);

    EXPECT_EQUAL(f17_2.numerator(), 17);
    EXPECT_EQUAL(f17_2.denominator(), 2);
}

CONDITIONAL_TEST("reciprocal works on simple cases.", Fraction, reciprocal) {
    Fraction f3_2(3, 2);
    Fraction f2_3 = f3_2.reciprocal();

    EXPECT_EQUAL(f2_3.numerator(),   2);
    EXPECT_EQUAL(f2_3.denominator(), 3);
}

CONDITIONAL_TEST("reciprocal reports errors as appropriate.", Fraction, reciprocal) {
    Fraction zero;

    EXPECT_EQUAL(zero.numerator(), 0);
    EXPECT_EQUAL(zero.denominator(), 1);

    EXPECT_ERROR(zero.reciprocal());
}

CONDITIONAL_TEST("divide works on simple cases.", Fraction, divide) {
    Fraction f35_6(35, 6);
    Fraction f5_2(5, 2);

    Fraction f7_3 = f35_6;
    f7_3.divide(f5_2);

    EXPECT_EQUAL(f7_3.numerator(), 7);
    EXPECT_EQUAL(f7_3.denominator(), 3);
}

CONDITIONAL_TEST("divide reports errors as appropriate", Fraction, divide) {
    Fraction zero;
    Fraction one = 1;

    EXPECT_ERROR(one.divide(zero));
}
