/*Author: Rosman R Cariño
 *
 *
 */

#include <iostream>
#include "SimpleTest.h"
#include "lexicon.h"
#include "error.h"
#include "map.h"
using namespace std;


/**
 * @brief obtainCEO: Iterative Version where we use a `while` loop to continuously
 *                  find the boss a specific person until we reach the CEO
 * @param person
 * @param personToBoss
 * @return
 */
string obtainCEO(string person, const Map< string, string>& personToBoss) {
    // While there is a person in the Key section of the Map
    while (personToBoss.containsKey(person)) {
        // Update `person` to its respective boss and continue
        // in the loop
        person = personToBoss[person];
    }
    // Once the While Loop Terminates - Recall that a CEO is not a Key in the Map
    // Then we return the CEO
    return person;
}

string obtainCEORecursive(string person, const Map< string, string>& personToBoss) {
    // Base Case: We cannot continue to `explore` the `personToBoss` Map
    // because recall that the CEO is not a key in the Map.
    if (!personToBoss.containsKey(person)) return person;

    // Recursive Case:
    // Step 1 - Let's update the person by getting the next boss in the
    // organizational hierarchy.

    person = personToBoss[person];

    // Step 2 - Now, that we made our problem smaller by going up in the
    // organizational map, let's recurse
    return obtainCEORecursive(person, personToBoss);
}


bool areAtSameCompany(const string& p1,
                      const string& p2,
                      const Map<string, string>& bosses) {
    // Obtain the CEO of `person1`
    string ceoOfPerson1 = obtainCEO(p1, bosses);
    string ceoOfPerson2 = obtainCEO(p2, bosses);
    // Now that we have the CEO of each respective let's see if their CEO's
    // are the same. If they are the same then they work for the same company
    if (ceoOfPerson1 == ceoOfPerson2) return true;
    return false; // If that `if statement` is not true then we return false
}

PROVIDED_TEST("Works with two CEOs") {
    EXPECT(!areAtSameCompany("Kate", "Katherine", {}));
    EXPECT(areAtSameCompany("Kate", "Kate", {}));
}

PROVIDED_TEST("Works for the examples from the problem statement.") {
    Map<string, string> orgChart = {
                                    { "b", "a" },
                                    { "c", "a" },
                                    { "d", "a" },
                                    { "e", "b" },
                                    { "f", "d" },
                                    { "g", "d" },
                                    { "h", "g" },
                                    { "i", "g" },
                                    { "j", "h" },
                                    { "l", "k" },
                                    { "m", "k" },
                                    { "n", "l" },
                                    { "o", "l" },
                                    { "p", "m" },
                                    { "q", "m" },
                                    { "r", "o" },
                                    { "s", "q" },
                                    { "t", "q" },
                                    };

    EXPECT(areAtSameCompany("e", "j", orgChart));
    EXPECT(areAtSameCompany("a", "e", orgChart));
    EXPECT(!areAtSameCompany("a", "k", orgChart));
    EXPECT(areAtSameCompany("n", "k", orgChart));
    EXPECT(areAtSameCompany("c", "d", orgChart));
    EXPECT(!areAtSameCompany("j", "m", orgChart));
    EXPECT(!areAtSameCompany("u", "b", orgChart));
}
