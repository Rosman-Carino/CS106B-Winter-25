#include "RingBufferQueue.h"
#include "error.h"
using namespace std;

/* Capacity of a RingBufferQueue. */
const int kNumSlots = 5; // Matches diagram above

/**
 * @brief RingBufferQueue::RingBufferQueue: This is the constructor of our
 * RBQ class. This is the public method to create an instance of the
 * RBQ Class.
 */
RingBufferQueue::RingBufferQueue() {
    // Here are our member variables/instance variables/fields are initialized
    // for our RBQ Class.
    // Important Note: There is NO need to redeclare the
    // member variables/instance variables/fields we created in our header
    // file. We can just use them directly!
    _capacity = kNumSlots;
    _elements = new int[_capacity];
    // Important Aside! We can also initialize `_elements` in the following manner:
    //_elements = new int[_capacity](); This will auto initialize all the
                                        // elements in `_elements` to 0.
    _head = 0;
    _numUsed = 0;
}

/**
 * @brief RingBufferQueue::~RingBufferQueue: This is the destructor of our
 * RBQ class. This will destroy an instance of an RBQ instance once it goes
 * out of scope. Additionally, this will release the memory we asked on the Heap
 * for `_elements` in the constructor back to the Operating System.
 * This avoids memory leaks.
 */
RingBufferQueue::~RingBufferQueue() {
    delete[] _elements; // This syntax is used to ONLY delete a Dynamic Array.
                        // You will learn how to properly create deconstructors
                        // for other collections in the coming weeks.

}

/**
 * @brief RingBufferQueue::enqueue: This method will an enqueue an integer
 *                          to our RBQ. If the RBQ is full then we will raise
 *                          an error.
 * @param value
 */
void RingBufferQueue::enqueue(int value) {
    // Perform Check to not `enqueue()` if our `RBQ` is full.
    if (isFull()) {
        error("No! Bad! You cannot enqueue() when RBQ is full! Bad!");
    }
    // Note: We can create a member variable for this, too. But let's just
    // roll with this.
    int tail = (_head + _numUsed) % _capacity; // The % (Mod) operator is powerful
                                               // to "wrap" around a fixed size.
    _elements[tail] = value;
    _numUsed++;
}

/**
 * @brief RingBufferQueue::peek: This method will return the most front element
 *                      of the RBQ. Note: This does not actually change the size
 *                      of RBQ. If the RBQ is empty then it will raise an
 *                      error.
 * @return
 */
int RingBufferQueue::peek() const {
    if (isEmpty()) {
        error("Cannot peek from an Empty Queue! Bad!");
    }
    return _elements[_head];
}

/**
 * @brief RingBufferQueue::dequeue: Will return the the most front element of
 *                          the RBQ. If the RBQ is empty then it will raise
 *                          an error.
 * @return
 */
int RingBufferQueue::dequeue() {
    // Just call peek() to avoid redundant code.
    int frontElement = peek();
    // Now we need to update our RBQ
    _head = (_head + 1) % _capacity;
    _numUsed--;
    return frontElement;
}

/**
 * @brief RingBufferQueue::size: This method tells the current size of our RBQ
 *                      by using _numUsed.
 * @return
 */
int RingBufferQueue::size() const {
    return _numUsed;
}

/**
 * @brief RingBufferQueue::isEmpty: This method tells us of our RBQ is empty
 *                      by comparing it to _numUsed.
 * @return
 */
bool RingBufferQueue::isEmpty() const {
    return _numUsed == 0; // We can also do an if/else statement here, but this is cleaner.
}

/**
 * @brief RingBufferQueue::isFull: This private member method will tell us
 *                  if we have reached our RBQ _capacity.
 * @return
 */
bool RingBufferQueue::isFull() const {
    return _numUsed == _capacity;
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
