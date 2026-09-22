/* Exercice 222, A.1o) : la version naive, pleine de fuites memoire */
#include "inheritance.hpp"

int main() {
  Distance d1(new Distance_meters(1.));
  Distance d2(new Distance_leagues(3.));

  std::cout << std::boolalpha << d1 << " vs " << d2 << " => " << (d1 < d2) << " | "
            << (d1 == d2) << " | " << (d1 > d2) << std::endl;

  Distance d3(nullptr);
  std::cout << d3 << std::endl;   // <- lecture invalide : segfault

  return 0;
}
