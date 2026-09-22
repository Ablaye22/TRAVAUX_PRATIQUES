#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
using namespace std;

class Dossier;

class Element{
    protected:
        string _nom;
        Dossier* _parent;
    public:
        Element(string nom,Dossier *parent);
        Element();
        virtual ~Element();
        string getNom() const;
        virtual void afficher(int profondeur = 0) const = 0;
        virtual size_t  taille() const = 0;
};
#endif