#include "element.hpp"

namespace map::core {


Element::~Element() {}
Location::~Location() {}

//---------------------------------------
Street::Street(tag_street const t) : _tag(t) {}

std::ostream& Street::_print(std::ostream& cout) const {
    return cout << _tag;
}

tag_street const& Street::get_tag() const {
    return _tag;
}

//------------------------------------
Shop::Shop(tag_shop const t) : _tag(t) {}

std::ostream& Shop::_print(std::ostream& cout) const {
    return cout << _tag;
}

tag_shop const& Shop::get_tag() const {
    return _tag;
}

//-----------------------------------------------------
Monument::Monument(tag_monument const t) : _tag(t) {}

std::ostream& Monument::_print(std::ostream& cout) const {
    return cout << _tag;
}

tag_monument const& Monument::get_tag() const {
    return _tag;
}

//---------------------------------------
std::ostream& operator<<(std::ostream& cout, Element const& obj) {
    return obj._print(cout);
}

} // namespace map::core
