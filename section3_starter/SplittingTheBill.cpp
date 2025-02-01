/**
 * Author: Rosman R Cariño
 * CS 106B Winter 2025
 */
#include "SplittingTheBill.h"
#include "map.h"

using namespace std;

/**
 * @brief listPossiblePaymentsRecV1: In this version of `listPossiblePaymentsRec`
 *          we following the `const` that Keith uses. This code is similar to
 *          the solution, but let's optimized to get some intuition on what's going
 *          on.
 * @param total
 * @param people
 * @param personToTotalSoFar
 */
void listPossiblePaymentsRecV1(int total, const Set<string>& people,
                                const Map<string, int>& personToTotalSoFar) {
    // Base Case: There is only 1 person in the Set so they have
    // to pay the entire `total` because there is no one else
    // to split the `total`
    if (people.size() == 1) {
        // Grab the only person from the `people` Set
        string onlyPerson = people.first();
        //Creat a Map where `onlyPerson` is associated to the `total`
        //However, we must copy everything from `personToTotal to make sure
        //we have all of our information
        Map<string, int> finalPersonToTotal = personToTotalSoFar;
        finalPersonToTotal[onlyPerson] = total;
        // Now that we have populated our final Map containing all the information
        // let's print it out
        cout << finalPersonToTotal << endl;
        // Need this `return` statement to exit out of this recursive call
        // from our Call Stack.
        return;
    }
    // Recursive Cases: Let's iterate through the possible of choices a person
    // can "chip in" to split the `total`
    for (int payment = 0; payment <= total; payment++) {
        // Create an updated `personToTotalSoFar` for this Recursive Call and copy
        // the contents of `personToTotalSoFar` into `currentPersonToTotal`
        Map<string, int> updatedPersonToTotal = personToTotalSoFar;
        // Get a person from the Set
        string currentPerson = people.first();
        //Populate `currentPersonToTotal` to the `payment`
        updatedPersonToTotal[currentPerson] = payment;
        // Let's Update our Set
        Set<string> updatedPeople = people - people.first();
        // Let's update our `total`
        int updatedTotal = total - payment;
        // Now that we have made our problem smaller, let's recurse
        listPossiblePaymentsRecV1(updatedTotal, updatedPeople, updatedPersonToTotal);
    }
}

/**
 * @brief listPossiblePaymentsRecV2: This is a version that I would have gone
 *                          with, but it doesn't have the `const` that Keith
 *                          puts in. Personally, I like this more becuase
 *                          it avoids creating copies on each recursive call.
 *                          I also think the code is a little cleaner, but excuse
 *                          the comments I added.
 * @param total
 * @param people
 * @param personToTotalSoFar
 */
void listPossiblePaymentsRecV2(int total, const Set<string>& people,
                               Map<string, int>& personToTotalSoFar) {
    // Base Case: There is only 1 person in the Set so they have
    // to pay the entire `total` because there is no one else
    // to split the `total`
    if (people.size() == 1) {
        // Grab the only person from the `people` Set
        string onlyPerson = people.first();
        // Let's populate `personToTotalSoFar` by associating `onlyPerson` to
        // the `total`
        personToTotalSoFar[onlyPerson] = total;
        // Now that we have populated our final Map containing all the information
        // let's print it out
        cout << personToTotalSoFar << endl;
        // Need this `return` statement to exit out of this recursive call
        // from our Call Stack.
        return;
    }
    // Recursive Cases: Let's iterate through the possible of choices a person
    // can "chip in" to split the `total`
    for (int payment = 0; payment <= total; payment++) {
        // Get a perfom from the `people` Set
        string currentPerson = people.first();
        // Let's populate `personToTotalSoFar` by associating `currentPerson` to
        // the `payment`
        personToTotalSoFar[currentPerson] = payment;
        // Let's Update our Set
        Set<string> updatedPeople = people - people.first();
        // Let's update our `total`
        int updatedTotal = total - payment;
        // Now that we have made our problem smaller, let's recurse
        listPossiblePaymentsRecV2(updatedTotal, updatedPeople, personToTotalSoFar);
    }
}
/**
 * @brief listPossiblePaymentsRecV3: This is similar to Version 2, but
 *                              we put an `else` if that is easier for you
 *                              to understand.
 * @param total
 * @param people
 * @param personToTotalSoFar
 */
