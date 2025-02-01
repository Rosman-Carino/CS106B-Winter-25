#pragma once

#include "vector.h"
#include <string>
#include <functional>

/* Some section problems this week involving printing a collection of options
 * to cout. To check whether they're correct, we need the ability to look at
 * what was printed out and make sure that it has the right contents. Because
 * the output format is underspecified, we will try to be as generous as
 * possible with matching the output. Specifically, we'll assume that
 * each output line consists of a single option, and that option consists
 * of a particular series of strings with some extra characters tossed in.
 *
 * To check whether that's the case, this function takes in a callback function
 * that prints to cout. It also takes in a Vector<string>, where each string is
 * a space-separated series of tokens that need to appear on some line of output.
 * We then invoke the callback, see what got printed, and check that each line
 * matches one of the lines from the Vector<string>, in the sense that it has
 * the same tokens in the same order, possibly with extra stuff squished in-between.
 */
bool outputMatchesImpl(std::function<void()> callback,
                       const Vector<std::string>& expected);

#define outputMatches(expr, ...) outputMatchesImpl([&] { expr; }, __VA_ARGS__)
