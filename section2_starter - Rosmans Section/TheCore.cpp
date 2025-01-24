#include "TheCore.h"
using namespace std;

Set<string> kCoreOf(const Map<string, Set<string>>& network, int k) {
    (void) network;
    (void) k;
    return {};
}

/* * * * * Test Cases Below This Point * * * * */

#include "GUI/SimpleTest.h"

namespace {
    /* This is a helper function that's useful for designing test cases. You give it a Map
     * of cities and what they're adjacent to, and it then produces a new Map where if city
     * A links to city B, then city B links back to city A. We recommend using this helper
     * function when writing tests, though you won't need it in your implementation of the main
     * canBeMadeDisasterReady function.
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

PROVIDED_TEST("Works on a ring of people.") {
    /*  A -- B
     *  |    |
     *  D -- C
     *
     *  1-core is everyone
     *  2-core is everyone
     *  3-core is no one.
     */
    Map<string, Set<string>> network = makeSymmetric({
        { "A", { "B" } },
        { "B", { "C" } },
        { "C", { "D" } },
        { "D", { "A" } },
    });

    EXPECT_EQUAL(kCoreOf(network, 0), { "A", "B", "C", "D" });
    EXPECT_EQUAL(kCoreOf(network, 1), { "A", "B", "C", "D" });
    EXPECT_EQUAL(kCoreOf(network, 2), { "A", "B", "C", "D" });
    EXPECT_EQUAL(kCoreOf(network, 3), { });
}

PROVIDED_TEST("Works the example from the problem description.") {
    /*  A---B---C
     *  |\  |\ /|
     *  | \ | x |
     *  |  \|/ \|
     *  D---E---F
     */
    Map<string, Set<string>> network = makeSymmetric({
        { "A", { "B", "E", "D" } },
        { "B", { "C", "E", "F" } },
        { "C", { "E", "F" } },
        { "D", { "E" } },
        { "E", { "F" } },
    });

    EXPECT_EQUAL(kCoreOf(network, 0), { "A", "B", "C", "D", "E", "F" });
    EXPECT_EQUAL(kCoreOf(network, 1), { "A", "B", "C", "D", "E", "F" });
    EXPECT_EQUAL(kCoreOf(network, 2), { "A", "B", "C", "D", "E", "F" });
    EXPECT_EQUAL(kCoreOf(network, 3), { "B", "C", "E", "F" });
    EXPECT_EQUAL(kCoreOf(network, 4), { });
}
