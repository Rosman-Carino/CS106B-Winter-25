#include "RingBufferQueue.h"
#include "error.h"
using namespace std;

/* Capacity of a RingBufferQueue. */
const int kNumSlots = 5; // Matches diagram above

RingBufferQueue::RingBufferQueue() {

}

RingBufferQueue::~RingBufferQueue() {

}

void RingBufferQueue::enqueue(int value) {
    (void) value;
}

int RingBufferQueue::peek() const {
    return -1;
}

int RingBufferQueue::dequeue() {
    return -1;
}

int RingBufferQueue::size() const {
    return -1;
}

bool RingBufferQueue::isEmpty() const {
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

/* NOTE: All tests included here assume that the RBQ has five slots. */

PROVIDED_TEST("Basic correctness checks.") {
    RingBufferQueue q;

    EXPECT_EQUAL(q.isEmpty(), true);
    EXPECT_EQUAL(q.size(),        0);
    EXPECT_ERROR(q.peek());
    EXPECT_ERROR(q.dequeue());

    q.enqueue(1);
    EXPECT_EQUAL(q.isEmpty(), false);
    EXPECT_EQUAL(q.size(),        1);
    EXPECT_EQUAL(q.peek(),        1);
    EXPECT_EQUAL(q.dequeue(),     1);
    EXPECT_EQUAL(q.isEmpty(),  true);
    EXPECT_EQUAL(q.size(),        0);
    EXPECT_ERROR(q.peek());
    EXPECT_ERROR(q.dequeue());
}

PROVIDED_TEST("Works on a mix of enqueues and dequeues.") {
    RingBufferQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    EXPECT_ERROR(q.enqueue(7));
    EXPECT_EQUAL(q.peek(), 3);
    EXPECT_EQUAL(q.dequeue(), 3);

    q.enqueue(8);
    EXPECT_ERROR(q.enqueue(9));

    EXPECT_EQUAL(q.peek(), 4);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.peek(), 5);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.peek(), 6);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT_EQUAL(q.peek(), 7);
    EXPECT_EQUAL(q.dequeue(), 7);
    EXPECT_EQUAL(q.peek(), 8);
    EXPECT_EQUAL(q.dequeue(), 8);
}
