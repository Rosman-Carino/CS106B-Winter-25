#include "TwoStacks.h"
#include "error.h"
using namespace std;

const int kInitialSize = 10; // Matching the images from above

TwoStacks::TwoStacks() {

}

TwoStacks::~TwoStacks() {

}

void TwoStacks::pushFirst(int value) {
    (void) value;
}

void TwoStacks::pushSecond(int value) {
    (void) value;
}

int TwoStacks::peekFirst() const {
    return -1;
}

int TwoStacks::peekSecond() const {
    return -1;
}

int TwoStacks::popFirst() {
    return -1;
}

int TwoStacks::popSecond() {
    return -1;
}

int TwoStacks::sizeFirst() const {
    return -1;
}

int TwoStacks::sizeSecond() const {
    return -1;
}

bool TwoStacks::isFirstEmpty() const {
    return false;
}

bool TwoStacks::isSecondEmpty() const {
    return false;
}


/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

/* NOTE: All test cases below assume the TwoStack type reserves ten slots for its
 * elements.
 */
PROVIDED_TEST("Basic checks") {
    TwoStacks stacks;

    EXPECT_EQUAL(stacks.isFirstEmpty(), true);
    EXPECT_EQUAL(stacks.isSecondEmpty(), true);
    EXPECT_EQUAL(stacks.sizeFirst(), 0);
    EXPECT_EQUAL(stacks.sizeSecond(), 0);
    EXPECT_ERROR(stacks.peekFirst());
    EXPECT_ERROR(stacks.popFirst());
    EXPECT_ERROR(stacks.peekSecond());
    EXPECT_ERROR(stacks.popSecond());

    stacks.pushFirst(1);
    stacks.pushSecond(2);

    EXPECT_EQUAL(stacks.sizeFirst(), 1);
    EXPECT_EQUAL(stacks.sizeSecond(), 1);
    EXPECT_EQUAL(stacks.isFirstEmpty(), false);
    EXPECT_EQUAL(stacks.isSecondEmpty(), false);
    EXPECT_EQUAL(stacks.peekFirst(), 1);
    EXPECT_EQUAL(stacks.peekSecond(), 2);

    EXPECT_EQUAL(stacks.popFirst(), 1);
    EXPECT_EQUAL(stacks.popSecond(), 2);
    EXPECT_EQUAL(stacks.isFirstEmpty(), true);
    EXPECT_EQUAL(stacks.isSecondEmpty(), true);
    EXPECT_EQUAL(stacks.sizeFirst(), 0);
    EXPECT_EQUAL(stacks.sizeSecond(), 0);
    EXPECT_ERROR(stacks.peekFirst());
    EXPECT_ERROR(stacks.popFirst());
    EXPECT_ERROR(stacks.peekSecond());
    EXPECT_ERROR(stacks.popSecond());
}

PROVIDED_TEST("More elaborate checks.") {
    TwoStacks stacks;

    stacks.pushFirst(101);
    stacks.pushSecond(201);
    stacks.pushFirst(102);
    stacks.pushFirst(103);
    stacks.pushSecond(202);
    stacks.pushFirst(104);
    stacks.pushFirst(105);
    stacks.pushFirst(106);
    stacks.pushSecond(203);
    stacks.pushFirst(107);
    EXPECT_ERROR(stacks.pushSecond(204));

    EXPECT_EQUAL(stacks.popFirst(), 107);

    stacks.pushSecond(204);

    EXPECT_EQUAL(stacks.sizeFirst(), 6);
    EXPECT_EQUAL(stacks.sizeSecond(), 4);

    EXPECT_EQUAL(stacks.popSecond(), 204);
    EXPECT_EQUAL(stacks.popFirst(), 106);
    EXPECT_EQUAL(stacks.popFirst(), 105);
    EXPECT_EQUAL(stacks.popFirst(), 104);
}
