#include "Circle.h"
#include <cmath>
using namespace std;





/* * * * * Test Cases Below This Point * * * * */
#include "Demos/ConditionalTest.h"

CONDITIONAL_TEST("Can set and read radius.", Circle, radius) {
    Circle one(1), two(2);

    EXPECT_EQUAL(one.radius(), 1);
    EXPECT_EQUAL(two.radius(), 2);
}

CONDITIONAL_TEST("Circumference is calculated correctly.", Circle, circumference) {
    Circle one(1), two(2);

    EXPECT_EQUAL(one.circumference(), 2 * M_PI);
    EXPECT_EQUAL(two.circumference(), 4 * M_PI);
}

CONDITIONAL_TEST("Area is calculated correctly.", Circle, area) {
    Circle one(1), two(2);

    EXPECT_EQUAL(one.area(), M_PI);
    EXPECT_EQUAL(two.area(), 4 * M_PI);
}
