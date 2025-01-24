/** Author: Rosman R Cariño
 *  CS106B Winter 2025 Section
*/

#include "ChocolateBar.h"
using namespace std;

int numWaysToEat(int numSquares) {
    /* Can't have a negative number of squares. */
    if (numSquares < 0) {
        error("Negative chocolate? YOU MONSTER!");
    }

    /* If we have zero or one square, there's exactly one way to eat
     * the chocolate.
     */
    if (numSquares <= 1) {
        return 1;
    }
    /* Otherwise, we should be looping through all the potential
     * ways to eat the square - Please refer to the Tree we drew out
     */
    int totalWaysToEat = 0; // This will be our `result` aggregate variable

    for (int i = 1; i <= numSquares; i++) { // We need to loop from 1 because that's a valid bite and inclusive to `numSquares`
        totalWaysToEat += numWaysToEat(numSquares - i); // Recurse on the way to eat here.
                                                        // Note: The `numSquares` on the next recursive call
                                                        // will be reducued by `i` on line 25 as well.
    }
    return totalWaysToEat;
}

/* Print all ways to eat numSquares more squares, given that we've
 * already taken the bites given in soFar.
 */
void printWaysToEatRecV1(int numSquares, const Vector<int>& soFar) {
    /* Base Case: If there are no squares left, the only option is to use
     * the bites we've taken already in soFar.
     */
    if (numSquares == 0) {
        cout << soFar << endl;
        return;
    }
    /* Base Case: If there is one square lfet, the only option is to eat
     * that square.
     */
    if (numSquares == 1) {
        cout << soFar + 1 << endl;
        return;
    }
    /* Otherwise, we should be looping through all the potential
     * ways to eat the square - Please refer to the Tree we drew out
     */

    // We need to loop from 1 because that's a valid bite and inclusive to `numSquares`
    for (int i = 1; i <= numSquares; i++) {
        printWaysToEatRecV1(numSquares - i, soFar + i); // Recurse on the way to eat here.
                                                      // Note: The `numSquares` on the next recursive call
                                                      // will be reducued by `i` on line 56 as well.
    }
}

/* Print all ways to eat numSquares more squares, given that we've
 * already taken the bites given in soFar.
 */
void printWaysToEatRecV2(int numSquares, const Vector<int>& soFar) {
    /* Base Case: If there are no squares left, the only option is to use
     * the bites we've taken already in soFar.
     */
    if (numSquares == 0) {
        cout << soFar << endl;
    }
    /* Base Case: If there is one square lfet, the only option is to eat
     * that square.
     */
    else if (numSquares == 1) {
        cout << soFar + 1 << endl;
    }
    /* Otherwise, we should be looping through all the potential
     * ways to eat the square - Please refer to the Tree we drew out
     */
    else {
        // We need to loop from 1 because that's a valid bite and inclusive to `numSquares`
        for (int i = 1; i <= numSquares; i++) {
            printWaysToEatRecV2(numSquares - i, soFar + i); // Recurse on the way to eat here.
                // Note: The `numSquares` on the next recursive call
                // will be reducued by `i` on line 56 as well.
        }
    }
}

void printWaysToEat(int numSquares) {
    if (numSquares < 0) {
        error("You owe me some chocolate!");
    }

    /* We begin without having made any bites. */
    printWaysToEatRecV2(numSquares, {});
}

/* Returns all ways to eat numSquares more squares, given that we've
 * already taken the bites given in soFar.
 */
Set<Vector<int>> waysToEatRecV1(int numSquares, const Vector<int>& soFar) {
    /* Base Case: If there are no squares left, the only option is to use
     * the bites we've taken already in soFar.
     */
    if (numSquares == 0) {
        /* There is one option here, namely, the set of bites we came up
         * with in soFar. So if we return all the ways to eat the
         * chocolate bar given that we've committed to what's in soFar,
         * we should return a set with just one item, and that one item
         * should be soFar.
         */
        return { soFar };
    }
    /* Base Case: If there is one square lfet, the only option is to eat
     * that square.
     */
    if (numSquares == 1) {
        /* Take what we have, and extend it by eating one more bite. */
        return { soFar + 1 };
    }
    /* Otherwise, we should be looping through all the potential
     * ways to eat the square - Please refer to the Tree we drew out
     */
    Set<Vector<int>> totalWaysToEat;
    // We need to loop from 1 because that's a valid bite and inclusive to `numSquares`
    for (int i = 1; i <= numSquares; i++) {
        Set<Vector<int>> currenSet = waysToEatRecV1(numSquares - i, soFar + i);
        totalWaysToEat += currenSet;
    }
    return totalWaysToEat;
}


/* Returns all ways to eat numSquares more squares, given that we've
 * already taken the bites given in soFar.
 */
