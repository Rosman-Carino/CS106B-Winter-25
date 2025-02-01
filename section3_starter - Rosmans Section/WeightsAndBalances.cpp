/**
 * Author: Rosman R Cariño
 * CS 106B Winter 2025
 */
#include "WeightsAndBalances.h"
using namespace std;
/*
 * Weights and Balances (Code Writing)
 * --------------------------------------------------------
 * Write a recursive function that determines whether it is
 * possible to measure out the desired target amount with a
 * given set of weights, which is stored in the vector
 * weights.
 */

/**
 * @brief isMeasurableV1: Naive Version where fully explore the Recursive
 *                      Tree by letting our base case be when the size of
 *                      our `weights` is empty.
 * @param amount
 * @param weights
 * @return
 */
bool isMeasurableV1(int amount, const Vector<int>& weights) {
    // Base Case
    if (weights.size() == 0) {
        if (amount == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights.get(0);
    // Let's update our weight's vector
    Vector<int> updatedWeights = weights.subList(1);
    // Choice 1: Place weight on the right scale
    bool rightScaleChoice = isMeasurableV1(amount - currWeight, updatedWeights);
    // Choice 2: Place weight on the left scale
    bool leftScaleChoice = isMeasurableV1(amount + currWeight, updatedWeights);
    // Choice 3: Exclude the weight
    bool excludeChoice = isMeasurableV1(amount, updatedWeights);
    // See which side it will work
    return rightScaleChoice || leftScaleChoice || excludeChoice;
}

/**
 * @brief isMeasurableV2: This is a more optimized version of V1. Once we
 *                  found the case where `amount` == 0 then there is no
 *                  need to explore any additional weights from `weights`.
 * @param amount
 * @param weights
 * @return
 */
bool isMeasurableV2(int amount, const Vector<int>& weights) {
    // Base Case: Success Case
    if (amount == 0) return true;
    // Base Case: Failure Case
    if (weights.isEmpty()) return false;
    // Recursive Cases
    int currWeight = weights.get(0);
    // Let's update our weight's vector
    Vector<int> updatedWeights = weights.subList(1);
    // Choice 1: Place weight on the right scale
    bool rightScaleChoice = isMeasurableV2(amount - currWeight, updatedWeights);
    // Choice 2: Place weight on the left scale
    bool leftScaleChoice = isMeasurableV2(amount + currWeight, updatedWeights);
    // Choice 3: Exclude the weight
    bool excludeChoice = isMeasurableV2(amount, updatedWeights);
    // See which side it will work
    return rightScaleChoice || leftScaleChoice || excludeChoice;
}

/**
 * @brief isMeasurableRecV3: This is similar to V1, but rather than
 *                           creating an `updatedWeights` for the next
 *                           recursive call we can just pass an extra parameter
 *                           called `index` to keep track of where we are located.
 *                           This will minimze the amount of auxiliary memory
 *                           we're using.
 * @param target
 * @param weights
 * @param index
 * @return
 */
bool isMeasurableRecV3(int target, const Vector<int>& weights, int index){
    // Base Case
    if (index == weights.size()) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights[index];
    // Choice 1: Place weight on the right scale
    bool rightScaleChoice = isMeasurableRecV3(target - currWeight,
                                              weights, index + 1);
    // Choice 2: Place weight on the left scale
    bool leftScaleChoice = isMeasurableRecV3(target + currWeight,
                                             weights, index + 1);
    // Choice 3: Exclude the weight
    bool excludeChoice = isMeasurableRecV3(target, weights, index + 1);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}

/**
 * @brief isMeasurableRecV4: This is a similar version to V2, but rather than
 *                           creating an `updatedWeights` for the next
 *                           recursive call we can just pass an extra parameter
 *                           called `index` to keep track of where we are located.
 *                           This will minimze the amount of auxiliary memory
 *                           we're using.
 * @param target
 * @param weights
 * @param index
 * @return
 */
bool isMeasurableRecV4(int target, const Vector<int>& weights, int index) {
    // Base Case
    if (target == 0) return true; // Success Case
    if (index == weights.size()) return false; // We've explored all `weights`
    // Recursive Cases
    int currWeight = weights[index];
    // Choice 1: Place weight on the right scale
    bool rightScaleChoice = isMeasurableRecV4(target - currWeight,
                                              weights, index + 1);
    // Choice 2: Place weight on the left scale
    bool leftScaleChoice = isMeasurableRecV4(target + currWeight,
                                             weights, index + 1);
    // Choice 3: Exclude the weight
    bool excludeChoice = isMeasurableRecV4(target, weights, index + 1);
    return rightScaleChoice || leftScaleChoice || excludeChoice;
}



/**
 * @brief isMeasurable: Wrapper Function to call different versions of
 *                      `isMeasurableRec`.
 * @param amount
 * @param weights
 * @return
 */
bool isMeasurable(int amount, const Vector<int>& weights) {
    return isMeasurableV2(amount, weights);
    //return isMeasurableRecV3(amount, weights, 0);
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for the examples from the problem statement.") {
    EXPECT( isMeasurable(2, {1, 3}));
    EXPECT(!isMeasurable(5, {1, 3}));
    EXPECT( isMeasurable(6, {1, 3, 7}));
}

PROVIDED_TEST("Can measure everything from -13 to +13 with well-chosen weights.") {
    for (int i = -13; i <= +13; i++) {
        EXPECT(isMeasurable(i, { 1, 3, 9 }));
    }
    EXPECT(!isMeasurable(-14, { 1, 3, 9 }));
    EXPECT(!isMeasurable(+14, { 1, 3, 9 }));
}
