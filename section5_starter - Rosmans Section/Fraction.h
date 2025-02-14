#pragma once

#include <string>

class Fraction {
public:
    /* Creates the fraction num / denom. If neither is specified,
     * the fraction defaults to 0. If only the numerator is specified,
     * the fraction will be equal to that value exactly (the
     * denominator will be 1). For example:
     *
     * Fraction f;          // f == 0      (0/1)
     * Fraction f = 137;    // f == 137    (137/1)
     * Fraction f(137, 42); // f == 137/42
     */
    Fraction(int num = 0, int denom = 1);

    /* Access numerator and denominator. */
    int numerator() const;
    int denominator() const;

    /* Adds the given value to this fraction. For example, if this
     * fraction is 1/2 and the other fraction is 1/4, this fraction
     * ends up equal to 3/4.
     */
    void add(const Fraction& f);

    /* Multiplies this fraction by the other fraction. For example,
     * if this fraction is 1/2 and the other fraction is 1/4, this
     * fraction ends up equal to 1/8.
     */
    void multiply(const Fraction& f);

    /* Evaluates the ratio represented by this fraction. */
    double asDecimal() const;

private:
    /* The actual numerator and denominator. */
    int num;
    int den;

    /* Reduces the fraction to its simplest form. */
    void reduce();
};
