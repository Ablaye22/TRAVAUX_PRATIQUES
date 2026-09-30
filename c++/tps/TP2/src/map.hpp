#ifndef MAP_CORE_MAP_HPP
#define MAP_CORE_MAP_HPP

#include <cstddef>
#include <iterator>
#include <initializer_list>
#include "element.hpp"

namespace map::core {

//------------------------
struct Position {
    std::size_t const x;
    std::size_t const y;
    Position(std::size_t const x, std::size_t const y);
};

//------------------------
class Iterator_element {
    Element** _content;
public:
    using iterator_category = std::input_iterator_tag;
    using value_type        = Element*;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;

    Iterator_element(Element** content);

    friend bool operator==(Iterator_element const& a, Iterator_element const& b);
    friend bool operator!=(Iterator_element const& a, Iterator_element const& b);
    friend value_type operator*(Iterator_element& it);
    friend Iterator_element& operator++(Iterator_element& it);
};

//------------------------
class Line {
    Element** _content;
    std::size_t const _nb_element;
public:
    Line(Element** content, std::size_t const nb_element);

    Iterator_element begin() const;
    Iterator_element end() const;
};

//------------------------
class Iterator_line {
    Element** _content;
    std::size_t const _line_size;
public:
    using iterator_category = std::input_iterator_tag;
    using value_type        = Line;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;

    Iterator_line(Element** content, std::size_t const line_size);

    friend bool operator==(Iterator_line const& a, Iterator_line const& b);
    friend bool operator!=(Iterator_line const& a, Iterator_line const& b);
    friend value_type operator*(Iterator_line& it);
    friend Iterator_line& operator++(Iterator_line& it);
};

//------------------------
class Map {
    Element** _content;
    std::size_t const _nb_line;
    std::size_t const _nb_column;
public:
    Map(std::size_t const nbl, std::size_t const nbc,
        std::initializer_list<std::initializer_list<Element*>> obj);
    ~Map();

    std::size_t const& get_nb_line() const;
    std::size_t const& get_nb_column() const;

    // question 3 : operateur "accesseur"
    Element* operator[](Position p) const;

    Iterator_line begin() const;
    Iterator_line end() const;
};

} // namespace map::core

#endif
