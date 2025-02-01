/**
 * Author: Rosman R Cariño
 * CS 106B Winter 2025
 */
#include "SocialDistancing.h"
#include "strlib.h"
using namespace std;

/**
 * @brief safeArrangementsRec: In this Helper function we have a respective
 *              Set for a specific scenario
 * @param lineLength
 * @param numPeople
 * @param soFar
 * @return
 */
Set<string> safeArrangementsRecV1(int lineLength, int numPeople,
                                const string& soFar) {
    // Base Case: The length of `soFar` is the same as `lineLength`
    if (soFar.size() == lineLength) {
        // Success Case: If there are no more people then this means
        // we were able to arrange everyone in `numPeople`in accordance
        // to the social distance requirements in the checkout line.
        if (numPeople == 0) {
            return { soFar };
        } else {
        // Failure Case: If there are still people left in `numPeople` then
        // we are not meeting the problem statement requirements since there
        // are people left over.
            return {};
        }
    }
    // Recursive Cases: What choices can I make? We can either place a . or a Person.

    // Choice 1: We place a Square
    Set<string> square = safeArrangementsRecV1(lineLength, numPeople, soFar + '.');

    // Choice 2: We place a Person; however there is some nuance here.
    /* 1) There should be people left in `numPeople`. If there are no more people
     *      in `numPeople` then we cannot add them to the checkout line.
     * 2) In `soFar` there should not be a `P` at the End because we cannot place
     *      one Person next to another Person.
     * 3) In `soFar` there should be two spaces between that Person. An easy way to
     *      handle this by ensuring `P.` is not at the End.
     */
    Set<string> person;
    // We need this `if condition` based on what we talked about above.
    if (numPeople > 0 && !endsWith(soFar, 'P') && !endsWith(soFar, "P.")) {
        person = safeArrangementsRecV1(lineLength, numPeople - 1, soFar + 'P');
    }
    // Let's combine both choices/scenarios of our arrangements
    Set<string> combinedArrangements = square + person;
    // Let's return our combined arrangements
    return combinedArrangements;
}

/**
 * @brief safeArrangementsRecV2: This is similar to Version 1, but we are only
 *                      using 1 `Set`. If our `if` condition for People is valid
 *                      then we will just add on to our `arrangements` Set.
 * @param lineLength
 * @param numPeople
 * @param soFar
 * @return
 */
Set<string> safeArrangementsRecV2(int lineLength, int numPeople,
                                  const string& soFar) {
    // Base Case: The length of `soFar` is the same as `lineLength`
    if (soFar.size() == lineLength) {
        // Success Case: If there are no more people then this means
        // we were able to arrange everyone in `numPeople`in accordance
        // to the social distance requirements in the checkout line.
        if (numPeople == 0) {
            return { soFar };
        } else {
            // Failure Case: If there are still people left in `numPeople` then
            // we are not meeting the problem statement requirements since there
            // are people left over.
            return {};
        }
    }
    // Recursive Cases: What choices can I make? We can either place a . or a Person.

    // Choice 1: We place a Square
    Set<string> arrangements = safeArrangementsRecV2(lineLength, numPeople, soFar + '.');

    // Choice 2: We place a Person; however there is some nuance here.
    /* 1) There should be people left in `numPeople`. If there are no more people
     *      in `numPeople` then we cannot add them to the checkout line.
     * 2) In `soFar` there should not be a `P` at the End because we cannot place
     *      one Person next to another Person.
     * 3) In `soFar` there should be two spaces between that Person. An easy way to
     *      handle this by ensuring `P.` is not at the End.
     */
    // We need this `if condition` based on what we talked about above.
    if (numPeople > 0 && !endsWith(soFar, 'P') && !endsWith(soFar, "P.")) {
        arrangements += safeArrangementsRecV2(lineLength, numPeople - 1, soFar + 'P');
    }
    return arrangements;
}


