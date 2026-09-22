#ifndef DOSSIER_H
#define DOSSIER_H
#include <iostream>
#include <vector>
#include "Element.h"
using namespace std;


class Dossier: public Element{
    vector<Element*> elements;
public:
    Dossier();
    Dossier(string nom,Dossier * parent);
    ~Dossier();
    void ajouter(Element *element);
    void supprimer(const string &nom);
    Element* rechercher(const string &nom);
    void afficher(int profondeur = 0) const override;
    size_t taille() const override;

};
#endif