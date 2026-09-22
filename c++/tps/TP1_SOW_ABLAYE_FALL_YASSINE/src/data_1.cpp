/* Exercice 222, B.1o) : NE COMPILE PAS, et c'est le but de la question.
   g++ rale : « call of overloaded 'test(int&)' is ambiguous », parce qu'un
   int& comme un int&& se convertissent implicitement en int. */
#include "data_1.hpp"

#include <utility>

int main() {
  int i = 0;
  int & r = i;

  test(i);              // ambigu : int, int& et int&& conviennent
  test(&i);             // seul int* convient : celui-la passerait
  test(r);              // ambigu aussi
  test(std::move(i));   // ambigu aussi

  return 0;
}
