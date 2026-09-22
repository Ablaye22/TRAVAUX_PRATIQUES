#ifndef LIVRE_H
#define LIVRE_H
#include<iostream>
#include<string.h>
#include"Document.h"
using namespace std;

class Livre: public Document{
    protected:
        string auteur;
        int annee;
        bool disponible;
    public:
        Livre();
        Livre(string titre,string auteur,int annee);
        ostream& operator<<(Livre &obj);
        string getAuteur();
        int getAnnee();
        bool estDisponible();
        void setAuteur(string auteur);
        void setAnnee(int annee);
        void afficher();
        void emprunter();
        void rendre();
};

#endif