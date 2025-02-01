/**
 * Author: Rosman R Cariño
 * CS 106B Winter 2025
 */
#include "WinSumLoseSum.h"
using namespace std;

/**
 * @brief numbersMadeFromRecV1: Helper function for `numbersMadeFrom`
 *                  Because Keith loves using `const` this makes things
 *                  more complicated. Therefore, we can't modify the `values` being
 *                  passed in. In this solution we create another Set just to make it
 *                  easier for all of you to understand what's going on.
 * @param values
 * @param soFar
 * @return
 */
Set<int> numbersMadeFromRecV1(const Set<int>& values, int soFar) {
    // Base Case
    if (values.isEmpty()) { // There is nothing in the set
        return { soFar };
    }
    // Recursive Cases
    int currentVal = values.first(); // Obtain the First Value from the Set to examine
    // Create a New Set for the next Recursive Call
    Set<int> updatedValuesSet = values - currentVal;
    // Inclusive Set
    Set<int> include = numbersMadeFromRecV1(updatedValuesSet, soFar + currentVal);
    // Exclusive Set
    Set<int> exclude = numbersMadeFromRecV1(updatedValuesSet, soFar);
    // Unionize both Inclusive and Exclusive Set
    Set<int> result = include + exclude;
    return result;
}

/**
 * @brief numbersMadeFromRecV2: Helper function for `numbersMadeFrom`.
 *                              This version is similar to V1, but we "create"
 *                              the set within the next recursive call.
 * @param values
 * @param soFar
 * @return
 */
Set<int> numbersMadeFromRecV2(const Set<int>& values, int soFar) {
    // Base Case
    if (values.isEmpty()) { // There is nothing in the set
        return { soFar };
    }
    // Recursive Cases
    int currentVal = values.first();
    // Inclusive Set
    Set<int> include = numbersMadeFromRecV2(values - currentVal, soFar + currentVal);
    // Exclusive Set
    Set<int> exclude = numbersMadeFromRecV2(values - currentVal, soFar);
    // Unionize both Inclusive and Exclusive Set
    Set<int> result = include + exclude;
    return result;
}



/**
 * @brief numbersMadeFrom: Wrapper function for either V1 Rec or V2 Rec.
 * @param values
 * @return
 */
Set<int> numbersMadeFrom(const Set<int>& values) {
    return numbersMadeFromRecV1(values, 0);
}

// /**
//  * @brief canMakeTargetRecV1: Here is the naive way I went over in section.
//  * @param values
//  * @param target
//  * @param soFar
//  * @return
//  */
// bool canMakeTargetRecV1(const Set<int>& values, int target, int soFar) {
//     // Base Case
//     if (values.isEmpty()) {
//         if (soFar == target) {
//             return true; // Success Case
//         } else {
//             return false; // Failure Case
//         }
//     }
//     int currentValue = values.first();
//     Set<int> updatedValuesSet = values - currentValue;
//     bool include = canMakeTargetRecV1(updatedValuesSet, target, soFar + currentValue);
//     bool exclude = canMakeTargetRecV1(updatedValuesSet, target, soFar);
//     return include || exclude;
// }



// /**
//  * @brief canMakeTargetRecV2: This is a more optimized version. Once
//  *                              `soFar` == `target` then we stop exploring
//  *                              and return true. There is no need to
//  *                              continue exploring the Tree.
//  * @param values
//  * @param target
//  * @param soFar
//  * @return
//  */
// bool canMakeTargetRecV2(const Set<int>& values, int target, int soFar) {
//     // Base Cases
//     if (soFar == target) return true; // Success Case
//     if (values.isEmpty()) return false; // Failure Case

//     int currentValue = values.first();
//     Set<int> updatedValuesSet = values - currentValue;
//     bool include = canMakeTargetRecV2(updatedValuesSet, target, soFar + currentValue);
//     bool exclude = canMakeTargetRecV2(updatedValuesSet, target, soFar);
//     return include || exclude;

// }

