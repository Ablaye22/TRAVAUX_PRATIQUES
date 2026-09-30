#include "map.hpp"
#include <iostream>
#include <stdexcept>

namespace map::core {

//------------------------
Position::Position(std::size_t const x, std::size_t const y) : x(x), y(y) {}

//------------------------
// Iterator_element
//------------------------
Iterator_element::Iterator_element(Element** content) : _content(content) {}

bool operator==(Iterator_element const& a, Iterator_element const& b) {
    return a._content == b._content;
}

bool operator!=(Iterator_element const& a, Iterator_element const& b) {
    return !(a == b);
}

Iterator_element::value_type operator*(Iterator_element& it) {
    return *it._content;
}

Iterator_element& operator++(Iterator_element& it) {
    ++it._content;
    return it;
}

//------------------------
// Line
//------------------------
Line::Line(Element** content, std::size_t const nb_element)
    : _content(content), _nb_element(nb_element) {}

Iterator_element Line::begin() const {
    return Iterator_element(_content);
}

Iterator_element Line::end() const {
    return Iterator_element(_content + _nb_element);
}

//------------------------
// Iterator_line
//------------------------
Iterator_line::Iterator_line(Element** content, std::size_t const line_size)
    : _content(content), _line_size(line_size) {}

bool operator==(Iterator_line const& a, Iterator_line const& b) {
    return a._content == b._content;
}

bool operator!=(Iterator_line const& a, Iterator_line const& b) {
    return !(a == b);
}

Iterator_line::value_type operator*(Iterator_line& it) {
    return Line(it._content, it._line_size);
}

Iterator_line& operator++(Iterator_line& it) {
    it._content += it._line_size;
    return it;
}

//------------------------
// Map
//------------------------
Map::Map(std::size_t const nbl, std::size_t const nbc,
         std::initializer_list<std::initializer_list<Element*>> obj)
    : _content(nullptr), _nb_line(nbl), _nb_column(nbc) {

    if (obj.size() != _nb_line) {
        throw std::invalid_argument("Map: nombre de lignes incoherent avec l'initializer_list");
    }

    _content = new Element*[_nb_line * _nb_column];

    std::size_t i = 0;
    for (std::initializer_list<Element*> const& row : obj) {
        if (row.size() != _nb_column) {
            delete[] _content;
            throw std::invalid_argument("Map: nombre de colonnes incoherent avec l'initializer_list");
        }
        std::size_t j = 0;
        for (Element* const& element : row) {
            // stockage ligne par ligne : la ligne i occupe
            // [_content + i*_nb_column, _content + i*_nb_column + _nb_column)
            _content[(i * _nb_column) + j] = element;
            ++j;
        }
        ++i;
    }
}

Map::~Map() {
    std::cout << "Classe Map detruite" << std::endl;
    delete[] _content;
}

std::size_t const& Map::get_nb_line() const {
    return _nb_line;
}

std::size_t const& Map::get_nb_column() const {
    return _nb_column;
}

Element* Map::operator[](Position p) const {
    if (p.x >= _nb_column || p.y >= _nb_line) {
        throw std::out_of_range("Map::operator[]: position hors limites");
    }
    // Formule imposee par le sujet : x * _nb_line + y.
    // Coherente avec le stockage ligne-par-ligne (rempli via i*_nb_column+j)
    // uniquement si _nb_line == _nb_column, ce qui est le cas dans map_test.cpp.
    return _content[(p.x * _nb_line) + p.y];
}

Iterator_line Map::begin() const {
    return Iterator_line(_content, _nb_column);
}

Iterator_line Map::end() const {
    return Iterator_line(_content + (_nb_line * _nb_column), _nb_column);
}

} // namespace map::core
