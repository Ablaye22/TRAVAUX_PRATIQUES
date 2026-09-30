#include <iostream>
#include "element.hpp"
#include "map.hpp"

namespace map::core {

void test1() {
    Street st(tag_street::none);
    Street tr(tag_street::trap);
    Street sl(tag_street::slipery);
    Street dr(tag_street::door);
    Shop s1(tag_shop::generous);
    Shop s2(tag_shop::mimic);
    Monument wl(tag_monument::wall);
    Monument tb(tag_monument::table);

    Map map(17, 17, {
        {&wl, &wl, &wl, &wl, &dr, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &dr, &wl, &wl, &wl, &wl},
        {&wl, &s1, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl},
        {&wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &tr, &st, &st, &st, &tr, &st, &wl},
        {&wl, &st, &st, &tb, &st, &tr, &st, &st, &st, &st, &st, &st, &st, &tb, &st, &st, &wl},
        {&wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl},
        {&wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &tr, &st, &st, &st, &st, &s2, &wl},
        {&wl, &wl, &wl, &st, &st, &st, &st, &st, &st, &st, &sl, &st, &st, &sl, &wl, &wl, &wl},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &tb, &st, &st, &st, &st, &st, &tb, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &sl, &tr, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &sl, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &tb, &st, &st, &st, &st, &sl, &tb, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &tr, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl}
    });

    for (std::size_t i = 0; i < map.get_nb_line(); ++i) {
        for (std::size_t j = 0; j < map.get_nb_column(); ++j) {
            std::cout << *map[Position(i, j)];
        }
    }
    std::cout << std::endl;
}

void test2() {
    Street st(tag_street::none);
    Street tr(tag_street::trap);
    Street sl(tag_street::slipery);
    Street dr(tag_street::door);
    Shop s1(tag_shop::generous);
    Shop s2(tag_shop::mimic);
    Monument wl(tag_monument::wall);
    Monument tb(tag_monument::table);

    Map map(17, 17, {
        {&wl, &wl, &wl, &wl, &dr, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &dr, &wl, &wl, &wl, &wl},
        {&wl, &s1, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl},
        {&wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &tr, &st, &st, &st, &tr, &st, &wl},
        {&wl, &st, &st, &tb, &st, &tr, &st, &st, &st, &st, &st, &st, &st, &tb, &st, &st, &wl},
        {&wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl},
        {&wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &tr, &st, &st, &st, &st, &s2, &wl},
        {&wl, &wl, &wl, &st, &st, &st, &st, &st, &st, &st, &sl, &st, &st, &sl, &wl, &wl, &wl},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &tb, &st, &st, &st, &st, &st, &tb, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &sl, &tr, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &sl, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &tb, &st, &st, &st, &st, &sl, &tb, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &tr, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&st, &st, &wl, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &st, &wl, &st, &st},
        {&wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl, &wl}
    });

    for (Line line : map) {
        for (Element* el : line) {
            std::cout << *el;
        }
    }
    std::cout << std::endl;
}

} // namespace map::core

int main() {
    map::core::test1();
    map::core::test2();
    return 0;
}
