#include "XzibitWords.h"
using namespace std;

string mostXzibitWord(const Lexicon& words) {
    (void) words;
    return "";
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Works with strings made only of a's.") {
    /* We use a reduced Lexicon so we can do targeted tests. */
    Lexicon words = {
        "a", "aa", "aaa", "aaaa", "aaaaa"
    };
    EXPECT_EQUAL(mostXzibitWord(words), "aaaaa");
}

PROVIDED_TEST("Works on the full lexicon.") {
    Lexicon words("res/EnglishWords.txt");
    EXPECT_EQUAL(mostXzibitWord(words), "anticholinesterases");
}
