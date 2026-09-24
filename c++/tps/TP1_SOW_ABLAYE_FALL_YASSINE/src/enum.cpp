#include "enum.hpp"

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

/* ---- constantes de conversion (const au scope fichier => linkage interne) ---- */
double const M_TO_FEET    = 3.280839895;
double const M_TO_LEAGUES = 0.0002071237;
double const M_TO_NAUTIC  = 0.0005399568;
double const EPSILON      = 1e-9;

/* ---- Constructeur de la classe Distance ---- */
Distance::Distance(double const value, distance_t const unit): _value(value), _unit(unit) {
  std::cout << "A distance of " << this->_value << " " << this->_unit
            << " was just created" << std::endl;

}
/* Destructeur de la classe Distance*/
Distance::~Distance() {
  std::cout << "A distance of " << this->_value << " " << this->_unit
            << " was just destroyed" << std::endl;
}
/* getter permettant de recuperer la valeur de  _value*/
double     Distance::get_value() const { 
  return this->_value; 
}
/* getter permettant de recuperer la valeur de _unite*/
distance_t Distance::get_unit()  const { 
  return this->_unit;  
}

/* ---- conversion d'une unité à une autre  ---- */
Distance const Distance::convert_to(distance_t const new_unit) const {
  /* On convertiti l'unite courant en mettre */
  double meters;

  switch (this->_unit) {
    case distance_t::meters:       meters = this->_value;                 break;
    case distance_t::feet:         meters = this->_value / M_TO_FEET;     break;
    case distance_t::leagues:      meters = this->_value / M_TO_LEAGUES;  break;
    case distance_t::nautic_miles: meters = this->_value / M_TO_NAUTIC;   break;
  }
  /* On convertit la valeur précedante dans la nouvelle unite */
  double new_value;

  switch (new_unit) {
    case distance_t::meters:       new_value = meters;                  break;
    case distance_t::feet:         new_value = meters * M_TO_FEET;      break;
    case distance_t::leagues:      new_value = meters * M_TO_LEAGUES;   break;
    case distance_t::nautic_miles: new_value = meters * M_TO_NAUTIC;    break;
  }
  /* On renvoi une nouvelle instance */
  return Distance(new_value, new_unit);
}
/* redefinition de l'operateur d'affichage */
std::ostream& operator<<(std::ostream& os, Distance const & d) {
  return os << d._value << " " << d._unit;
}

/* ---- redefinition de l'operateur == ---- */
bool operator==(Distance const & d1, Distance const & d2) {
  // conversion de la distance d1 en metre
  double d1_meters;
  switch (d1.get_unit()) {
    case distance_t::meters:       d1_meters = d1.get_value();                 break;
    case distance_t::feet:         d1_meters = d1.get_value() / M_TO_FEET;     break;
    case distance_t::leagues:      d1_meters = d1.get_value() / M_TO_LEAGUES;  break;
    case distance_t::nautic_miles: d1_meters = d1.get_value() / M_TO_NAUTIC;   break;
  }
  // conversion de la distance d2 en metre 
  double d2_meters;
  switch (d2.get_unit()) {
    case distance_t::meters:       d2_meters = d2.get_value();                 break;
    case distance_t::feet:         d2_meters = d2.get_value() / M_TO_FEET;     break;
    case distance_t::leagues:      d2_meters = d2.get_value() / M_TO_LEAGUES;  break;
    case distance_t::nautic_miles: d2_meters = d2.get_value() / M_TO_NAUTIC;   break;
  }
  // on fait la difference car on travail avec des doubles 
  double diff = d1_meters - d2_meters;
  if (diff < 0)
    diff = -diff;
  return diff < EPSILON;
}
/* redifinition de l'operateur != */
bool operator!=(Distance const & d1, Distance const & d2) { 
  return !(d1 == d2); 
}
/* redifinition de l'operateur < */
bool operator< (Distance const & d1, Distance const & d2) {
  // on convertit la distance d1 en metre 
  double d1_meters;
  switch (d1.get_unit()) {
    case distance_t::meters:       d1_meters = d1.get_value();                 break;
    case distance_t::feet:         d1_meters = d1.get_value() / M_TO_FEET;     break;
    case distance_t::leagues:      d1_meters = d1.get_value() / M_TO_LEAGUES;  break;
    case distance_t::nautic_miles: d1_meters = d1.get_value() / M_TO_NAUTIC;   break;
  }
  // On converti la distance d2 en metre
  double d2_meters;
  switch (d2.get_unit()) {
    case distance_t::meters:       d2_meters = d2.get_value();                 break;
    case distance_t::feet:         d2_meters = d2.get_value() / M_TO_FEET;     break;
    case distance_t::leagues:      d2_meters = d2.get_value() / M_TO_LEAGUES;  break;
    case distance_t::nautic_miles: d2_meters = d2.get_value() / M_TO_NAUTIC;   break;
  }

  return (d1_meters < d2_meters);
}
/* redifinition de l'operateur > */
bool operator> (Distance const & d1, Distance const & d2) { 
  return d2 < d1; 
}
/* redefinition de l'operateur  <= on inverse seulement la position des distance d1 et d2 */
bool operator<=(Distance const & d1, Distance const & d2) { 
  return !(d1 > d2); 
}
/* redefinition de l'operateur >= */
bool operator>=(Distance const & d1, Distance const & d2) { 
  return !(d1 < d2); 
}