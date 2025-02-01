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

bool isMeasurableV1(int target, Vector<int>& weights){
    // Base Case
    if (weights.size() == 0) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights.remove(0);
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableV1(target - currWeight, weights);
    bool leftScaleChoice = isMeasurableV1(target + currWeight, weights);
    bool excludeChoice = isMeasurableV1(target, weights);
    weights.insert(0, currWeight);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}

bool isMeasurableV2(int target, Vector<int>& weights){
    // Base Case
    if (weights.size() == 0) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights.remove(weights.size() - 1);
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableV2(target - currWeight, weights);
    bool leftScaleChoice = isMeasurableV2(target + currWeight, weights);
    bool excludeChoice = isMeasurableV2(target, weights);
    weights.add(currWeight);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}


bool isMeasurableRecV3(int target, Vector<int>& weights, int index){
    // Base Case
    if (index >= weights.size()) {
        if (target == 0) { // Success Case
            return true;
        } else {
            return false; // Failure Case
        }
    }
    // Recursive Cases
    int currWeight = weights[index];
    // Choice 1: Place weight on the right scale
    // Choice 2: Place weight on the left scale
    // Choice 3: Exclude the weight
    bool rightScaleChoice = isMeasurableRecV3(target - currWeight,
                                              weights, index + 1);
    bool leftScaleChoice = isMeasurableRecV3(target + currWeight,
                                             weights, index + 1);
    bool excludeChoice = isMeasurableRecV3(target, weights, index + 1);
    return rightScaleChoice || leftScaleChoice || excludeChoice;

}

bool isMeasurableV3(int target, Vector<int>& weights) {
    return isMeasurableRecV3(target, weights, 0);

}


bool isMeasurableRecV4(int target, Vector<int>& weights, int index) {
    // Base Case
    if (target == 0) return true; // Success Case
    if (index >= weights.size()) return false; // We've explored all `weights`
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
 *                      `isMeasurableRec`. Please look at the commented
 *                      code for `isMeasurableRecV4`
 * @param amount
 * @param weights
 * @return
 */
bool isMeasurable(int amount, const Vector<int>& weights) {
    Vector<int> weightsCopy = weights; // Doing this to bypass Keith's love for const
    return isMeasurableV1(amount, weightsCopy);
    //return isMeasurableRecV4(amount, weightsCopy, 0);
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