/**
 * @brief safeArrangementsOf: Wrapper function that calls
 *                          the helper function `safeArrangementsRec`
 * @param lineLength
 * @param numPeople
 * @return
 */
Set<string> safeArrangementsOf(int lineLength, int numPeople) {
    return safeArrangementsRecV2(lineLength, numPeople, "");
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Handles one person in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 1), { });
    EXPECT_EQUAL(safeArrangementsOf(1, 1), {"P"});
    EXPECT_EQUAL(safeArrangementsOf(2, 1), {"P.", ".P"});
    EXPECT_EQUAL(safeArrangementsOf(3, 1), {"P..", ".P.", "..P"});
    EXPECT_EQUAL(safeArrangementsOf(4, 1), {"P...", ".P..", "..P.", "...P"});
}

PROVIDED_TEST("Handles common impossible varieties.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 40000), { });
    EXPECT_EQUAL(safeArrangementsOf(4, 0), {"...."});
    EXPECT_EQUAL(safeArrangementsOf(10, 10), { });
}

PROVIDED_TEST("Handles two people in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(1, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(2, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(3, 2), { });
    EXPECT_EQUAL(safeArrangementsOf(4, 2), { "P..P" });
}

PROVIDED_TEST("Handles no people in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 0), {""});
    EXPECT_EQUAL(safeArrangementsOf(1, 0), {"."});
    EXPECT_EQUAL(safeArrangementsOf(2, 0), {".."});
    EXPECT_EQUAL(safeArrangementsOf(3, 0), {"..."});
    EXPECT_EQUAL(safeArrangementsOf(4, 0), {"...."});
}

PROVIDED_TEST("Handles three people in small lines.") {
    EXPECT_EQUAL(safeArrangementsOf(0, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(1, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(2, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(3, 3), { });
    EXPECT_EQUAL(safeArrangementsOf(4, 3), { });
}

PROVIDED_TEST("Handles three people in medium-sized lines.") {
    EXPECT_EQUAL(safeArrangementsOf(7, 3), { "P..P..P" });
    EXPECT_EQUAL(safeArrangementsOf(8, 3), { "P..P..P.",
                                             "P..P...P",
                                             "P...P..P",
                                             ".P..P..P" });
}

PROVIDED_TEST("Handles two people in a big line.") {
    EXPECT_EQUAL(safeArrangementsOf(8, 2), {
                     "P..P....",
                     "P...P...",
                     "P....P..",
                     "P.....P.",
                     "P......P",
                     ".P..P...",
                     ".P...P..",
                     ".P....P.",
                     ".P.....P",
                     "..P..P..",
                     "..P...P.",
                     "..P....P",
                     "...P..P.",
                     "...P...P",
                     "....P..P"
                 });
}

PROVIDED_TEST("Handles four people in medium-sized lines.") {
    EXPECT_EQUAL(safeArrangementsOf(12, 4), {
                     "P..P..P..P..",
                     "P..P..P...P.",
                     "P..P..P....P",
                     "P..P...P..P.",
                     "P..P...P...P",
                     "P..P....P..P",
                     "P...P..P..P.",
                     "P...P..P...P",
                     "P...P...P..P",
                     "P....P..P..P",
                     ".P..P..P..P.",
                     ".P..P..P...P",
                     ".P..P...P..P",
                     ".P...P..P..P",
                     "..P..P..P..P"
                 });
}

PROVIDED_TEST("Stress test: Handles ten people in a reasonably-sized line. (This should take at most a few seconds.)") {
    EXPECT_EQUAL(safeArrangementsOf(32, 10).size(), 1001);
}

PROVIDED_TEST("Stress test: Handles ten people in the smallest possible line") {
    EXPECT_EQUAL(safeArrangementsOf(28, 10), {"P..P..P..P..P..P..P..P..P..P"});
}

PROVIDED_TEST("Example from Section") {
    EXPECT_EQUAL(safeArrangementsOf(5, 2), {".P..P", "P...P", "P..P."});
}
