#pragma once

#include "GUI/SimpleTest.h"

/* Introduces a new CONDITIONAL_TEST macro that only runs if the specified
 * data member / field exists.
 */
#define CONDITIONAL_TEST(name, type, field) \
    DO_CONDITIONAL_TEST(name, type, field, __LINE__)

#define DO_CONDITIONAL_TEST(name, type, field, line) \
    DO_CONDITIONAL_TEST_2(name, type, field, line)

#define DO_CONDITIONAL_TEST_2(name, type, field, line) \
    struct _condTest##line {\
        /* SFINAE dispatch will fail the test if the function isn't implemented, \
         * and will actually run the tests if it is. \
         */ \
        template <typename U> static void test(...) {\
            SHOW_ERROR(#type "::" #field " not defined."); \
        } \
        template <typename U> static void test(decltype(&U::field)*); \
    }; \
    PROVIDED_TEST(name) { \
        _condTest##line::test<type>(nullptr); \
    } \
    /* Use the type name as the template argument so that we can reference the \
     * name of whatever type we're referring to regardless of whether the given \
     * function/field exists. \
     */ \
    template <typename type> void _condTest##line::test(decltype(&type::field)*)