Set<Vector<int>> waysToEatRecV2(int numSquares, const Vector<int>& soFar) {
    /* Base Case: If there are no squares left, the only option is to use
     * the bites we've taken already in soFar.
     */
    if (numSquares == 0) {
        /* There is one option here, namely, the set of bites we came up
         * with in soFar. So if we return all the ways to eat the
         * chocolate bar given that we've committed to what's in soFar,
         * we should return a set with just one item, and that one item
         * should be soFar.
         */
        return { soFar };
    }
    /* Base Case: If there is one square lfet, the only option is to eat
     * that square.
     */
    if (numSquares == 1) {
        /* Take what we have, and extend it by eating one more bite. */
        return { soFar + 1 };
    }
    /* Otherwise, we should be looping through all the potential
     * ways to eat the square - Please refer to the Tree we drew out
     */
    Set<Vector<int>> totalWaysToEat;
    // We need to loop from 1 because that's a valid bite and inclusive to `numSquares`
    for (int i = 1; i <= numSquares; i++) {
        totalWaysToEat += waysToEatRecV2(numSquares - i, soFar + i);
    }
    return totalWaysToEat;
}

Set<Vector<int>> waysToEat(int numSquares) {
    if (numSquares < 0) {
        error("You owe me some chocolate!");
    }

    /* We begin without having made any bites. */
    return waysToEatRecV2(numSquares, {});
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("numWaysToEat works on simple inputs.") {
    EXPECT_EQUAL(numWaysToEat(1), 1); // 1
    EXPECT_EQUAL(numWaysToEat(2), 2); // 2, 1 + 1
    EXPECT_EQUAL(numWaysToEat(3), 4); // 3, 2 + 1, 1 + 2, 1 + 1 + 1
    EXPECT_EQUAL(numWaysToEat(4), 8); // 3, 2 + 1, 1 + 2, 1 + 1 + 1
}

PROVIDED_TEST("numWaysToEat works on large inputs.") {
    EXPECT_EQUAL(numWaysToEat(10), 512); // Lots of ways to do this!
    EXPECT_EQUAL(numWaysToEat(11), 1024); // Lots of ways to do this!
}

PROVIDED_TEST("numWaysToEat works on small inputs.") {
    EXPECT_EQUAL(numWaysToEat(0), 1); // Do nothing
}

PROVIDED_TEST("numWaysToEat reports errors on invalid inputs.") {
    EXPECT_ERROR(numWaysToEat(-1));
    EXPECT_ERROR(numWaysToEat(-137));
}

namespace {
/* Utility function to get back a Set<Vector<int>> from what was printed
     * to cout. Calls error if any duplicates were found.
     */
Set<Vector<int>> decode(const StreamCatcher& catcher) {
    Set<Vector<int>> result;
    istringstream extractor(catcher.output());

    /* Read each line one at a time. */
    for (string line; getline(extractor, line); ) {
        Vector<int> value;
        istringstream converter(line);
        converter >> value;

        if (!converter) {
            SHOW_ERROR("Something was printed to cout that wasn't a Vector<int>.");
        }

        /* Make sure there's nothing else there. */
        char leftover;
        if (converter >> leftover) {
            SHOW_ERROR("Something was printed to cout that wasn't a Vector<int>.");
        }

        /* Make sure it's unique. */
        if (result.contains(value)) {
            SHOW_ERROR("Sequence " + line + " was produced twice.");
        }
        result += value;
    }
    return result;
}
}

PROVIDED_TEST("printWaysToEat works for n = 3.") {
    /* Divert cout so we can see what's printed. */
    StreamCatcher catcher;
    printWaysToEat(3);

    EXPECT_EQUAL(decode(catcher), {
                                      {3},
                                      {2, 1},
                                      {1, 2},
                                      {1, 1, 1}
                                  });
}

PROVIDED_TEST("printWaysToEat works for n = 4.") {
    /* Divert cout so we can see what's printed. */
    StreamCatcher catcher;
    printWaysToEat(4);

    EXPECT_EQUAL(decode(catcher), {
                                      {4},
                                      {3, 1},
                                      {2, 2},
                                      {2, 1, 1},
                                      {1, 3},
                                      {1, 2, 1},
                                      {1, 1, 2},
                                      {1, 1, 1, 1}
                                  });
}

PROVIDED_TEST("printWaysToEat works for n = 0.") {
    /* Divert cout so we can see what's printed. */
    StreamCatcher catcher;
    printWaysToEat(0);

    EXPECT_EQUAL(decode(catcher), { { } });
}

PROVIDED_TEST("printWaysToEat reports errors for n < 0.") {
    StreamCatcher catcher;
    EXPECT_ERROR(printWaysToEat(-137));
    EXPECT_EQUAL(decode(catcher), { }); // Nothing should have been printed.
}

PROVIDED_TEST("waysToEat works for n = 3.") {
    EXPECT_EQUAL(waysToEat(3), {
                                   {3},
                                   {2, 1},
                                   {1, 2},
                                   {1, 1, 1}
                               });
}

PROVIDED_TEST("waysToEat works for n = 4.") {
    EXPECT_EQUAL(waysToEat(4), {
                                   {4},
                                   {3, 1},
                                   {2, 2},
                                   {2, 1, 1},
                                   {1, 3},
                                   {1, 2, 1},
                                   {1, 1, 2},
                                   {1, 1, 1, 1}
                               });
}

PROVIDED_TEST("waysToEat works for n = 0.") {
    EXPECT_EQUAL(waysToEat(0), { { } });
}

PROVIDED_TEST("waysToEat reports errors for n < 0.") {
    EXPECT_ERROR(waysToEat(-137));
}
