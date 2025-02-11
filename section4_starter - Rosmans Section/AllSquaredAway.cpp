#include "AllSquaredAway.h"
using namespace std;

Optional<Vector<int>> findSquareSequence(int n) {
    (void) n;
    return Nothing;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include "set.h"

namespace {
    /* Checks if the given sequence is a square sequence. */
    void check(int n, const Vector<int>& values) try {
        Set<int> used;

        for (int i = 0; i < values.size(); i++) {
            /* Should be between 1 and n, inclusive, and not a repeat. */
            if (values[i] < 1 || values[i] > n) {
                error("Invalid value: " + to_string(values[i]));
            }

            /* Make sure it's not a duplicate. */
            if (used.contains(values[i])) {
                error("Duplicate value: " + to_string(values[i]));
            }
            used += values[i];

            /* Confirm that the delta is a perfect square. */
            if (i != 0 && !isPerfectSquare(values[i] + values[i - 1])) {
                error("Sum isn't a perfect square: " + to_string(values[i-1]) + ", " + to_string(values[i]));
            }
        }

        /* Should have seen 1, 2, ..., n. */
        if (used.size() != n) {
            error("Not all values from 1 to n appear in the sequence.");
        }
    } catch (const ErrorException& e) {
        ostringstream builder;
        builder << "Invalid sequence: " << e.what() << endl;
        builder << "      " << values << endl;
        SHOW_ERROR(builder.str());
    }
}

PROVIDED_TEST("Works on small cases.") {
    EXPECT_EQUAL(findSquareSequence(1), { 1 }); // 1
    EXPECT_EQUAL(findSquareSequence(2), Nothing);
    EXPECT_EQUAL(findSquareSequence(3), Nothing);
}

PROVIDED_TEST("Works on mid-sized values.") {
    auto sequence = findSquareSequence(15);
    EXPECT_NOT_EQUAL(sequence, Nothing);
    check(15, sequence.value());

    EXPECT_EQUAL(findSquareSequence(18), Nothing);
    EXPECT_EQUAL(findSquareSequence(19), Nothing);

    sequence = findSquareSequence(23);
    EXPECT_NOT_EQUAL(sequence, Nothing);
    check(23, sequence.value());
}

/* * * * * Implementation of isPerfectSquare * * * * */

#include <cmath>

/* Checks if a number is a perfect square. Due to rounding issues and the like,
 * we've implemented this one for you.
 */
bool isPerfectSquare(int n) {
    /* Negative numbers cannot be perfect squares. */
    if (n < 0) return false;

    /* Get the square root, round it to the nearest integer, and square it. */
    int candidate = round(sqrt(double(n)));
    return candidate * candidate == n;
}
