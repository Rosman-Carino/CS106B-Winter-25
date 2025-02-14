#include "TwoStacks.h"
#include "error.h"
using namespace std;

const int kInitialSize = 10; // Matching the images from above

/**
 * @brief TwoStacks::TwoStacks: This is the constructor of our
 * TwoStacks class. This is the public method to create an instance of the
 * TwoStacks Class.
 */
TwoStacks::TwoStacks() {
    // Here are our member variables/instance variables/fields are initialized
    // for our TwoStacks Class.
    // Important Note: There is NO need to redeclare the
    // member variables/instance variables/fields we created in our header
    // file. We can just use them directly!
    _capacity = kInitialSize;
    _elements = new int[_capacity];
    // Important Aside! We can also initialize `_elements` in the following manner:
    //_elements = new int[_capacity](); This will auto initialize all the
    // elements in `_elements` to 0.
    _firstStackSize = 0;
    _secondStackSize = 0;
}

/**
 * @brief TwoStacks::~TwoStacks: This is the destructor of our
 * TwoStacks class. This will destroy an instance of a TwoStack instance once
 * it goes out of scope. Additionally, this will release the memory we asked
 * on the Heap for `_elements` in the constructor back to the Operating System.
 */
TwoStacks::~TwoStacks() {
    delete[] _elements; // This syntax is used to ONLY delete a Dynamic Array.
                        // You will learn how to properly create deconstructors
                        // for other collections in the coming weeks.
}

void TwoStacks::pushFirst(int value) {
    if (isTwoStackFull()) {
        error("There is no more room! Ah!");
    }
    int baseIndex = 0;
    _elements[baseIndex + sizeFirst()] = value;
    _firstStackSize++;
}

void TwoStacks::pushSecond(int value) {
    if (isTwoStackFull()) {
        error("There is no more room! Ah!");
    }
    int baseIndex = _capacity - 1;
    _elements[baseIndex - sizeSecond()] = value;
    _secondStackSize++;
}

int TwoStacks::peekFirst() const {
    if (isFirstEmpty()) {
        error("First Stack Size is Empty! Error! No!");
    }
    int baseIndex = 0;
    int offSet = sizeFirst() - 1;
    int topOfFirstStack = _elements[baseIndex + offSet];
    return topOfFirstStack;
}

int TwoStacks::peekSecond() const {
    if (isSecondEmpty()) {
        error("Second Stack Size is Empty! Error! No!");
    }
    int baseIndex = _capacity - 1;
    int offSet = sizeSecond() - 1;
    int topOfSecondStack = _elements[baseIndex - offSet];
    return topOfSecondStack;
}

int TwoStacks::popFirst() {
    int topOfFirstStack = peekFirst();
    _firstStackSize--;
    return topOfFirstStack;
}

int TwoStacks::popSecond() {
    int topOfSecondStack = peekSecond();
    _secondStackSize--;
    return topOfSecondStack;
}

int TwoStacks::sizeFirst() const {
    return _firstStackSize;
}

int TwoStacks::sizeSecond() const {
    return _secondStackSize;
}

bool TwoStacks::isFirstEmpty() const {
    return _firstStackSize == 0;
}

bool TwoStacks::isSecondEmpty() const {
    return _secondStackSize == 0;
}

bool TwoStacks::isTwoStackFull() const {
    return (sizeFirst() + sizeSecond()) == _capacity;
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