void listPossiblePaymentsRecV3(int total, const Set<string>& people,
                               Map<string, int>& personToTotalSoFar) {
    // Base Case: There is only 1 person in the Set so they have
    // to pay the entire `total` because there is no one else
    // to split the `total`
    if (people.size() == 1) {
        // Grab the only person from the `people` Set
        string onlyPerson = people.first();
        // Let's populate `personToTotalSoFar` by associating `onlyPerson` to
        // the `total`
        personToTotalSoFar[onlyPerson] = total;
        // Now that we have populated our final Map containing all the information
        // let's print it out
        cout << personToTotalSoFar << endl;
        // Need this `return` statement to exit out of this recursive call
        // from our Call Stack.
    } else {
        // Recursive Cases: Let's iterate through the possible of choices a person
        // can "chip in" to split the `total`
        for (int payment = 0; payment <= total; payment++) {
            // Get a perfom from the `people` Set
            string currentPerson = people.first();
            // Let's populate `personToTotalSoFar` by associating `currentPerson` to
            // the `payment`
            personToTotalSoFar[currentPerson] = payment;
            // Let's Update our Set
            Set<string> updatedPeople = people - people.first();
            // Let's update our `total`
            int updatedTotal = total - payment;
            // Now that we have made our problem smaller, let's recurse
            listPossiblePaymentsRecV3(updatedTotal, updatedPeople, personToTotalSoFar);
        }
    }
}



void listPossiblePayments(int total, const Set<string>& people) {
    // SafeGaurd 1: The `total` is less than 0 call error
    if (total < 0) error("There is no total to split the bill!");

    // SafeGaurd 2: There is less than 1 person int the `people` Set.
    if (people.size() < 1) error("There is only 1 person. We can't split the bill with 1 peron!");

    // Uncomment the line below for Version 1
    listPossiblePaymentsRecV1(total, people, {});
    // Uncomment the lines below for Version 2 and Version 3
    // Let's call our helper function inside our `wrapper function`
    // Map<string, int> peopleToBill;
    // listPossiblePaymentsRecV3(total, people, peopleToBill);

}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/SubsequenceTesting.h"

PROVIDED_TEST("Works with one person.") {
    Set<string> people = { "A" };
    EXPECT(outputMatches(listPossiblePayments(137, people), {
                             "A 137",
                         }));
}

PROVIDED_TEST("Works with one dollar and three people.") {
    Set<string> people = { "A", "B", "C" };
    EXPECT(outputMatches(listPossiblePayments(1, people), {
                             "A 1 B 0 C 0",
                             "A 0 B 1 C 0",
                             "A 0 B 0 C 1"
                         }));
}

PROVIDED_TEST("Works with two dollars and three people.") {
    Set<string> people = { "A", "B", "C" };
    EXPECT(outputMatches(listPossiblePayments(2, people), {
                             "A 2 B 0 C 0",
                             "A 1 B 1 C 0",
                             "A 1 B 0 C 1",
                             "A 0 B 2 C 0",
                             "A 0 B 1 C 1",
                             "A 0 B 0 C 2"
                         }));
}

PROVIDED_TEST("Works with four dollars and three people.") {
    Set<string> people = { "A", "B", "C" };

    EXPECT(outputMatches(listPossiblePayments(4, people), {
                             "A 0 B 0 C 4",
                             "A 0 B 1 C 3",
                             "A 0 B 2 C 2",
                             "A 0 B 3 C 1",
                             "A 0 B 4 C 0",
                             "A 1 B 0 C 3",
                             "A 1 B 1 C 2",
                             "A 1 B 2 C 1",
                             "A 1 B 3 C 0",
                             "A 2 B 0 C 2",
                             "A 2 B 1 C 1",
                             "A 2 B 2 C 0",
                             "A 3 B 0 C 1",
                             "A 3 B 1 C 0",
                             "A 4 B 0 C 0"
                         }));
}

