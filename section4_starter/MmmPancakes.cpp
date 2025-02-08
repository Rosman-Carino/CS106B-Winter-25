#include "MmmPancakes.h"
#include "queue.h"
#include <cfloat>
using namespace std;

// Optional<Vector<int>> sortStack(Stack<double> pancakes, int numFlips) {
//     (void) pancakes;
//     (void) numFlips;
//     return Nothing;
// }
/* Given a stack of pancakes, returns whether it's sorted. */
bool isSorted(Stack<double> pancakes) {
    // Let's set

    double last = DBL_MIN;

    while (!pancakes.isEmpty()) {
        /* Check the next pancake. */
        double next = pancakes.pop();
        if (next < last) {
            return false;
        }

        last = next;
    }

    /* Pancakes are in increasing order! */
    return true;
}

/* Given a stack of pancakes and a flip size, flips that many pancakes
 * on the top of the stack.
 */
Stack<double> flip(Stack<double> pancakes, int numToFlip) {
    /* Take the top pancakes off the stack and run them into a queue.
     * This preserves the order in which they were removed.
     */

    // Step 1: Place everything into a Queue
    Queue<double> buffer;
    for (int i = 0; i < numToFlip; i++) {
        buffer.enqueue(pancakes.pop());
    }

    // Step 2: Place the Pancakes we placed in our `Queue` back
    // into the Stack. Essentially this reverses it.
    /* Move the pancakes back. */
    while (!buffer.isEmpty()) {
        pancakes.push(buffer.dequeue());
    }

    return pancakes;
}

Optional<Vector<int>> sortStackV1(Stack<double> pancakes, int numFlips) {
    /* Base Case: If the stack is sorted, great! We're done, and no flips
     * were needed. This is our Success Case.
     */
    if (isSorted(pancakes)) {
        return { }; // No flips
    }
    /* Base Case: If the stack isn't sorted and we're out of flips, then
     * there is no way to sort things. This is our Failure Case.
     */
    if (numFlips == 0) {
        return Nothing;
    }
    /* Recursive Case: The stack isn't sorted and we still have flips left.
     * The next flip could flip 1, 2, 3, ..., or all N of the pancakes.
     * Try each option and see whether any of them work.
     */
    for (int numToFlip = 1; numToFlip <= pancakes.size(); numToFlip++) {
        /* Make the flip and see if it works. */

        //Step 1: Perform the Flip on the Stack of Pancakes.
        Stack<double> flippedPancakes = flip(pancakes, numToFlip);
        // Recurse and See if this choice worked.
        Optional<Vector<int>> result = sortStackV1(flippedPancakes, numFlips - 1);

        // We need to check if our answer worked.
        if (result != Nothing) {
            /* The result holds all the remaining flips but doesn't know about
             * the flip we just did. Insert that flip at the beginning.
             */
            result.value().insert(0, numToFlip);
            return result;
        }
    }

    /* If we're here, then no matter which flip we make first, we cannot
     * get the pancakes sorted. Give up after exhaustively going through
     * every possible attempt.
     */
    return Nothing;
}


Optional<Vector<int>> sortStack(Stack<double> pancakes, int numFlips) {
    return sortStackV1(pancakes, numFlips);

}


// Optional<Vector<int>> sortStackV1(Stack<double> pancakes, int numFlips) {
//     /* Base Case: If the stack is sorted, great! We're done, and no flips
//      * were needed. This is our Success Case.
//      */
//     if (isSorted(pancakes)) {
//         return { }; // No flips
//     }
//     /* Base Case: If the stack isn't sorted and we're out of flips, then
//      * there is no way to sort things. This is our Failure Case.
//      */
//     if (numFlips == 0) {
//         return Nothing;
//     }
//     /* Recursive Case: The stack isn't sorted and we still have flips left.
//      * The next flip could flip 1, 2, 3, ..., or all N of the pancakes.
//      * Try each option and see whether any of them work.
//      */
//     for (int numToFlip = 1; numToFlip <= pancakes.size(); numToFlip++) {
//         /* Make the flip and see if it works. */
//         Stack<double> flippedPancakes = flip(pancakes, numToFlip);
//         Optional<Vector<int>> result = sortStack(flippedPancakes, numFlips - 1);

//         // We need to check if our answer worked.
//         if (result != Nothing) {
//             /* The result holds all the remaining flips but doesn't know about
//              * the flip we just did. Insert that flip at the beginning.
//              */
//             result.value().insert(0, numToFlip);
//             return result;
//         }
//     }

//     /* If we're here, then no matter which flip we make first, we cannot
//      * get the pancakes sorted. Give up after exhaustively going through
//      * every possible attempt.
//      */
//     return Nothing;
// }

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on simple examples.") {
    EXPECT_EQUAL(sortStack({ 3, 2, 1 }, 0), { });
    EXPECT_EQUAL(sortStack({ 3, 2, 1 }, 1), { });
    EXPECT_EQUAL(sortStack({ 1, 2, 3 }, 0), Nothing);
    EXPECT_EQUAL(sortStack({ 1, 2, 3 }, 1), { 3 });
}

PROVIDED_TEST("Works on the example from the problem description.") {
    EXPECT_EQUAL(sortStack({ 7, 6, 1, 2, 5, 4, 3 }, 2), { 3, 5 });
}

PROVIDED_TEST("Works on a trickier example.") {
    Stack<double> values = { 0, 1, 3, 6, 2, 7, 13, 20, 12 };
    EXPECT_EQUAL(sortStack(values, 6), Nothing);
    EXPECT_EQUAL(sortStack(values, 7), { 3, 2, 4, 5, 7, 6, 9 });
}

PROVIDED_TEST("Section Example.") {
    EXPECT_EQUAL(sortStack({1, 4, 2, 3 }, 3), { 2, 3, 4 });
    EXPECT_EQUAL(sortStack({1, 4, 2, 3 }, 2), Nothing);

}
