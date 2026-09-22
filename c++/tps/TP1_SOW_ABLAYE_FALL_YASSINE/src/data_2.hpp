#ifndef DATA_2_HPP
#define DATA_2_HPP

#include <iostream>

/* Exercice 222, B.2o) : on remplace `int` par `int const &&`, qui n'est
   jamais produit par les conversions implicites. Plus d'ambiguite. */

inline void test(int const &&) { std::cout << "int const &&" << std::endl; }
inline void test(int*)         { std::cout << "int*"         << std::endl; }
inline void test(int&)         { std::cout << "int&"         << std::endl; }
inline void test(int&&)        { std::cout << "int&&"        << std::endl; }

#endif
