#pragma once

class TwoStackQueue {
public:
    /* Adds a new item to the back of the queue. */
    void enqueue(int value);

    /* Removes and returns the front item of the queue. If the queue is
     * empty, this calls error().
     */
    int dequeue();

    /* Returns how many items are in the queue. */
    int size() const;

    /* Returns whether the queue is empty. */
    bool isEmpty() const;

private:
};
