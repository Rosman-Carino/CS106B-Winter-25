/******************************************************************************
 * File: OurSet.h
 * Author: Rosman R Cariño
 * CS106B Winter 2025
 * Header file defining a type that acts like Set<string>.
 */
#pragma once

#include <string>
#include "vector.h"
#include "HashFunction.h"

class OurSet {
public:
    /**
     * @brief OurSet: Constructor
     */
    OurSet();

    /**
     * @brief contains: Checks to see if `value` is in `OurSet`.
     * @param value
     * @return True/False to indicate if `value` is in `OurSet`.
     */
    bool contains(const std::string& value) const;

    /**
     * @brief add: Adds `value` to `OurSet`.
     * @param value
     */
    void add(const std::string& value);

    /**
     * @brief size: Returns the number of elements present in `OurSet`.
     * @return Total number of elements present in `OurSet`.
     */
    int size() const;

    /**
     * @brief isEmpty: Checks to see if `OurSet` is empty.
     * @return True/False if there are no elements present in `OurSet`
     */
    bool isEmpty() const;

    /**
     * @brief printHashTable: Visualization of `OurSet`.
     */
    void printHashTable() const;

private:
    /* List of buckets. Each bucket is a list of the strings in
     * that bucket.
     *
     * string = one item
     * Vector<string> = list of items (bucket)
     * Vector<Vector<stirng>> = list of buckets
     */
    Vector<Vector<std::string>> _buckets;

    /* Hash function to distribute items into buckets. */
    HashFunction<std::string> _hashFunction;

    /* Total number of elements, different from number of buckets. */
    int _numElements;

    /*Rehashes all the elements into a larger Hash Table*/
    void rehash();
};

