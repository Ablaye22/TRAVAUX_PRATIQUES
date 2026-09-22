#ifndef ROMAN_H
#define ROMAN_H
#include"Livre.h"
using namespace std;
class Roman:public Livre{
    string genre;
    public:
        Roman();
        Roman(string titre,string auteur,int annee,string genre);
        void afficher();
};

#endif