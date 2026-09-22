#ifndef COMPTE_H
#define COMPTE_H
#include <iostream>
class Compte{
    protected:
        std::string numero;
        std::string titulaire;
        double solde;
    public:
        Compte();
        Compte(std::string numero,std::string titulaire);
        virtual ~Compte();
        std::string getNumero();
        std::string getTitulaire();
        double getSolde();
        virtual void afficher() = 0;
        virtual void retirer(double montant) = 0;
        virtual void deposer(double montant);

};
#endif