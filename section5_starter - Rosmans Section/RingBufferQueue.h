#pragma once

class RingBufferQueue {
public:
    /* Creates a new, empty, RingBufferQueue. */
    RingBufferQueue();

    /* Cleans up all memory used by the RingBufferQueue. */
    ~RingBufferQueue();

    /* Enqueues an item. If there is no space left, this function calls
     * error().
     */
    void enqueue(int value);

    /* Looks at, but does not remove, the first element of the queue.
     * If the queue is empty, calls error().
     */
    int peek() const;

    /* Removes and returns the first element of the queue. If the queue
     * is empty, calls error().
     */
    int dequeue();

    /* Returns how many elements are in the queue. */
    int size() const;

    /* Returns whether the queue is empty. */
    bool isEmpty() const;

private:
    // These are are our member variables/instance variables/fields.
    // In the private section is where we are going to store the information
    // we need to interact with our `RingBufferQueue` class.
    // Note: It is a convention to use the _ (Underscore) for these
    // member variables/instance variables/fields to differentiate them from
    // local variables.

    // Additionally, whenever we have helper functions that serve our public
    // methods we place them here to abstract them away from the client.
    // We don't need the client to know how a public member method works
    // behind the scence. E.X. the enlarge() method to expand a Dynamic Array.
    // We don't see enlarge() in the Stanford Vector documentation.

    // Here are our member variables/instance variables/fields for our RBQ Class.
    int *_elements; // Pointer to our Dynamic Array on the Heap
    int _capacity; // Capacity of our Dynamic Array (Max elements we can have in it).
    int _numUsed; // The number of elements in our RBQ. We could also use _size
    int _head; // An instance variable to keep track of the Front of the RBQ
    bool isFull() const; // A private member method to check if the RBQ is full.
};
