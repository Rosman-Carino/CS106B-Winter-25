#pragma once

#include "map.h"
#include <string>

bool areAtSameCompany(const std::string& p1,
                      const std::string& p2,
                      const Map<std::string, std::string>& bosses);
