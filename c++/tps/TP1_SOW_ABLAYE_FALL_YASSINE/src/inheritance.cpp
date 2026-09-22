#include "inheritance.hpp"

#include <cmath>

/* ---- les facteurs donnes par l'enonce ---- */
namespace {
  double const M_TO_FEET    = 3.280839895;
  double const M_TO_LEAGUES = 0.0002071237;
  double const M_TO_NAUTIC  = 0.0005399568;
  double const FT_TO_LEAGUES= 6.31313e-5;
  double const FT_TO_NAUTIC = 0.0001645788;
  double const LG_TO_NAUTIC = 2.606928726;

  double const EPSILON = 1e-9;

  // valeur en metres d'une Distance, sans fuite memoire
  double meters_of(Distance const & d) {
    Distance_core const * const p = d.get_content()->convert_to_meters();
    double const v = p->get_value();
    delete p;
    return v;
  }
}

/* ---- Distance_core ---- */
Distance_core::Distance_core(double const value) : _value(value) {}

double Distance_core::get_value() const { return this->_value; }

std::ostream& operator<<(std::ostream& os, Distance_core const * d) {
  return d->_print(os);
}

/* ---- Distance (le wrapper) ---- */
Distance::Distance(Distance_core const * const content) : _content(content) {}

Distance_core const * Distance::get_content() const { return this->_content; }

Distance Distance::convert_to_meters() const {
  return Distance(this->_content->convert_to_meters());
}
Distance Distance::convert_to_feet() const {
  return Distance(this->_content->convert_to_feet());
}
Distance Distance::convert_to_leagues() const {
  return Distance(this->_content->convert_to_leagues());
}
Distance Distance::convert_to_nautic_miles() const {
  return Distance(this->_content->convert_to_nautic_miles());
}

std::ostream& operator<<(std::ostream& os, Distance const & d) {
  return os << d._content;
}

/* ---- Distance_meters ---- */
Distance_meters::Distance_meters(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " meters was just created" << std::endl;
}
Distance_meters::~Distance_meters() {
  std::cout << "A distance of " << this->_value << " meters was just destroyed" << std::endl;
}
std::ostream& Distance_meters::_print(std::ostream& os) const {
  return os << this->_value << " meters";
}
Distance_core const * Distance_meters::convert_to_meters() const {
  return new Distance_meters(this->_value);
}
Distance_core const * Distance_meters::convert_to_feet() const {
  return new Distance_feet(this->_value * M_TO_FEET);
}
Distance_core const * Distance_meters::convert_to_leagues() const {
  return new Distance_leagues(this->_value * M_TO_LEAGUES);
}
Distance_core const * Distance_meters::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value * M_TO_NAUTIC);
}

/* ---- Distance_feet ---- */
Distance_feet::Distance_feet(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " feet was just created" << std::endl;
}
Distance_feet::~Distance_feet() {
  std::cout << "A distance of " << this->_value << " feet was just destroyed" << std::endl;
}
std::ostream& Distance_feet::_print(std::ostream& os) const {
  return os << this->_value << " feet";
}
Distance_core const * Distance_feet::convert_to_meters() const {
  return new Distance_meters(this->_value / M_TO_FEET);
}
Distance_core const * Distance_feet::convert_to_feet() const {
  return new Distance_feet(this->_value);
}
Distance_core const * Distance_feet::convert_to_leagues() const {
  return new Distance_leagues(this->_value * FT_TO_LEAGUES);
}
Distance_core const * Distance_feet::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value * FT_TO_NAUTIC);
}

/* ---- Distance_leagues ---- */
Distance_leagues::Distance_leagues(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " leagues was just created" << std::endl;
}
Distance_leagues::~Distance_leagues() {
  std::cout << "A distance of " << this->_value << " leagues was just destroyed" << std::endl;
}
std::ostream& Distance_leagues::_print(std::ostream& os) const {
  return os << this->_value << " leagues";
}
Distance_core const * Distance_leagues::convert_to_meters() const {
  return new Distance_meters(this->_value / M_TO_LEAGUES);
}
Distance_core const * Distance_leagues::convert_to_feet() const {
  return new Distance_feet(this->_value / FT_TO_LEAGUES);
}
Distance_core const * Distance_leagues::convert_to_leagues() const {
  return new Distance_leagues(this->_value);
}
Distance_core const * Distance_leagues::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value * LG_TO_NAUTIC);
}

/* ---- Distance_nautic_miles ---- */
Distance_nautic_miles::Distance_nautic_miles(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " nautic_miles was just created" << std::endl;
}
Distance_nautic_miles::~Distance_nautic_miles() {
  std::cout << "A distance of " << this->_value << " nautic_miles was just destroyed" << std::endl;
}
std::ostream& Distance_nautic_miles::_print(std::ostream& os) const {
  return os << this->_value << " nautic_miles";
}
Distance_core const * Distance_nautic_miles::convert_to_meters() const {
  return new Distance_meters(this->_value / M_TO_NAUTIC);
}
Distance_core const * Distance_nautic_miles::convert_to_feet() const {
  return new Distance_feet(this->_value / FT_TO_NAUTIC);
}
Distance_core const * Distance_nautic_miles::convert_to_leagues() const {
  return new Distance_leagues(this->_value / LG_TO_NAUTIC);
}
Distance_core const * Distance_nautic_miles::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value);
}

/* ---- les comparaisons ---- */
bool operator==(Distance const & lhs, Distance const & rhs) {
  return std::abs(meters_of(lhs) - meters_of(rhs)) < EPSILON;
}
bool operator!=(Distance const & lhs, Distance const & rhs) { return !(lhs == rhs); }
bool operator< (Distance const & lhs, Distance const & rhs) {
  return (meters_of(lhs) < meters_of(rhs)) && (lhs != rhs);
}
bool operator> (Distance const & lhs, Distance const & rhs) { return rhs < lhs; }
bool operator<=(Distance const & lhs, Distance const & rhs) { return !(rhs < lhs); }
bool operator>=(Distance const & lhs, Distance const & rhs) { return !(lhs < rhs); }
