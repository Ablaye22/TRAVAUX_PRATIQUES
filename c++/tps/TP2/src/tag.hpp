#ifndef MAP_CORE_TAG_HPP
#define MAP_CORE_TAG_HPP

#include <ostream>

namespace map::core {

enum class tag_street { none, trap, slipery, door };
std::ostream& operator<<(std::ostream& cout, tag_street const& obj);

enum class tag_shop { none, mimic, generous };
std::ostream& operator<<(std::ostream& cout, tag_shop const& obj);

enum class tag_monument { statue, wall, table };
std::ostream& operator<<(std::ostream& cout, tag_monument const& obj);

} // namespace map::core

#endif
