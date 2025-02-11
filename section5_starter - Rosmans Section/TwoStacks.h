#pragma once

class TwoStacks {
public:
    /* Creates two new empty stacks. */
    TwoStacks();

    /* Cleans up the memory used by the stacks. */
    ~TwoStacks();

    /* Pushes an item onto a stack. If there is no space left, these function call
     * error() to report an error.
     */
    void pushFirst(int value);
    void pushSecond(int value);

    /* Pops and item from one of the stacks. If the relevant stack is empty, these
     * functions call error() to report an error.
     */
    int popFirst();
    int popSecond();

    /* Looks at, but does not remove, the top of one of the stacks. These functions
     * call error() to report an error.
     */
    int peekFirst() const;
    int peekSecond() const;

    /* Returns the size of the relevant stack. */
    int sizeFirst() const;
    int sizeSecond() const;

    /* Returns whether the relevant stacks are empty. */
    bool isFirstEmpty() const;
    bool isSecondEmpty() const;

private:
    int* elems;             // Elements array
    int  allocatedSize;     // Number of slots in that array
    int  logicalSizeFirst;  // Number of elements in the first stack
    int  logicalSizeSecond; // Number of elements in the second stack
};
