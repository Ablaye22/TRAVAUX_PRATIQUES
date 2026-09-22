#ifndef MAGAZINE_H
#define MAGAZINE_H
#include"Livre.h"
#include"Magazine.h"
using namespace std;
class Magazine: public Livre{
    int numero;
public:
    Magazine();
    Magazine(string titre,string auteur,int annee,int numero);
    void afficher();
};


#endif