// /**
//  * @brief canMakeTargetRecV3: This is similar to V1, but there is no need for a
//  *                          `soFar`. We can just decrement from `target`.
//  * @param values
//  * @param target
//  * @return
//  */
// bool canMakeTargetRecV3(const Set<int>& values, int target) {
//     // Base Case
//     if (values.isEmpty()) {
//         if (target == 0) {
//             return true; // Success Case
//         } else  {
//             return false; // Failure Case
//         }
//     }
//     // Recursive Cases
//     int currentValue = values.first();
//     Set<int> updatedValuesSet = values - currentValue;
//     bool include = canMakeTargetRecV3(updatedValuesSet, target - currentValue);
//     bool exclude = canMakeTargetRecV3(updatedValuesSet, target);
//     return include || exclude;

// }

// /**
//  * @brief canMakeTargetRecV4: This is similar to V2, but similar to V3 we're
//  *                          decrementing from `target`.
//  * @param values
//  * @param target
//  * @return
//  */
// bool canMakeTargetRecV4(const Set<int>& values, int target) {
//     // Base Cases
//     if (target == 0) return true; // Success Case
//     if (values.isEmpty()) return false; // Failure Case
//     // Recursive Cases
//     int currentValue = values.first();
//     Set<int> updatedValuesSet = values - currentValue;
//     bool include = canMakeTargetRecV4(updatedValuesSet, target - currentValue);
//     bool exclude = canMakeTargetRecV4(updatedValuesSet, target);
//     return include || exclude;
// }


// /**
//  * @brief canMakeTarget: Wrapper function: For Part 2 of the Problem
//  * @param values
//  * @param target
//  * @return
//  */
// bool canMakeTarget(const Set<int>& values, int target) {
//     //return canMakeTargetRecV1(values, target, 0);
//     return canMakeTargetRecV4(values, target);

// }



/*IMPORTANT NOTE: BELOW ARE THE SOLUTIONS FOR THE SOLUTIONS FOR PART 3
 * /

/**
 * @brief sumOfSet: This function returns the sum of a Set.
 * @param inputSet
 * @return
 */
int sumOfSet(const Set<int>& inputSet){
    int sum = 0;
    for (const int& elem : inputSet) {
        sum += elem;
    }
    return sum;
}


/**
 * @brief canMakeTargetRecV1: Naive Solution Where We Wait until `values` is empty
 *                          to see if we have a Success Case or Failure Case.
 *                          In this version we have a `soFar` Set where
 *                          we accumulate our choices. During each call
 *                          we call `sumOfSet` and return the sum of `soFar`.
 *                          If the sum of `soFar` is equal to `target` then we
 *                          return `true` and set our `solution` to `soFar`.
 *                          Othwerwise we return `false`
 * @param values
 * @param target
 * @param solution
 * @param soFar
 * @return
 */
bool canMakeTargetRecV1(const Set<int>& values, int target,
                        Set<int>& solution, Set<int> soFar) {
    if (values.isEmpty()){
        if (target == sumOfSet(soFar)) {
            solution = soFar;
            return true;
        } else {
            return false;
        }
    }
    // Recursive Cases
    int currentValue = values.first();
    Set<int> updatedSet = values - currentValue;
    bool include = canMakeTargetRecV1(updatedSet, target, solution, soFar + currentValue);
    bool exclude = canMakeTargetRecV1(updatedSet, target, solution, soFar);
    return include || exclude;
}

/**
 * @brief canMakeTargetRecV2: More optimal version where once `currentSumTotal`
 *                      is equal to `target`.
 *                      In this version we have a `soFar` Set where
 *                      we accumulate our choices. During each call
 *                      we call `sumOfSet` and return the sum of `soFar`.
 *                      If the sum of `soFar` is equal to `target` then we
 *                      return `true` and set our `solution` to `soFar`.
 *                      Othwerwise we return `false`
 * @param values
 * @param target
 * @param solution
 * @param soFar
 * @return
 */
bool canMakeTargetRecV2(const Set<int>& values, int target,
                      Set<int>& solution, Set<int> soFar) {
    int currentSumTotal = sumOfSet(soFar);
    if (currentSumTotal == target){
        solution = soFar;
        return true;
    }
    if (values.isEmpty()) {
        return false;
    }
    // Recursive Cases
    int currentValue = values.first();
    Set<int> updatedSet = values - currentValue;
    bool include = canMakeTargetRecV2(updatedSet, target, solution, soFar + currentValue);
    bool exclude = canMakeTargetRecV2(updatedSet, target, solution, soFar);
    return include || exclude;
}

