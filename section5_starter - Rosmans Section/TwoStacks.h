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
    // These are are our member variables/instance variables/fields.
    // In the private section is where we are going to store the information
    // we need to interact with our `TwoStacks` class.
    // Note: It is a convention to use the _ (Underscore) for these
    // member variables/instance variables/fields to differentiate them from
    // local variables.

    // Additionally, whenever we have helper functions that serve our public
    // methods we place them here to abstract them away from the client.
    // We don't need the client to know how a public member method works
    // behind the scence. E.X. the enlarge() method to expand a Dynamic Array.
    // We don't see enlarge() in the Stanford Vector documentation.

    int* _elements;             // Elements array
    int  _capacity;     // Number of slots in that array
    int  _firstStackSize;  // Number of elements in the first stack
    int  _secondStackSize; // Number of elements in the second stack
    bool isTwoStackFull() const; // A private member method to check if TwoStack is full.
};
