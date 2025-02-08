#include "CountingSort.h"
using namespace std;

void countingSort(Vector<int>& values) {
    (void) values;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include <algorithm>

PROVIDED_TEST("Works on simple cases.") {
    Vector<int> elems;

    elems = { 1, 2, 3 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2, 3 });

    elems = { 1, 3, 2 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2, 3 });

    elems = { 2, 1, 3 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2, 3 });

    elems = { 2, 3, 1 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2, 3 });

    elems = { 3, 1, 2 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2, 3 });

    elems = { 3, 2, 1 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2, 3 });
}

PROVIDED_TEST("Works when elements are duplicated.") {
    Vector<int> elems;

    elems = { 1, 2, 1, 2 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 1, 2, 2 });

    elems = { 2, 1, 3, 3, 1, 2 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 1, 2, 2, 3, 3 });
}

PROVIDED_TEST("Works on small arrays.") {
    Vector<int> elems;

    elems = { };
    countingSort(elems);
    EXPECT_EQUAL(elems, { });

    elems = { 1 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1 });

    elems = { 1, 2 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2 });

    elems = { 2, 1 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 1, 2 });

    elems = { 2, 2 };
    countingSort(elems);
    EXPECT_EQUAL(elems, { 2, 2 });
}

PROVIDED_TEST("Works on a medium-sized array.") {
    Vector<int> elems;

    elems = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4, 6, };
    countingSort(elems);
    EXPECT_EQUAL(elems, {
                     1, 1, 2, 2, 3, 3, 3,
                     3, 4, 4, 5, 5, 5, 6,
                     6, 7, 8, 8, 9, 9, 9
                 });
}

PROVIDED_TEST("Works on a large array.") {
    /* Form an array of two copies of each of the numbers in
     * 0, 1, 2, ..., kSize - 1, but in an unusual order.
     */
    const int kSize  = 4127; // Important that this is prime
    const int kStep1 = 2503; // Can be anything less than kSize
    const int kStep2 = 463;  // Same

    Vector<int> values;
    int v1 = 2022, v2 = 1989; // These can be arbitrary
    for (int i = 0; i < kSize; i++) {
        values += v1;
        values += v2;
        v1 = (v1 + kStep1) % kSize;
        v2 = (v2 + kStep2) % kSize;
    }

    /* Sort it. */
    countingSort(values);
    EXPECT_EQUAL(values.size(), 2 * kSize);

    /* Confirm it's what we want it to be. */
    for (int i = 0; i < 2 * kSize; i++) {
        EXPECT_EQUAL(values[i], i / 2);
    }
}
