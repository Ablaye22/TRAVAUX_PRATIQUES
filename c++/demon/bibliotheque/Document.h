#ifndef DOCUMENT_H
#define DOCUMENT_H
#include<iostream>
using namespace std;

class Document{
    protected:
        string titre;
    public:
        Document();
        Document(string titre);
        virtual void afficher() = 0;
        string getTitre();
        void setTitre(string titre);
        virtual int getAnnee() = 0;
        virtual bool estDisponible() = 0;
        virtual void setAuteur(string auteur) = 0;
        virtual void setAnnee(int annee) = 0;
        virtual void emprunter() = 0;
        virtual void rendre() = 0;
};

#endif
