#include "ChangeWeCanBelieveIn.h"
#include "error.h"
using namespace std;

/**
 * @brief fewestCoinsFor: This is the solution that Keith provided.
 * @param cents
 * @param coins
 * @return
 */
int fewestCoinsForV1(int cents, const Set<int>& coins) {
    // SafeGuard: If cents is less than 0
    if (cents < 0) error("You have to have cents to make change!");

    // Base Case 1: If there are `0` cents then we return nothing!
    if (cents == 0) return 0;

    // Base Case 2: If there are no `coins` then give back a large value
    if (coins.isEmpty()) return cents + 1;

    // Recursive Cases: We need to create a variable `bestSoFar` to make sure
    // we find the global minimum that will represent the fewest coins
    // to make change.
    int bestSoFar = cents + 1;
    int currentCoin = coins.first();
    for (int copies = 0; copies * currentCoin <= cents; copies++) {
        int currentSoFar = copies + fewestCoinsForV1(cents - copies * currentCoin,
                                                    coins - currentCoin);
        // Perform a Minimum Check to See if we can update
        // the global minimum variable `bestSoFar`
        if (currentSoFar < bestSoFar){
            bestSoFar = currentSoFar;
        }
    }
    // Now that we have explored through the entire space of choices (Enumeration)
    // we can return the the global minimum variable `bestSoFar`
    return bestSoFar;
}

/**
 * @brief fewestCoinsForV2: This is another version here. Instead of removing
 *                      the coins we can just iterate through the `coins` Set.
 * @param cents
 * @param coins
 * @return
 */
int fewestCoinsForV2(int cents, const Set<int>& coins) {
    // SafeGuard: If cents is less than 0
    if (cents < 0) error("You have to have cents to make change!");
    // Base Case 1: If there are `0` cents then we return nothing!
    if (cents == 0) return 0;
    // Recursive Cases: We need to create a variable `bestSoFar` to make sure
    // we find the global minimum that will represent the fewest coins
    // to make change.
    int bestSoFar = cents + 1;
    for (int currentCoin : coins) {
        // We use this `if statement` to avoid overshooting
        if (currentCoin <= cents) {
           int currentSoFar = fewestCoinsForV2(cents - currentCoin, coins) + 1;
            // Perform a Minimum Check to See if we can update
            // the global minimum variable `bestSoFar`
           bestSoFar = min(currentSoFar, bestSoFar);
        }
    }
    // We need to take into account this coin
    return bestSoFar;
}

int fewestCoinsFor(int cents, const Set<int>& coins){
    return fewestCoinsForV1(cents, coins);
    //return fewestCoinsForV2(cents, coins);
}
/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works for US currency.") {
    Set<int> usCoins = { 1, 5, 10, 25, 50, 100 };
    EXPECT_EQUAL(fewestCoinsFor(13,  usCoins), 4);
    cout << "Completed 1" << endl;
    EXPECT_EQUAL(fewestCoinsFor(26,  usCoins), 2);
    cout << "Completed 2" << endl;
    EXPECT_EQUAL(fewestCoinsFor(54,  usCoins), 5);
    cout << "Completed 3" << endl;
    EXPECT_EQUAL(fewestCoinsFor(88,  usCoins), 6);
    cout << "Completed 4" << endl;
    EXPECT_EQUAL(fewestCoinsFor(189, usCoins), 8);
    cout << "Completed 5" << endl;

}

PROVIDED_TEST("Works for Recursian currency.") {
    Set<int> rCoins = { 1, 12, 14, 63 };

    EXPECT_EQUAL(fewestCoinsFor(12,  rCoins), 1);
    EXPECT_EQUAL(fewestCoinsFor(11,  rCoins), 11);
    EXPECT_EQUAL(fewestCoinsFor(24,  rCoins), 2);
}

/* All denominations of coinage that have ever been issued in the United States,
 * ranging from 1 cent to $100.
 */
const Set<int> kAllUSDenominations = {
           // Half-cent coins used to exist, but are too small for an int. :-(
    1,
    2,     // Two-cent coins were minted from 1864 - 1873
    3,     // Three-cent nickels were minted from 1865 - 1889
    5,
    10,
    20,    // Twenty-cent coins were minted from 1875 - 1878
    25,
    50,
    100,
    250,   // "Quarter eagle" coins were minted from 1796-1929
    300,   // Three-dollar gold coins were minted from 1854 - 1889
    400,   // Four-dollar gold coins were minted from 1879 - 1880
    500,   // "Half eagle" coins were minted from  1795 - 1929
    1000,  // "Eagle" coins were minted from 1792 - 1933
    2000,  // "Double eagle" coins were minted from 1792 - 1933
    2500,  // "Quarter Platinum Eagle" coins have been minted since 1995
    5000,  // "American Gold Eagle" and "American Buffalo" coins have been minted since 1985
    10000  // "American Platinum Eagle" coins have been minted since 1995
};

PROVIDED_TEST("Works for historical US currency.") {
    EXPECT_EQUAL(fewestCoinsFor(4,  kAllUSDenominations), 2);
    cout << "Completed 1 - US" << endl;
    EXPECT_EQUAL(fewestCoinsFor(24, kAllUSDenominations), 3);
    cout << "Completed 2 - US" << endl;
    EXPECT_EQUAL(fewestCoinsFor(37, kAllUSDenominations), 3);
    cout << "Completed 3 - US" << endl;
}

PROVIDED_TEST("Example From Section.") {
    Set<int> rCoins = { 1, 6, 10};
    EXPECT_EQUAL(fewestCoinsFor(12,  rCoins), 2);

}
