#ifndef COMPTECOURANTE_H
#define COMPTECOURANTE_H
#include "Compte.h"

class CompteCourante:public Compte {
    double decouvertAutorise;
    public:
        CompteCourante(std::string numero,std::string titulaire);
        CompteCourante();
        ~CompteCourante();
        void afficher();
        void retirer(double montant);
        double getDecouvertAutorise();
};
#endif