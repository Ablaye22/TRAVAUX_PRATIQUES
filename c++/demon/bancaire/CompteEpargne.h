#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include "Compte.h"
#include <iostream>
class CompteEpargne:public Compte{
    double tauxInteret;
    public:
        CompteEpargne(std::string numero,std::string titulaire);
        CompteEpargne();
        ~CompteEpargne();
        void appliquerInterets();
        void afficher();
        void retirer(double montant);
};
#endif