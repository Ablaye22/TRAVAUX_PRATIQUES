#ifndef SUITE_H
#define SUITE_H
#include "Chambre.h"
#include <iostream>

using namespace std;

class Suite:public Chambre{
    double _surface;
public:
    Suite();
    Suite(int numero,double prixNuit,double surface);
    ~Suite();
    void afficher() const override;
};

#endif