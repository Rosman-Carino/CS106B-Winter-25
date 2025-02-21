/*****************************************************
 * File: Main.cpp
 * Author: Rosman R Cariño
 * A program to play around with our new hash set!
 */
#include <iostream>
#include "OurSet.h"
#include "console.h"
#include "simpio.h"
using namespace std;

int main() {
    OurSet set;
    Vector<string> peopleToAdd = {
        "Aidan",
        "Alice",
        "Hloni",
        "Jonathan",
        "Maxton",
        "Nani",
        "Vanesska",
        "Reyad",
        "Meera",
        // Famous Movie Characters
        "Darth Vader",
        "Harry Potter",
        "James Bond",
        "Indiana Jones",
        "The Joker",
        "Forrest Gump",
        "Tony Stark",
        "Black Panther",
        "Luke Skywalker",
        "Jack Sparrow",
        "Rocky Balboa",
        "Neo",
        "The Terminator",
        "Batman",
        "The Dude",
        "Wolverine",
        "Gandalf",
        "Elsa",
        "John Wick",
        "Shrek",
        // Famous TV Show Characters
        "Walter White",
        "Sherlock Holmes",
        "Tyrion Lannister",
        "Michael Scott",
        "Homer Simpson",
        "Rick Sanchez",
        "Tony Soprano",
        "Eleven",
        "Dexter Morgan",
        "BoJack Horseman",
        "Barney Stinson",
        "Joey Tribbiani",
        "Dr. House",
        "Mr. Spock",
        "Buffy Summers",
        "Omar Little",
        "Jean-Luc Picard",
        "Eric Cartman",
        "Daenerys Targaryen",
        "The Mandalorian"
    };

    // Making HashTable Size to 1
    set.add(peopleToAdd[0]);
    set.printHashTable();

    // Making HashTable Size to 3
    for (int i = 1; i < 3; i++) {
        set.add(peopleToAdd[i]);
    }
    set.printHashTable();

    // Making HashTable Size to 6
    for (int i = 3; i < 6; i++) {
        set.add(peopleToAdd[i]);
    }
    set.printHashTable();

    // Making HashTable Size to 7 - We should Rehash Now
    set.add(peopleToAdd[6]);
    set.printHashTable();

    // Now let's hash the remainder of the table
    for (int i = 6; i < peopleToAdd.size(); i++) {
        set.add(peopleToAdd[i]);
    }
    cout << "******************** FINAL STATE OF HASHTABLE ********************\n" << endl;
    set.printHashTable();

    return 0;
}
