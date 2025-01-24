#pragma once

#include "set.h"
#include "map.h"
#include <string>

Set<std::string> kCoreOf(const Map<std::string, Set<std::string>>& network, int k);
