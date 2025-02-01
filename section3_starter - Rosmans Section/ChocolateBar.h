#pragma once

#include "set.h"
#include "vector.h"
#include <iostream>

int              numWaysToEat(int numSquares);
void             printWaysToEat(int numSquares);
Set<Vector<int>> waysToEat(int numSquares);

/* Way to catch the contents of cout and read it back later. */
class StreamCatcher {
public:
    StreamCatcher() {
        oldBuf = std::cout.rdbuf(buffer.rdbuf());
    }

    ~StreamCatcher() {
        std::cout.rdbuf(oldBuf);
    }

    std::string output() const {
        return buffer.str();
    }
private:
    std::ostringstream buffer;
    std::streambuf* oldBuf;
};
