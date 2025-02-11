#include "RandomBag.h"
#include "random.h"
#include "error.h"
using namespace std;

void RandomBag::add(int value) {
    elems += value;
}

int RandomBag::removeRandom() {
    /* We're using our own isEmpty() function. This is okay to do because we
     * told C++ that isEmpty is a function in the header file, so C++ knows
     * to expect it later on.
     */
    if (isEmpty()) {
        error("Aaaaaah!");
    }

    /* This is an inefficient implementation. Great question to ponder: how
     * fast is this code in big-O terms, and how can you make it run in time
     * O(1)?
     */
    int index  = randomInteger(0, size() - 1);
    int result = elems[index];
    elems.remove(index);

    return result;
}

/* We need to put the const here because, as we said in the header file, this
 * function doesn't change the size of the bag.
 */
int RandomBag::size() const {
    return elems.size();
}

bool RandomBag::isEmpty() const {
    return size() == 0;
}


/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/ConditionalTest.h"
#include "set.h"

PROVIDED_TEST("Basic correctness checks.") {
    RandomBag bag;
    EXPECT(bag.isEmpty());
    EXPECT_EQUAL(bag.size(), 0);
    EXPECT_ERROR(bag.removeRandom());

    bag.add(137);
    EXPECT(!bag.isEmpty());
    EXPECT_EQUAL(bag.size(), 1);
    EXPECT_EQUAL(bag.removeRandom(), 137);

    bag.add(0);
    bag.add(1);
    bag.add(2);
    bag.add(3);
    bag.add(4);

    Set<int> used;
    for (int i = 5; i > 0; i--) {
        EXPECT_EQUAL(bag.size(), i);
        EXPECT_EQUAL(bag.isEmpty(), i == 0);
        used += bag.removeRandom();
    }
    EXPECT_EQUAL(bag.size(), 0);
    EXPECT_EQUAL(bag.isEmpty(), true);
    EXPECT_EQUAL(used, { 0, 1, 2, 3, 4 });
}

PROVIDED_TEST("removeRandom runs in time O(1).") {
    const int kNumItems = 200000;
    RandomBag bag;
    for (int i = 0; i < kNumItems; i++) {
        bag.add(i);
    }

    /* If removeRandom runs in time O(n), then across all these iterations
     * the time complexity is O(n^2), not very fast. But if you make
     * removeRandom run in time O(1), this will take O(n) time.
     */
    Vector<bool> found(kNumItems, false); // Track what we've seen

    EXPECT_COMPLETES_IN(0.5,
        while (!bag.isEmpty()) {
            int next = bag.removeRandom();
            EXPECT(next >= 0 && next < kNumItems);
            EXPECT(!found[next]);
            found[next] = true;
        }
    );

    /* Now make sure we got everything. */
    for (int i = 0; i < kNumItems; i++) {
        EXPECT(found[i]);
    }
}

CONDITIONAL_TEST("peek works correctly,", RandomBag, peek) {
    RandomBag bag;
    EXPECT_ERROR(bag.peek());

    /* Fill a RandomBag with a bunch of items. */
    for (int i = 0; i < 1000; i++) {
        bag.add(i);
    }

    /* Confirm they all peek out correctly. */
    Set<int> used;
    for (int i = 0; i < 1000; i++) {
        int expected = bag.peek();
        EXPECT_EQUAL(bag.removeRandom(), expected);
        used += expected;
    }
    EXPECT_ERROR(bag.peek());

    /* Confirm we got everything we wanted. */
    EXPECT_EQUAL(used.size(), 1000);
    for (int i = 0; i < 1000; i++) {
        EXPECT(used.contains(i));
    }
}