PROVIDED_TEST("Works with five dollars and five people.") {
    Set<string> people = { "A", "B", "C", "D", "E" };

    EXPECT(outputMatches(listPossiblePayments(5, people), {
                             "A 0 B 0 C 0 D 0 E 5",
                             "A 0 B 0 C 0 D 1 E 4",
                             "A 0 B 0 C 0 D 2 E 3",
                             "A 0 B 0 C 0 D 3 E 2",
                             "A 0 B 0 C 0 D 4 E 1",
                             "A 0 B 0 C 0 D 5 E 0",
                             "A 0 B 0 C 1 D 0 E 4",
                             "A 0 B 0 C 1 D 1 E 3",
                             "A 0 B 0 C 1 D 2 E 2",
                             "A 0 B 0 C 1 D 3 E 1",
                             "A 0 B 0 C 1 D 4 E 0",
                             "A 0 B 0 C 2 D 0 E 3",
                             "A 0 B 0 C 2 D 1 E 2",
                             "A 0 B 0 C 2 D 2 E 1",
                             "A 0 B 0 C 2 D 3 E 0",
                             "A 0 B 0 C 3 D 0 E 2",
                             "A 0 B 0 C 3 D 1 E 1",
                             "A 0 B 0 C 3 D 2 E 0",
                             "A 0 B 0 C 4 D 0 E 1",
                             "A 0 B 0 C 4 D 1 E 0",
                             "A 0 B 0 C 5 D 0 E 0",
                             "A 0 B 1 C 0 D 0 E 4",
                             "A 0 B 1 C 0 D 1 E 3",
                             "A 0 B 1 C 0 D 2 E 2",
                             "A 0 B 1 C 0 D 3 E 1",
                             "A 0 B 1 C 0 D 4 E 0",
                             "A 0 B 1 C 1 D 0 E 3",
                             "A 0 B 1 C 1 D 1 E 2",
                             "A 0 B 1 C 1 D 2 E 1",
                             "A 0 B 1 C 1 D 3 E 0",
                             "A 0 B 1 C 2 D 0 E 2",
                             "A 0 B 1 C 2 D 1 E 1",
                             "A 0 B 1 C 2 D 2 E 0",
                             "A 0 B 1 C 3 D 0 E 1",
                             "A 0 B 1 C 3 D 1 E 0",
                             "A 0 B 1 C 4 D 0 E 0",
                             "A 0 B 2 C 0 D 0 E 3",
                             "A 0 B 2 C 0 D 1 E 2",
                             "A 0 B 2 C 0 D 2 E 1",
                             "A 0 B 2 C 0 D 3 E 0",
                             "A 0 B 2 C 1 D 0 E 2",
                             "A 0 B 2 C 1 D 1 E 1",
                             "A 0 B 2 C 1 D 2 E 0",
                             "A 0 B 2 C 2 D 0 E 1",
                             "A 0 B 2 C 2 D 1 E 0",
                             "A 0 B 2 C 3 D 0 E 0",
                             "A 0 B 3 C 0 D 0 E 2",
                             "A 0 B 3 C 0 D 1 E 1",
                             "A 0 B 3 C 0 D 2 E 0",
                             "A 0 B 3 C 1 D 0 E 1",
                             "A 0 B 3 C 1 D 1 E 0",
                             "A 0 B 3 C 2 D 0 E 0",
                             "A 0 B 4 C 0 D 0 E 1",
                             "A 0 B 4 C 0 D 1 E 0",
                             "A 0 B 4 C 1 D 0 E 0",
                             "A 0 B 5 C 0 D 0 E 0",
                             "A 1 B 0 C 0 D 0 E 4",
                             "A 1 B 0 C 0 D 1 E 3",
                             "A 1 B 0 C 0 D 2 E 2",
                             "A 1 B 0 C 0 D 3 E 1",
                             "A 1 B 0 C 0 D 4 E 0",
                             "A 1 B 0 C 1 D 0 E 3",
                             "A 1 B 0 C 1 D 1 E 2",
                             "A 1 B 0 C 1 D 2 E 1",
                             "A 1 B 0 C 1 D 3 E 0",
                             "A 1 B 0 C 2 D 0 E 2",
                             "A 1 B 0 C 2 D 1 E 1",
                             "A 1 B 0 C 2 D 2 E 0",
                             "A 1 B 0 C 3 D 0 E 1",
                             "A 1 B 0 C 3 D 1 E 0",
                             "A 1 B 0 C 4 D 0 E 0",
                             "A 1 B 1 C 0 D 0 E 3",
                             "A 1 B 1 C 0 D 1 E 2",
                             "A 1 B 1 C 0 D 2 E 1",
                             "A 1 B 1 C 0 D 3 E 0",
                             "A 1 B 1 C 1 D 0 E 2",
                             "A 1 B 1 C 1 D 1 E 1",
                             "A 1 B 1 C 1 D 2 E 0",
                             "A 1 B 1 C 2 D 0 E 1",
                             "A 1 B 1 C 2 D 1 E 0",
                             "A 1 B 1 C 3 D 0 E 0",
                             "A 1 B 2 C 0 D 0 E 2",
                             "A 1 B 2 C 0 D 1 E 1",
                             "A 1 B 2 C 0 D 2 E 0",
                             "A 1 B 2 C 1 D 0 E 1",
                             "A 1 B 2 C 1 D 1 E 0",
                             "A 1 B 2 C 2 D 0 E 0",
                             "A 1 B 3 C 0 D 0 E 1",
                             "A 1 B 3 C 0 D 1 E 0",
                             "A 1 B 3 C 1 D 0 E 0",
                             "A 1 B 4 C 0 D 0 E 0",
                             "A 2 B 0 C 0 D 0 E 3",
                             "A 2 B 0 C 0 D 1 E 2",
                             "A 2 B 0 C 0 D 2 E 1",
                             "A 2 B 0 C 0 D 3 E 0",
                             "A 2 B 0 C 1 D 0 E 2",
                             "A 2 B 0 C 1 D 1 E 1",
                             "A 2 B 0 C 1 D 2 E 0",
                             "A 2 B 0 C 2 D 0 E 1",
                             "A 2 B 0 C 2 D 1 E 0",
                             "A 2 B 0 C 3 D 0 E 0",
                             "A 2 B 1 C 0 D 0 E 2",
                             "A 2 B 1 C 0 D 1 E 1",
                             "A 2 B 1 C 0 D 2 E 0",
                             "A 2 B 1 C 1 D 0 E 1",
                             "A 2 B 1 C 1 D 1 E 0",
                             "A 2 B 1 C 2 D 0 E 0",
                             "A 2 B 2 C 0 D 0 E 1",
                             "A 2 B 2 C 0 D 1 E 0",
                             "A 2 B 2 C 1 D 0 E 0",
                             "A 2 B 3 C 0 D 0 E 0",
                             "A 3 B 0 C 0 D 0 E 2",
                             "A 3 B 0 C 0 D 1 E 1",
                             "A 3 B 0 C 0 D 2 E 0",
                             "A 3 B 0 C 1 D 0 E 1",
                             "A 3 B 0 C 1 D 1 E 0",
                             "A 3 B 0 C 2 D 0 E 0",
                             "A 3 B 1 C 0 D 0 E 1",
                             "A 3 B 1 C 0 D 1 E 0",
                             "A 3 B 1 C 1 D 0 E 0",
                             "A 3 B 2 C 0 D 0 E 0",
                             "A 4 B 0 C 0 D 0 E 1",
                             "A 4 B 0 C 0 D 1 E 0",
                             "A 4 B 0 C 1 D 0 E 0",
                             "A 4 B 1 C 0 D 0 E 0",
                             "A 5 B 0 C 0 D 0 E 0",
                         }));
}

PROVIDED_TEST("Reports errors on invalid inputs.") {
    /* Negative money. */
    EXPECT_ERROR(listPossiblePayments(-1, { "A", "B", "C" }));

    /* No people. */
    EXPECT_ERROR(listPossiblePayments(0, {  }));

    /* Both. */
    EXPECT_ERROR(listPossiblePayments(-1, {  }));
}
