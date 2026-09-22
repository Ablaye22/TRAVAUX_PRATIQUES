#ifndef DATA_1_HPP
#define DATA_1_HPP

#include <iostream>

/* Exercice 222, B.1o) : les 4 etats d'une donnee, version naive.
   Attention : ce fichier compile, mais les appels de data_1.cpp sont ambigus. */

inline void test(int)    { std::cout << "int"    << std::endl; }
inline void test(int*)   { std::cout << "int*"   << std::endl; }
inline void test(int&)   { std::cout << "int&"   << std::endl; }
inline void test(int&&)  { std::cout << "int&&"  << std::endl; }

#endif
