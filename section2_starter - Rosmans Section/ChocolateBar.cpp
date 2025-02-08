#include "ChocolateBar.h"
using namespace std;

int numWaysToEatV1(int numSquares) {
    // Safe Guard
    if (numSquares < 0) error("There are no squares!");

    // Base Case: Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    if (numSquares == 0) return 1;

    // Base Case 2:Given a chocolate with 1 piece then there is only 1 way
    // to eating it by eating that piece.
    if (numSquares == 1) return 1;

    // Recuresive Cases
    int breakOnePiece = numWaysToEatV1(numSquares - 1);
    int breakTwoPieces = numWaysToEatV1(numSquares - 2);
    int totalWaysToEat = breakOnePiece + breakTwoPieces;
    return totalWaysToEat;
}


int numWaysToEatV2(int numSquares) {
    // Safe Guard
    if (numSquares < 0) error("There are no squares!");

    // Base Case: Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all. Given a
    // chocolate with 1 piece then there is only 1 way to eating it by
    // eating that piece.
    if (numSquares <= 1) return 1;

    // Recuresive Cases
    int breakOnePiece = numWaysToEatV2(numSquares - 1);
    int breakTwoPieces = numWaysToEatV2(numSquares - 2);
    int totalWaysToEat = breakOnePiece + breakTwoPieces;
    return totalWaysToEat;
}


/**
 * @brief numWaysToEatV3: This version using a for loop instead. The main
 *                      idea from this comes from Section 3. Recursion and Iteration, Backtracking
 *                      where we can use a for loop.
 * @param numSquares
 * @return
 */
int numWaysToEatV3(int numSquares) {
    // Safe Guard
    if (numSquares < 0) error("There are no squares!");

    // Base Case: Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all. Given a
    // chocolate with 1 piece then there is only 1 way to eating it by
    // eating that piece.
    if (numSquares <= 1) return 1;

    // Recuresive Cases
    int totalWaysToEat = 0;
    for (int i = 1; i <= 2; i++) {
        totalWaysToEat += numWaysToEatV3(numSquares - 1);

    }
    return totalWaysToEat;
}



int numWaysToEat(int numSquares) {
    return numWaysToEatV1(numSquares);
}
/**
 * @brief printWaysToEatHelperV1: Here We are printing out `waysToEatSoFar`
 *                              in our first Base Case.
 * @param numSquares
 * @param waysToEatSoFar
 */
void printWaysToEatHelperV1(int numSquares, const Vector<int>& waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        cout << waysToEatSoFar << endl;
        return; // This `return` statement is necessary to "exit" out of the recursive call
                // otherwise we will have a Stack Overflow.
    }

    // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
    // eating it by eating that piece.
    if (numSquares == 1) {
        printWaysToEatHelperV1(numSquares - 1, waysToEatSoFar + 1);
        return; // This `return` statement is necessary to "exit" out of the recursive call
                // otherwise we will have a Stack Overflow.
    }

    // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
    printWaysToEatHelperV1(numSquares - 1, waysToEatSoFar + 1);
    printWaysToEatHelperV1(numSquares - 2, waysToEatSoFar + 2);
}

/**
 * @brief printWaysToEatHelperV2
 * @param numSquares
 * @param waysToEatSoFar
 */
void printWaysToEatHelperV2(int numSquares, const Vector<int>& waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        cout << waysToEatSoFar << endl;
    } else if (numSquares == 1) {
        // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
        // eating it by eating that piece. In this case we recurse to reach
        // Base Case 1.
        printWaysToEatHelperV2(numSquares - 1, waysToEatSoFar + 1);
    } else {
        // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
        printWaysToEatHelperV2(numSquares - 1, waysToEatSoFar + 1);
        printWaysToEatHelperV2(numSquares - 2, waysToEatSoFar + 2);
    }
}

/**
 * @brief printWaysToEatHelperV3: Here we use the `add` Vector method
 * @param numSquares
 * @param waysToEatSoFar
 */