/**
 * @brief canMakeTargetRecV3: In this version we are adding an additional
 *                  parameter called `soFar` where we avoid doing a linear
 *                  scan through the Set `soFarSet`.
 * @param values
 * @param target
 * @param solution
 * @param soFarSet
 * @param soFar
 * @return
 */
bool canMakeTargetRecV3(const Set<int>& values, int target,
                        Set<int>& solution, Set<int> soFarSet, int soFar) {
    if (soFar == target){
        solution = soFarSet;
        return true;
    }
    if (values.isEmpty()) {
        return false;
    }
    // Recursive Cases
    int currentValue = values.first();
    Set<int> updatedSet = values - currentValue;
    bool include = canMakeTargetRecV3(updatedSet, target, solution,
                                      soFarSet + currentValue, soFar + currentValue);
    bool exclude = canMakeTargetRecV3(updatedSet, target, solution,
                                      soFarSet, soFar);
    return include || exclude;
}
/**
 * @brief canMakeTargetRecV4: Here we avoid performing a linear scan like
 *                  in V3, but instead we are decrementing from `target`
 * @param values
 * @param target
 * @param solution
 * @param soFarSet
 * @return
 */

bool canMakeTargetRecV4(const Set<int>& values, int target,
                        Set<int>& solution, Set<int> soFarSet) {
    if (target == 0){
        solution = soFarSet;
        return true;
    }
    if (values.isEmpty()) {
        return false;
    }
    // Recursive Cases
    int currentValue = values.first();
    Set<int> updatedSet = values - currentValue;
    bool include = canMakeTargetRecV4(updatedSet, target - currentValue,
                                      solution, soFarSet + currentValue);
    bool exclude = canMakeTargetRecV4(updatedSet, target, solution,
                                      soFarSet);
    return include || exclude;
}


/**
 * @brief canMakeTarget: Wrapper function
 * @param values
 * @param target
 * @return
 */
bool canMakeTarget(const Set<int>& values, int target, Set<int>& solution) {
    //return canMakeTargetRecV1(values, target, solution, {});
    //return canMakeTargetRecV3(values, target, solution, {}, 0);
    return canMakeTargetRecV4(values, target, solution, {});
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("numbersMadeFrom works on small sets of numbers.") {
    EXPECT_EQUAL(numbersMadeFrom({ }), {
                     0 // Can make 0 by adding up nothing
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1 }), {
                     0, 1
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 3 }), {
                     0, 1, 3, 4
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 2, 4 }), {
                     0, 1, 2, 3, 4, 5, 6, 7
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 2, 3 }), {
                     0, 1, 2, 3, 4, 5, 6
                 });
    EXPECT_EQUAL(numbersMadeFrom({ 1, 3, 4 }), {
                     0, 1, 3, 4, 5, 7, 8
                 });
    // Section Example
    EXPECT_EQUAL(numbersMadeFrom({ 1, 2, 4}), {
                    0, 1, 2, 3, 4, 5, 6, 7
                    });
}



/* We want our test cases to work for canMakeTarget both if you are on part (ii)
 * or on part (iii) of this problem. To do this, we've set things up so that you
 * can use this function, which will call the right version of canMakeTarget based
 * on which version you've written.
 */
namespace {
    /* Dispatch as appropriate. */
    bool invoke(bool callback(const Set<int>&, int, Set<int>&),
                const Set<int>& values, int target, Set<int>& solution) {
        return callback(values, target, solution);
    }
    bool invoke(bool callback(const Set<int>&, int),
                const Set<int>& values, int target, Set<int>&) {
        return callback(values, target);
    }

    /* Suppress compiler warnings. */
    bool quiet1(const Set<int>&, int, Set<int>&) {
        return false;
    }
    bool quiet2(const Set<int>&, int) {
        return false;
    }
    void quietPlease() {
        Set<int> dummy;
        (void) dummy;
        (void) invoke(quiet1, dummy, 137, dummy);
        (void) invoke(quiet2, dummy, 137, dummy);
    }

