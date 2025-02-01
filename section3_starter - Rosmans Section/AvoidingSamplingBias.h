#pragma once

#include "map.h"
#include "set.h"
#include <string>

Set<std::string> largestUnbiasedGroupIn(const Map<std::string, Set<std::string>>& network);
