#include "OurGrid.h"
#include "error.h"
using namespace std;

OurGrid::OurGrid(int numRows, int numCols) {
    (void) numRows;
    (void) numCols;
}

OurGrid::~OurGrid() {

}

bool OurGrid::inBounds(int row, int col) const {
    (void) row;
    (void) col;
    return false;
}

int OurGrid::numRows() const {
    return -1;
}
int OurGrid::numCols() const {
    return -1;
}

int OurGrid::get(int row, int col) const {
    (void) row;
    (void) col;
    return -1;
}

void OurGrid::set(int row, int col, int value) {
    (void) row;
    (void) col;
    (void) value;
}

/* * * * * Test Cases Below This Point * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Basic correctness checks.") {
    OurGrid grid(2, 3);

    EXPECT_EQUAL(grid.get(0, 0), 0);
    EXPECT_EQUAL(grid.get(0, 1), 0);
    EXPECT_EQUAL(grid.get(0, 2), 0);
    EXPECT_EQUAL(grid.get(1, 0), 0);
    EXPECT_EQUAL(grid.get(1, 1), 0);
    EXPECT_EQUAL(grid.get(1, 2), 0);

    EXPECT_EQUAL(grid.numRows(), 2);
    EXPECT_EQUAL(grid.numCols(), 3);

    EXPECT_ERROR(grid.get(-1, 0));
    EXPECT_ERROR(grid.get(0, -1));
    EXPECT_ERROR(grid.get(-1, -1));
    EXPECT_ERROR(grid.get(3, 0));
    EXPECT_ERROR(grid.get(3, -1));
    EXPECT_ERROR(grid.get(3, 4));
    EXPECT_ERROR(grid.get(0, 4));
    EXPECT_ERROR(grid.get(-1, 4));

    grid.set(0, 0, 4);
    grid.set(0, 1, 5);
    grid.set(0, 2, 6);
    grid.set(1, 0, 7);
    grid.set(1, 1, 8);
    grid.set(1, 2, 9);

    EXPECT_EQUAL(grid.get(0, 0), 4);
    EXPECT_EQUAL(grid.get(0, 1), 5);
    EXPECT_EQUAL(grid.get(0, 2), 6);
    EXPECT_EQUAL(grid.get(1, 0), 7);
    EXPECT_EQUAL(grid.get(1, 1), 8);
    EXPECT_EQUAL(grid.get(1, 2), 9);

    EXPECT(grid.inBounds(0, 0));
    EXPECT(grid.inBounds(1, 2));
    EXPECT(!grid.inBounds(2, 1));
}
