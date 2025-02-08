#include "TugOfWar.h"
using namespace std;

bool canSplitEvenly(const Vector<int>& strengths) {
    (void) strengths;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works in simple cases.") {
    EXPECT( canSplitEvenly({ }));
    EXPECT( canSplitEvenly({ 0 }));
    EXPECT(!canSplitEvenly({ 1 }));
    EXPECT(!canSplitEvenly({ 1, 2 }));
    EXPECT( canSplitEvenly({ 2, 2 }));
}

PROVIDED_TEST("Works in trickier cases.") {
    EXPECT( canSplitEvenly({ 1, 9, 3, 4, 1 }));
    EXPECT(!canSplitEvenly({ 1, 2, 4, 8, 16 }));
}
