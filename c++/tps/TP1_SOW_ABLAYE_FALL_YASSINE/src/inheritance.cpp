#include "inheritance.hpp"


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

/* ---- Constructeur de la classe Distance_core ---- */
Distance_core::Distance_core(double const value) : _value(value) {

}
/* definition de la fonction get_value retournant la valeur de l'objet*/
double Distance_core::get_value() const { 
  return this->_value; 
}
/* redefinition de l'operateur  d'affichage */
std::ostream& operator<<(std::ostream& os, Distance_core const * d) {
  return d->_print(os);
}

/* ---- Constructeur de la classe Distance ---- */
Distance::Distance(Distance_core const * const content) : _content(content) {

}
/* definition de la methode get_content retournant la valeur de la variable _content */
Distance_core const * Distance::get_content() const { 
  return this->_content; 
}
/* definition de la methode convert_to en metre*/
Distance Distance::convert_to_meters() const {
  return Distance(this->_content->convert_to_meters());
}
/* definition de la methode convert_to en feet*/
Distance Distance::convert_to_feet() const {
  return Distance(this->_content->convert_to_feet());
}
/* definition de la methode convert_to en leagues*/
Distance Distance::convert_to_leagues() const {
  return Distance(this->_content->convert_to_leagues());
}
/* definition de la methode convert_to en nautic_miles*/
Distance Distance::convert_to_nautic_miles() const {
  return Distance(this->_content->convert_to_nautic_miles());
}
/* redefinition de l'operateur d'affichage pour la classe Distance */
std::ostream& operator<<(std::ostream& os, Distance const & d) {
  return os << d._content;
}

/* ---- Constructeur de la classe Distance_meters ---- */
Distance_meters::Distance_meters(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " meters was just created" << std::endl;
}
/* --- Destructeur de la classe Distance_meters --- */
Distance_meters::~Distance_meters() {
  std::cout << "A distance of " << this->_value << " meters was just destroyed" << std::endl;
}
/* definition de la fonction _print pour la classe Distance_meters */
std::ostream& Distance_meters::_print(std::ostream& os) const {
  return os << this->_value << " meters";
}
/* definition de la methode convert_to_meters */
Distance_core const * Distance_meters::convert_to_meters() const {
  return new Distance_meters(this->_value);
}
/* definition de la methode convert_to_feet */
Distance_core const * Distance_meters::convert_to_feet() const {
  return new Distance_feet(this->_value * M_TO_FEET);
}
/* definition de la methode convert_to_leagues */
Distance_core const * Distance_meters::convert_to_leagues() const {
  return new Distance_leagues(this->_value * M_TO_LEAGUES);
}
/* definition de la methode convert_to_nautic_miles */
Distance_core const * Distance_meters::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value * M_TO_NAUTIC);
}

/* ---- Constructeur de la classe Distance_feet ---- */
Distance_feet::Distance_feet(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " feet was just created" << std::endl;
}
/* Destructeur de la classe Distance_feet */
Distance_feet::~Distance_feet() {
  std::cout << "A distance of " << this->_value << " feet was just destroyed" << std::endl;
}
/* definition de la methode _print pour la classe Distance_feet */
std::ostream& Distance_feet::_print(std::ostream& os) const {
  return os << this->_value << " feet";
}
/* definition de la methode convert_to_meters */
Distance_core const * Distance_feet::convert_to_meters() const {
  return new Distance_meters(this->_value / M_TO_FEET);
}
/* definition de la methode convert_to_feet */
Distance_core const * Distance_feet::convert_to_feet() const {
  return new Distance_feet(this->_value);
}
/* definition de la methode convert_to_leagues */
Distance_core const * Distance_feet::convert_to_leagues() const {
  return new Distance_leagues(this->_value * FT_TO_LEAGUES);
}
/* definition de la methode convert_to_nautic_miles */
Distance_core const * Distance_feet::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value * FT_TO_NAUTIC);
}

