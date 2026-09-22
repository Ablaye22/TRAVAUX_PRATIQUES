#ifndef INHERITANCE_HPP
#define INHERITANCE_HPP

#include <iostream>

/* ==== Exercice 111, Partie 1.B : les conversions par heritage ==== */

// 1o) la classe abstraite
class Distance_core {
protected:
  double const _value;

  Distance_core(double const value);
  virtual std::ostream& _print(std::ostream& os) const = 0;

public:
  virtual ~Distance_core() {}   // destructeur virtuel : indispensable

  double get_value() const;     // note du 5o)

  virtual Distance_core const * convert_to_meters()       const = 0;
  virtual Distance_core const * convert_to_feet()         const = 0;
  virtual Distance_core const * convert_to_leagues()      const = 0;
  virtual Distance_core const * convert_to_nautic_miles() const = 0;

  friend std::ostream& operator<<(std::ostream& os, Distance_core const * d);
};

std::ostream& operator<<(std::ostream& os, Distance_core const * d);

// 2o) le wrapper qui cache le pointeur
class Distance {
private:
  Distance_core const * const _content;

public:
  Distance(Distance_core const * const content);

  Distance_core const * get_content() const;

  Distance convert_to_meters()       const;
  Distance convert_to_feet()         const;
  Distance convert_to_leagues()      const;
  Distance convert_to_nautic_miles() const;

  friend std::ostream& operator<<(std::ostream& os, Distance const & d);
};

std::ostream& operator<<(std::ostream& os, Distance const & d);

// 3o) une classe concrete par unite
class Distance_meters : public Distance_core {
protected:
  std::ostream& _print(std::ostream& os) const;
public:
  Distance_meters(double const value);
  ~Distance_meters();
  Distance_core const * convert_to_meters()       const;
  Distance_core const * convert_to_feet()         const;
  Distance_core const * convert_to_leagues()      const;
  Distance_core const * convert_to_nautic_miles() const;
};

class Distance_feet : public Distance_core {
protected:
  std::ostream& _print(std::ostream& os) const;
public:
  Distance_feet(double const value);
  ~Distance_feet();
  Distance_core const * convert_to_meters()       const;
  Distance_core const * convert_to_feet()         const;
  Distance_core const * convert_to_leagues()      const;
  Distance_core const * convert_to_nautic_miles() const;
};

class Distance_leagues : public Distance_core {
protected:
  std::ostream& _print(std::ostream& os) const;
public:
  Distance_leagues(double const value);
  ~Distance_leagues();
  Distance_core const * convert_to_meters()       const;
  Distance_core const * convert_to_feet()         const;
  Distance_core const * convert_to_leagues()      const;
  Distance_core const * convert_to_nautic_miles() const;
};

class Distance_nautic_miles : public Distance_core {
protected:
  std::ostream& _print(std::ostream& os) const;
public:
  Distance_nautic_miles(double const value);
  ~Distance_nautic_miles();
  Distance_core const * convert_to_meters()       const;
  Distance_core const * convert_to_feet()         const;
  Distance_core const * convert_to_leagues()      const;
  Distance_core const * convert_to_nautic_miles() const;
};

// 5o) les comparaisons, sur Distance et pas sur les pointeurs
bool operator==(Distance const & lhs, Distance const & rhs);
bool operator!=(Distance const & lhs, Distance const & rhs);
bool operator<=(Distance const & lhs, Distance const & rhs);
bool operator>=(Distance const & lhs, Distance const & rhs);
bool operator< (Distance const & lhs, Distance const & rhs);
bool operator> (Distance const & lhs, Distance const & rhs);

#endif
