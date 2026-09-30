#ifndef MAP_CORE_ELEMENT_HPP
#define MAP_CORE_ELEMENT_HPP

#include <ostream>
#include "tag.hpp"

namespace map::core {

class Element {
    friend std::ostream& operator<<(std::ostream& cout, Element const& obj);
protected:
    virtual std::ostream& _print(std::ostream&) const = 0;
public:
    virtual ~Element() = 0;
};
//--------------------------------------------------------------------
class Location : public Element {
protected:
    virtual std::ostream& _print(std::ostream&) const = 0;
public:
    virtual ~Location() = 0;
};
//---------------------------------------
class Street : public Element {
protected:
    tag_street const _tag;
    std::ostream& _print(std::ostream&) const override;
public:
    Street(tag_street const t);
    tag_street const& get_tag() const;
};
//------------------------------------
class Shop : public Location {
protected:
    tag_shop const _tag;
    std::ostream& _print(std::ostream&) const override;
public:
    Shop(tag_shop const t);
    tag_shop const& get_tag() const;
};
//-----------------------------------------------------
class Monument : public Location {
protected:
    tag_monument const _tag;
    std::ostream& _print(std::ostream&) const override;
public:
    Monument(tag_monument const t);
    tag_monument const& get_tag() const;
};

std::ostream& operator<<(std::ostream& cout, Element const& obj);

} 

#endif