/* ---- Constructeur de la classe Distance_leagues ---- */
Distance_leagues::Distance_leagues(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " leagues was just created" << std::endl;
}
/* ---- Destructeur de la classe Distance_leagues ---- */
Distance_leagues::~Distance_leagues() {
  std::cout << "A distance of " << this->_value << " leagues was just destroyed" << std::endl;
}
/* definiton de la methode _print pour la classe Distance_leagues */
std::ostream& Distance_leagues::_print(std::ostream& os) const {
  return os << this->_value << " leagues";
}
/* definition de la methode convert_to_meters */
Distance_core const * Distance_leagues::convert_to_meters() const {
  return new Distance_meters(this->_value / M_TO_LEAGUES);
}
/* definition de la methode convert_to_feet */
Distance_core const * Distance_leagues::convert_to_feet() const {
  return new Distance_feet(this->_value / FT_TO_LEAGUES);
}
/* definition de la methode convert_to_leagues */
Distance_core const * Distance_leagues::convert_to_leagues() const {
  return new Distance_leagues(this->_value);
}
/* definition de la methode convert_to_nautic_miles */
Distance_core const * Distance_leagues::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value * LG_TO_NAUTIC);
}

/* ---- Constructeur de la classe Distance_nautic_miles ---- */
Distance_nautic_miles::Distance_nautic_miles(double const value) : Distance_core(value) {
  std::cout << "A distance of " << this->_value << " nautic_miles was just created" << std::endl;
}
/* ---- Destructeur de la classe Distance_nautic_miles ---- */
Distance_nautic_miles::~Distance_nautic_miles() {
  std::cout << "A distance of " << this->_value << " nautic_miles was just destroyed" << std::endl;
}
/* definition de la methode _print pour la classe Distance_nautic_miles */
std::ostream& Distance_nautic_miles::_print(std::ostream& os) const {
  return os << this->_value << " nautic_miles";
}
/* definition de la methode convert_to_meters */
Distance_core const * Distance_nautic_miles::convert_to_meters() const {
  return new Distance_meters(this->_value / M_TO_NAUTIC);
}
/* definition de la methode convert_to_feet */
Distance_core const * Distance_nautic_miles::convert_to_feet() const {
  return new Distance_feet(this->_value / FT_TO_NAUTIC);
}
/* definition de la methode convert_to_leagues */
Distance_core const * Distance_nautic_miles::convert_to_leagues() const {
  return new Distance_leagues(this->_value / LG_TO_NAUTIC);
}
/* definition de la methode convert_to_nautic_miles */
Distance_core const * Distance_nautic_miles::convert_to_nautic_miles() const {
  return new Distance_nautic_miles(this->_value);
}

/* ---- les comparaisons ---- */
/* redefinition de l'operateur d'affichage */
bool operator==(Distance const & d1, Distance const & d2) {
  // On calcule la distance en metre pour les deux distances
  Distance_core const * const p1 = d1.get_content()->convert_to_meters();
  Distance_core const * const p2 = d2.get_content()->convert_to_meters();
  double const valeur1 = p1->get_value();
  double const valeur2 = p2->get_value();
  // on libere la memoire 
  delete p1;
  delete p2;
  double diff = valeur1 - valeur2;
  if (diff < 0)
    diff = -diff;
  return diff < EPSILON;
}
/* redefinition de la l'operateur != */
bool operator!=(Distance const & d1, Distance const & d2) { 
  return !(d1 == d2); 
}
/* redefinition de l'operateur < */
bool operator<(Distance const & d1, Distance const & d2) {
  // On calcule la distance en metre pour les deux distances
  Distance_core const * const p1 = d1.get_content()->convert_to_meters();
  Distance_core const * const p2 = d2.get_content()->convert_to_meters();
  double const valeur1 = p1->get_value();
  double const valeur2 = p2->get_value();
  // on libere la memoire 
  delete p1;
  delete p2;
  return valeur1 < valeur2;
}
/* redefinition de l'operateur > */
bool operator> (Distance const & d1, Distance const & d2) { 
  return d2 < d1; 
}
/* redefinition de l'operateur <= */
bool operator<=(Distance const & d1, Distance const & d2) { 
  return !(d2 < d1); 
}
/* redefinition de l'operateur >= */
bool operator>=(Distance const & d1, Distance const & d2) { 
  return !(d1 < d2); 
}
