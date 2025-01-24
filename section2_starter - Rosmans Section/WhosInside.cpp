#include "WhosInside.h"
using namespace std;

Set<int> peopleInsideGreen(const Vector<int>& idScans) {
    (void) idScans;
    return {};
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works when no one leaves.") {
    EXPECT_EQUAL(peopleInsideGreen({ 1, 2, 3 }), { 1, 2, 3 });
    EXPECT_EQUAL(peopleInsideGreen({  }), { });
}

PROVIDED_TEST("Works when one person leaves.") {
    EXPECT_EQUAL(peopleInsideGreen({ 1, 1 }), { });
    EXPECT_EQUAL(peopleInsideGreen({ 1, 2, 1 }), { 2 });
}

PROVIDED_TEST("Works on a mix of people entering and leaving.") {
    EXPECT_EQUAL(peopleInsideGreen({ 137, 106, 137, 161, 261, 137, 106 }), { 137, 161, 261 });
}

PROVIDED_TEST("Works when people come and go multiple times.") {
    EXPECT_EQUAL(peopleInsideGreen({ 1, 2, 1, 2, 1, 2, 1, 2, 1 }), { 1 });
}
