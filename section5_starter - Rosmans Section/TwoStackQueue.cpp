#include "TwoStackQueue.h"
#include "error.h"
using namespace std;

void TwoStackQueue::enqueue(int value) {
    (void) value;
}

int TwoStackQueue::dequeue() {
    return -1;
}

int TwoStackQueue::size() const {
    return -1;
}

bool TwoStackQueue::isEmpty() const {
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Basic correctness checks.") {
    TwoStackQueue q;
    EXPECT_EQUAL(q.isEmpty(), true);
    EXPECT_EQUAL(q.size(),       0);
    EXPECT_ERROR(q.dequeue());

    q.enqueue(1);
    q.enqueue(2);

    EXPECT_EQUAL(q.size(), 2);
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.size(), 1);
    EXPECT_EQUAL(q.isEmpty(), false);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.isEmpty(), true);
    EXPECT_EQUAL(q.size(), 0);
    EXPECT_ERROR(q.dequeue());
}

PROVIDED_TEST("Works on interleaved enqueues and dequeues.") {
    TwoStackQueue q;

    int nextIn = 0;
    int nextOut = 0;
    for (int i = 0; i < 10; i++) {
        q.enqueue(nextIn);
        nextIn++;
        q.enqueue(nextIn);
        nextIn++;

        EXPECT_EQUAL(q.dequeue(), nextOut);
        nextOut++;
    }
}