void printWaysToEatHelperV3(int numSquares, Vector<int> waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        cout << waysToEatSoFar << endl;
    } else if (numSquares == 1) {
        // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
        // eating it by eating that piece and then recursing.
        waysToEatSoFar.add(1);
        printWaysToEatHelperV3(numSquares - 1, waysToEatSoFar);
    } else {
        // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
        waysToEatSoFar.add(1);
        printWaysToEatHelperV3(numSquares - 1, waysToEatSoFar);
        waysToEatSoFar.add(2);
        printWaysToEatHelperV3(numSquares - 2, waysToEatSoFar);
    }
}

/**
 * @brief printWaysToEatHelperV4: Here we use the `add` Vector method, too,
 *                              but print out on Base Case 2
 * @param numSquares
 * @param waysToEatSoFar
 */
void printWaysToEatHelperV4(int numSquares, Vector<int> waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        cout << waysToEatSoFar << endl;
    } else if (numSquares == 1) {
        // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
        // eating it by eating that piece. Then we can print this out.
        waysToEatSoFar.add(1);
        cout << waysToEatSoFar << endl;
    } else {
        // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
        waysToEatSoFar.add(1);
        printWaysToEatHelperV4(numSquares - 1, waysToEatSoFar);
        waysToEatSoFar.add(2);
        printWaysToEatHelperV4(numSquares - 2, waysToEatSoFar);
    }
}

/**
 * @brief printWaysToEatHelperV5: Here we use the `add` Vector method, too,
 *                              but print out on Base Case 2. However, in
 *                              this version we use another syntax.
 * @param numSquares
 * @param waysToEatSoFar
 */
void printWaysToEatHelperV5(int numSquares, Vector<int> waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        cout << waysToEatSoFar << endl;
    } else if (numSquares == 1) {
        // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
        // eating it by eating that piece.
        cout << waysToEatSoFar + 1 << endl;
    } else {
        // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
        waysToEatSoFar.add(1);
        printWaysToEatHelperV5(numSquares - 2, waysToEatSoFar);
        waysToEatSoFar.add(2);
        printWaysToEatHelperV5(numSquares - 1, waysToEatSoFar);
    }
}

/**
 * @brief printWaysToEatHelperV6: This version was inspired by Aidan. Here
 *                  we add an additional parameter callled `totalSoFar` and
 *                  compare it to `numSquares`.
 * @param numSquares
 * @param waysToEatSoFar
 * @param totalSoFar
 */
void printWaysToEatHelperV6(int numSquares, Vector<int> waysToEatSoFar,
                            int totalSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (totalSoFar == numSquares) {
        cout << waysToEatSoFar << endl;
    } else if (numSquares == 1) {
        // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
        // eating it by eating that piece.
        printWaysToEatHelperV6(numSquares - 1, waysToEatSoFar + 1, totalSoFar + 1);
    } else {
        // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
        printWaysToEatHelperV6(numSquares - 1, waysToEatSoFar + 1, totalSoFar + 1);
        printWaysToEatHelperV6(numSquares - 2, waysToEatSoFar + 2, totalSoFar + 2);
    }
}

/**
 * @brief printWaysToEat: Wrapper function that calls a specific helper
 *                  function.
 * @param numSquares
 */
void printWaysToEat(int numSquares) {
    // Safe Guard
    if (numSquares < 0) error("There are no squares!");
    // Call Helper Function
    printWaysToEatHelperV1(numSquares, {});

    // Inspired by Aidan - Make sure to comment line 209 if you choose to run this version.
    //printWaysToEatHelperV6(numSquares, {}, 0);
}

/**
 * @brief waysToEatHelperV1: Here for Base Case 2 we just recurse again.
 * @param numSquares
 * @param waysToEatSoFar
 * @return
 */
Set<Vector<int>> waysToEatHelperV1(int numSquares, Vector<int> waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        return { waysToEatSoFar };
    }

    // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
    // eating it by eating that piece. Then we recurse.
    if (numSquares == 1) {
        return waysToEatHelperV1(numSquares - 1, waysToEatSoFar + 1);
    }

    // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
    Set<Vector<int>> onePieceSet = waysToEatHelperV1(numSquares - 1, waysToEatSoFar + 1);
    Set<Vector<int>> twoPieceSet = waysToEatHelperV1(numSquares - 2, waysToEatSoFar + 2);
    Set<Vector<int>> totalWaysToEatSet = onePieceSet + twoPieceSet; // Unionize Both Set
    return totalWaysToEatSet;
}

