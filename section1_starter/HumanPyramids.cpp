#include "HumanPyramids.h"
#include "error.h"
using namespace std;

/**
 * @brief peopleInPyramidOfHeightV1: Have the safety base case and true simplest base case.
 * @param n
 * @return
 */
int peopleInPyramidOfHeightV1(int n) {
    // Safety Base Case
    if (n < 0) error ("There should be people in the pyramid!");

    // Base Case: If there are no people then return 0
    if (n == 0) return 0;

    // Recursive Case: Count that layer and recurse on a smaller layer
    return n + peopleInPyramidOfHeightV1(n - 1);
}

/**
 * @brief peopleInPyramidOfHeightV2: Here we added another base case, but this can
 *                              can be redundant. In recursion we want to have
 *                              the most trivial problem possible for our base case.
 * @param n
 * @return
 */
int peopleInPyramidOfHeightV2(int n) {
    // Safety Base Case
    if (n < 0) error ("There should be people in the pyramid!");

    // Base Case 1: If there are no people then return 0
    if (n == 0) return 0;

    // Base Case 2: If there is one person then return 1
    if (n == 1) return 1;

    // Recursive Case: Count that layer and recurse on a smaller layer
    return n + peopleInPyramidOfHeightV2(n - 1);
}

/**
 * @brief peopleInPyramidOfHeightV3: Similar to V1, but we have an if/else
 *                              statement to handle our Base Case and Recursive
 *                              Case.
 * @param n
 * @return
 */
int peopleInPyramidOfHeightV3(int n) {
    // Safety Base Case
    if (n < 0) error ("There should be people in the pyramid!");

    // Base Case: If there are no people then return 0
    if (n == 0) {
        return 0;
    } else {
        // Recursive Case: Count that layer and recurse on a smaller layer
        return n + peopleInPyramidOfHeightV3(n - 1);
    }
}

int peopleInPyramidOfHeight(int n) {
    // Call one of the version
    return peopleInPyramidOfHeightV1(n);
}



/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for small numbers.") {
    EXPECT_EQUAL(peopleInPyramidOfHeight(1), 1);
    EXPECT_EQUAL(peopleInPyramidOfHeight(2), 3);
    EXPECT_EQUAL(peopleInPyramidOfHeight(3), 6);
}

PROVIDED_TEST("Reports an error on invalid inputs.") {
    EXPECT_ERROR(peopleInPyramidOfHeight(-1));
    EXPECT_ERROR(peopleInPyramidOfHeight(-137));
    EXPECT_NO_ERROR(peopleInPyramidOfHeight(0));
}
