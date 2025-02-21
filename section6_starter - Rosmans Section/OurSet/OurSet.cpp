/* Author: Rosman R Cariño
 * CS106B Winter 2025
 */
#include "OurSet.h"
using namespace std;

const int kInitialBucketCount = 3;
const double LOAD_FACTOR_THESHOLD = 2;

/********************************************
 * private:
 *    Vector<Vector<string>> buckets;
 *    HashFunction<string> hashFn;
 *    int numElems;
 */

/**
 * @brief OurSet::OurSet: Constructor for `OurSet` which is backed by a HashTable.
 */
OurSet::OurSet() {
    /* Create buckets: We can do this through 2 options
    */

    // Option 1:
    // for (int i = 0; i < kInitialBucketCount; i++) {
    //     buckets.add({ });
    // }

    // Option 2:
    Vector<Vector<string>> ourBuckets(kInitialBucketCount);
    _buckets = ourBuckets;

    // /* Pick a hash function: This is given to us*/
    _hashFunction = forSize(kInitialBucketCount);
    _numElements = 0;
}

/**
 * @brief OurSet::add: This method adds an element, `value` to `OurSet`. If
 * `value` is already in `OurSet` then we do not add it again to `OurSet`.
 * If the Load Factor exceeds 2 then the private member method `rehash`
 * is called to evenly distribute the elements in `OurSet`.
 * @param value: A string element being added to `OurSet`
 */
void OurSet::add(const string& value) {
    /* If already present, do nothing. */
    if (contains(value)) return;

    /* Otherwise, find its bucket and put it there. */
    int bucket = _hashFunction(value);
    _buckets[bucket] += value; // You can also use the .add() method from the Vector class.
    _numElements++;

    /* If our load factor exceeds the maximum, rehash. */
    if (double(_numElements) / _buckets.size() > LOAD_FACTOR_THESHOLD) {
        cout << "****** BEFORE REHASHING ******" << endl;
        printHashTable();
        cout << "It is now time to rehash! \n" << endl;
        cout << "Rehasing in Process......\n" << endl;
        rehash();
        cout << "Rehashing Complete \n" << endl;
    }
}

/**
 * @brief OurSet::contains: This method checks to see if `value` is already
 *              present in `OurSet`.
 * @param value: A string element.
 * @return True/False to indicate if `OurSet` contains `value`.
 */
bool OurSet::contains(const string& value) const {
    /* If it's here, it's in the bucket associated with its hash code.
     * So look there and see if we can find it.
     */
    int bucket = _hashFunction(value);

    for (string elem: _buckets[bucket]) {
        if (elem == value) return true;
    }

    return false;
}

/**
 * @brief OurSet::size: This method returns the number of elements that have been
 *                          added to `OurSet`.
 * @return numElems
 */
int OurSet::size() const {
    return _numElements;
}

/**
 * @brief OurSet::isEmpty: This method checks to see if `OurSet` is empty.
 * @return True/False if the `OurSet` is empty;
 */
bool OurSet::isEmpty() const {
    return size() == 0;
}

/**
 * @brief OurSet::rehash: This method will rehash all the elements in our
 * `Set` backed by a HashTable once the Load Factor exceeds 2.
 * Recall that Load Factor = Number of Elements / Number of Buckets
 */
void OurSet::rehash() {
    /* We need new buckets and a new hash function, since our old hash
     * function is designed to only work on a smaller range.
     */
    Vector<Vector<std::string>> newBuckets(_buckets.size() * 2);
    HashFunction<std::string> newHashFn = forSize(_buckets.size() * 2);

    /* Redistribute all elements into the new buckets. */
    for (int i = 0; i < _buckets.size(); i++) {
        for (string elem: _buckets[i]) {
            int newBucket = newHashFn(elem);
            newBuckets[newBucket] += elem;
        }
    }

    /* Update master list of buckets and our hash function. */
    _buckets = newBuckets;
    _hashFunction = newHashFn;
}

/**
 * @brief OurSet::printHashTable: This method will print the contents of the
 * `Set` backed by a HashTable.
 */
void OurSet::printHashTable() const {
    cout << "***** Hash Table After Adding " << _numElements << " Element(s) ***** \n" << endl;
    cout << "Number of Buckets: " << _buckets.size() << endl;
    cout << "Number of Elements: " << _numElements << endl;
    cout << "Load Factor: " << double(_numElements) / _buckets.size() << "\n" << endl;
    for (int i = 0; i < _buckets.size(); i++) {
        cout << "Bucket [" << i << "]: ";
        for(const string &person : _buckets[i]) {
            cout << person << ", ";
        }
        cout << endl;
    }
    cout << endl;
}


