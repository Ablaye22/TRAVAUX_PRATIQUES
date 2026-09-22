/* Petit main de test pour la partie 1.A (enumerations) */
#include "enum.hpp"

int main() {
  Distance const d1(1., distance_t::meters);
  Distance const d2(3., distance_t::leagues);

  Distance const d1_ft = d1.convert_to(distance_t::feet);
  std::cout << d1 << " == " << d1_ft << std::endl;

  std::cout << std::boolalpha << d1 << " vs " << d2 << " => " << (d1 < d2) << " | "
            << (d1 == d2) << " | " << (d1 > d2) << std::endl;

  return 0;
}
