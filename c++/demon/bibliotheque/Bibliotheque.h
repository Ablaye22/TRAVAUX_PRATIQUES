#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include"Document.h"
#include<iostream>
#include<vector>
using namespace std;

class Bibliotheque{
    vector<Document*> documents;
    public:
        Bibliotheque();
        ~Bibliotheque();
        void ajouterDocument();
        void supprimerDocument(string titre);
        void afficherDocuments();
        Document *chercher(string titre);
        //Document * chercher(string auteur);
        Document *chercher(int annee);
        int trouverPosition(string titre);
        void emprunter(string titre);
        void rendre(string titre);
        void sauvegarder(Document *doc);
        void charger();
        void menu();
};

#endif