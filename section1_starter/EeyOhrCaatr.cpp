#include "EeyOhrCaatr.h"
using namespace std;

string everyOtherCharacterOf(string input) {
    (void) input;
    return "";
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on short strings.") {
    EXPECT_EQUAL(everyOtherCharacterOf("A"),    "A");
    EXPECT_EQUAL(everyOtherCharacterOf("AB"),   "A");
    EXPECT_EQUAL(everyOtherCharacterOf("ABC"),  "AC");
    EXPECT_EQUAL(everyOtherCharacterOf("ABCD"), "AC");
}

PROVIDED_TEST("Works on the empty string.") {
    EXPECT_EQUAL(everyOtherCharacterOf(""), "");
}

PROVIDED_TEST("Works on more complex strings.") {
    EXPECT_EQUAL(everyOtherCharacterOf("aabbccddeeffgg"), "abcdefg");
    EXPECT_EQUAL(everyOtherCharacterOf("Every Other Character"), "EeyOhrCaatr");
}
