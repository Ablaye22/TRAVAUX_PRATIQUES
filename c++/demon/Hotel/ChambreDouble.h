#ifndef CHAMBREDOUBLE_H
#define CHAMBREDOUBLE_H
#include  "Chambre.h"

using namespace std;

class ChambreDouble:public Chambre{
    int _lits;
public:
    ChambreDouble();
    ChambreDouble(int numero,double prixNuit,int lits);
    ~ChambreDouble();
    void afficher() const override;
};

#endif