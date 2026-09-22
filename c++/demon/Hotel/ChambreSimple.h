#ifndef CHAMBRESIMPLE_H
#define CHAMBRESIMPLE_H
#include <iostream>
#include "Chambre.h"
using namespace std;

class ChambreSimple: public Chambre{
    int _lit;  
public:
    ChambreSimple();
    ChambreSimple(int numero,double prixNuit,int lit);
    ~ChambreSimple();
    void afficher() const override;
};

#endif