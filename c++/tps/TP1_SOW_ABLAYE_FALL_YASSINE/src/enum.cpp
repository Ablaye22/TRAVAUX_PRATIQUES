#include "enum.hpp"

#include <cmath>

/* ---- affichage de l'enumeration ---- */
std::ostream& operator<<(std::ostream& os, distance_t const & unit) {
  switch(unit) {
    case distance_t::meters:       os << "meters";       break;
    case distance_t::feet:         os << "feet";         break;
    case distance_t::leagues:      os << "leagues";      break;
    case distance_t::nautic_miles: os << "nautic_miles"; break;
  }
  return os;
}

/* ---- les facteurs de conversion, tous exprimes depuis le metre ---- */
namespace {
  double const M_TO_FEET    = 3.280839895;
  double const M_TO_LEAGUES = 0.0002071237;
  double const M_TO_NAUTIC  = 0.0005399568;

  // combien de metres vaut une unite de `unit`
  double to_meters(double const value, distance_t const unit) {
    switch(unit) {
      case distance_t::meters:       return value;
      case distance_t::feet:         return value / M_TO_FEET;
      case distance_t::leagues:      return value / M_TO_LEAGUES;
      case distance_t::nautic_miles: return value / M_TO_NAUTIC;
    }
    return value;
  }

  // combien d'unites `unit` vaut une valeur exprimee en metres
  double from_meters(double const value, distance_t const unit) {
    switch(unit) {
      case distance_t::meters:       return value;
      case distance_t::feet:         return value * M_TO_FEET;
      case distance_t::leagues:      return value * M_TO_LEAGUES;
      case distance_t::nautic_miles: return value * M_TO_NAUTIC;
    }
    return value;
  }

  double meters_of(Distance const & d) {
    return to_meters(d.get_value(), d.get_unit());
  }

  double const EPSILON = 1e-9;
}

/* ---- la classe Distance ---- */
Distance::Distance(double const value, distance_t const unit): _value(value), _unit(unit) {
  std::cout << "A distance of " << this->_value << " " << this->_unit
            << " was just created" << std::endl;
}

Distance::~Distance() {
  std::cout << "A distance of " << this->_value << " " << this->_unit
            << " was just destroyed" << std::endl;
}

double     Distance::get_value() const { 
  return this->_value; 
}
distance_t Distance::get_unit()  const { 
  return this->_unit;  
}

Distance const Distance::convert_to(distance_t const new_unit) const {
  return Distance(from_meters(to_meters(this->_value, this->_unit), new_unit),
                  new_unit);
}

std::ostream& operator<<(std::ostream& os, Distance const & d) {
  return os << d._value << " " << d._unit;
}

/* ---- les comparaisons : tout est ramene en metres ---- */
bool operator==(Distance const & lhs, Distance const & rhs) {
  return std::abs(meters_of(lhs) - meters_of(rhs)) < EPSILON;
}
bool operator!=(Distance const & lhs, Distance const & rhs) { 
  return !(lhs == rhs); 
}
bool operator< (Distance const & lhs, Distance const & rhs) {
  return (meters_of(lhs) < meters_of(rhs)) && (lhs != rhs);
}
bool operator> (Distance const & lhs, Distance const & rhs) { 
  return rhs < lhs; 
}
bool operator<=(Distance const & lhs, Distance const & rhs) { 
  return !(rhs < lhs); 
}
bool operator>=(Distance const & lhs, Distance const & rhs) { 
  return !(lhs < rhs); 
}
