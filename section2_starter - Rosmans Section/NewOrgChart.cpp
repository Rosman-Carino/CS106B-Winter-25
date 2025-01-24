#include "NewOrgChart.h"
using namespace std;

bool areAtSameCompany(const string& p1,
                      const string& p2,
                      const Map<string, string>& bosses) {
    (void) p1;
    (void) p2;
    (void) bosses;
    return false;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works with two CEOs") {
    EXPECT(!areAtSameCompany("Kate", "Katherine", {}));
    EXPECT(areAtSameCompany("Kate", "Kate", {}));
}

PROVIDED_TEST("Works for the examples from the problem statement.") {
    Map<string, string> orgChart = {
        { "b", "a" },
        { "c", "a" },
        { "d", "a" },
        { "e", "b" },
        { "f", "d" },
        { "g", "d" },
        { "h", "g" },
        { "i", "g" },
        { "j", "h" },
        { "l", "k" },
        { "m", "k" },
        { "n", "l" },
        { "o", "l" },
        { "p", "m" },
        { "q", "m" },
        { "r", "o" },
        { "s", "q" },
        { "t", "q" },
    };

    EXPECT(areAtSameCompany("e", "j", orgChart));
    EXPECT(areAtSameCompany("n", "k", orgChart));
    EXPECT(areAtSameCompany("c", "d", orgChart));
    EXPECT(!areAtSameCompany("j", "m", orgChart));
    EXPECT(!areAtSameCompany("u", "b", orgChart));
}