    bool testCanMakeTarget(const Set<int>& values, int target, Set<int>& solution) {
        quietPlease();
        return invoke(canMakeTarget, values, target, solution);
    }
}

PROVIDED_TEST("canMakeTarget works for small sets of numbers, with no outparameter.") {
    Set<int> unused;

    /* Can make 0, but not others. */
    EXPECT( testCanMakeTarget({ },  0, unused));
    EXPECT(!testCanMakeTarget({ },  1, unused));
    EXPECT(!testCanMakeTarget({ }, -1, unused));

    /* Can make 0 and 137, but not others. */
    EXPECT( testCanMakeTarget({ 137 },   0, unused));
    EXPECT( testCanMakeTarget({ 137 }, 137, unused));
    EXPECT(!testCanMakeTarget({ 137 },   1, unused));
    EXPECT(!testCanMakeTarget({ 137 },  -1, unused));

    /* Can make 0, 1, 2, and 3, but not others. */
    EXPECT( testCanMakeTarget({ 1, 2 },  0, unused));
    EXPECT( testCanMakeTarget({ 1, 2 },  1, unused));
    EXPECT( testCanMakeTarget({ 1, 2 },  2, unused));
    EXPECT( testCanMakeTarget({ 1, 2 },  3, unused));
    EXPECT(!testCanMakeTarget({ 1, 2 }, 71, unused));
    EXPECT(!testCanMakeTarget({ 1, 2 }, -1, unused));

    /* Can make 0, 1, 3, 4, 5, 7, and 8, but not others. */
    EXPECT(!testCanMakeTarget({ 1, 3, 4 }, -1, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  0, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  1, unused));
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  2, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  3, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  4, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  5, unused));
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  6, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  7, unused));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  8, unused));
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  9, unused));
}

PROVIDED_TEST("canMakeTarget works for small sets of numbers, with outparameter.") {
    Set<int> solution = { 1, 2, 3, 4, 5 };

    /* Can make 0, but not others. */
    EXPECT( testCanMakeTarget({ },  0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT(!testCanMakeTarget({ },  1, solution));
    EXPECT(!testCanMakeTarget({ }, -1, solution));

    /* Can make 0 and 137, but not others. */
    EXPECT( testCanMakeTarget({ 137 },   0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT( testCanMakeTarget({ 137 }, 137, solution));
    EXPECT_EQUAL(solution, { 137 });
    EXPECT(!testCanMakeTarget({ 137 },   1, solution));
    EXPECT(!testCanMakeTarget({ 137 },  -1, solution));

    /* Can make 0, 1, 2, and 3, but not others. */
    EXPECT( testCanMakeTarget({ 1, 2 },  0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT( testCanMakeTarget({ 1, 2 },  1, solution));
    EXPECT_EQUAL(solution, { 1 });
    EXPECT( testCanMakeTarget({ 1, 2 },  2, solution));
    EXPECT_EQUAL(solution, { 2 });
    EXPECT( testCanMakeTarget({ 1, 2 },  3, solution));
    EXPECT_EQUAL(solution, { 1, 2 });
    EXPECT(!testCanMakeTarget({ 1, 2 }, 71, solution));
    EXPECT(!testCanMakeTarget({ 1, 2 }, -1, solution));

    /* Can make 0, 1, 3, 4, 5, 7, and 8, but not others. */
    EXPECT(!testCanMakeTarget({ 1, 3, 4 }, -1, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  0, solution));
    EXPECT_EQUAL(solution, { });
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  1, solution));
    EXPECT_EQUAL(solution, { 1 });
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  2, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  3, solution));
    EXPECT_EQUAL(solution, { 3 });
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  4, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  5, solution));
    EXPECT_EQUAL(solution, { 1, 4 });
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  6, solution));
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  7, solution));
    EXPECT_EQUAL(solution, { 3, 4 });
    EXPECT( testCanMakeTarget({ 1, 3, 4 },  8, solution));
    EXPECT_EQUAL(solution, { 1, 3, 4 });
    EXPECT(!testCanMakeTarget({ 1, 3, 4 },  9, solution));
}
