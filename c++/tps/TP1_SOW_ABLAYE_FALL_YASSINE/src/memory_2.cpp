/* Exercice 222, A.3o) : Distance_1 libere son pointeur et interdit la copie */
#include "inheritance.hpp"

#include <cmath>

class Distance_1 {
private:
  Distance_core const * const _content;

public:
  Distance_1(Distance_core const * const content);
  ~Distance_1();                              // <- corrige la fuite memoire
  Distance_1(Distance_1 const &) = delete;    // <- interdit le partage du pointeur

  Distance_core const * get_content() const;

  Distance_1 convert_to_meters()       const;
  Distance_1 convert_to_feet()         const;
  Distance_1 convert_to_leagues()      const;
  Distance_1 convert_to_nautic_miles() const;

  friend std::ostream& operator<<(std::ostream& os, Distance_1 const & d);
};

Distance_1::Distance_1(Distance_core const * const content) : _content(content) {}

Distance_1::~Distance_1() { delete this->_content; }

Distance_core const * Distance_1::get_content() const { return this->_content; }

Distance_1 Distance_1::convert_to_meters() const {
  return Distance_1(this->_content->convert_to_meters());
}
Distance_1 Distance_1::convert_to_feet() const {
  return Distance_1(this->_content->convert_to_feet());
}
Distance_1 Distance_1::convert_to_leagues() const {
  return Distance_1(this->_content->convert_to_leagues());
}
Distance_1 Distance_1::convert_to_nautic_miles() const {
  return Distance_1(this->_content->convert_to_nautic_miles());
}

std::ostream& operator<<(std::ostream& os, Distance_1 const & d) {
  return os << d._content;
}

namespace {
  double const EPSILON = 1e-9;

  double meters_of(Distance_1 const & d) {
    Distance_core const * const p = d.get_content()->convert_to_meters();
    double const v = p->get_value();
    delete p;
    return v;
  }
}

bool operator==(Distance_1 const & lhs, Distance_1 const & rhs) {
  return std::abs(meters_of(lhs) - meters_of(rhs)) < EPSILON;
}
bool operator!=(Distance_1 const & lhs, Distance_1 const & rhs) { return !(lhs == rhs); }
bool operator< (Distance_1 const & lhs, Distance_1 const & rhs) {
  return (meters_of(lhs) < meters_of(rhs)) && (lhs != rhs);
}
bool operator> (Distance_1 const & lhs, Distance_1 const & rhs) { return rhs < lhs; }
bool operator<=(Distance_1 const & lhs, Distance_1 const & rhs) { return !(rhs < lhs); }
bool operator>=(Distance_1 const & lhs, Distance_1 const & rhs) { return !(lhs < rhs); }

int main() {
  Distance_1 d1(new Distance_meters(1.));
  Distance_1 d2(new Distance_leagues(3.));

  std::cout << std::boolalpha << d1 << " vs " << d2 << " => " << (d1 < d2) << " | "
            << (d1 == d2) << " | " << (d1 > d2) << std::endl;

  Distance_1 d3(nullptr);
  std::cout << d3 << std::endl;   // <- il reste cette unique erreur

  return 0;
}
