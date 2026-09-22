/* Exercice 222, B.2o) */
#include "data_2.hpp"

#include <utility>

int main() {
  int i = 0;

  test(std::move(std::as_const(i)));  // int const &&
  test(&i);                           // int*
  test(i);                            // int&
  test(std::move(i));                 // int&&

  return 0;
}
