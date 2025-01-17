#pragma once

#include <vector>
#include <functional>

/* Logic to check whether the results of a given experiment are "close enough"
 * to the expected probabilities.
 *
 * The input consists of a list of probabilities for the outcomes 0, 1, 2, ..., n-1,
 * along with a function that performs some random process and then outputs one of
 * 0, 1, 2, ..., or n-1.
 *
 * The result is true if the observed probability distribution is "close enough" to
 * the expected distribution that it appears to be correct. It's false if the
 * observed probability distribution is anomalously far away from the expected one.
 */
namespace ChiSquaredTesting {
    bool isClose(const std::vector<double>& probabilities,
                 std::function<int ()> experiment);
}
