#include "SubsequenceTesting.h"
#include "strlib.h"
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

namespace {
    /* Way to catch the contents of cout and read it back later. */
    class StreamCatcher {
    public:
        StreamCatcher() {
            oldBuf = std::cout.rdbuf(buffer.rdbuf());
        }

        ~StreamCatcher() {
            std::cout.rdbuf(oldBuf);
        }

        string output() const {
            return buffer.str();
        }
    private:
        ostringstream buffer;
        streambuf* oldBuf;
    };

    /* Utility function to get back a Set<Vector<int>> from what was printed
     * to cout. Calls error if any duplicates were found.
     */
    Vector<string> decode(const StreamCatcher& catcher) {
        Vector<string> result;
        istringstream extractor(catcher.output());

        /* Read each line one at a time. */
        for (string line; getline(extractor, line); ) {
            result += line;
        }
        return result;
    }

    /* Tokenizes the expected lines. */
    Vector<Vector<string>> tokenize(const Vector<string>& expected) {
        Vector<Vector<string>> result;
        for (const auto& line: expected) {
            result += stringSplit(line, " ");
        }
        return result;
    }

    /* Checks whether a string matches a pattern. */
    bool matches(const string& text, const Vector<string>& pattern) {
        size_t index = 0;
        for (const auto& token: pattern) {
            /* Resume the search from where we left off. */
            index = text.find(token, index);
            if (index == string::npos) {
                return false;
            }

            /* Skip past the token. */
            index += token.length();
        }

        return true;
    }
}

bool outputMatchesImpl(function<void()> callback, const Vector<string>& expected) {
    /* Tokenize our expected lines. */
    Vector<Vector<string>> options = tokenize(expected);

    /* Divert cout. */
    StreamCatcher catcher;

    /* Invoke the callback to see what it prints out. */
    callback();

    /* Make sure everything printed matches something. */
    for (string line: decode(catcher)) {
        bool found = false;
        for (int i = 0; i < options.size(); i++) {
            if (matches(line, options[i])) {
                /* Remove efficiently. */
                swap(options[i], options[options.size() - 1]);
                options.remove(options.size() - 1);
                found = true;
                break;
            }
        }
        /* Didn't match anything. */
        if (!found) return false;
    }

    /* We should have matched all the expected lines. */
    return options.isEmpty();
}
