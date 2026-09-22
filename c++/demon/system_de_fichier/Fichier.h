#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include "Element.h"
using namespace std;
class Fichier: public Element{
    string _contenu;
    string _extension;
public:
    Fichier(string nom,Dossier* parent,string contenu,string extension);
    Fichier();
    ~Fichier();
    string getContenu() const;
    string getExtension() const;
    void afficher(int profondeur = 0) const override;
    size_t taille() const override;
    void ecrire(const string &text);
};
#endif