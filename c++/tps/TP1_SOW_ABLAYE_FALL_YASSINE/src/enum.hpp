#ifndef ENUM_HPP
#define ENUM_HPP

#include <iostream>

/* ==== Exercice 111, Partie 1.A : les conversions avec une enumeration ==== */

// 1o) l'enumeration des unites de distance
enum class distance_t { meters, feet, leagues, nautic_miles };

std::ostream& operator<<(std::ostream& os, distance_t const & unit);

// 2o) la classe Distance
class Distance {
private:
  double     const _value;
  distance_t const _unit;

public:
  Distance(double const value, distance_t const unit);
  ~Distance();

  double     get_value() const;
  distance_t get_unit()  const;

  // 3o) conversion vers une autre unite
  Distance const convert_to(distance_t const new_unit) const;

  friend std::ostream& operator<<(std::ostream& os, Distance const & d);
};

std::ostream& operator<<(std::ostream& os, Distance const & d);

// 4o) les operateurs de comparaison
bool operator==(Distance const & lhs, Distance const & rhs);
bool operator!=(Distance const & lhs, Distance const & rhs);
bool operator<=(Distance const & lhs, Distance const & rhs);
bool operator>=(Distance const & lhs, Distance const & rhs);
bool operator< (Distance const & lhs, Distance const & rhs);
bool operator> (Distance const & lhs, Distance const & rhs);

#endif