/**
 * @brief waysToEatHelperV2: Here on Base Case 2 we add and then we return our Set
 * @param numSquares
 * @param waysToEatSoFar
 * @return
 */
Set<Vector<int>> waysToEatHelperV2(int numSquares, Vector<int> waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        return { waysToEatSoFar };
    }

    // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
    // eating it by eating that piece. Here we add it to our Set when returning it.
    if (numSquares == 1) {
        waysToEatSoFar.add(1);
        return { waysToEatSoFar};
    }

    // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
    Set<Vector<int>> onePieceSet = waysToEatHelperV2(numSquares - 1, waysToEatSoFar + 1);
    Set<Vector<int>> twoPieceSet = waysToEatHelperV2(numSquares - 2, waysToEatSoFar + 2);
    Set<Vector<int>> totalWaysToEatSet = onePieceSet + twoPieceSet; // Unionize Both Set
    return totalWaysToEatSet;
}

/**
 * @brief waysToEatHelperV3: Here on the same return statement for Base Case 2 we
 *                      add the 1
 * @param numSquares
 * @param waysToEatSoFar
 * @return
 */
Set<Vector<int>> waysToEatHelperV3(int numSquares, Vector<int> waysToEatSoFar) {
    // Base Case 1 : Problem statement states that given a chocolate with no
    // squares one can eat it by not eating anything at all.
    // Another way to think about this is that we're done with our bookkeeping
    if (numSquares == 0) {
        return { waysToEatSoFar };
    }

    // Base Case 2:Given a chocolate with 1 piece then there is only 1 way to
    // eating it by eating that piece. Here we add it to our Set when returning it.
    if (numSquares == 1) {
        return { waysToEatSoFar + 1};
    }

    // Recursive Cases: What choices can I make? I can eat 1 Piece or 2 Pieces.
    Set<Vector<int>> onePieceSet = waysToEatHelperV3(numSquares - 1, waysToEatSoFar + 1);
    Set<Vector<int>> twoPieceSet = waysToEatHelperV3(numSquares - 2, waysToEatSoFar + 2);
    Set<Vector<int>> totalWaysToEatSet = onePieceSet + twoPieceSet; // Unionize Both Set
    return totalWaysToEatSet;
}

Set<Vector<int>> waysToEat(int numSquares) {
    // Safe Guard
    if (numSquares < 0) error("There are no squares!");
    // Call Helper Function
    Set<Vector<int>> waysToEatResult = waysToEatHelperV1(numSquares, {});
    return waysToEatResult;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("numWaysToEat works on simple inputs.") {
    EXPECT_EQUAL(numWaysToEat(1), 1); // 1
    EXPECT_EQUAL(numWaysToEat(2), 2); // 2, 1 + 1
    EXPECT_EQUAL(numWaysToEat(3), 3); // 2 + 1, 1 + 2, 1 + 1 + 1
    EXPECT_EQUAL(numWaysToEat(5), 8); // 2 + 1, 1 + 2, 1 + 1 + 1
    EXPECT_EQUAL(numWaysToEat(4), 5); // Section Example
}

PROVIDED_TEST("numWaysToEat works on large inputs.") {
    EXPECT_EQUAL(numWaysToEat(13), 377);   // Lots of ways to do this!
    EXPECT_EQUAL(numWaysToEat(21), 17711); // Lots of ways to do this!
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
                     {2, 2},
                     {2, 1, 1},
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
                     {2, 1},
                     {1, 2},
                     {1, 1, 1}
                 });
}

PROVIDED_TEST("waysToEat works for n = 4.") {
    EXPECT_EQUAL(waysToEat(4), {
                     {2, 2},
                     {2, 1, 1},
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
