#include "LookAndSay.h"
using namespace std;

string lookAndSay(string number) {
    (void) number;
    return "";
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on one-digit strings.") {
    EXPECT_EQUAL(lookAndSay("1"), "11");
    EXPECT_EQUAL(lookAndSay("2"), "12");
    EXPECT_EQUAL(lookAndSay("3"), "13");
    EXPECT_EQUAL(lookAndSay("4"), "14");
    EXPECT_EQUAL(lookAndSay("0"), "10");
}

PROVIDED_TEST("Works on one run of digits.") {
    EXPECT_EQUAL(lookAndSay("11"), "21");
    EXPECT_EQUAL(lookAndSay("111"), "31");
    EXPECT_EQUAL(lookAndSay("1111"), "41");
    EXPECT_EQUAL(lookAndSay("1111111111"), "101");
    EXPECT_EQUAL(lookAndSay("11111111111"), "111");
    EXPECT_EQUAL(lookAndSay("99"), "29");
    EXPECT_EQUAL(lookAndSay("999"), "39");
    EXPECT_EQUAL(lookAndSay("9999"), "49");
    EXPECT_EQUAL(lookAndSay("9999999999"), "109");
    EXPECT_EQUAL(lookAndSay("99999999999"), "119");
}

PROVIDED_TEST("Works with multiple different digits.") {
    EXPECT_EQUAL(lookAndSay("12"), "1112");
    EXPECT_EQUAL(lookAndSay("1112"), "3112");
    EXPECT_EQUAL(lookAndSay("3112"), "132112");
    EXPECT_EQUAL(lookAndSay("132112"), "1113122112");
    EXPECT_EQUAL(lookAndSay("1113122112"), "311311222112");
}
