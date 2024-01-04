#pragma once

#include <cstddef>
#include <vector>

using ushort = unsigned short;

namespace Utils {

using tableVector = std::vector<std::vector<ushort>>;
tableVector emptyVector();

}