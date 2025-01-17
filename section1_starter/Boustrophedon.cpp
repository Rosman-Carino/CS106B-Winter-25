#include "Boustrophedon.h"
using namespace std;

string fromBoustrophedon(const Grid<char>& message) {
    (void) message;
    return "";
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works on a 2xn grid.") {
    Grid<char> chars = {
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' }
    };

    EXPECT_EQUAL(fromBoustrophedon(chars), "abcfed");
}

PROVIDED_TEST("Works on a 3xn grid.") {
    Grid<char> chars = {
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' }
    };

    EXPECT_EQUAL(fromBoustrophedon(chars), "abcfedghi");
}
