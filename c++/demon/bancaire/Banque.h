#ifndef BANQUE_H
#define BANQUE_H
#include <iostream>
#include<vector>    
#include "Compte.h"
class Banque{
    std::vector<Compte*> comptes;
    std::string nomBanque;
    public:
        Banque(std::string nom);
        ~Banque();
        std::string getNomBanque();
        void setNomBanque(std::string nom);
        void ajouterCompte(); 
        void afficherComptes();
        Compte* chercher(std::string numero);
        void chercher();
        int trouverPosition(std::string numero);
        void supprimerCompte();
        void deposer();
        void retirer();
        void appliquerInterets();
        void menu();
        void executer(int choix);
};
#endif
