#include "tag.hpp"

namespace map::core {

std::ostream& operator<<(std::ostream& cout, tag_street const& obj) {
    switch (obj) {
        case tag_street::door:
            cout << 'D';
            break;
        case tag_street::none:
        case tag_street::trap:
        case tag_street::slipery:
        default:
            cout << ' ';
            break;
    }
    return cout;
}

std::ostream& operator<<(std::ostream& cout, tag_shop const& obj) {
    switch (obj) {
        case tag_shop::generous:
            cout << 'G';
            break;
        case tag_shop::none:
        case tag_shop::mimic:
        default:
            cout << 'S';
            break;
    }
    return cout;
}

std::ostream& operator<<(std::ostream& cout, tag_monument const& obj) {
    switch (obj) {
        case tag_monument::statue:
            cout << 'O';
            break;
        case tag_monument::wall:
            cout << 'W';
            break;
        case tag_monument::table:
            cout << 'T';
            break;
    }
    return cout;
}

} // namespace map::core
