#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <iostream>
using namespace std;

class Chambre{
protected:
    int _numero;
    double _prixNuit;
    bool _occupee;
public:
    Chambre();
    Chambre(int numero,double prixNuit);
    ~Chambre();
    int getNumero() const;
    double getPrixNuit() const;
    bool estOccupee() const;
    void reverser();
    void liberer();
    virtual void afficher() const = 0;
};
#endif