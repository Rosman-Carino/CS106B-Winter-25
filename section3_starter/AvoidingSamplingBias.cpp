/**
 * Author: Rosman R Cariño
 * CS 106B Winter 2025
 */
#include "AvoidingSamplingBias.h"
using namespace std;

Set<string> largestUnbiasedGroupIn(const Map<string, Set<string>>& network) {
    (void) network;
    return {};
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

namespace {
    /* This is a helper function that's useful for designing test cases. You give it a Map
     * of people and who they're friends with, and it then produces a new Map where if person
     * A is friends with person B, then city B links back to city A.
     */
    Map<string, Set<string>> makeSymmetric(const Map<string, Set<string>>& source) {
        Map<string, Set<string>> result = source;

        for (const string& from: source) {
            for (const string& to: source[from]) {
                result[from] += to;
                result[to] += from;
            }
        }

        return result;
    }
}

// PROVIDED_TEST("Works in very simple cases.") {
//     /* No people to sample from. */
//     EXPECT_EQUAL(largestUnbiasedGroupIn({ }), { });

//     /* One person to sample from. */
//     EXPECT_EQUAL(largestUnbiasedGroupIn({ { "A", { } } }), { "A" });

//     /* Two non-friends to sample from. */
//     EXPECT_EQUAL(largestUnbiasedGroupIn({ { "A", { } }, { "B", { } } }), { "A", "B" });
// }

// PROVIDED_TEST("Works with a triangle of people.") {
//     auto friends = makeSymmetric({
//                                      { "A", { "B" } },
//                                      { "B", { "C" } },
//                                      { "C", { "A" } },
//                                  });

//     EXPECT_EQUAL(largestUnbiasedGroupIn(friends).size(), 1);
//     EXPECT(largestUnbiasedGroupIn(friends).isSubsetOf({ "A", "B", "C" }));
// }

// PROVIDED_TEST("Works with a line of three people.") {
//     /* B -- A -- C */
//     auto friends = makeSymmetric({
//                                      { "A", { "B", "C" } }
//                                  });

//     EXPECT_EQUAL(largestUnbiasedGroupIn(friends), { "B", "C" });

//     /* A -- B -- C */
//     friends = makeSymmetric({
//                                 { "B", { "A", "C" } }
//                             });
//     EXPECT_EQUAL(largestUnbiasedGroupIn(friends), { "A", "C" });
// }

PROVIDED_TEST("Works for the example in the problem description.") {
    /*   B   E   G
     *  / \  |\ /
     * A   \ | F
     *  \   \|/ \
     *   C---D---H
     */
    auto friends = makeSymmetric({
                                     { "A", { "B", "C" } },
                                     { "B", { "D" } },
                                     { "C", { "D" } },
                                     { "D", { "E", "F", "H" } },
                                     { "E", { "F" } },
                                     { "F", { "G", "H" } },
                                  });

    EXPECT_EQUAL(largestUnbiasedGroupIn(friends), { "B", "C", "E", "G", "H" });
}

