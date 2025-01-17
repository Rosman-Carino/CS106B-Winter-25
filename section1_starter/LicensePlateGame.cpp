#include "LicensePlateGame.h"
#include "strlib.h"
using namespace std;

/**
 * @brief wordMatchesPlateV1: Similar to the Section Handout Solution, but
 *                  we're using -1 instead of string::npos
 * @param word
 * @param plate
 * @return
 */
bool wordMatchesPlateV1(string word, string plate) {
    // To avoid Upper Case / Lower Case let's turn both strings to Upper Case
    word = toUpperCase(word);
    plate = toUpperCase(plate);
    int currentIndex = 0;
    // Iterate through the plate
    for (char ch : plate) {
        // Make sure we're looking at an alphabetical character
        if (isalpha(ch)) {
            // Attempt to find the character
            currentIndex = word.find(ch, currentIndex);
            if (currentIndex == -1) return false;
            currentIndex++;
        }
    }
    return true;
}

/**
 * @brief wordMatchesPlateV2: In this version we have a double for loop
 * @param word
 * @param plate
 * @return
 */
bool wordMatchesPlateV2(string word, string plate) {
    // To avoid Upper Case / Lower Case let's turn both strings to Upper Case
    word = toUpperCase(word);
    plate = toUpperCase(plate);
    int currentIndex = 0;
    // Iterate through the plate
    for (char ch : plate) {
        // Make sure we're looking at an alphabetical character
        if (isalpha(ch)) {
            // Attempt to find the character
            bool foundCharacter = false;
            for (int i = currentIndex; i < word.size(); i++) {
                // Found the character
                if (ch == word[i]) {
                    foundCharacter = true;
                    // Need to add this +1 so we can move on to the next character
                    currentIndex = i + 1;
                    break;
                }
            }
            if (!foundCharacter) return false;
        }
    }
    return true;
}

/**
 * @brief wordMatchesPlateV3: Here we our outer loop is the word and our inner
 *                  loop is the plate
 * @param word
 * @param plate
 * @return
 */
bool wordMatchesPlateV3(string word, string plate) {
    // To avoid Upper Case / Lower Case let's turn both strings to Upper Case
    word  = toUpperCase(word);
    plate = toUpperCase(plate);
    int currentIndex = 0;
    for (char ch : word) {
        while (currentIndex < plate.length()) {
            if (!isalpha(plate[currentIndex])) {
                currentIndex++; // Skip non-alphabetic characters in the plate
            } else if (ch == plate[currentIndex]) {
                currentIndex++; // Match found, move to the next plate character
                break;        // Break the loop to process the next word character
            } else {
                break;        // Break the loop if no match
            }
        }
    }

    // After processing the word, ensure all alphabetic characters in plate are matched
    while (currentIndex < plate.length() && !isalpha(plate[currentIndex])) {
        currentIndex++;
    }

    return currentIndex == plate.length();
}

bool wordMatchesPlateV4(string word, string plate) {
    // Convert both strings to uppercase for case-insensitive matching
    word  = toUpperCase(word);
    plate = toUpperCase(plate);
    int plateIndex = 0;
    for (char ch : word) {
        if (plateIndex >= plate.length()) {
            return true;
        }
        if (!isalpha(plate[plateIndex])) {
            plateIndex++;
        }
        int foundIndex = plate.find(ch, plateIndex);

        if (foundIndex == plateIndex) {
            plateIndex++;
        }
    }
    while (plateIndex < plate.length() && !isalpha(plate[plateIndex])) {
        plateIndex++;
    }
    return plateIndex == plate.length();
}




bool wordMatchesPlate(string word, string plate) {
    return wordMatchesPlateV4(word, plate);
}


/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"


PROVIDED_TEST("Works on a simple license plate.") {
    /* Literally the same. */
    // EXPECT(wordMatchesPlate("8JSP137", "8JSP137"));

    /* Just the letters. */
    EXPECT(wordMatchesPlate("JSP", "8JSP137"));

    /* Extra letters added. */
    EXPECT(wordMatchesPlate("JASPER", "8JSP137"));

    /* Same letters, different order. */
    EXPECT(!wordMatchesPlate("SUPERMAJORITY", "8JSP137"));
}

PROVIDED_TEST("Is case-insensitive.") {
    EXPECT(wordMatchesPlate("KOOTENAY", "3KTY271"));
    EXPECT(wordMatchesPlate("kootenay", "3KTY271"));
    EXPECT(wordMatchesPlate("kOoTeNaY", "3KTY271"));
}

PROVIDED_TEST("Works if license plate doesn't have exactly three letters.") {
    EXPECT(wordMatchesPlate("GALACTOSE", "GC2020"));
    EXPECT(!wordMatchesPlate("CAGEY", "GC2020"));
    EXPECT(wordMatchesPlate("HYPOCHLORITE", "2YOHO"));
    EXPECT(!wordMatchesPlate("YAHOO", "2YOHO"));
    EXPECT(wordMatchesPlate("ANYTHINGGOES", ""));
}
